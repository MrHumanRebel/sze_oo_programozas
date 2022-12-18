#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

#include "megoldas_dani.hpp"

int main()
{
    static_assert(std::is_abstract<EtlapElem>(), "Hiba! EtlapElem osztaly nem absztrakt!");
    EtlapElem *ee1 = new Leves("Magocskas leves", 450);
    EtlapElem *ee2 = new Leves("Frankfurti leves", 800);
    EtlapElem *ee3 = new Foetel("Paprikas csirke", "rizs", 1200);
    EtlapElem *ee4 = new Foetel("Paprikas csirke", "hasabburgonya", 1500);
    ee1->print();
    ee2->print();
    ee3->print();
    ee4->print();

    delete ee1;
    delete ee2;
    delete ee3;
    delete ee4;
    return 0;
}