#pragma once

namespace wasm_cmake {
class CalcEngine {
public:
    constexpr int add(int a, int b) const { return a + b; }
    constexpr int sub(int a, int b) const { return a - b; }
    constexpr int mul(int a, int b) const { return a * b; }
    constexpr int div(int a, int b) const { return a / b; }
}; // class CalcEngine
} // namespace wasm_cmake
