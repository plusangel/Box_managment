//
// Created by angelos on 03/08/2019.
//

#include "Truckload.h"

Truckload::Truckload(const std::vector<SharedBox> &boxes) {
  for (const auto &item : boxes) {
    addBox(item);
  }
}

Truckload::Truckload(const Truckload &src) {
  std::cout << "Copy constructor invoked" << std::endl;
  for (Package *a_package{src.pHead}; a_package; a_package = a_package->pNext) {
    addBox(a_package->pBox);
  }
}

Truckload::Truckload(Truckload &&moved) noexcept
    : pHead{moved.pHead}, pTail{moved.pTail} {
  std::cout << "Move constructor invoked" << std::endl;
  moved.pHead = nullptr;
  moved.pTail = nullptr;
}

SharedBox Truckload::Iterator::getFirstBox() {
  pCurrent = pHead;
  return pCurrent ? pCurrent->pBox : nullptr;
}

SharedBox Truckload::Iterator::getNextBox() {
  if (!pCurrent)
    return getFirstBox();

  pCurrent = pCurrent->pNext;
  return pCurrent ? pCurrent->pBox : nullptr;
}

void Truckload::addBox(SharedBox pBox) {
  auto pPackage = new Package{pBox};

  if (pTail)
    pTail->pNext = pPackage;
  else
    pHead = pPackage;

  pTail = pPackage;
}

bool Truckload::removeBox(SharedBox boxToRemove) {
  Package *previous{nullptr};
  Package *current{pHead};

  while (current) {
    if (current->pBox == boxToRemove) {
      if (previous) {
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

SharedBox &Truckload::operator[](size_t index) {
  size_t count{};
  for (Package *package{pHead}; package; package = package->pNext) {
    if (index == count++)
      return package->pBox;
  }
  throw std::out_of_range{"Index too large " + std::to_string(index)};
}

size_t Truckload::count() const {
  size_t count{};
  if (pHead == nullptr)
    return 0;
  for (Package *package{pHead}; package; package = package->pNext)
    count++;
  return count;
}
