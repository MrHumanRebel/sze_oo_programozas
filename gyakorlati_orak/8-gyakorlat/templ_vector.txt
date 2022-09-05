http://www.cplusplus.com/reference/
Templ/<vector>/1
/********* Decl.hpp ************/
using namespace std;

vector<int> hpmp(3);
//vector<int>::iterator ke; /* elemek címzése */

/* komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény */
//bool hasonlit(int i, int j) { return i<j; } 
//bool szuro (int i) { return ((i%2)==1); }
//bool szuro2 (int i) { return ((i%2)==0 && i!=0); }

/***************************************************************************************/
#include <iostream>
#include <vector>
//#include <algorithm>
#include "Decl.hpp"
 
int main(void)
 {
  int i;
  hpmp[0]=-1;
  hpmp.push_back(6);
  for(i=0; i<hpmp.size()/*10*/; i++)
   { cout << hpmp[i] << " ";
    /*hpmp.push_back(7+i);*/ } cout << "\n";
/*  for(i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; }
  cout << "\n" << hpmp.size() << "\n";
  hpmp.pop_back();
  cout << "\n" << hpmp.size() << "\n";
  hpmp.resize(19);
  for(i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  hpmp.push_back(20);
  //Típus felismerés a fordítóra bízva! 
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it &(*it) << " "; }  cout << "\n";
  for(auto it = --hpmp.end(); it != --hpmp.begin(); it--) { cout << *it << " "; }
  sort(hpmp.begin(), hpmp.end(), greater<int>()); cout << "\n";
  //sort(hpmp.begin(), hpmp.end(), hasonlit); cout << "\n";
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it << " "; }
  sort(hpmp.begin(), hpmp.end()); cout << "\n";
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it << " "; }
  cout << "\n";*/
  //hpmp.insert(hpmp.begin()/*+4*/,42);
  //hpmp.insert(hpmp.end(),2,42);
  /*hpmp.insert(hpmp.begin(),hpmp.begin()+9,hpmp.begin()+15);
  for(int i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  //remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
  //remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
  //hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)),hpmp.end());  
  for(i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  ke=find(hpmp.begin(), hpmp.end(), 20);
  if(ke!=hpmp.end()) cout << *ke&(*ke) << "\n";
  cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n";
  cout << count(hpmp.begin(), hpmp.end(),0);
  cout << count_if(hpmp.begin(), hpmp.end(),szuro2) << "\n";
  hpmp.clear();
  cout << "\n" << hpmp.size() << "\n";
  if(hpmp.empty()) cout << "Üres a vektor!\n";*/
  return 0;
}
/***************************************************************************************/
Templ/<vector>/2
/********* Decl.hpp ************/
using namespace std;

vector<int> hpmp(3);
vector<int>::iterator ke; /* elemek címzése */

/* komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény */
bool hasonlit(int i, int j) { return i<j; } 
bool szuro (int i) { return ((i%2)==1); }
bool szuro2 (int i) { return ((i%2)==0 && i!=0); }

/***************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include "Decl.hpp"
 
int main(void)
 {
  int i;
  hpmp[0]=-1;
  hpmp.push_back(6);
  for(i=0; i</*hpmp.size()*/10; i++)
   { cout << hpmp[i] << " ";
    hpmp.push_back(7+i); } cout << "\n";
  for(i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; }
  cout << "\n" << hpmp.size() << "\n";
  hpmp.pop_back();
  cout << "\n" << hpmp.size() << "\n";
  hpmp.resize(19);
  for(i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  hpmp.push_back(20);
   //Típus felismerés a fordítóra bízva! 
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it /*&(*it)*/ << " "; } cout << "\n";
  for(auto it = --hpmp.end(); it != --hpmp.begin(); it--) { cout << *it << " "; }
  /*sort(hpmp.begin(), hpmp.end(), greater<int>()); cout << "\n";*/
  sort(hpmp.begin(), hpmp.end(), hasonlit); cout << "\n";
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it << " "; }
  sort(hpmp.begin(), hpmp.end()); cout << "\n";
  for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it << " "; }
  cout << "\n";
  hpmp.insert(hpmp.begin()+4,42);
  hpmp.insert(hpmp.end(),2,42);
  /*hpmp.insert(hpmp.begin(),hpmp.begin()+9,hpmp.begin()+15);*/
  for(int i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  //remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
  //remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
  //hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)),hpmp.end());
  for(int i=0; i<hpmp.size(); i++)
   { cout << hpmp[i] << " "; } cout << "\n";
  ke=find(hpmp.begin(), hpmp.end(), 0);
  if(ke!=hpmp.end()) cout << /*&*/(*ke) << "\n";
  cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n";
  cout << count(hpmp.begin(), hpmp.end(),0) << "\n";
  cout << count_if(hpmp.begin(), hpmp.end(),szuro2) << "\n";
  hpmp.clear();
  cout << "\n" << hpmp.size() << "\n";
  if(hpmp.empty()) cout << "Üres a vektor!\n";
  return 0;
}
/***************************************************************************************/
Tri_vector/1
/********* Decl.hpp ************/
using namespace std;

