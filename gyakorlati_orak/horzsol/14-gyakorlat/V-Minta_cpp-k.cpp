.cpp/1
/*********************/
#include "Decl.hpp"

int main()
{
  BaseClass* bc = new DerivedClass;
  bc->print();
  delete bc;
  return 0;
}
/*********************/
.cpp/2/1
A feladat 1. része az alábbi Clonable interfészt implementáló 2 származtatott osztály elkészítése.

class Clonable {
public:
    virtual ~Clonable() = default;
    virtual Clonable* clone() const = 0;
};

A 2 származtatott osztály a ClonableString és a ClonableNumber, előbbi egy std::string-et tároljon,
 utóbbi egy double-t.
Ezeket az adatokat a konstruktornak lehessen megadni, és a getString() ill. getNumber() metódusokkal
 lehessen lekérdezni.
A clone() metódus dinamikusan hozzon létre egy másolatot az objektumból, és adja vissza a másolat címét.
 A visszatérési érték típusa minden osztályban az adott osztályra mutató pointer legyen!

#include "Decl.hpp"

int main()
{
 const ClonableString str1("text");
 string testStr = str1.getString();
 cout << "str1 = " << testStr << endl;
 ClonableString* str2 = str1.clone();
 cout << "str2 = " << str2->getString() << endl;

 const ClonableNumber num1(3.14);
 double testNum = num1.getNumber();
 cout << "num1 = " << testNum << endl;
 ClonableNumber* num2 = num1.clone();
 cout << "num2 = " << num2->getNumber() << endl;

 delete str2;
 delete num2;
 return 0;
}
/******/
A feladat 2. része egy CloneContainer osztály elkészítése.
 Ez tetszőleges, előre nem ismert számú, Clonable interfészt megvalósító objektumot tudjon tárolni.
 Legyen egy push_back() metódusa, ami a paraméterként kapott Clonable objektumot leklónozza,
 és a clone() által visszaadott címet tárolja el.
 A tároláshoz használható STL tároló vagy saját implementáció is
 (további szükséges #include-ok megadhatók a válasz elején).
A destruktor gondoskodjon a klónok destruktálásáról!
Legyen egy [] operátora is, ami adjon vissza egy Clonable referenciát a megadott indexű klónra!
És legyen egy size() metódusa is, ami visszaadja a tárolt objektumok darabszámát!
.cpp/2/2

#include "Decl.hpp"

int main()
{
 const ClonableString str1("szo");
 const ClonableString str2("szoveg");
 const ClonableString str3("word");

 const ClonableNumber num1(4.2);
 const ClonableNumber num2(-6.66);

 CloneContainer clones;
 clones.push_back(str1);
 clones.push_back(num1);
 clones.push_back(str2);
 cout << clones.size() << " clones have been made\n";

 Clonable& i1 = clones[0];
 string testStr = dynamic_cast<ClonableString*>(&i1)->getString();
 cout << "Item 1: " << testStr << endl;

 ClonableNumber* i2 = dynamic_cast<ClonableNumber*>(&clones[1]);
 cout << "Item 2: " << i2->getNumber() << endl;

 ClonableString& i3 = dynamic_cast<ClonableString&>(clones[2]);
 cout << "Item 3: " << i3.getString() << endl;

 clones.push_back(str3);
 clones.push_back(num2);
 cout << clones.size() << " clones have been made\n";

 ClonableString* i4 = dynamic_cast<ClonableString*>(&clones[3]);
 cout << "Item 4: " << i4->getString() << endl;

 ClonableNumber& i5 = dynamic_cast<ClonableNumber&>(clones[4]);
 cout << "Item 5: " << i5.getNumber() << endl;
 return 0;
}
/*********************/
.cpp/3
A feladat az alábbi SoccerPlayer absztrakt osztály 2 leszármazott osztályának elkészítése.
class SoccerPlayer {
    const std::string name;
    short speed;
    short stamina;
  public:
    SoccerPlayer(const std::string& name, short speed, short stamina); //TODO
    virtual ~SoccerPlayer() = default;
    const std::string& getName() const { return name; }
    short getSpeed() const { return speed; }
    short getStamina() const { return stamina; }
    virtual short getOverall() const = 0;
};
A SoccerPlayer konstruktorának hiányzó implementációját is definiálja az osztályon kívül!
A 2 származtatott osztály a FieldPlayer és a Goalkeeper.
Minden SoccerPlayer rendelkezik speed és stamina értékeléssel.
A FieldPlayerek ezen kívül rendelkeznek shooting, passing és tackling képességekkel. //lövés-passz-labda kezelés
A Goalkeeperek pedig reflexes és agility képességekkel. //mozgékonyság
Ezeket a további képességeket ebben a sorrendben kelljen megadni a származtatott osztályok
konstruktorainak, a SoccerPlayer konstruktorában is szereplő paraméterek (name, speed, stamina) után.
A képességek szintjeit 0-100 közötti egész számok tárolják.

A származtatott osztályokban valósítsa meg a getOverall() metódust, ami visszaadja a játékos átlagos
képességét (a képességszintek átlagának alsó egész részét)!
Továbbá készítsen gettert minden tulajdonságnak (getShooting, getPassing, getTackling, illetve
 getReflexes, getAgility)!
Definiáljon egy << operátort is, amivel ki lehet írni egy SoccerPlayer nevét és átlagos képességét
 az std::cout streamre! Formátum: név (átlag).
 
#include "Decl.hpp"

int main()
{
 const FieldPlayer* fp1 = new FieldPlayer("C. Ronaldo", 90, 85, 95, 91, 76);
 const FieldPlayer* fp2 = new FieldPlayer("L. Messi", 88, 93, 75, 88, 96);
 const Goalkeeper* gk = new Goalkeeper("M. Neuer", 89, 87, 94, 95);

 const SoccerPlayer* p1 = fp1;
 const SoccerPlayer* p2 = fp2;
 const SoccerPlayer* p3 = gk;

 cout << p1->getName() << endl;
 cout << p1->getSpeed() << endl;
 cout << p1->getStamina() << endl;
 cout << fp1->getShooting() << endl;
 cout << fp1->getPassing() << endl;
 cout << fp1->getTackling() << endl;
 cout << p1->getOverall() << endl;
 cout << endl;

 cout << fp2->getName() << endl;
 cout << fp2->getSpeed() << endl;
 cout << fp2->getStamina() << endl;
 cout << fp2->getShooting() << endl;
 cout << fp2->getPassing() << endl;
 cout << fp2->getTackling() << endl;
 cout << fp2->getOverall() << endl;
 cout << endl;

 cout << gk->getName() << endl;
 cout << gk->getSpeed() << endl;
 cout << gk->getStamina() << endl;
 cout << gk->getReflexes() << endl;
 cout << gk->getAgility() << endl;
 cout << gk->getOverall() << endl;
 cout << endl;

 cout << *p1 << endl;
 cout << *p2 << endl;
 cout << *p3 << endl;

 delete p1;
 delete fp2;
 delete gk;
 return 0;
}