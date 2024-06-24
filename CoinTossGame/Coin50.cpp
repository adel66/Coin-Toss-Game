#include "Coin50.h"
#include <iostream>
using namespace std;

Coin50::Coin50() : Coin(), value(50) {}

bool Coin50::toss() const
{
    bool t;
    t = rand() % 2;
    return t;
}

double Coin50::getValue() const
{
    return value;
}

