// #include <print>

#include <algorithm>
#include <iostream>
#include <istream>

#include "analysis.hpp"
#include "input.hpp"
#include "input_with_expectation.hpp"
#include "read_numbers_with_rc.hpp"
#include "read_numbers_using_exceptions.hpp"
#include "loops.hpp"
#include "vector_input.hpp"

enum class ExampleToRun {
    READ_NUMBERS_WITH_RC,
    READ_NUMBERS_WITH_EXCEPTION,
    READ_NUMBERS_WITH_EXPECTATION,
    LOOPS,
    VECTORS,
    GET_PRICES
};

static std::vector<double> get_prices(std::istream & input_stream) {
    std::cout << "Please enter some numbers." << std::endl << "> ";

    std::vector<double> numbers{};
    auto number = stock_prices::get_number(input_stream);
    while (number.has_value()) {
        numbers.push_back(number.value());
        std::cout << "> ";
        number = stock_prices::get_number(input_stream);
    }

    return numbers;
}

int main()
{
    auto example_to_run = ExampleToRun::GET_PRICES;

    switch (example_to_run) {
        case ExampleToRun::READ_NUMBERS_WITH_RC:
            read_numbers_with_rc_main();
            break;
        case ExampleToRun::READ_NUMBERS_WITH_EXCEPTION:
            read_numbers_with_exceptions_main();
            break;
        case ExampleToRun::READ_NUMBERS_WITH_EXPECTATION:
            input_with_expectation_main();
            break;
        case ExampleToRun::LOOPS:
            loop_main();
        break;
        case ExampleToRun::VECTORS:
            vector_input_main();
            break;
        case ExampleToRun::GET_PRICES:
            auto prices = get_prices(std::cin);

            if (!prices.empty()) {
                auto result = std::ranges::minmax(prices);
                std::cout << "min: " << result.min << std::endl;
                std::cout << "max: " << result.max << std::endl;
            }

            std::ranges::sort(prices, std::ranges::greater{});

            for (auto price : prices) {
                std::cout << price << " ";
            }
            std::cout << std::endl;

            auto invalid = std::ranges::count_if(prices, stock_prices::negative);
            std::cout << invalid << " prices below zero" << std::endl;

            auto erased = std::erase_if(prices, stock_prices::negative);
            std::cout << "erased " << erased << " prices"  << std::endl;

            std::cout << "Average is " << stock_prices::average(prices) << std::endl;

            std::cout << "Sorted:" << std::endl;
            std::ranges::sort(prices, std::ranges::greater{});
            for (auto price : prices) {
                std::cout << price << " ";
            }
            std::cout << std::endl;

            break;
    }
}
