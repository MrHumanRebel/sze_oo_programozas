#pragma once

#include <string>

class Tetel
{
public:
    Tetel(const std::string &nev)
        : nev(nev)
    {
    }
    virtual ~Tetel() {}
    virtual int ar() const = 0;
    virtual std::string megnevezes() const { return nev; }
    std::string toString() const
    {
        return megnevezes() + "\t" + std::to_string(ar());
    }

private:
    std::string nev;
};