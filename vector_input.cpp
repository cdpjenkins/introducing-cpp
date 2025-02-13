#include "vector_input.hpp"

#include <iostream>
#include <ostream>
#include <vector>
#include <__algorithm/ranges_count.h>
#include <__expected/expected.h>

void vector_experiment() {
    std::vector numbers{1,2};
    numbers.push_back(-123);
    auto iterator = numbers.begin();
    numbers.insert(++iterator, 1000);
    numbers.insert(iterator + 2, -4000);
    numbers.insert(numbers.end(), 3000);

    numbers[0] = 999;
    // numbers.at(10) = 1010; // blows up with std::out_of_range: vector

    for (const auto & number : numbers) {
        std::cout << number << std::endl;
    }
}

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


void vector_input_main() {

    vector_experiment();

    std::cout << "Please enter some numbers.\n> ";
    std::vector<double> numbers;

    auto number = get_number(std::cin);
    while (number.has_value())
    {
        numbers.push_back(number.value());
        std::cout << "Got " << number.value() << "\n";
        std::cout << "Capacity is " << numbers.capacity() << std::endl;

        number = get_number(std::cin);
    }

    std::cout << "Look out, here are the numbers that you just entered:" << std::endl;
    for (const auto & number : numbers) {
        std::cout << number << std::endl;
    }

    numbers.erase(numbers.begin());
    std::cout << "we just erased the first element, let's see what we have left: " << std::endl;
    std::cout << "[";
    for (const auto & number : numbers) {
        std::cout << number << ", ";
    }
    std::cout << "]" << std::endl;

}