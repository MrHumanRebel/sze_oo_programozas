/* A kulcs-érték  adatpárok  egyedi kulcs  szerinti,  rendezett  tárolása a pair (temp_class)
 struktúrasablonnal (<utility>).
A konténerek képviselik az adatszerkezeteket.
 A bennük tárolt adatokat általános algoritmusokkal dolgozhatjuk fel,
 iterátorok közvetítésével. 
A map elemei egy önkiegyensúlyozó  bináris  keresőfa adatstruktúrában
 helyezkednek el. */
Templ/<map>/1
/********* Decl.hpp ************/
using namespace std;

//typedef pair<string, int> sps;
map<string, int> hpmp;


/***************************************************************************************/
#include <iostream>
#include <map>
#include <algorithm>
#include "Decl.hpp"
 
int main(void)
{
	hpmp["F: "] = 2300;
	for (auto it : hpmp)
	{ cout << it.first << it.second << "\n"; }
	hpmp = { {"Ú: ",1200}, {"B: ",4200} }; // Felüldefiniálás!
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size();
	hpmp.clear();
	cout << "\n" << hpmp.size() << "\n\n";
	hpmp = { {"F: ",0}, {"Ú: ",1200}, {"B: ",4200} };
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size() << "\n\n";
	hpmp["D: "] = 123; // Beszúrás!
	hpmp["D: "] = 123; // Nem lehet ismétlődés!
	hpmp["F: "] = 2300;   // Felülírás!
	//auto it = hpmp.begin();
	hpmp.insert(/*it,*/pair<string, int>("Ú+B+D: ", 1200 + 4200 + 123));
	//hpmp.insert(make_pair("Ú+B+D: ",1200+4200+123));
	//hpmp.insert(sps("Ú+B+D: ",1200+4200+123));
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	cout << "\n" << hpmp.size() << "\n\n";
	for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
	 { cout << r_it->first << r_it->second << "\n";	} cout << "\n";
	hpmp.erase(hpmp.find("D: "));
	for (auto it : hpmp)
	 {	cout << it.first << it.second << "\n"; }
	if (hpmp.count("F: ")) cout << "\nLétezik az elem!";
	else cout << "\nNem létezik az elem!";
	hpmp.clear();
	if (hpmp.empty()) cout << "\nÜres a szótár!\n";
	return 0;
}
/***************************************************************************************/
Templ/<map>/2
/********* Decl.hpp ************/
using namespace std;

typedef pair<string, int> sps;
map<int, sps> hpmp;

/***************************************************************************************/
#include <iostream>
#include <map>
#include <algorithm>
#include "Decl.hpp"

int main(void)
{
    hpmp[5] = { "F: ", 2300 };
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    hpmp = { { 1, {"Ú: ",1200} }, { 2, {"B: ",4200} } }; // Felüldefiniálás!
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    cout << "\n" << hpmp.size();
    hpmp.clear();
    cout << "\n" << hpmp.size() << "\n\n";
    hpmp = { { 1, {"Ú: ",1200} }, { 2, {"B: ",4200} },\
             { 5, {"F: ",0} } };
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    cout << "\n" << hpmp.size() << "\n\n";
    hpmp[3] = { "D: ", 123 }; // Beszúrás!
    hpmp[5] = { "F: ", 2300 };   // Felülírás!
    hpmp.insert(make_pair(4, sps("Ú+B+D: ", 1200 + 4200 + 123)));// Dupla pair!!!
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    cout << "\n" << hpmp.size() << "\n\n";
    for (auto r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
     { cout << r_it->second.first << r_it->second.second << "\n"; }
    cout << "\n";
    hpmp.erase(hpmp.find(3));
    for (auto it : hpmp)
     { cout << it.second.first << it.second.second << "\n"; }
    if (hpmp.count(5)) cout << "\nLétezik az elem!";
    else cout << "Nem létezik az elem!";
    hpmp.clear();
    if (hpmp.empty()) cout << "\nÜres a szótár!\n";
    return 0;
}
/***************************************************************************************/
