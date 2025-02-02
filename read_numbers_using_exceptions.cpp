//
// Created by Chris Jenkins on 02/02/2025.
//

#include "read_numbers_using_exceptions.hpp"

#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>

[[nodiscard]]
double get_number(std::istream & input_stream) {
    double number{};

    input_stream >> number;

    if (input_stream) {
        return number;
    } else {
        throw std::exception{};
    }
}

//void test_code() {
//    double value{};
//
//    std::stringstream some_input{"1"};
//    const bool ok = get_number(some_input, value);
//    assert(ok);
//    assert(value == 1);
//
//    double unused{};
//    std::stringstream bad_input{"q"};
//    const bool not_ok = get_number(bad_input, unused);
//    assert(!not_ok);
//}

void read_numbers_with_exceptions_main() {
//    test_code();

    std::cout << "Please enter a number." << std::endl << "> ";
    const double number = get_number(std::cin);
    std::cout << "Got " << number << ", thanks!" << std::endl;
}