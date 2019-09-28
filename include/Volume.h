//
// Created by angelos on 28/09/2019.
//

#ifndef TRUCKLOAD_VOLUME_H
#define TRUCKLOAD_VOLUME_H

#include "Box.h"

class Volume {
public:

    double operator()(double x, double y, double z) { return x*y*z;}
    double operator()(const Box& aBox) { return aBox.getWidth()*aBox.getHeight()*aBox.getLength(); }
};
#endif //TRUCKLOAD_VOLUME_H
