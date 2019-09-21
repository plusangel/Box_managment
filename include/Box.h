//
// Created by angelos plastropoulos on 03/08/2019.
//

#ifndef TRUCKLOAD_BOX_H
#define TRUCKLOAD_BOX_H

#include <iostream>
#include <iomanip>
#include <algorithm>

class Box {
private:
    double length {1.0};
    double width {1.0};
    double height {1.0};

public:
    Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} { }

    Box() = default;

    double volume() const
    { return length * width * height; }

    int compare(const Box& box) const
    {
        if (volume() < box.volume()) return -1;
        if (volume() == box.volume()) return 0;
        return 1;
    }

    bool operator<(const Box& aBox) const
    { return volume() < aBox.volume(); }

    bool operator==(const Box& aBox) const
    { return volume() == aBox.volume(); }

    Box& operator+=(const Box& aBox);
    Box operator+(const Box& aBox) const;

    bool operator<(double value) const;

    double getLength() const
    { return length; }

    double getWidth() const
    { return width; }

    double getHeight() const
    { return height; }

    void listBox() const
    {
        std::cout << "Box(" << std::setw(2) << length << ','
                            << std::setw(2) << width  << ','
                            << std::setw(2) << height << ") ";
    }
};
/*
inline bool operator<(const Box& box1, const Box& box2)
{ return box1.volume() < box2.volume(); }
*/

/*
// standalone implementation
inline Box Box::operator+(const Box &aBox) const
{
    return Box {std::max(length, aBox.length),
                std::max(width, aBox.width),
                height + aBox.height };
}
 */

inline Box& Box::operator+=(const Box &aBox)
{
    length = std::max(length, aBox.length);
    width  = std::max(width, aBox.width);
    height += aBox.height;
    return *this;
}

inline Box Box::operator+(const Box &aBox) const
{
    Box copy {*this};
    copy += aBox;
    return copy;
}


inline bool Box::operator<(double value) const
{ return volume() < value; }

inline bool operator<(double value, const Box& aBox)
{ return value < aBox.volume(); }

inline std::ostream& operator<<(std::ostream& stream, const Box& box)
{
    stream << "Box(" << std::setw(2) << box.getLength() << ','
           << std::setw(2) << box.getWidth() << ','
           << std::setw(2) << box.getHeight() << ')';
    return stream;
}
#endif //TRUCKLOAD_BOX_H
