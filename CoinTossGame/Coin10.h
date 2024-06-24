#ifndef Coin10_h
#define Coin10_h
#include "Coin.h"
#include <cstdlib>

class Coin10 : public Coin
{
private:
    const double value;

public:
    Coin10();
    virtual bool toss() const override;
    virtual double getValue() const override;
   
};

#endif