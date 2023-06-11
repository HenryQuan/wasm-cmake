cmake_minimum_required(VERSION 3.16)
project(wasm_cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "EMSDK: $ENV{EMSDK}")

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(wasm_cmake_lib STATIC ${SOURCES})
target_compile_options(wasm_cmake_lib PRIVATE -O2)
target_compile_options(wasm_cmake_lib PRIVATE -Wall -Wextra -pedantic)
target_include_directories(wasm_cmake_lib PUBLIC include)
target_include_directories(wasm_cmake_lib PUBLIC $ENV{EMSDK}/upstream/emscripten/system/include)

add_executable(${PROJECT_NAME} exe/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE wasm_cmake_lib)

# export export/calc_engine.cpp to wasm
add_library(calc_engine export/calc_engine.cpp)
target_link_libraries(calc_engine PRIVATE wasm_cmake_lib)
# after build output to js with em++
add_custom_command(TARGET calc_engine POST_BUILD
    COMMAND em++ $<TARGET_FILE:calc_engine> -o ${CMAKE_BINARY_DIR}/calc_engine.html
    COMMENT "convert calc_engine.a to calc_engine.html"
)
