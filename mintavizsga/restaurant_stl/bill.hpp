#pragma once

#include <list>
#include <vector>
#include <algorithm>

#include "item.hpp"

bool predicate(Tetel *t1, Tetel *t2)
{
    return t1->ar() < t2->ar();
}

bool predicate2(Tetel *t1, Tetel *t2)
{
    return t1->ar() > t2->ar();
}

class Szamla
{
public:
    void addTetel(Tetel *t)
    {
        tetelek.push_back(t);
    }
    ~Szamla()
    {
        /*for (size_t i = 0; i < tetelek.size(); ++i) {
            delete tetelek[i];
        }*/
        for (const auto &t : tetelek)
        {
            delete t;
        }
    }
    int vegosszeg() const
    {
        int ossz = 0;
        for (const auto &t : tetelek)
        {
            ossz += t->ar();
        }
        return ossz;
    }
    friend std::ostream &operator<<(std::ostream &out, const Szamla &sz)
    {
        for (const auto &t : sz.tetelek)
        {
            out << t->toString() << '\n';
        }
        out << "----------------------------\n";
        return out << "OSSZEG:\t\t\t" << sz.vegosszeg() << '\n';
    }
    void cancel()
    {
        // delete tetelek[tetelek.size() - 1];
        delete tetelek.back();
        tetelek.pop_back();
    }
    void sortByPrice(bool asc = true)
    {
        if (asc)
            std::sort(tetelek.begin(), tetelek.end(), predicate);
        else
            std::sort(tetelek.begin(), tetelek.end(), predicate2);
        /*
        for (size_t i = 0; i + 1 < tetelek.size(); i++) {
            size_t minIdx = i;
            for (size_t j = i + 1; j < tetelek.size(); ++j) {
                if (asc) {
                    if (tetelek[j]->ar() < tetelek[minIdx]->ar()) {
                        minIdx = j;
                    }
                } else {
                    if (tetelek[j]->ar() > tetelek[minIdx]->ar()) {
                        minIdx = j;
                    }
                }
            }
            Tetel* seged = tetelek[minIdx];
            tetelek[minIdx] = tetelek[i];
            tetelek[i] = seged;
        }*/
    }

private:
    std::vector<Tetel *> tetelek;
    // std::list<Tetel*> tetelek;
};