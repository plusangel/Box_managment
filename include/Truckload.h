//
// Created by angelos plastropoulos on 03/08/2019.
//

#ifndef TRUCKLOAD_TRUCKLOAD_H
#define TRUCKLOAD_TRUCKLOAD_H
#include "Box.h"
#include <memory>
#include <vector>

using SharedBox = std::shared_ptr<Box>;

class Truckload {
private:
  class Package {
  public:
    SharedBox pBox; // Pointer to the Box object contained in this Package
    Package *pNext; // Pointer to the next Package in the list

    explicit Package(SharedBox pb) : pBox{pb}, pNext{nullptr} {} // Constructor
    ~Package() { delete pNext; }                                 // Destructor
  };

  Package *pHead{};
  Package *pTail{};

  //static SharedBox nullBox;

public:
  class Iterator {
  private:
    Package *pHead;
    Package *pCurrent;

    friend class Truckload;
    explicit Iterator(Package *head) : pHead{head}, pCurrent{nullptr} {}

  public:
    SharedBox getFirstBox();
    SharedBox getNextBox();
  };

  [[nodiscard]] Iterator getIterator() const { return Iterator{pHead}; }

  // default constructor
  Truckload() = default;

  // custom constructors
  explicit Truckload(const std::vector<SharedBox> &boxes);
  explicit Truckload(SharedBox pBox) { pHead = pTail = new Package{pBox}; }

  // copy constructor
  Truckload(const Truckload &src);

  // move constructor
  Truckload(Truckload&& moved) noexcept ;

  ~Truckload() { delete pHead; }

  SharedBox &operator[](size_t index);

  void addBox(SharedBox pBox);
  bool removeBox(SharedBox box);
  size_t count() const;
};

inline std::ostream &operator<<(std::ostream &stream, const Truckload &load) {
  size_t count{};
  auto iterator = load.getIterator();

  for (auto box = iterator.getFirstBox(); box; box = iterator.getNextBox()) {
    std::cout << *box;
    if (!(++count % 5))
      std::cout << std::endl;
  }
  if (count % 5)
    std::cout << std::endl;
  return stream;
}

#endif // TRUCKLOAD_TRUCKLOAD_H
