// #include <print>
#include <cassert>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>

#include "read_numbers_with_rc.hpp"
#include "read_numbers_using_exceptions.hpp"

int main()
{
    // read_numbers_with_rc_main();
    try {
        read_numbers_with_exceptions_main();
    } catch (const std::exception& e) {
        std::cout << "Something went wrong! Oh no!" << std::endl;
    }
}
