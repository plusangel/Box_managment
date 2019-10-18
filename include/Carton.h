//
// Created by angelos on 28/09/2019.
//

#ifndef TRUCKLOAD_CARTON_H
#define TRUCKLOAD_CARTON_H
#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
private:
    std::string material;

public:
    Carton(double lv, double wv, double hv, std::string_view mat)
    : Box{lv, wv, hv}, material{mat}
    {
        //std::cout << "Carton(double,double,double,string_view) called.\n";
    }

    Carton(double side, std::string_view mat) : Box{side}, material{mat}
    {
        //std::cout << "Carton(double,string_view) called.\n";
    }

    explicit Carton(std::string_view mat) : material {mat}
    {
        //std::cout << "Carton(string_view) called.\n";
    }

    Carton(const Carton& carton) : Box{carton}, material{carton.material}
    {
        //std::cout << "Carton copy constructor" << std::endl;
    }

    Carton() = default;
    ~Carton() = default;

    double volume() const override { return 0.75 * length * width * height; }
};

#endif //TRUCKLOAD_CARTON_H
