//
// Created by angelos on 30/10/2019.
//

#ifndef TRUCKLOAD_BOXTROUBLE_H
#define TRUCKLOAD_BOXTROUBLE_H

#include <exception>

class BoxTrouble : public std::exception
{
public:
    BoxTrouble(std::string_view errorMessage = "There is a problem") : message {errorMessage} {}
    virtual const char* what() const noexcept override
    { return message.c_str(); }

private:
    std::string message;
};

#endif //TRUCKLOAD_BOXTROUBLE_H
