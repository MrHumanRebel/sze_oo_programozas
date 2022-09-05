multi_in/1
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
    tri_race() /* Alapértelmezett konstruktor */
      { lic='-'; swim=0; cycle=0; run=0; depo=0; }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) /* Alapérték beállító konstruktor */
     { 
      lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp;
      cout << "\nA paraméteres objektum létrejött";
     } 
   virtual void kiir() =0 ; 
   int getSum() const { return sum; }
	 tri_race& setSum(int ij);
   virtual ~tri_race()
    { cout << "\nTöröltem a szülő osztályt!"; }
	tri_race(const tri_race&) = delete;
    tri_race& operator=(const tri_race&) = delete;
	};
	
class in_ch : public tri_race, protected h_m_s /* származtatott gyerek osztály deklarációja */
 {
   protected:
    int kat;
   public:
    in_ch() : tri_race() { kat=0; }
    in_ch(char lc, int sw, int cyc, int rn, int dp, int kt) : \
           tri_race(lc, sw, cyc, rn, dp) { kat=kt; }
    void kiir() ;
    ~in_ch()
    { cout << "\nTöröltem a gyerek-objektum saját adatait!"; }
 };
 
 class in_gr_ch : public in_ch  /*származtatott unoka osztály deklarációja */
 {
   private:
    char nem;
   public:
    in_gr_ch() : in_ch(), nem('N') {  }
    in_gr_ch(char lc, int sw, int cyc, int rn, int dp, int kt, char nm) : \
           in_ch(lc, sw, cyc, rn, dp, kt), nem(nm) {  }
    void kiir() ;
    ~in_gr_ch()
    { cout << "\nTöröltem az unoka-objektum saját adatait!"; }
 };

class h_m_s  /* az átszámoló osztály deklarációja de rossz helyen! */
 {
   protected:
    int h, p, mp;
    const int oRA, pRC;
    h_m_s() : oRA(3600),pRC(60) { }
    void s_hms(int s)
     { h=s/oRA; p=(s%oRA)/pRC; mp=(s%oRA)%pRC; }
     ~h_m_s()
    { cout << "\nTöröltem az átszámoló osztályt!"; }
 };
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void in_ch::kiir()
 {

  s_hms(swim);
  cout << "\nLicence: " << lic << "\nÚ: " \
       << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(cycle);     
  cout <<  "\nB: " \
   << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(depo);     
  cout <<  "\nD: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(swim+cycle+depo);     
  cout <<  "\nÚ+B+D: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(run);     
  cout <<  "\nF: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(getSum());
  cout << "\nCél idő: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  cout << "\nKategória: " << kat; 
 }
 
 void in_gr_ch::kiir()
 {
 s_hms(swim);
  cout << "\nLicence: " << lic << "\nÚ: " \
       << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(cycle);     
  cout <<  "\nB: " \
   << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(depo);     
  cout <<  "\nD: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(swim+cycle+depo);     
  cout <<  "\nÚ+B+D: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(run);     
  cout <<  "\nF: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  s_hms(getSum());
  cout << "\nCél idő: " \
  << h << ":" << p << ":" << mp  << " [h:m:s]";
  cout << "\nKategória: " << kat; 
  cout << "\nNem: " << nem;
 }

tri_race& tri_race::setSum(int ij)
 {
  sum=swim+cycle+run+depo-ij;
  return *this;
 }
 
 void mind1(tri_race& x_tri)
 {
  x_tri.kiir();
  cout << "\n" << endl;
 }
 
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