class tri_race /* szülő osztály deklarációja */
 {
   protected:
    char lic;
    int swim, cycle, run, depo;
   private:
    int sum;
   public:
    tri_race() { lic='-'; swim=0; cycle=0; run=0; depo=0; }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) 
     { lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp;
      cout << "\nA paraméteres objektum létrejött"; } 
   virtual void kiir() =0 ; 
   int getSum() const { return sum; }
	 tri_race& setSum(int ij);
   virtual ~tri_race() { cout << "\nTöröltem a szülő osztályt!"; }
	 tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;
	};

class h_m_s  /* az átszámoló osztály deklarációja */
 {
  protected:
  vector<int> hpmp;
  vector<int> sps;
  vector<string> jelek = {"Ú:","B:","D:","Ú+B+D:","F:","Cél idő:"};
  vector<int>::iterator it;
  vector<string>::iterator j_it;
  const int oRA, pRC;
  h_m_s() : oRA(3600),pRC(60) { }
  void s_hms(int s)
   { hpmp.push_back(s/oRA); hpmp.push_back((s%oRA)/pRC);
     hpmp.push_back((s%oRA)%pRC); }
  ~h_m_s() { cout << "\nTöröltem az átszámoló osztályt!"; }
 };

class in_ch : public tri_race, protected h_m_s /* gyerek osztály */
 {
  protected:
   int kat;
  public:
   in_ch() : tri_race() { kat=0; }
   in_ch(char lc, int sw, int cyc, int rn, int dp, int kt) : \
          tri_race(lc, sw, cyc, rn, dp) { kat=kt; }
   void kiir();
   ~in_ch() { cout << "\nTöröltem a gyerek-objektum saját adatait!"; }
 };
 
 class in_gr_ch : public in_ch  /* unoka osztály */
 {
  private:
   char nem;
  public:
   in_gr_ch() : in_ch(), nem('N') {  }
   in_gr_ch(char lc, int sw, int cyc, int rn, int dp, int kt, char nm)\
             : in_ch(lc, sw, cyc, rn, dp, kt), nem(nm) {  }
   void kiir();
   ~in_gr_ch() { cout << "\nTöröltem az unoka-objektum saját adatait!"; }
 };
/***************************************************************************************/
#include <iostream>
#include <vector>
#include "Decl.hpp"

void in_ch::kiir()
 {
  sps = {swim,cycle,depo,swim+cycle+depo,run,getSum()};
  cout << "\nLicence: " << lic;
  for(it = sps.begin(), j_it = jelek.begin();\
      it != sps.end(); it++, j_it++)
   {
    hpmp.clear(); s_hms(*it);
    cout << "\n" << *j_it << " "; 
    for(auto itb = hpmp.begin(); itb != hpmp.end(); itb++)
     {
      cout << *itb;
      if(itb != --hpmp.end()) cout << ":";
      else cout << " [h:m:s]";
     }
   }
  cout << "\nKategória: " << kat; 
 }
 
 void in_gr_ch::kiir()
 {
  sps = {swim,cycle,depo,swim+cycle+depo,run,getSum()};
  cout << "\nLicence: " << lic;
  for(it = sps.begin(), j_it = jelek.begin();\
      it != sps.end(); it++, j_it++)
   {
    hpmp.clear(); s_hms(*it);
    cout << "\n" << *j_it << " "; 
    for(auto itb = hpmp.begin(); itb != hpmp.end(); itb++)
     {
      cout << *itb;
      if(itb != --hpmp.end()) cout << ":";
      else cout << " [h:m:s]";
     }
   }
  cout << "\nKategória: " << kat; 
  cout << "\nNem: " << nem;
 }

tri_race& tri_race::setSum(int ij)
 { sum=swim+cycle+run+depo-ij; return *this; }
 
void mind1(tri_race& x_tri)
 { x_tri.kiir(); cout << "\n" << endl; }
 
int main(void)
 {
  in_ch A_tri('A',1200,4200,2300,123,1), B_tri('B',1300,4300,2400,125,2),\
           C_tri('C',1400,4400,2400,130,3); /* Objektumok példányosítása, beállítása */
  A_tri.setSum(0); B_tri.setSum(0); C_tri.setSum(120);
  in_ch D_tri('D',1450,4400,2400,130,5); D_tri.setSum(0);
  in_gr_ch E_tri('E',1450,4400,2300,120,4,'F'); E_tri.setSum(180);
  mind1(A_tri); mind1(B_tri); mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri);
  return 0;
}
/***************************************************************************************/