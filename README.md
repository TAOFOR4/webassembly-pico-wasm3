# webassembly-pico
This is a experiment for trying webassembly on raspberry pico.


## Build for Raspberry Pi Pico


### C
- Download [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) and install its dependencies
- `export PICO_SDK_PATH=/path/to/sdk`
- `cd resource/webassembly-c`
- `./build.sh` Generate .wasm, .wat, .h files
- `cd ../../raspi_pico`
- `mkdir build && cd build && cmake .. && make`
- Copy `build/main.uf2` to your Pico USB Mass Storage Device
- Output is sent to USB serial, connect a terminal to observe



## Performance Analysis

### Memory measurement

Measure the size of .uf2 file 

PS: The size of the UF2 file generally reflects the size of the binary that it contains, along with some additional metadata used by the UF2 bootloader. 

```
cd build
ls -ls main.uf2
```

### Execution Time

```
absolute_time_t start = get_absolute_time(); // start time count

// run your wasm program

absolute_time_t end = get_absolute_time(); // end time count
```


### Analyze WASM File

1. Get all the sections from .wasm file
```
wasm-objdump -x filename.wasm
```


2. [WebAssembly text format](https://developer.mozilla.org/en-US/docs/WebAssembly/Understanding_the_text_format)

```
wat2wasm export.wat -o export.wasm
```