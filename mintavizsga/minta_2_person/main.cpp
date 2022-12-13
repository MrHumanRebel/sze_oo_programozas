#include <iostream>
#include <vector>
#include "megoldas_dani.hpp"
/*
Készítsen el 2 C++ osztályt az alábbiak szerint:

- Person osztály az alábbiakat tartalmazza

a.) konstruktort, mellyel beállítjuk Person nevét

b.) notify() metódust, amely argumentumként vár egy string üzenetet, és egy küldő Person címét, majd konzolra kiírja a szükséges információkat: hogy kitől ki kapott üzenetet és mi az üzenet tartalma.

- Mediator osztály az alábbiakat tartalmazza:

a.) egy vectort, amely eltárolja a feliratkozott Person címeket

b.) egy add() metódust, amellyel fel lehet iratni a mediatorra egy adott Person objektumot

c.) egy send() metódust, amelynek át kell adni, hogy ki küld milyen üzenetet. Ez a metódust meghívja az összes, Mediator objektumra feliratkozott Person notify() metódusát, kivéve azét, aki az aktuális üzenetet küldi. Például, láthatjuk a példában, hogy Lári Fanni nem kapja meg a saját maga által küldött üzenetet, noha a kalapjakabFriends Mediator objektumra fel van iratkozva.
*/
/*
Result:
Kalap Jakab megkapta Moka Mester uzenetet: Jottok a humor estemre?
Lari Fanni megkapta Moka Mester uzenetet: Jottok a humor estemre?
Kalap Jakab megkapta Lari Fanni uzenetet: Jaj ne, mar megint ezek a faviccek...
*/

int main()
{
    Mediator mindenki;
    Mediator kalapjakabFriends;

    Person kalapjakab("Kalap Jakab");
    Person larifanni("Lari Fanni");
    Person mokamester("Moka Mester");

    mindenki.add(&kalapjakab);
    mindenki.add(&larifanni);
    mindenki.add(&mokamester);

    kalapjakabFriends.add(&kalapjakab);
    kalapjakabFriends.add(&larifanni);

    mindenki.send(&mokamester, "Jottok a humor estemre?");
    kalapjakabFriends.send(&larifanni, "Jaj ne, mar megint ezek a faviccek...");

    return 0;
}