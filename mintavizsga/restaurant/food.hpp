#pragma once

#include "item.hpp"

class Etel : public Tetel
{
public:
    Etel(const std::string &nev, int ar, bool kisAdag = false)
        : Tetel(nev), alapar(ar), kisAdag(kisAdag) {}
    std::string megnevezes() const override
    {
        return Tetel::megnevezes() + (kisAdag ? " (kicsi)" : "");
    }
    int ar() const override
    {
        return int(kisAdag ? alapar * 0.75 : alapar);
    }

private:
    int alapar;
    bool kisAdag;
};