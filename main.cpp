#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <string_view>
#include "Truckload.h"
#include "Volume.h"
#include "Carton.h"
#include "ToughPack.h"

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
    /*
    Truckload load1;

    const size_t boxCount {12};
    for (size_t i {}; i < boxCount; ++i)
        load1.addBox(randomBox());

    std::cout << "The first list:\n";
    std::cout << load1;

    const std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                                  Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
    const Box theBox {3.0, 1.0, 3.0};

    // find the smallest box
    Volume volume;
    double maxVolume {};
    size_t  maxIndex {};
    size_t i {};
    while (load1[i])
    {
        if (volume(*load1[i]) > maxVolume)
        {
            maxIndex = i;
            maxVolume = volume(*load1[i]);
        }
        ++i;
    }

    std::cout << "\nThe largest box is: ";
    std::cout << *load1[maxIndex] << std::endl;

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
    */

    Box *pBox = nullptr;
    Carton carton {20.0, 30.0, 40.0, "Plastic"};

    pBox = &carton;
    std::cout << "The volume of the carton is " << pBox->volume() << std::endl;

    ToughPack toughPack {20.0, 30.0, 40.0};
    pBox = &toughPack;
    std::cout << "The volume of the toughpack is " << pBox->volume() << std::endl;

    std::vector<std::unique_ptr<Box>> polymorphicBoxes;
    polymorphicBoxes.push_back(std::make_unique<Box>(20,30,40));
    polymorphicBoxes.push_back(std::make_unique<ToughPack>(20,30,40));
    polymorphicBoxes.push_back(std::make_unique<Carton>(20,30,40, "plastic"));

    for (const auto& p : polymorphicBoxes)
        p->showVolume();

    return 0;
}