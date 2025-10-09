cmake_minimum_required(VERSION 4.0)
project(Rational)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Rational main.cpp
        Rational.h
        Rational.cpp
        Rational.h)

target_compile_options(Rational PRIVATE -Wextra -Werror -fsanitize=address)
target_link_options(Rational PRIVATE -fsanitize=address)