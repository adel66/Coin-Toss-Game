#include "Coin20.h"
#include <iostream>
using namespace std;

Coin20::Coin20() : Coin(), value(20) {}

bool Coin20::toss() const
{
    bool t;
    t = rand() % 2;
    return t;
}

double Coin20::getValue() const
{
    return value;
}

