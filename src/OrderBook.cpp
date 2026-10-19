#include "OrderBook.hpp"

void OrderBook::addOrder(const Order &order)
{
    if (order.side == Side::Buy)
    {
        auto [it, _] = bids_.try_emplace(
            order.price,
            PriceLevel{order.price});

        it->second.addOrder(order);
    }
    else
    {
        auto [it, _] = asks_.try_emplace(
            order.price,
            PriceLevel{order.price});

        it->second.addOrder(order);
    }
}

std::optional<Price> OrderBook::bestBid() const
{
    if (bids_.empty())
    {
        return std::nullopt;
    }
    return bids_.begin()->first;
}

std::optional<Price> OrderBook::bestAsk() const
{
    if (asks_.empty())
    {
        return std::nullopt;
    }
    return asks_.begin()->first;
}