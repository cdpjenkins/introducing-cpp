// #include <print>
#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>

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
    VECTORS
};

int main()
{
    auto example_to_run = ExampleToRun::VECTORS;

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
    }
}
