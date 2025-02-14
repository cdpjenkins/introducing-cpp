#include "analysis.hpp"

#include <numeric>
#include <vector>

namespace stock_prices {
    double average(const std::vector<double> &prices) {
        return std::accumulate(prices.begin(), prices.end(), 0.0) / prices.size();
    }
}
