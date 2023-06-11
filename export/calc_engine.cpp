#include <emscripten.h>
#include <emscripten/bind.h>
#include <iostream>
#include <map>
#include <vector>
#include <wasm_cmake/core.h>


using namespace emscripten;

extern "C" {
/// NOTE: It seems that as long as one function is exported, everything here
/// will be exported.
EMSCRIPTEN_KEEPALIVE
void emscripten_loader() {}

EMSCRIPTEN_KEEPALIVE
wasm_cmake::CalcEngine *create_calc_engine() {
    return new wasm_cmake::CalcEngine();
}

EMSCRIPTEN_KEEPALIVE
void destroy_calc_engine(wasm_cmake::CalcEngine *calc) { delete calc; }

EMSCRIPTEN_KEEPALIVE
int calc_add(wasm_cmake::CalcEngine *calc, int a, int b) {
    return calc->add(a, b);
}

EMSCRIPTEN_KEEPALIVE
int calc_sub(wasm_cmake::CalcEngine *calc, int a, int b) {
    return calc->sub(a, b);
}

EMSCRIPTEN_KEEPALIVE
int calc_mul(wasm_cmake::CalcEngine *calc, int a, int b) {
    return calc->mul(a, b);
}

EMSCRIPTEN_KEEPALIVE
int calc_div(wasm_cmake::CalcEngine *calc, int a, int b) {
    return calc->div(a, b);
}

EMSCRIPTEN_KEEPALIVE
void all_type(int a, float b, double c, bool d, char e) {
    std::cout << "int: " << a << std::endl;
    std::cout << "float: " << b << std::endl;
    std::cout << "double: " << c << std::endl;
    std::cout << "bool: " << d << std::endl;
    std::cout << "char: " << e << std::endl;
}

EMSCRIPTEN_KEEPALIVE
void vector_int(int *vec, int size) {
    std::cout << "vector<int>: ";
    for (int i = 0; i < size; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

EMSCRIPTEN_KEEPALIVE
void read_string(emscripten::val str) {
    std::cout << "string: " << str.as<std::string>() << std::endl;
}
} // extern "C"

// EMSCRIPTEN_KEEPALIVE
// EMSCRIPTEN_BINDINGS(my_module) {
//     class_<wasm_cmake::CalcEngine>("CalcEngine")
//         .constructor<>()
//         .function("add", &wasm_cmake::CalcEngine::add)
//         .function("sub", &wasm_cmake::CalcEngine::sub)
//         .function("mul", &wasm_cmake::CalcEngine::mul)
//         .function("div", &wasm_cmake::CalcEngine::div);
// }