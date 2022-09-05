/**** Próba_zh **************/
/********* Decl.hpp ************/
using namespace std;

class tri_race /* Osztály deklarációja */	
 {
   private:
    char lic;
    int swim;
    int cycle;
    int run;
    int depo;
    int sum;
    int h;
    int p;
    int mp;
    const int oRA;
    const int pRC;
   public:
    tri_race() : oRA(3600), pRC(60)
      { lic='-'; swim=0; cycle=0; run=0; depo=0; }  /* Alapértelmezett konstruktor */
    tri_race(char lc, int sw, int cyc, int rn, int dp) : oRA(3600), pRC(60)  
     { lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp;} /* Alapérték beállító konstruktor */
   void kiir() const;
	 tri_race& setSum(int ij);
   ~tri_race()
    { cout << "\nA töröltem az objektumot!"; }
	};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void tri_race::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nF: " << run \
       << "\nD: " << depo;
  //cout << "\nCél idő: " << sum;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
 }

tri_race& tri_race::setSum(int ij)
 {
  sum=swim+cycle+run+depo-ij;
  h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
  return *this;
 }
 void mind(tri_race& A_tri, tri_race& B_tri, tri_race& C_tri)
 {
  A_tri.kiir(); B_tri.kiir(); C_tri.kiir();
  cout << "\n" << endl;
 }
 
int main(void)
 {
  tri_race A_tri('A',1200,4200,2300,123), B_tri('B',1300,4300,2400,125),\
           C_tri('C',1400,4400,2400,130); /* Objektumok példányosítása, beállítása */
  A_tri.setSum(0); B_tri.setSum(0); C_tri.setSum(0);
  mind(A_tri,B_tri,C_tri);
  C_tri.setSum(120);
  mind(A_tri,B_tri,C_tri);
  return 0;
}
/***************************************************************************************/
/**** Próba_zh láncolt hívással **************/
/********* Decl.hpp ************/
using namespace std;

class tri_race /* Osztály deklarációja */
 {
   private:
    char lic;
    int swim;
    int cycle;
    int run;
    int depo;
    int sum;
    int h;
    int p;
    int mp;
    const int oRA;
    const int pRC;
   public:
    tri_race() : oRA(3600), pRC(60)
      { lic='-'; swim=0; cycle=0; run=0; depo=0; }  /* Alapértelmezett konstruktor */
    tri_race(char lc, int sw, int cyc, int rn, int dp) : oRA(3600), pRC(60)  
     { lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp;} /* Alapérték beállító konstruktor */
   tri_race& kiir(); /* elveszítette a "const" besorolását a "return *this" miatt! */
	 tri_race& setSum(int ij);
   ~tri_race()
    { cout << "\nA töröltem az objektumot!"; }
	};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

tri_race& tri_race::kiir() /* elveszítette a "const" besorolását a "return *this" miatt! */
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nF: " << run \
       << "\nD: " << depo;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
  return *this;
 }

tri_race& tri_race::setSum(int ij)
 {
  sum=swim+cycle+run+depo-ij;
  h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
  return *this;
 }
 
 /* Nem kell a "mind" fgv! */
 
int main(void)
 {
  tri_race A_tri('A',1200,4200,2300,123), B_tri('B',1300,4300,2400,125),\
           C_tri('C',1400,4400,2400,130); /* Objektumok példányosítása, beállítása */
  A_tri.setSum(0).kiir(); B_tri.setSum(0).kiir(); C_tri.setSum(0).kiir(); /* láncolt hívások */
  cout << "\n" << endl;
  A_tri.setSum(0).kiir(); B_tri.setSum(0).kiir(); C_tri.setSum(120).kiir(); /* láncolt hívások */
  cout << "\n" << endl;
  return 0;
}
/***************************************************************************************/