#include <iostream>

#include "bill.hpp"

#include "food.hpp"
#include "drink.hpp"

using namespace std;

int main()
{
    Szamla sz;
    sz.addTetel(new Etel("Sajtos tojasrantotta", 500));
    sz.addTetel(new Ital("Narancsle", 200, 2));
    sz.addTetel(new Etel("Ham & eggs", 800, true));
    cout << sz;
}