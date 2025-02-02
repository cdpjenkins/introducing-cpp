// #include <print>
#include <cassert>
#include <istream>
#include <sstream>

[[nodiscard]]
bool get_number(std::istream & input_stream, double & number) {
    input_stream >> number;

    if (input_stream) {
        return true;
    } else {
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

int main()
{
    test_code();
}
