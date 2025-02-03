cmake_minimum_required(VERSION 3.29)
project(introducing_cpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(introducing_cpp main.cpp
        read_numbers_with_rc.cpp
        read_numbers_using_exceptions.cpp
        input_with_expectation.cpp)
