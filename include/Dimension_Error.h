//
// Created by angelos on 30/10/2019.
//

#ifndef TRUCKLOAD_DIMENSION_ERROR_H
#define TRUCKLOAD_DIMENSION_ERROR_H
#include <stdexcept>
#include <string>

class dimension_error : public std::out_of_range
{
private:
    double value;
public:
    explicit dimension_error(double dim)
    : std::out_of_range{"Zero or negative dimension: " + std::to_string(dim)}, value{dim} {}

    double getValue() const noexcept { return value; }
};

#endif //TRUCKLOAD_DIMENSION_ERROR_H
