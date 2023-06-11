#include <emscripten.h>
#include <emscripten/bind.h>
#include <wasm_cmake/core.h>

using namespace emscripten;

// extern "C" {
// EMSCRIPTEN_KEEPALIVE
// wasm_cmake::CalcEngine *createCalcEngine() {
//     return new wasm_cmake::CalcEngine();
// }

// EMSCRIPTEN_KEEPALIVE
// void destroyCalcEngine(wasm_cmake::CalcEngine *calc) { delete calc; }

// EMSCRIPTEN_KEEPALIVE
// int calc_add(wasm_cmake::CalcEngine *calc, int a, int b) { return calc->add(a, b); }

// EMSCRIPTEN_KEEPALIVE
// int calc_sub(wasm_cmake::CalcEngine *calc, int a, int b) { return calc->sub(a, b); }

// EMSCRIPTEN_KEEPALIVE
// int calc_mul(wasm_cmake::CalcEngine *calc, int a, int b) { return calc->mul(a, b); }

// EMSCRIPTEN_KEEPALIVE
// int calc_div(wasm_cmake::CalcEngine *calc, int a, int b) { return calc->div(a, b); }
// } // extern "C"

EMSCRIPTEN_KEEPALIVE
EMSCRIPTEN_BINDINGS(my_module) {
    class_<wasm_cmake::CalcEngine>("CalcEngine")
        .constructor<>()
        .function("add", &wasm_cmake::CalcEngine::add)
        .function("sub", &wasm_cmake::CalcEngine::sub)
        .function("mul", &wasm_cmake::CalcEngine::mul)
        .function("div", &wasm_cmake::CalcEngine::div);
}