http://www.cplusplus.com/reference/
Templ/<list>
using namespace std;

list<int> hpmp(3);
list<int>::iterator ke; /* un. "bejárók", az elemek címzéséhez */

/* komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény */
bool hasonlit(int i, int j) { return i>j; } 
bool szuro (int i) { return ((i%2)==1 || (i%2)==-1); }
bool szuro2 (int i) { return ((i%2)==0 && i!=0); }

/***************************************************************************************/
#include <iostream>
#include <list>
#include <algorithm>
#include "Decl.hpp"
 
int main(void)
 {
  int i=0;
  auto it = hpmp.begin(); //Típus felismerés a fordítóra bízva!
  //hpmp[0]=-1;
  hpmp.pop_front(); hpmp.push_front(-1);
  hpmp.push_back(6);
  //for(i=0; i<10; i++) { cout << hpmp[i] << " "; hpmp.push_back(7+i); }
  for(it = hpmp.begin(); i<10; it++, i++)
   { cout << *it << " "; hpmp.push_back(7+i); } cout << "\n";
  //for(i=0; i<hpmp.size(); i++) { cout << hpmp[i] << " "; }
  for(it = hpmp.begin(), i=0; i<hpmp.size(); it++, i++)
   { cout << *it << " "; }
  cout << "\n" << hpmp.size() << "\n";
  hpmp.pop_back();
  cout << "\n" << hpmp.size() << "\n";
  hpmp.resize(19);
  //for(i=0; i<hpmp.size(); i++) { cout << hpmp[i] << " "; }
  for(it = hpmp.begin(), i=0; i<hpmp.size(); it++, i++)
   { cout << *it << " "; } cout << "\n";
  hpmp.push_back(20); 
  for(it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it /*&(*it)*/ << " "; } cout << "\n";
  for(it = --hpmp.end(); it != --hpmp.begin(); it--)
   { cout << *it << " "; }
  //sort(hpmp.begin(), hpmp.end(), greater<int>()); cout << "\n";
  //sort(hpmp.begin(), hpmp.end(), hasonlit); cout << "\n";
  hpmp.sort(hasonlit); cout << "\n";
  for(it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it << " "; }
  hpmp.sort(); cout << "\n";
  for(it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it << " "; } cout << "\n";
  //hpmp.insert(hpmp.begin()+4,42);
  it = hpmp.begin(); for(i=0;i<4;it++,i++);
  hpmp.insert(it,42);
  hpmp.insert(hpmp.end(),2,42);
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) //it túlterhelés!!!
   { cout << *it << " "; } cout << "\n";
  //hpmp.insert(hpmp.begin(),hpmp.begin()+9,hpmp.begin()+15);
  for(i=0;i<5;it++,i++);
  auto it2 = hpmp.begin(); for(i=0;i<16;it2++,i++);
  hpmp.insert(hpmp.begin(),it,it2);
  for(it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it << " "; } cout << "\n";
  //remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
  //remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
  //hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)),hpmp.end());
  for(it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it << " "; } cout << "\n";
   // Tartományalapú for ciklus:
   //for(auto/*&*/ it : hpmp)  { cout << it << " "; } cout << "\n";
   //for(auto/*&*/ it : hpmp)  { cout << ++it << " "; } cout << "\n";
   //for(auto/*&*/ it : hpmp)  { cout << it << " "; } cout << "\n";
  ke=find(hpmp.begin(), hpmp.end(), 42);
  if(ke!=hpmp.end()) cout << /*&*/(*ke) << "\n";
  cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n";
  cout << count(hpmp.begin(), hpmp.end(),0) << "\n";
  cout << count_if(hpmp.begin(), hpmp.end(),szuro2) << "\n";
  hpmp.clear();
  cout << "\n" << hpmp.size() << "\n";
  if(hpmp.empty()) cout << "Üres a lista!\n";
  return 0;
}
/***************************************************************************************/
