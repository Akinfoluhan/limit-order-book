#pragma once
#include <functional>
#include <map>
#include <optional>
#include <vector>

#include "Order.hpp"
#include "PriceLevel.hpp"
#include "Trade.hpp"

class OrderBook
{
public:
    std::vector<Trade> addOrder(const Order &order);

    std::optional<Price> bestBid() const;
    std::optional<Price> bestAsk() const;

private:
    std::map<Price, PriceLevel, std::greater<Price>> bids_;
    std::map<Price, PriceLevel> asks_;
};