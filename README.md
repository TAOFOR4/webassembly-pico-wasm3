# webassembly-pico-wasm3
This is a experiment for trying webassembly on raspberry pico using wasm3.


## Build for Raspberry Pi Pico

### Install wasm3, wasi-sdk, raspberry pi pico sdk
- Clone `wasm3` from [here](https://github.com/wasm3/wasm3/tree/main). Set `WAMR_PATH` to this path in your user profile.
- Install `wasi-sdk` as mentioned [here](https://github.com/WebAssembly/wasi-sdk).
- Set WASI_SDK_PATH `export WASI_SDK_PATH=/opt/wasi-sdk/wasi-sdk-20.0`
- Download [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk) and install its dependencies
- `export PICO_SDK_PATH=/path/to/sdk`

### C
- `cd resource/webassembly-c`
- `./build.sh` Generate .wasm, .wat, .h files

### Rust
- `cd resource/webassembly-rs`
- `./build.sh` Generate .wasm, .wat, .h files

### Build and flash project
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

In /raspi_pico/main.c, there are some code for execution time measurement.
```
absolute_time_t start = get_absolute_time(); // start time count

// run your wasm program

absolute_time_t end = get_absolute_time(); // end time count
```

Then, monitor the output from pico.
```
screen /dev/ttyACM0 115200
```

### Power Consumption
Still ongoing. refer to [here](https://community.element14.com/challenges-projects/element14-presents/workbenchwednesdays/w/documents/27761/measuring-the-pi-pico-w-s-power-consumption---workbench-wednesdays-60). Will use Power Profilier Kit II (NRF-PPK2)

### Analyze WASM File

1. Get all the sections from .wasm file
```
wasm-objdump -x filename.wasm
```


2. [WebAssembly text format](https://developer.mozilla.org/en-US/docs/WebAssembly/Understanding_the_text_format)

```
wat2wasm export.wat -o export.wasm
```


