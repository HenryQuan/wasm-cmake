cmake_minimum_required(VERSION 3.16)
project(wasm_cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(wasm_cmake_lib STATIC ${SOURCES})
target_compile_options(wasm_cmake_lib PRIVATE -O2)
target_compile_options(wasm_cmake_lib PRIVATE -Wall -Wextra -pedantic)
target_include_directories(wasm_cmake_lib PUBLIC include)

add_executable(${PROJECT_NAME} exe/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE wasm_cmake_lib)
