#pragma once

#include <iostream>
#include <string>

#include "date.hpp"

struct Vaccination
{
    std::string type;
    Date date;

    Vaccination(std::string type = "", Date date = Date(1970, 1, 1))
        : type(type), date(date)
    {
        date = date;
        this->date = date;
    }

    ~Vaccination()
    {
        std::cerr << "Vaccination destructed: " << type << " "
                  << date.toString() << std::endl;
    }
};