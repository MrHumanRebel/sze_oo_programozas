/* A kulcs-érték  adatpárok  egyedi kulcs  szerinti,  rendezett  tárolása a pair (temp_class)
 struktúrasablonnal (.first and .second).
A konténerek képviselik az adatszerkezeteket.
 A bennük tárolt adatokat általános algoritmusokkal dolgozhatjuk fel,
 iterátorok közvetítésével.
A map elemei egy önkiegyensúlyozó  bináris  keresőfa adatstruktúrában
 helyezkednek el. */
Templ / <map> / 1
/********* Decl.hpp ************/
#include <iostream>
#include <map> // asszociatív tömb
#include <algorithm>

    using namespace std;

typedef pair<string, int> sps;
map<string, int> hpmp;
map<string, int>::iterator ke;

/***************************************************************************************/
#include "Decl.hpp"

int main(void)
{
    hpmp["F: "] = 2300;
    for (auto it : hpmp)
    {
        cout << it.first << it.second << "\n\n";
    }
    hpmp = {{"Ú: ", 1200}, {"B: ", 4200}}; // Felüldefiniálás!
    for (auto it : hpmp)
    {
        cout << it.first << it.second << "\n";
    }
    cout << "\n"
         << hpmp.size();
    hpmp.clear();
    cout << "\n"
         << hpmp.size() << "\n\n";
    hpmp = {{"F: ", 0}, {"Ú: ", 1200}, {"B: ", 4200}};
    for (auto it : hpmp)
    {
        cout << it.first << it.second << "\n";
    }
    cout << "\n"
         << hpmp.size() << "\n\n";
    hpmp["D: "] = 123;  // Beszúrás!
    hpmp["D: "] = 123;  // Nem lehet ismétlődés! => Ez egy felülírás!
    hpmp["F: "] = 2300; // Felülírás!
    auto it = hpmp.begin();
    // hpmp.insert(it,pair<string, int>("Ú+B+D: ", 1200 + 4200 + 123));
    // hpmp.insert(make_pair("Ú+B+D: ",1200+4200+123));
    hpmp.insert(sps("Ú+B+D: ", 1200 + 4200 + 123));
    for (auto it : hpmp)
    {
        cout << it.first << it.second << "\n";
    }
    cout << "\n"
         << hpmp.size() << "\n\n";
    for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
    {
        cout << r_it->first << r_it->second << "\n";
    }
    cout << "\n";
    hpmp.erase(hpmp.find("D: "));
    for (auto it : hpmp)
    {
        cout << it.first << it.second << "\n";
    }
    if (hpmp.count("Ú: "))
    {
        cout << "\nLétezik az elem!\n";
        ke = hpmp.find("Ú: ");
        cout << ke->first << ke->second << "\n";
        ke->second = 1100; // Nem kell felüldefiniálni a teljes pair-t!
        cout << ke->first << ke->second << "\n";
    }
    else
        cout << "\nNem létezik az elem!";
    ke = hpmp.find("B: ");
    cout << ke->first << ke->second << "\n";
    ke = hpmp.find("Ú+B+D: "); // Törölt "D: " esete!
    cout << ke->first << ke->second << "\n";
    ke = hpmp.find("F: ");
    cout << ke->first << ke->second << "\n";
    hpmp.clear();
    if (hpmp.empty())
        cout << "\nÜres a szótár!\n";
    return 0;
}

/***************************************************************************************/
Templ / <map> / 2 dupla pair(temp_class) struktúrasablon
/********* Decl.hpp ************/
#include <iostream>
#include <map>
#include <algorithm>

    using namespace std;

typedef pair<string, int> sps;
map<int, sps> hpmp;

/***************************************************************************************/
#include "Decl.hpp"

int main(void)
{
    hpmp[5] = {"F: ", 2300};
    for (auto it : hpmp)
    {
        cout << it.second.first << it.second.second << "\n\n";
    }                                                // it.first ill. it.second
    hpmp = {{1, {"Ú: ", 1200}}, {2, {"B: ", 4200}}}; // Felüldefiniálás!
    for (auto it : hpmp)
    {
        cout << it.second.first << it.second.second << "\n";
    }
    cout << "\n"
         << hpmp.size();
    hpmp.clear();
    cout << "\n"
         << hpmp.size() << "\n\n";
    hpmp = {{1, {"Ú: ", 1200}}, {2, {"B: ", 4200}}, {5, {"F: ", 0}}};
    for (auto it : hpmp)
    {
        cout << it.second.first << it.second.second << "\n";
    }
    cout << "\n"
         << hpmp.size() << "\n\n";
    hpmp[3] = {"D: ", 123};                                       // Beszúrás!
    hpmp[5] = {"F: ", 2300};                                      // Felülírás!
    hpmp.insert(make_pair(4, sps("Ú+B+D: ", 1200 + 4200 + 123))); // Dupla pair!
    for (auto it : hpmp)
    {
        cout << it.second.first << it.second.second << "\n";
    }
    cout << "\n"
         << hpmp.size() << "\n\n";
    hpmp.find(5)->second.second = 2200; // Nem kell felüldefiniálni a teljes pair-t!
    for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
    {
        cout << r_it->second.first << r_it->second.second << "\n";
    }
    cout << "\n";
    hpmp.erase(hpmp.find(3));
    for (auto it : hpmp)
    {
        cout << it.second.first << it.second.second << "\n";
    }
    if (hpmp.count(5))
        cout << "\nLétezik az elem!";
    else
        cout << "Nem létezik az elem!";
    hpmp.clear();
    if (hpmp.empty())
        cout << "\nÜres a szótár!\n";
    return 0;
}
/***************************************************************************************/
