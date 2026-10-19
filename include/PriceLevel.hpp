#pragma once
#include <list>
#include "Order.hpp"

struct PriceLevel
{
    Price price;
    std::list<Order> orders;
    Quantity totalQuantity = 0;

    void addOrder(const Order &order)
    {
        orders.push_back(order);
        totalQuantity += order.quantity;
    }
};