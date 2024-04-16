#!/bin/bash

echo "Building WASM app..."
$WASI_SDK_PATH/bin/clang -O3 \
    -z stack-size=4096 -Wl,--initial-memory=65536 \
    -o main.wasm main.c \
    -Wl,--export=matrixMultiply \
    -Wl,--strip-all -Wl,--no-entry \
    -Wl,--allow-undefined \
    -nostdlib
#-Wl,--export=matrixMultiply \ export multiple functions

if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi


echo "Generate readable wasm file"
wasm2wat main.wasm -o readable_module.wat

# Check if the wasm2wat conversion was successful
if [ $? -ne 0 ]; then
    echo "Failed to convert WASM to WAT"
    exit 1
fi

echo "Generate main_wasm.h .."
xxd -i main.wasm ../wasm_head_files/main_wasm.h

# Check if the xxd operation was successful
if [ $? -ne 0 ]; then
    echo "Failed to generate C header file"
    exit 1
fi

echo "Done"
