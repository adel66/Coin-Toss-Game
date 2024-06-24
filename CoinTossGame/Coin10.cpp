#include "Coin10.h"
#include <iostream>
using namespace std;

Coin10::Coin10() : Coin(), value(10) {}

bool Coin10::toss() const
{
    bool t;
    t = rand() % 2;
    return t;
}

double Coin10::getValue() const
{
    return value;
}

