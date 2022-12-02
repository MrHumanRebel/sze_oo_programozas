#pragma once

#include "item.hpp"

class Ital : public Tetel
{
public:
    Ital(const std::string &nev, int egysegar, int mennyiseg)
        : Tetel(nev), ftPerDl(egysegar), dl(mennyiseg)
    {
    }
    std::string megnevezes() const override
    {
        return Tetel::megnevezes() + " (" + std::to_string(dl) + " dl)";
    }
    int ar() const override { return dl * ftPerDl; }

private:
    int ftPerDl;
    int dl;
};
