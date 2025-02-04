//
// Created by Chris Jenkins on 02/02/2025.
//

#include "read_numbers_with_rc.hpp"

#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>


[[nodiscard]]
static bool get_number(std::istream & input_stream, double & number) {
    input_stream >> number;

    if (input_stream) {
        return true;
    } else {
        input_stream.clear();
        input_stream.ignore(std::numeric_limits<std::stringstream>::max().get(), '\n');

        return false;
    }
}

void test_code() {
    double value{};

    std::stringstream some_input{"1"};
    const bool ok = get_number(some_input, value);
    assert(ok);
    assert(value == 1);

    double unused{};
    std::stringstream bad_input{"q"};
    const bool not_ok = get_number(bad_input, unused);
    assert(!not_ok);
}

void read_numbers_with_rc_main() {
    test_code();

    double number{};

    std::cout << "Please enter a number." << std::endl << "> ";
    const bool ok = get_number(std::cin, number);
    if (ok) {
        std::cout << "Got " << number << ", thanks!" << std::endl;
    }
}

