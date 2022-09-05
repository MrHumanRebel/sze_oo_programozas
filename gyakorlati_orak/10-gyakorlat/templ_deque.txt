http://www.cplusplus.com/reference/
Templ/<deque>
/********* Decl.hpp ************/
using namespace std;

deque<int> hpmp(3);
deque<int>::iterator ke; /* un. "bejárók", az elemek címzéséhez */

/* komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény */
bool hasonlit(int i, int j) { return i>j; } 
bool szuro (int i) { return ((i%2)==1 || (i%2)==-1); }
bool szuro2 (int i) { return ((i%2)==0 && i!=0); }

/***************************************************************************************/
#include <iostream>
#include <deque>
#include <algorithm>
#include "Decl.hpp"
 
int main(void)
{
	hpmp[0] = -1;
	hpmp.push_back(6);
	for (int i = 0; i < 10; i++)
	 { cout << hpmp[i] << " "; hpmp.push_back(7 + i);	}
	cout << "\n";
	for (auto it : hpmp) { cout << it << " "; }
	cout << "\n" << hpmp.size() << "\n";
	hpmp.pop_back();
	hpmp.pop_front(); hpmp.push_front(-2);
	cout << "\n" << hpmp.size() << "\n";
	hpmp.resize(19);
	for (auto it : hpmp)
	 { cout << it << " ";	} cout << "\n";
	hpmp.push_back(20);
	for (auto it : hpmp) { cout << it /*&it*/ << " "; } cout << "\n";
	//for(it = --hpmp.end(); it != --hpmp.begin(); it--) { cout << *it << " "; }
	for (deque<int>::reverse_iterator r_it = hpmp.rbegin(); r_it != hpmp.rend(); r_it++)
	 { cout << *r_it << " "; }  cout << "\n";
	sort(hpmp.begin(), hpmp.end(), hasonlit);
	for (auto it : hpmp) { cout << it << " "; }
	sort(hpmp.begin(), hpmp.end()); cout << "\n";
	for (auto it : hpmp) { cout << it << " "; } cout << "\n";
	hpmp.insert(hpmp.begin()+4,42);
	hpmp.insert(hpmp.end(),2,42);
	for (auto it : hpmp) { cout << it << " "; } cout << "\n";
	hpmp.insert(hpmp.begin(), hpmp.begin()+10, hpmp.begin()+16);
	for (auto it : hpmp) { cout << it << " "; } cout << "\n";
	hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)), hpmp.end());
	for (auto it : hpmp) { cout << it << " "; } cout << "\n";
	ke = find(hpmp.begin(), hpmp.end(), 0);
	if (ke != hpmp.end()) cout << /*&*/(*ke) << "\n";
	cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
	cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
	cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
	cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n";
	cout << count(hpmp.begin(), hpmp.end(), 0) << "\n";
	cout << count_if(hpmp.begin(), hpmp.end(), szuro2) << "\n";
	hpmp.clear();
	cout << "\n" << hpmp.size() << "\n";
	if (hpmp.empty()) cout << "Üres a kétvégű sor!\n";
	return 0;
}
/***************************************************************************************/
