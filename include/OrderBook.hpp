#pragma once
#include <functional>
#include <map>
#include <optional>

#include "Order.hpp"
#include "PriceLevel.hpp"

class OrderBook
{
public:
    void addOrder(const Order &order);

    std::optional<Price> bestBid() const;
    std::optional<Price> bestAsk() const;

private:
    std::map<Price, PriceLevel, std::greater<Price>> bids_;
    std::map<Price, PriceLevel> asks_;
};