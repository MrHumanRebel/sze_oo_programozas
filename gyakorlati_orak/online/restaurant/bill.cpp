#include "bill.hpp"

#include "item.hpp"

std::ostream& operator<<(std::ostream& out, const Szamla& sz)
{
    for (int i = 0; i < sz.db; ++i) {
        out << sz.tetelek[i]->toString() << '\n';
    }
    out << "----------------------------\n";
    return out << "OSSZEG:\t\t\t" << sz.vegosszeg() << '\n';
}

int Szamla::vegosszeg() const
{
    int osszeg = 0;
    for (int i = 0; i < db; ++i)
        osszeg += tetelek[i]->ar();
    return osszeg;
}
