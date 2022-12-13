#include <iostream>
#include <vector>
#include "megoldas_dani.hpp"

/*
Készítsen el 4 C++ osztályt az alábbiak szerint:

- Termek osztály az alábbiakat tartalmazza

a.) konstruktort, mellyel beállítjuk a termék alap-mértékegységét (pl. "kg" vagy "l"), mennyiségét és fajlagos árát (ár per mértékegység)

b.) double-t visszaadó getTotal() metódust, amely visszaadja a termék árát (fajlagos ár szorozva mennyiség)

- Kosar osztály az alábbiakat tartalmazza:

a.) Eltarol egy vectort Termek pointerekkel

b.) add() metodust, mellyel ujabb termekek adhatok a kosarhoz

c.) total() metodust, amely kiirja a teljes arat (összes termék árának összegét)

d.) Ne felejtkezzen el a destruktorról sem, a memóriaszivárgás elkerülése érdekében

- Egy további Tej és Barack osztályt, amelyek megvalósítása alapján a megadott kimenetet kell, hogy adja a program.
*/
/*
Result:
Kosar erteke: 9360 + 2400 = 11760
*/

int main()
{
    Kosar s;
    s.add(new Barack(5.2, 1800, "kg")); // 5.2kg barack, 480 Ft / kg
    s.add(new Tej(3.0, 2.8, 800, "l")); // 3 liter 2.8 szazalekos, 800 Ft / liter
    s.total();

    return 0;
}