#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Truckload_nested.h"

long random(const size_t i);

inline SharedBox randomBox()
{
    const size_t dimLimit {99};
    return std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit));
}

long random(const size_t count)
{
    return 1 + static_cast<unsigned>(std::rand()/(RAND_MAX / count + 1));
}

SharedBox findLargestBox(const Truckload_nested& truckload)
{
    auto iterator = truckload.getIterator();
    SharedBox largestBox { iterator.getFirstBox() };

    SharedBox nextBox { iterator.getNextBox() };

    while (nextBox)
    {
        if (nextBox->compare(*largestBox) > 0)
            largestBox = nextBox;
        nextBox = iterator.getNextBox();
    }

    return largestBox;
}

int main() {

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Truckload_nested load1;

    const size_t boxCount {12};
    for (size_t i {}; i < boxCount; ++i)
        load1.addBox(randomBox());

    std::cout << "The first list:\n";
    load1.listBoxes();

    // copy
    Truckload_nested copy {load1};
    std::cout << "The copied truckload:\n";
    copy.listBoxes();

    // find the largest box in the list
    std::cout << "\nThe largest box in the first list is ";
    findLargestBox(load1)->listBox();
    std::cout << std::endl;

    /*
    load1.removeBox(largestBox);
    std::cout << "\nAfter deleting the largest box, the list contains:\n";
    load1.listBoxes();

    const size_t nBoxes {20};
    std::vector<SharedBox> boxes;

    for (size_t i {}; i < nBoxes ; ++i)
        boxes.push_back(randomBox());

    Truckload_nested load2 {boxes};
    std::cout << "The second list:\n";
    load2.listBoxes();

    auto smallestBox = load2.getFirstBox();
    for (auto nextBox = load2.getNextBox(); nextBox; nextBox = load2.getNextBox())
        if (nextBox->compare(*smallestBox) < 0)
            smallestBox = nextBox;

    std::cout << "\nThe smallest box in the second list is ";
    smallestBox->listBox();
    std::cout << std::endl;
    */
    return 0;
}