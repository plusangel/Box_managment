//
// Created by angelos on 05/09/2019.
//

#ifndef TRUCKLOAD_TRUCKLOAD_NESTED_H
#define TRUCKLOAD_TRUCKLOAD_NESTED_H

#include "Box.h"
#include <vector>
#include <memory>

using SharedBox = std::shared_ptr<Box>;

class Truckload_nested {
private:
    class Package {
    public:
        SharedBox pBox;             // Pointer to the Box object contained in this Package
        Package* pNext;             // Pointer to the next Package in the list

        explicit Package(SharedBox pb) : pBox{pb}, pNext{nullptr} {}     // Constructor
        ~Package() { delete pNext; }                            // Destructor
    };

    Package* pHead {};                               // First in the list
    Package* pTail {};                               // Last in the list

public:

    class Iterator
    {
    private:
        Package* pHead;
        Package* pCurrent;

        friend class Truckload_nested; // Only Truckload can create an iterator
        explicit Iterator(Package* head) : pHead{head}, pCurrent{nullptr} {}
    public:
        SharedBox getFirstBox();
        SharedBox getNextBox();
    };

    Iterator getIterator() const { return Iterator{pHead}; }

    Truckload_nested() = default;

    explicit Truckload_nested(SharedBox pBox)
    { pHead = pTail = new Package {pBox};}

    explicit Truckload_nested(const std::vector<SharedBox>& boxes);

    Truckload_nested(const Truckload_nested& src);

    ~Truckload_nested() { delete pHead; }

    void addBox(SharedBox pBox);
    bool removeBox(SharedBox box);
    void listBoxes() const;
};

#endif //TRUCKLOAD_TRUCKLOAD_NESTED_H
