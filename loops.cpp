#include "loops.hpp"

#include <array>
#include <expected>
#include <iostream>

static std::expected<double, std::string> get_number(std::istream & input_stream) {
    double number{};

    input_stream >> number;
    if (input_stream) {
        return number;
    }
    input_stream.clear();
    input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return std::unexpected("That's not a number");
}

void loop_main() {

    std::array<double, 5u> numbers{};

    std::cout << "Please enter some numbers.\n> ";
    size_t count = 0;
    while (count < numbers.size())
    {
        auto number = get_number(std::cin);
        if (number.has_value()) {
            numbers[count] = number.value();
            std::cout << "Got " << number.value() << "\n";
        } else {
            std::cout << number.error() << std::endl;
        }

        ++count;
    }
}
