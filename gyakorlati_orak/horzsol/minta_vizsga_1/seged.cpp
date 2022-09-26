#include "decl.hpp"
using namespace std;

void tri_race::kiir_rajt(int i, int sum, int sw, int cy, int ru, int de, int co)
{
    int h = sum / ora;
    int p = (sum % ora) / perc;
    int mp = (sum % ora) % perc;
    cout << "Rajt idő: " << h << ':' << p << ':' << mp << " [h:m:s]" << endl;
    cout << "Ú: " << sw << endl;
    cout << "B: " << cy << endl;
    cout << "F: " << ru << endl;
    cout << "D: " << de << endl;
    cout << "T-: " << co << endl;
}

void tri_race::kiir_cel(int i, int sum)
{
    int h = sum / ora;
    int p = (sum % ora) / perc;
    int mp = (sum % ora) % perc;
    cout << "Cél idő: " << h << ':' << p << ':' << mp << " [h:m:s]" << endl;
}
