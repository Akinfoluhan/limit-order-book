# C++ Limit Order Book & Backtesting Engine

An in-progress C++20 project focused on building a limit order book, matching engine, and eventually a backtesting engine for trading strategies.

## Current Features

- Buy and sell limit orders
- Separate bid and ask price levels
- Best bid and best ask lookup
- Price-time priority
- FIFO ordering within each price level
- Partial order fills
- Matching across multiple price levels
- Trade generation

## Project Structure

```text
include/
├── Order.hpp
├── OrderBook.hpp
├── PriceLevel.hpp
└── Trade.hpp

src/
├── main.cpp
└── OrderBook.cpp
```

## Build

Compile with C++20:

```bash
g++ -std=c++20 -Iinclude src/main.cpp src/OrderBook.cpp -o orderbook
```

Run:

```bash
./orderbook
```

## Design

The order book currently uses:

- `std::map` to maintain sorted bid and ask price levels
- `std::list` to maintain FIFO order priority within each price level
- Integer-based prices to avoid floating-point precision issues

## Roadmap

Planned additions include:

- Order cancellation and modification
- Fast order lookup by order ID
- Unit testing
- CMake build configuration
- Performance benchmarking and optimization
- Historical market-data replay
- Strategy execution
- Portfolio and P&L tracking
- Transaction costs and slippage
- Backtesting performance metrics

## Status

This project is actively under development.
