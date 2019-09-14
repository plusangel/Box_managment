//
// Created by angelos plastropoulos on 03/08/2019.
//

#ifndef TRUCKLOAD_TRUCKLOAD_H
#define TRUCKLOAD_TRUCKLOAD_H

#include "Package.h"

class Truckload {
private:
    Package* pHead {};
    Package* pTail {};
    Package* pCurrent {};

public:
    Truckload() = default;

    Truckload(SharedBox pBox)
    { pHead = pTail = new Package {pBox};}

    Truckload(const std::vector<SharedBox>& boxes);

    Truckload(const Truckload& src);

    ~Truckload() { delete pHead; }

    SharedBox getFirstBox();
    SharedBox getNextBox();
    void addBox(SharedBox pBox);
    bool removeBox(SharedBox box);
    void listBoxes() const;
};

#endif //TRUCKLOAD_TRUCKLOAD_H
