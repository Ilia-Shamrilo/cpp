cmake_minimum_required(VERSION 4.0)
project(String)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(String main.cpp
        String.h
        String.cpp)

target_compile_options(String PRIVATE -Wextra -Werror -fsanitize=address)
target_link_options(String PRIVATE -fsanitize=address)