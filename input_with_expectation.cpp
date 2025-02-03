#include "input_with_expectation.hpp"

#include <expected>
#include <iostream>
#include <string>

static std::expected<double, std::string> get_number(std::istream& input_stream)
{
    double number{};

    input_stream >> number;
    if (input_stream) {
        return number;
    } else {
        return std::unexpected("That's not a number!");
    }
}

void input_with_expectation_main() {
    std::cout << "Please enter a number." << std::endl << "> ";
    auto number = get_number(std::cin);
    if (number) {
        std::cout << "Got " << number.value() << std::endl;
    } else {
        std::cout << number.error() << std::endl;
    }
}
