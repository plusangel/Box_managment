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

SharedBox Truckload::Iterator::getFirstBox()
{
    pCurrent = pHead;
    return pCurrent? pCurrent->getBox() : nullptr;
}

SharedBox Truckload::Iterator::getNextBox()
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

SharedBox Truckload::operator[](size_t index) const
{
    size_t count {};
    for (Package* package {pHead}; package; package = package->getNext())
    {
        if (index == count++)
            return package->getBox();
    }
    return nullptr;
}


