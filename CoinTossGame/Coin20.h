#ifndef Coin20_h
#define Coin20_h

#include "Coin.h"
class Coin20 : public Coin
{
private:
    const double value;

public:
    Coin20();
    virtual bool toss() const override;
    virtual double getValue() const override;
    
};

#endif