#pragma once

#include <ostream>

class Tetel;

class Szamla {
public:
    void addTetel(Tetel* t) 
    {
        if (db == meret) {
            Tetel** uj = new Tetel*[meret+=2];
            for (int i = 0; i < db; i++)
                uj[i] = tetelek[i];
            delete[] tetelek;
            tetelek = uj;
        }
        tetelek[db++] = t;
    }
    int vegosszeg() const;
    friend std::ostream& operator<<(std::ostream& out, const Szamla& sz);

private:
    Tetel** tetelek = nullptr;
    int db=0, meret=0;
};