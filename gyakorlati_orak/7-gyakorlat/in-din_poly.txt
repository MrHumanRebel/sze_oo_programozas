inheritance/1_din_poly/1
/********* Decl.hpp ************/
using namespace std;

class tri_race /* szülő osztály deklarációja */
 {
   //protected:
    char lic;
    int swim, cycle, run, depo, h, p, mp;
   private:
    int sum;
    const int oRA, pRC;
   public:
    tri_race() : oRA(3600), pRC(60) /* Alapértelmezett konstruktor */
      { lic='-'; swim=0; cycle=0; run=0; depo=0; }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) : oRA(3600), pRC(60) /* Alapérték beállító konstruktor */
     { 
      lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp;
      cout << "\nA paraméteres objektum létrejött";
     } 
   void kiir() const ; 
	 tri_race& setSum(int ij);
   ~tri_race()
    { cout << "\nTöröltem a szülő objektumot!"; }
   tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;
	};
	
class in_ch : public tri_race /* származtatott gyerek osztály deklarációja */
 {
   //protected:
    int kat;
   public:
    in_ch() : tri_race() { kat=0; }
    in_ch(char lc, int sw, int cyc, int rn, int dp, int kt) : \
           tri_race(lc, sw, cyc, rn, dp) { kat=kt; }
    void kiir() const ;
    ~in_ch()
    { cout << "\nTöröltem a gyerek-objektum saját adatait!"; }
 };
 
 /* class in_gr_ch : public in_ch  származtatott unoka osztály deklarációja 
 {
   private:
    char nem;
   public:
    in_gr_ch() : in_ch(), nem('N') {  }
    in_gr_ch(char lc, int sw, int cyc, int rn, int dp, int kt, char nm) : \
           in_ch(lc, sw, cyc, rn, dp, kt), nem(nm) {  }
    void kiir() const ;
    ~in_gr_ch()
    { cout << "\nTöröltem az unoka-objektum saját adatait!"; }
 }; */
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void tri_race::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nF: " << run \
       << "\nD: " << depo;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
 }

 void in_ch::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo \
       << "\nÚ+B+D: " << swim+cycle+depo << "\nF: " << run;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
  cout << "\nKategória: " << kat;
 }
 
 /*void in_gr_ch::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo \
       << "\nÚ+B+D: " << swim+cycle+depo << "\nF: " << run;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
  cout << "\nKategória: " << kat;
  cout << "\nNem: " << nem;
 }*/

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
 
/* void mind1(tri_race& x_tri)
 {
  x_tri.kiir();
  cout << "\n" << endl;
 }*/
 
int main(void)
 {
  tri_race A_tri('A',1200,4200,2300,123), B_tri('B',1300,4300,2400,125),\
           C_tri('C',1400,4400,2400,130); /* Objektumok példányosítása, beállítása */
  A_tri.setSum(0); B_tri.setSum(0); C_tri.setSum(120);
  mind(A_tri,B_tri,C_tri);
  in_ch D_tri('D',1450,4400,2400,130,5); D_tri.setSum(0);
  D_tri.kiir(); cout << "\n" << endl;
 /* D_tri.tri_race::kiir(); cout << "\n" << endl; */
 /* C_tri.in_ch::kiir();*/
 /* in_gr_ch E_tri('E',1450,4400,2300,120,4,'F'); E_tri.setSum(180);
  E_tri.kiir(); cout << "\n" << endl;*/
 /* mind1(A_tri); mind1(B_tri); mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri); */
  return 0;
}
/***************************************************************************************/
din_poly/2
/********* Decl.hpp ************/
using namespace std;

class tri_race /* szülő osztály deklarációja */
 {
   protected:
    char lic;
    int swim, cycle, run, depo, h, p, mp;
   private:
    int sum;
    const int oRA, pRC;
   public:
    tri_race() : oRA(3600), pRC(60) /* Alapértelmezett konstruktor */
      { lic='-'; swim=0; cycle=0; run=0; depo=0; }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) : oRA(3600), pRC(60) /* Alapérték beállító konstruktor */
     { 
      lic=lc; swim=sw; cycle=cyc; run=rn; depo=dp;
      cout << "\nA paraméteres objektum létrejött";
     } 
   virtual void kiir() const =0 ; 
	 tri_race& setSum(int ij);
   virtual ~tri_race()
    { cout << "\nTöröltem a szülő objektumot!"; }
	tri_race(const tri_race&) = delete;
    tri_race& operator=(const tri_race&) = delete;
	};
	
class in_ch : public tri_race /* származtatott gyerek osztály deklarációja */
 {
   protected:
    int kat;
   public:
    in_ch() : tri_race() { kat=0; }
    in_ch(char lc, int sw, int cyc, int rn, int dp, int kt) : \
           tri_race(lc, sw, cyc, rn, dp) { kat=kt; }
    void kiir() const ;
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
    void kiir() const ;
    ~in_gr_ch()
    { cout << "\nTöröltem az unoka-objektum saját adatait!"; }
 };
/**************************/
#include <iostream>
#include "Decl.hpp"

/*void tri_race::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nF: " << run \
       << "\nD: " << depo;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
 }*/

 void in_ch::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo \
       << "\nÚ+B+D: " << swim+cycle+depo << "\nF: " << run;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
  cout << "\nKategória: " << kat;
 }
 
 void in_gr_ch::kiir() const
 {
  cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo \
       << "\nÚ+B+D: " << swim+cycle+depo << "\nF: " << run;
  cout << "\nCél idő: " << h << ":" << p << ":" << mp  << " [h:m:s]";
  cout << "\nKategória: " << kat;
  cout << "\nNem: " << nem;
 }

tri_race& tri_race::setSum(int ij)
 {
  sum=swim+cycle+run+depo-ij;
  h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
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
/************************/