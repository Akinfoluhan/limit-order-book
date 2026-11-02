#include <algorithm>

#include "OrderBook.hpp"

std::vector<Trade> OrderBook::addOrder(const Order &order)
{
    std::vector<Trade> trades;

    Order incoming = order;

    if (incoming.side == Side::Buy)
    {
        while (incoming.quantity > 0 && !asks_.empty())
        {
            auto bestAskIt = asks_.begin();

            if (incoming.price < bestAskIt->first)
            {
                break;
            }

            PriceLevel &level = bestAskIt->second;

            while (incoming.quantity > 0 && !level.orders.empty())
            {
                Order &resting = level.orders.front();

                Quantity tradeQuantity =
                    std::min(incoming.quantity, resting.quantity);

                trades.push_back({incoming.id,
                                  resting.id,
                                  resting.price,
                                  tradeQuantity});

                incoming.quantity -= tradeQuantity;
                resting.quantity -= tradeQuantity;
                level.totalQuantity -= tradeQuantity;

                if (resting.quantity == 0)
                {
                    level.orders.pop_front();
                }
            }

            if (level.orders.empty())
            {
                asks_.erase(bestAskIt);
            }
        }

        if (incoming.quantity > 0)
        {
            auto [it, inserted] = bids_.try_emplace(
                incoming.price,
                PriceLevel{incoming.price});

            it->second.addOrder(incoming);
        }
    }
    else
    {
        while (incoming.quantity > 0 && !bids_.empty())
        {
            auto bestBidIt = bids_.begin();

            if (incoming.price > bestBidIt->first)
            {
                break;
            }

            PriceLevel &level = bestBidIt->second;

            while (incoming.quantity > 0 && !level.orders.empty())
            {
                Order &resting = level.orders.front();

                Quantity tradeQuantity =
                    std::min(incoming.quantity, resting.quantity);

                trades.push_back({resting.id,
                                  incoming.id,
                                  resting.price,
                                  tradeQuantity});

                incoming.quantity -= tradeQuantity;
                resting.quantity -= tradeQuantity;
                level.totalQuantity -= tradeQuantity;

                if (resting.quantity == 0)
                {
                    level.orders.pop_front();
                }
            }

            if (level.orders.empty())
            {
                bids_.erase(bestBidIt);
            }
        }

        if (incoming.quantity > 0)
        {
            auto [it, inserted] = asks_.try_emplace(
                incoming.price,
                PriceLevel{incoming.price});

            it->second.addOrder(incoming);
        }
    }
    return trades;
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