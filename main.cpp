#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string_view>
#include "Truckload.h"

long random(size_t count);
using namespace std::rel_ops;

inline SharedBox randomBox()
{
    const size_t dimLimit {99};
    return std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit));
}

long random(const size_t count)
{
    return 1 + static_cast<unsigned>(std::rand()/(RAND_MAX / count + 1));
}

void show(const Box& box1, std::string_view relationship, const Box& box2)
{
    std::cout << box1 << relationship << box2 << std::endl;
}

SharedBox findLargestBox(const Truckload& truckload)
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

    Truckload load1;

    const size_t boxCount {12};
    for (size_t i {}; i < boxCount; ++i)
        load1.addBox(randomBox());

    std::cout << "The first list:\n";
    std::cout << load1;

    // copy
    Truckload copy {load1};
    std::cout << "The copied truckload:\n";
    copy.listBoxes();

    const std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                                  Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
    const Box theBox {3.0, 1.0, 3.0};

    for (const auto& box : boxes)
        if (theBox > box) show(theBox, " is greater than ", box);

    std::cout << std::endl;

    std::cout << boxes[0] << std::endl;

    Box sum{0, 0,0};
    for (const auto& box : boxes)
        sum += box;

    std::cout << "The sum of " << boxes.size() << " random Boxes is " << sum << std::endl;

    Box oneBox {3.0, 1.0, 3.0};
    std::cout << std::endl << "Our test Box is " << oneBox << std::endl;
    std::cout << "Postfix increment evaluates to the original object: "
              << oneBox++ << std::endl;
    std::cout << "After postfix increment: " << oneBox << std::endl;
    std::cout << "Prefix decrement evaluates to the decremented object: " << --oneBox << std::endl;
    std::cout << "After prefix decrement: " << oneBox << std::endl;

    return 0;
}