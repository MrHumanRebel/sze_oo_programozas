#include <iostream>
#include <vector>
#include "megoldas_dani.hpp"

/*
Készítsen el 3 C++ osztályt az alábbiak szerint:

- Oktato egy absztrakt osztály, amely:

a.) tartalmaz egy lastName és firstName stringet, protected láthatósággal

b.) tartalmaz egy konstruktort, amely beállítja a vezetéknevet és keresztnevet

c.) egy virtuális print metódust ami nincs kifejtve

d.) egy virtuális destruktort, melynek törzse üres

- A Professzor és Tanarseged osztályok publikusan származnak az Oktato osztályból, megfelelő konstruktorral inicializálják a vezeték- és keresztnevet a szülő konstruktorán keresztül, és a megfelelő módon felüldefiniálják a print() metódust.

A megvalósítás olyan legyen, hogy a megadott példa szerinti kimenetet kapjuk.
*/

/*Result:
Professzor: Nagy, Agnes
Tanarseged: Kis, Bela
*/

int main()
{
    std::vector<Oktato *> oktatok;
    static_assert(std::is_abstract<Oktato>(), "Hiba! Oktato osztaly nem absztrakt!");
    Oktato *tanar1 = new Professzor("Nagy", "Agnes");
    Oktato *tanar2 = new Tanarseged("Kis", "Bela");
    oktatok.push_back(tanar1);
    oktatok.push_back(tanar2);

    for (Oktato *op : oktatok)
    {
        op->print();
    }

    delete tanar1;
    delete tanar2;
    return 0;
}
