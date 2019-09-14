//
// Created by angelos plastropoulos on 03/08/2019.
//

#ifndef TRUCKLOAD_PACKAGE_H
#define TRUCKLOAD_PACKAGE_H
#include <memory>
#include <vector>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Package
{
private:
    Package* pNext;     // Pointer to the next Package in the list
    SharedBox pBox;     // Pointer to the Box object contained in this Package

public:
    Package(SharedBox pb) : pBox {pb}, pNext {nullptr}
    {}
    ~Package() { delete pNext; }

    SharedBox getBox() const { return pBox; }
    Package* getNext() { return pNext; }
    void setNext(Package* pPackage) { pNext = pPackage; }
};

#endif //TRUCKLOAD_PACKAGE_H
