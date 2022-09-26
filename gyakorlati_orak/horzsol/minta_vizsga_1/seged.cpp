#include "decl.hpp"
using namespace std;

tri_race &tri_race::kiir_rajt()
{
    hour = sum / ora;
    sec = (sum % ora) / perc;
    msec = (sum % ora) % perc;
    cout << "Rajt idő: " << hour << ':' << sec << ':' << msec << " [h:m:s]" << endl;
    cout << "Ú: " << swim << endl;
    cout << "B: " << cycle << endl;
    cout << "F: " << run << endl;
    cout << "D: " << depo << endl;
    cout << "T-: " << correction << endl;
    return *this;
}

tri_race &tri_race::kiir_cel()
{
    hour = sum / ora;
    sec = (sum % ora) / perc;
    msec = (sum % ora) % perc;
    cout << "Cél idő: " << hour << ':' << sec << ':' << msec << " [h:m:s]\n"
         << endl;
    return *this;
}

int tri_race::getIj()
{
    return correction; // Idő jóváírás getter
}

// Setters
tri_race &tri_race::setSum(int correction)
{
    sum = swim + cycle + run + depo - correction;
    return *this;
};