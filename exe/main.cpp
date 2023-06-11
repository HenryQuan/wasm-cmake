#include <iostream>
#include <wasm_cmake/core.h>

int main() {
    std::cout << "Hello World" << std::endl;
    auto engine = wasm_cmake::CalcEngine();
    std::cout << "1 + 2 = " << engine.add(1, 2) << std::endl;
    std::cout << "1 - 2 = " << engine.sub(1, 2) << std::endl;
    std::cout << "1 * 2 = " << engine.mul(1, 2) << std::endl;
    std::cout << "1 / 2 = " << engine.div(1, 2) << std::endl;
    return 0;
}
