#include "analysis.hpp"

#include <numeric>
#include <ranges>
#include <vector>


namespace stock_prices {
    double average(const std::vector<double> &prices) {
        return std::accumulate(prices.begin(), prices.end(), 0.0) / prices.size();
    }

    double profit_on_first_uptick(const std::vector<double> &prices) {
        if (prices.empty()) {
            throw std::invalid_argument("prices is empty");
        }

        const double first = prices.front();
        auto where = std::ranges::find_if(prices,
                                            [first](double price) {
                                                return price > first;
                                            });

        if (where != prices.end()) {
            return *where - first;
        } else {
            return 0.0;
        }
    }

    bool required_profit_possible(const std::vector<double> &prices, double required_profit) {
        const double first = prices.front();

        auto where = std::ranges::find_if(prices,
                                        [first, required_profit](double price) {
                                            return (price - first) >= required_profit;
                                        });
        return where != prices.end();
    }
}
