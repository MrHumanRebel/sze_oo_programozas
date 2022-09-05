op_ovrld/1
/***************/
#include <iostream>
using namespace std;

class tort 
 {
   private:
    int szam, nev;  
   public:
    tort operator*(tort m_t) {
     return tort(szam * m_t.getSzam(), nev * m_t.getNev()); }
    tort operator*(int i) { return tort(szam * i, nev); }
    int getSzam() const { return szam; }
    int getNev() const { return nev; }
    tort(int sz, int nv) { szam=sz; nev=nv; }  
	~tort() { }                        
 };

/*tort operator*(tort e_t, tort m_t) {
    return tort(e_t.getSzam() * m_t.getSzam(),
                e_t.getNev() * m_t.getNev()); }*/

/*tort operator*(tort e_t, int i) {
    return tort(e_t.getSzam() * i,
                e_t.getNev()); }*/

tort operator*(int i, tort m_t) {
    return tort(i * m_t.getSzam(),
                m_t.getNev()); }

ostream& operator<<(ostream& ki, const tort& t) {
  ki << t.getSzam() << "/" << t.getNev();
  return ki;
}

int main(void)
 {
  tort t1(2, 3);
  tort t2(4, 5);
  tort t3 = t1 * t2;
  //tort t3 = t1.operator*(t2);
  cout << "\nAlap tört: " << t3.getSzam() << "/" << t3.getNev() << endl;
  cout << "Túlterhelt tört: " << t3 << "\n" << endl;
  int i = 3 * 4;
  tort t4 = t1 * /*2*/ i;
  cout << "Alap egész: " << i << endl;
  cout << "Túlterhelt tagfgv. egész: " << t4 << "\n" << endl;
  tort t5 = /*2*/ i * t1;
  cout << "Túlterhelt nem tagfgv. egész: " << t5 << "\n" << endl;
  cout << t1 << " - " << t2 << " - " << t3 << " - " << t4 << " - " << t5 << endl;
  return 0;
}
/***************************************************************************************/
op_ovrld/2
/***************/
#include <iostream>
using namespace std;

class tort 
 {
   private:
    int szam, nev;  
   protected:
    int getSzam() const { return szam; }
    int getNev() const { return nev; }
   public:
    tort operator*(tort m_t) {
     return tort(szam * m_t.getSzam(), nev * m_t.getNev()); }
    tort operator*(int i) { return tort(szam * i, nev); }
    tort(int sz, int nv) { szam=sz; nev=nv; } 
	~tort() { }    
   friend tort operator*(int i, tort m_t);
   friend ostream& operator<<(ostream& ki, const tort& t);              
 };

/*tort operator*(tort e_t, tort m_t) {
    return tort(e_t.getSzam() * m_t.getSzam(),
                e_t.getNev() * m_t.getNev()); }*/

/*tort operator*(tort e_t, int i) {
    return tort(e_t.getSzam() * i,
                e_t.getNev()); }*/

tort operator*(int i, tort m_t) {
    return tort(i * m_t.getSzam(),
                m_t.getNev()); }

ostream& operator<<(ostream& ki, const tort& t) {
  ki << t.getSzam() << "/" << t.getNev();
  return ki;
}

int main(void)
 {
  tort t1(2, 3);
  tort t2(4, 5);
  tort t3 = t1 * t2;
  //tort t3 = t1.operator*(t2);
  //cout << "\nAlap tört: " << t3.getSzam() << "/" << t3.getNev() << endl;
  cout << "Túlterhelt tört: " << t3 << "\n" << endl;
  int i = 3 * 4;
  tort t4 = t1 * /*2*/ i;
  cout << "Alap egész: " << i << endl;
  cout << "Túlterhelt tagfgv. egész: " << t4 << "\n" << endl;
  tort t5 = /*2*/ i * t1;
  cout << "Túlterhelt nem tagfgv. egész: " << t5 << "\n" << endl;
  cout << t1 << " - " << t2 << " - " << t3 << " - " << t4 << " - " << t5 << endl;
  return 0;
}
/***************************************************************************************/
op_ovrld/3
/***************/
#include <iostream>
using namespace std;

class tort 
 {
   private:
    int szam, nev;  
   protected:
    int getSzam() const { return szam; }
    int getNev() const { return nev; }
    void setSzam(int szm) { szam=szm; }
    void setNev(int nv) { nev=nv; }
   public:
   tort operator*(tort m_t) {
    return tort(szam * m_t.getSzam(), nev * m_t.getNev());}
   tort operator*(int i) { return tort(szam * i, nev); }
   tort() { }
   tort(int sz, int nv) { szam=sz; nev=nv; } 
   ~tort() { }    
   friend tort operator*(int i, tort m_t);
   friend ostream& operator<<(ostream& ki, const tort& t);
   friend istream& operator>>(istream& be, tort& t); 
 };

tort operator*(int i, tort m_t) {
    return tort(i * m_t.getSzam(), m_t.getNev()); }

ostream& operator<<(ostream& ki, const tort& t) {
  ki << t.getSzam() << "/" << t.getNev();
  return ki;
}

istream& operator>>(istream& be, tort& t) {
  cout << "\nKérem a tört számlálóját: ";
  be >> t.szam;
  cout << "Kérem a tört nevezőjét: ";
  be >> t.nev;
  return be;
}

int main(void)
 {
  tort t1, t2;
  cin >> t1 >> t2;
  tort t3 = t1 * t2;
  cout << "\nTúlterhelt tört: " << t3 << "\n" << endl;
  int i = 3 * 4;
  tort t4 = t1 * i;
  cout << "Alap egész: " << i << endl;
  cout << "Túlterhelt tagfgv. egész: " << t4 << "\n" << endl;
  tort t5 = i * t1;
  cout << "Túlterhelt nem tagfgv. egész: " << t5 << "\n" << endl;
  cout << t1 << " - " << t2 << " - " << t3 << " - " << t4 << " - " << t5 << endl;
  return 0;
}
/***************************************************************************************/
[] - lambda kifejezés
/********* Decl.hpp ************/
using namespace std;

vector<int> hpmp(3);
/* komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény */
 
/********* 1.cpp ************/
#include <iostream>
#include <vector>
#include <algorithm>
#include "Decl.hpp"
 
int main(void)
 {
  hpmp[0]=-1; hpmp.push_back(6);
  for(int i=0; i<10; i++)
   { cout << hpmp[i] << " "; hpmp.push_back(7+i); }
  cout << "\n"; hpmp.pop_back(); hpmp.resize(19); hpmp.push_back(20);
  for(auto it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it << " "; } cout << "\n";
  sort(hpmp.begin(), hpmp.end(),
    [](int i, int j) -> bool { return i>j; });
  for(auto it = hpmp.begin(); it != hpmp.end(); it++)
   { cout << *it << " "; } cout << "\n";
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(),
    [](int i) -> bool { return ((i%2)==1 || (i%2)==-1); })),hpmp.end());
  for(int i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  cout << count_if(hpmp.begin(), hpmp.end(),
   [](int i) -> bool { return ((i%2)==0 && i!=0); }) << "\n";
  int ve = [](int x){ return x*x; }(5);
  cout << ve << endl;
  int v = [](int x){ return x*x; }
  (count_if(hpmp.begin(), hpmp.end(),
   [](int i) -> bool { return ((i%2)==0 && i!=0); }));
  cout << v << endl;
  int j=7, k=10;
  cout << [=](int x){ return x*x+j; }(5) << "\n"
  << j;  /*&,k ++j +k*/
  return 0;
}
/***************************************************************************************/