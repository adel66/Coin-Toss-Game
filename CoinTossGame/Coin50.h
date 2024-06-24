#ifndef Coin50_h
#define Coin50_h

#include "Coin.h"
class Coin50 : public Coin
{
private:
    const double value;

public:
    Coin50();
    virtual bool toss() const override;
    virtual double getValue() const override;
};

#endif