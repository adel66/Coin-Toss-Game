#ifndef Coin_h
#define Coin_h
#include <iostream>
#include <cstdlib>
#include <ctime>

class Coin
{
public:
    Coin() = default;
    virtual ~Coin() = default;
    virtual bool toss() const = 0; // head -> 1 or tails-> 0
    virtual double getValue() const = 0;
};

#endif