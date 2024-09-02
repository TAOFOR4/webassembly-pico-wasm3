#include "pico/stdlib.h"
#include "pico/time.h"

#include <stdio.h>
#include <string.h>

#include "wasm3.h"
#include "m3_env.h"

#include "../../resource/wasm_head_files/main_wasm.h" // This should be the header file for your main.wasm

#define FATAL(msg, ...)                            \
    {                                              \
        printf("Fatal: " msg "\n", ##__VA_ARGS__); \
        return;                                    \
    }

static void run_wasm(void)
{
    M3Result result = m3Err_none;

    // Assuming your main wasm binary is included as two variables: test_wasm and test_wasm_len
    uint8_t *wasm = (uint8_t *)main_wasm;
    uint32_t fsize = main_wasm_len;

    // printf("Insert a number...\n");
    // int num;
    // scanf("%d", &num);
    // printf("The number was %d", num);

    printf("Loading WebAssembly...\n");
    IM3Environment env = m3_NewEnvironment();
    if (!env)
        FATAL("m3_NewEnvironment failed");

    IM3Runtime runtime = m3_NewRuntime(env, 8192, NULL); // Adjust the stack size(byte) as needed
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
    result = m3_FindFunction(&f, runtime, "main");
    if (result)
        FATAL("m3_FindFunction: %s", result);

    // Array Parameter

    // Prepare an array in host memory
    // uint8_t arr[] = {10, 20, 30, 40, 50};
    // uint8_t arrayLength = sizeof(arr) / sizeof(arr[0]);
    // size_t bytesNeeded = sizeof(arr);

    // Allocate memory in WebAssembly module for the array
    // uint8_t *wasmMemory = m3_GetMemory(runtime, NULL, 0); // m3_env.c
    // if (!wasmMemory)
    // {
    //     FATAL("Failed to get WebAssembly memory.");
    // }
    // else
    // {
    //     FATAL("Total allocated WebAssembly memory: %u bytes\n", *wasmMemory);
    // }

    // Check if the memory size is sufficient  uint32_t m3_GetMemorySize
    // if (m3_GetMemorySize(runtime) < bytesNeeded)
    // {
    //     FATAL("Insufficient WebAssembly memory allocated.");
    // }

    // int32_t baseAddr = (int32_t)(wasmMemory); // Cast to appropriate type if necessary

    // Copy the array from C to WebAssembly memory
    // memcpy(wasmMemory, arr, bytesNeeded);

    // Try to track the wasm memory and manually add array but not work

    printf("Running...\n");

    absolute_time_t start = get_absolute_time(); // start time count

    // Call the function
    // if (baseAddr + (arrayLength * sizeof(uint8_t)) > m3_GetMemorySize(runtime))
    // {
    //     FATAL("Array parameters out of WebAssembly memory bounds");
    // }
    // result = m3_CallV(f, baseAddr, 0, arrayLength - 1); // m3_CallV(f,1,2) 1 2 stands for the parameters

    // agruments for crc16

    result = m3_CallV(f);
    if (result)
        FATAL("m3_Call: %s", result);

    // Copy back the reversed array from WebAssembly memory
    // memcpy(arr, wasmMemory, bytesNeeded);

    absolute_time_t end = get_absolute_time(); // end time count

    long value = *(uint64_t *)(runtime->stack);
    // printf("Result: %ld\n", value); // result(return value of the function)
    //  printf("CRC16 Checksum: %04X\n", value);

    // printf("Reversed Array: ");
    // for (int i = 0; i < arrayLength; ++i)
    // {
    //     printf("%d ", arr[i]);
    // }

    printf("Elapsed: %lld us\n", absolute_time_diff_us(start, end)); // measure execution time

    // Cleanup
    m3_FreeRuntime(runtime);
    m3_FreeEnvironment(env);
}

int main(void)
{
    stdio_init_all(); // Initializes all the standard input/output interfaces

    printf("\nWasm3 v" M3_VERSION " on Raspberry Pi Pico, build " __DATE__ " " __TIME__ "\n");

    sleep_ms(5000);
    run_wasm();

    sleep_ms(5000); // Adjust the sleep time as needed or implement a different loop condition
}
