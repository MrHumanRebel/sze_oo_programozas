#include <iostream>
#include <vector>
#include "megoldas_dani.hpp"

/*
Készítsen el 4 C++ osztályt az alábbiak szerint:

- Termek osztály az alábbiakat tartalmazza

a.) konstruktort, mellyel beállítjuk a termék alap-mértékegységét (pl. "kg" vagy "l"), mennyiségét és fajlagos árát (ár per mértékegység)

b.) double-t visszaadó getTotal() metódust, amely visszaadja a termék árát (fajlagos ár szorozva mennyiség). Ez a metódus legyen virtuális, hogy a TrappistaSajt osztály felül tudja definiálni!

c.) egy üres, virtuális destruktort

d.) egy setAr() metodust, amivel ki lehet nullázni az árát egy terméknek, mintha kivettük volna a kosárból

- Kosar osztály az alábbiakat tartalmazza:

a.) Eltarol egy vectort Termek pointerekkel

b.) add() metodust, mellyel ujabb termekek adhatok a kosarhoz

c.) total() metodust, amely kiirja a teljes arat (összes termék árának összegét)

d.) Ne felejtkezzen el a destruktorról sem, a memóriaszivárgás elkerülése érdekében

e.) Egy remove() metodust, amely egy stringet vár és kitörli a megfelelő típusú terméket, setAr(0) meghívásával

- Egy további Tej és Barack és TrappistaSajt osztályt, amelyek megvalósítása alapján a megadott kimenetet kell, hogy adja a program.

- A TrappistaSajt osztály getTotal() metódusa a kedvezményt is beszámítja a részösszeg számításánál
*/
/*
Result:
Kosar erteke: 9360 + 2400 + 0 = 11760
*/

int main()
{
    Kosar s;
    s.add(new Barack(5.2, 1800, "kg"));             // 5.2kg barack, 480 Ft / kg
    s.add(new Tej(3.0, 2.8, 800, "l"));             // 3 liter 2.8 szazalekos, 800 Ft / liter
    s.add(new TrappistaSajt(0.5, 2205, "kg", 0.2)); // 0.5kg, 2205 Ft / kg, de 20%-os kedvezmeny jon ra
    s.remove("TrappistaSajt");
    s.total();

    return 0;
}