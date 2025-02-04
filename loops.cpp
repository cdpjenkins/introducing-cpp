#include "loops.hpp"

#include <expected>
#include <iostream>

static std::expected<double, std::string> get_number(std::istream & cin) {
    double number{};

    cin >> number;
    if (cin) {
        return number;
    }

    return std::unexpected("That's not a number");
}

void loop_main() {
    std::cout << "Please enter a number.\n> ";
    auto number = get_number(std::cin);

    while (number.has_value()) {
        std::cout << "Got " << number.value() << "\n";

        std::cout << "Please enter another number.\n> ";
        number = get_number(std::cin);
    }

    std::cout << number.error() << std::endl;
}
