//
// Created by angelos on 03/08/2019.
//

#include "Truckload.h"

Truckload::Truckload(const std::vector<SharedBox>& boxes)
{
    for (const auto& item : boxes)
    {
        addBox(item);
    }
}

Truckload::Truckload(const Truckload& src)
{
    for (Package* a_package{src.pHead}; a_package; a_package = a_package->getNext())
    {
        addBox(a_package->getBox());
    }
}

void Truckload::listBoxes() const
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

    for (Package* a_package{pHead}; a_package; a_package = a_package->getNext())
    {
        a_package->getBox()->listBox();
        if (!(++count % boxesPerLine))
            std::cout << std::endl;
    }
    if (count % boxesPerLine) std::cout << std::endl;
}

SharedBox Truckload::getFirstBox()
{
    pCurrent = pHead;
    return pCurrent? pCurrent->getBox() : nullptr;
}

SharedBox Truckload::getNextBox()
{
    if (!pCurrent)
        return getFirstBox();

    pCurrent = pCurrent->getNext();
    return pCurrent? pCurrent->getBox() : nullptr;
}

void Truckload::addBox(SharedBox pBox)
{
    auto pPackage = new Package{pBox};

    if (pTail)
        pTail->setNext(pPackage);
    else
        pHead = pPackage;

    pTail = pPackage;

}

bool Truckload::removeBox(SharedBox boxToRemove)
{
    Package* previous {nullptr};
    Package* current {pHead};

    while (current)
    {
        if (current->getBox() == boxToRemove)
        {
            if (previous)
            {
                previous->setNext(current->getNext());
            } else {
                pHead = current->getNext();
            }
            current->setNext(nullptr);
            delete current;

            return true;
        }
        previous = current;
        current = current->getNext();
    }
    return false;
}

