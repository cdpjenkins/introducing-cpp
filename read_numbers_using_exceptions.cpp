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
        if (number > 0) {
            return number;
        } else {
            throw std::invalid_argument("Please provide a non-negative number");
        }
    } else {
        throw std::exception{};
    }
}

void read_numbers_with_exceptions_main() {
    try {
        std::cout << "Please enter a number." << std::endl << "> ";
        const double number = get_number(std::cin);
        std::cout << "Got " << number << ", thanks!" << std::endl;
    } catch (const std::invalid_argument & e) {
        std::cout << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Something went wrong! Oh no!" << std::endl;
    }
}
