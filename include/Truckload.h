//
// Created by angelos plastropoulos on 03/08/2019.
//

#ifndef TRUCKLOAD_TRUCKLOAD_H
#define TRUCKLOAD_TRUCKLOAD_H
#include <memory>
#include <vector>
#include "Box.h"

using SharedBox = std::shared_ptr<Box>;

class Truckload {
private:
    class Package {
    public:
        SharedBox pBox;             // Pointer to the Box object contained in this Package
        Package* pNext;             // Pointer to the next Package in the list

        explicit Package(SharedBox pb) : pBox{pb}, pNext{nullptr} {}     // Constructor
        ~Package() { delete pNext; }                            // Destructor
    };

    Package* pHead {};
    Package* pTail {};

    static SharedBox nullBox;

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

    SharedBox& operator[](size_t index);
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
