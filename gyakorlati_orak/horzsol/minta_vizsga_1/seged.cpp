#include "decl.hpp"
using namespace std;

tri_race &tri_race::kiir_rajt()
{
    hour = sum / metric_hour;
    minute = (sum % metric_hour) / metric_min;
    sec = (sum % metric_hour) % metric_min;
    cout << "Rajt idő: " << hour << ':' << minute << ':' << sec << " [h:m:s]" << endl;
    cout << "Ú: " << swim << endl;
    cout << "B: " << cycle << endl;
    cout << "F: " << run << endl;
    cout << "D: " << depo << endl;
    cout << "T-: " << correction << endl;
    return *this;
}

tri_race &tri_race::kiir_cel()
{
    hour = sum / metric_hour;
    minute = (sum % metric_hour) / metric_min;
    sec = (sum % metric_hour) % metric_min;
    cout << "Cél idő: " << hour << ':' << minute << ':' << sec << " [h:m:s]\n"
         << endl;
    return *this;
}

int tri_race::getIj() const
{
    return correction; // Idő jóváírás getter
}

// Setters
tri_race &tri_race::setSum(int correction)
{
    sum = swim + cycle + run + depo - correction;
    return *this;
};