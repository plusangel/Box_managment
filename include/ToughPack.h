//
// Created by angelos on 15/10/2019.
//

#ifndef TRUCKLOAD_TOUGHPACK_H
#define TRUCKLOAD_TOUGHPACK_H

#include "Box.h"

class ToughPack : public Box
{
public:
    // Constructor
    ToughPack(double lv, double wv, double hv) : Box {lv, wv, hv}
    { }

    ~ToughPack() = default;

protected:
    double volume() const override
    {
        return 0.5 * length * width * height;
    }
};
#endif //TRUCKLOAD_TOUGHPACK_H
