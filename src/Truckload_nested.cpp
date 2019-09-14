//
// Created by angelos on 05/09/2019.
//

//
// Created by angelos on 03/08/2019.
//

#include "Truckload_nested.h"

Truckload_nested::Truckload_nested(const std::vector<SharedBox>& boxes)
{
    for (const auto& item : boxes)
    {
        addBox(item);
    }
}

Truckload_nested::Truckload_nested(const Truckload_nested& src)
{
    std::cout << "The copy constructor in action" << std::endl;
    for (Package* a_package{src.pHead}; a_package; a_package = a_package->pNext)
    {
        addBox(a_package->pBox);
    }
}

void Truckload_nested::listBoxes() const
{
    const size_t boxesPerLine = 5;
    size_t count {};

    /*
    Package* currentPackage {pHead};

    while (currentPackage)
    {
        currentPackage->getBox()->listBox();
        if (!(++count % boxesPerLine)) std::cout << std::endl;
        currentPackage = currentPackage->getNext();
    }*/

    for (Package* a_package{pHead}; a_package; a_package = a_package->pNext)
    {
        a_package->pBox->listBox();
        if (!(++count % boxesPerLine))
            std::cout << std::endl;
    }
    if (count % boxesPerLine) std::cout << std::endl;
}

void Truckload_nested::addBox(SharedBox pBox)
{
    auto pPackage = new Package{pBox};

    if (pTail)
        pTail->pNext = pPackage;
    else
        pHead = pPackage;

    pTail = pPackage;

}

bool Truckload_nested::removeBox(SharedBox boxToRemove)
{
    Package* previous {nullptr};
    Package* current {pHead};

    while (current)
    {
        if (current->pBox == boxToRemove)
        {
            if (previous)
            {
                previous->pNext = current->pNext;
            } else {
                pHead = current->pNext;
            }
            current->pNext = nullptr;
            delete current;

            return true;
        }
        previous = current;
        current = current->pNext;
    }
    return false;
}

SharedBox Truckload_nested::Iterator::getFirstBox() {
    pCurrent = pHead;
    return pCurrent? pCurrent->pBox : nullptr;
}

SharedBox Truckload_nested::Iterator::getNextBox()
{
    if (!pCurrent)
        return getFirstBox();

    pCurrent = pCurrent->pNext;
    return pCurrent? pCurrent->pBox : nullptr;
}
