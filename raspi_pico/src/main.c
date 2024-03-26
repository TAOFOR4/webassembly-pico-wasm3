#include "pico/stdlib.h"
#include "pico/time.h"

#include <stdio.h>

#include "wasm3.h"
#include "m3_env.h"

#include "extra/add.wasm.h" // This should be the header file for your add.wasm

#define FATAL(msg, ...)                            \
    {                                              \
        printf("Fatal: " msg "\n", ##__VA_ARGS__); \
        return;                                    \
    }

static void run_wasm(void)
{
    M3Result result = m3Err_none;

    // Assuming your add wasm binary is included as two variables: add_wasm and add_wasm_len
    uint8_t *wasm = (uint8_t *)add_wasm;
    uint32_t fsize = add_wasm_len;

    printf("Loading WebAssembly...\n");
    IM3Environment env = m3_NewEnvironment();
    if (!env)
        FATAL("m3_NewEnvironment failed");

    IM3Runtime runtime = m3_NewRuntime(env, 1024, NULL); // Adjust the stack size as needed
    if (!runtime)
        FATAL("m3_NewRuntime failed");

    IM3Module module;
    result = m3_ParseModule(env, &module, wasm, fsize);
    if (result)
        FATAL("m3_ParseModule: %s", result);

    result = m3_LoadModule(runtime, module);
    if (result)
        FATAL("m3_LoadModule: %s", result);

    IM3Function f;
    // Ensure the function name matches what's exported from your WebAssembly module
    result = m3_FindFunction(&f, runtime, "add");
    if (result)
        FATAL("m3_FindFunction: %s", result);

    printf("Running...\n");

    absolute_time_t start = get_absolute_time();

    // Call the add function, which should print "add, World!" to the console
    result = m3_CallV(f, 1, 2);
    if (result)
        FATAL("m3_Call: %s", result);

    absolute_time_t end = get_absolute_time();

    long value = *(uint64_t *)(runtime->stack);
    printf("Result of addition: %ld\n", value);
    printf("Elapsed: %lld us\n", absolute_time_diff_us(start, end));

    // Cleanup
    m3_FreeRuntime(runtime);
    m3_FreeEnvironment(env);
}

int main(void)
{
    stdio_init_all();
    while (true)
    {
        printf("\nWasm3 v" M3_VERSION " on Raspberry Pi Pico, build " __DATE__ " " __TIME__ "\n");

        run_wasm();

        sleep_ms(5000); // Adjust the sleep time as needed or implement a different loop condition
    }
}
