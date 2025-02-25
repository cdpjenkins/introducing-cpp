// #include <print>

#include <algorithm>
#include <iostream>
#include <istream>
#include <ranges>

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
    GET_PRICES,
    VIEWS_EXPERIMENT
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
    auto example_to_run = ExampleToRun::VIEWS_EXPERIMENT;

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
        case ExampleToRun::VIEWS_EXPERIMENT: {
            const std::vector prices{3.76, 1.5, -1.0, 3.0, 4.0, -2.0, 99.4};
            const double required_price = 4.75;
            auto non_negative = [](double price) { return price >= 0.0; };
            auto too_cheap = [required_price](double x) { return x <= required_price; };

            auto no_good = prices | std::views::filter(non_negative)
                                                 | std::views::take_while(too_cheap);

            std::cout << "Too cheap:" << std::endl;
            for (auto price : no_good) {
                std::cout << price << " ";
            }

            break;
        }
        case ExampleToRun::GET_PRICES:
            auto prices = get_prices(std::cin);

            if (!prices.empty()) {
                auto result = std::ranges::minmax(prices);
                std::cout << "min: " << result.min << std::endl;
                std::cout << "max: " << result.max << std::endl;
            }

            // std::ranges::sort(prices, std::ranges::greater{});

            for (auto price : prices) {
                std::cout << price << " ";
            }
            std::cout << std::endl;

            auto invalid = std::ranges::count_if(prices, stock_prices::negative);
            std::cout << invalid << " prices below zero" << std::endl;

            std::cout << "Average is " << stock_prices::average(prices) << std::endl;

            // std::cout << "Sorted:" << std::endl;
            // std::ranges::sort(prices, std::ranges::greater{});

            // std::cout << "All prices sorted" << std::endl;
            // for (auto price : prices) {
            //     std::cout << price << " ";
            // }
            // std::cout << std::endl;

            auto valid_prices = std::views::filter(prices, [](auto price) { return price >= 0; });

            std::cout << "Valid prices" << std::endl;
            for (auto valid_price : valid_prices) {
                std::cout << valid_price << " ";
            }
            std::cout << std::endl;

            auto valid_prices_as_vector = std::ranges::to<std::vector>(valid_prices);
            const double mean = stock_prices::average(valid_prices_as_vector);
            std::cout << "Mean: " << mean << std::endl;

            double potential_profit = stock_prices::profit_on_first_uptick(valid_prices_as_vector);
            std::cout << "Potential profit: " << potential_profit << std::endl;

            const double required_profit = 1.75;
            bool possible = stock_prices::required_profit_possible(valid_prices_as_vector, required_profit);

            std::cout << "Required profit possible: " << std::boolalpha << possible << std::endl;

            break;
    }
}
