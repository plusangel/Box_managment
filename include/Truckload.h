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

public:
    class Iterator
    {
    private:
        Package* pHead;
        Package* pCurrent;

        friend class Truckload;
        explicit Iterator(Package* head) : pHead {head}, pCurrent {nullptr} {}
    public:
        SharedBox getFirstBox();
        SharedBox getNextBox();
    };

    Iterator getIterator() const { return Iterator {pHead};}

    Truckload() = default;

    Truckload(SharedBox pBox) { pHead = pTail = new Package {pBox};}

    Truckload(const std::vector<SharedBox>& boxes);

    Truckload(const Truckload& src);

    ~Truckload() { delete pHead; }

    SharedBox operator[](size_t index) const;
    void addBox(SharedBox pBox);
    bool removeBox(SharedBox box);
};


inline std::ostream& operator<<(std::ostream& stream, const Truckload& load)
{
    size_t count {};
    auto iterator = load.getIterator();

    for (auto box = iterator.getFirstBox(); box; box = iterator.getNextBox())
    {
        std::cout << *box;
        if (!(++count % 5)) std::cout << std::endl;
    }
    if (count % 5) std::cout << std::endl;
    return stream;
}

#endif //TRUCKLOAD_TRUCKLOAD_H
