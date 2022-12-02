#pragma once

#include <string>

struct Drink
{
    std::string name;
    int price;

    bool operator<(const Drink &rhs) const
    {
        return name < rhs.name;
        // Ha meg akarjuk k�l�nb�ztetni az azonos nev�eket
        if (name != rhs.name)
            return name < rhs.name;
        else
            return price < rhs.price;
    }
};
