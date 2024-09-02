#include "pico/stdlib.h"
#include "pico/time.h"

#include <stdio.h>
#include <string.h>

#include "wasm3.h"
#include "m3_env.h"

#define FATAL(msg, ...)                            \
    {                                              \
        printf("Fatal: " msg "\n", ##__VA_ARGS__); \
        return;                                    \
    }

IM3Module module;

void init_wasm_runtime()
{
    printf("Loading WebAssembly...\n");
    IM3Environment env = m3_NewEnvironment();
    if (!env)
        FATAL("m3_NewEnvironment failed");

    IM3Runtime runtime = m3_NewRuntime(env, 8192, NULL); // Adjust the stack size(byte) as needed
    if (!runtime)
        FATAL("m3_NewRuntime failed");
}

static void update_wasm(IM3Environment env, IM3Runtime runtime, const char *contents, int len)
{
    M3Result result = m3Err_none;

    printf("Parsing WASM module...\n");
    result = m3_ParseModule(env, &module, contents, len);
    if (result)
        FATAL("m3_ParseModule: %s", result);

    printf("Loading WASM module...\n");
    result = m3_LoadModule(runtime, module);
    if (result)
        FATAL("m3_LoadModule: %s", result);

    printf("WASM module updated successfully\n");
}

// Get the function name from the message
char *extract_function_name(const char *wasm_text)
{
    const char *export_str = "export ";
    const char *func_str = "(func ";
    char function_name[100]; // Assuming function names won't exceed 100 characters

    const char *export_pos = strstr(wasm_text, export_str);
    while (export_pos)
    {
        // Find where the function keyword starts within the export block
        const char *func_pos = strstr(export_pos, func_str);
        if (!func_pos)
        {
            break; // No more functions to process
        }

        // Move past 'func ' to start reading the function index or name
        func_pos += strlen(func_str);

        // Check if there's a name directly instead of an index
        if (*func_pos == '0')
        {                                     // Assuming index follows if first character is a digit
            func_pos = strchr(func_pos, '"'); // Find the start of the name
            if (!func_pos)
            {
                break;
            }
            func_pos++; // Move past the quote
        }

        // Read the function name up to the closing quote
        const char *end_quote = strchr(func_pos, '"');
        if (!end_quote)
        {
            break;
        }

        int name_length = end_quote - func_pos;
        strncpy(function_name, func_pos, name_length);
        function_name[name_length] = '\0'; // Null-terminate the string

        break;
    }
    return function_name;
}

static void call_wasm(IM3Runtime runtime, const char *message, int len)
{
    printf("Calling function main...\n");
    // TODO: need to parse function name and function args from message
    M3Result result = m3Err_none;
    IM3Function f;
    // Ensure the function name matches what's exported from your WebAssembly module
    printf("Func name: %p\n", extract_function_name(message));
    result = m3_FindFunction(&f, runtime, extract_function_name(message));

    if (result)
        FATAL("m3_FindFunction: %s", result);
    result = m3_CallV(f);
    if (result)
        FATAL("m3_Call: %s", result);
    long value = *(uint64_t *)(runtime->stack);
    // TODO: make it output arbitrary types, not just long
    printf("Output: %d", value);
}

static my_getchar()
{
    int c = PICO_ERROR_TIMEOUT;
    while (c == PICO_ERROR_TIMEOUT)
    {
        c = getc_timeout_us(1000);
    }
    return c;
}

#define MSG_WASM_FILE 1
#define MSG_FUNC_CALL 2
#define MSG_EXIT 3

struct __attribute__((packed)) message_t
{
    uint16_t len;
    char type;
    char contents[1021];
};

static void get_uart_message(struct message_t *message)
{
    message->len = 0;
    message->type = getchar_timeout_us(1000);
    if (message->type == PICO_ERROR_TIMEOUT || message->type == 255)
        return;

    while (true)
    {
        int c = getchar_timeout_us(1000);
        if (c != PICO_ERROR_TIMEOUT && message->len < 1000)
        {
            message->contents[message->len++] = (c & 0xFF);
        }
        else
        {
            break;
        }
    }
    // printf("Received message type: %d len: %d\n", message->type, message->len);
}

int main(void)
{
    IM3Environment env;
    IM3Runtime runtime; // global value won't work
    struct message_t message;
    stdio_init_all(); // Initializes all the standard input/output interfaces
    sleep_ms(5000);
    printf("\nWasm3 v" M3_VERSION " on Raspberry Pi Pico, build " __DATE__ " " __TIME__ "\n");
    init_wasm_runtime();
    printf("Loading WebAssembly...\n");
    env = m3_NewEnvironment();
    if (!env)
        FATAL("m3_NewEnvironment failed");

    runtime = m3_NewRuntime(env, 8192, NULL); // Adjust the stack size(byte) as needed
    if (!runtime)
        FATAL("m3_NewRuntime failed");
    // printf("READY\n");
    while (true)
    {
        get_uart_message(&message);
        // printf("Here\n");
        if (message.len == 0)
        {
            printf("No data received\n");
        }
        else if (message.type == MSG_WASM_FILE)
        {
            update_wasm(env, runtime, message.contents, message.len);
        }
        else if (message.type == MSG_FUNC_CALL)
        {
            call_wasm(runtime, message.contents, message.len);
        }
        else if (message.type == MSG_EXIT)
        {
            m3_FreeRuntime(runtime);
            m3_FreeEnvironment(env);
            break;
        }
        else
        {
            printf("Something goes wrong: len: %d type: %d\n", message.len, message.type);
        }

        sleep_ms(5000); // Adjust the sleep time as needed or implement a different loop condition
    }
    printf("Shutting down...\n");
}
