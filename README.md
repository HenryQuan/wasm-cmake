# WASM CMake
Compile C++ to WASM using CMake. Follow this [guide](https://emscripten.org/docs/getting_started/downloads.html) to setup emscripten. Read more about [WASM](https://developer.mozilla.org/en-US/docs/WebAssembly).

## CMake
Use the following command to generate the build files. `emcmake` will setup environment variables for emscripten.
```terminal
cd build
emcmake cmake ..
```
