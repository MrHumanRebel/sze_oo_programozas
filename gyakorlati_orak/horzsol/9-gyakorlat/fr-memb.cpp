friend class & function/1
/********* Decl.hpp ************/
#pragma once
#include <iostream>
#include <vector>

using namespace std;

//class in_ch; /* forward deklaráció, de '*' vagy '&' ! */

class barat  /* barát osztály */
 {
  public:
   barat() { }
   void olvas(in_ch& X_Tri);
   ~barat() { cout << "\nTöröltem a barát osztályt!"; }
 };

class tri_race /* szülő */
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
   virtual void kiir() =0; 
   int getSum() const { return sum; }
	 tri_race& setSum(int ij);
   virtual ~tri_race() { cout << "\nTöröltem a szülő osztályt!"; }
	 tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;
   //friend class barat;
   //friend void barat::olvas(in_ch&);
	};

class h_m_s  /* átszámoló */
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

class in_ch : public tri_race, protected h_m_s    /* gyerek */
 {
  protected:
   int kat;
  public:
   in_ch() : tri_race() { kat=0; }
   in_ch(char lc, int sw, int cyc, int rn, int dp, int kt) : \
          tri_race(lc, sw, cyc, rn, dp) { kat=kt; }
   void kiir();
   ~in_ch() { cout << "\nTöröltem a gyerek-objektum saját adatait!"; }
   friend class barat;
   //friend void barat::olvas(in_ch&);
 };

class in_gr_ch : public in_ch  /* unoka */
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

void mind1(tri_race& x_tri);

/********* 1.cpp ************/
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
 
void barat::olvas(in_ch& X_Tri)
 { 
    cout << "\nLicence: " << X_Tri.lic << "\nKategória: " << X_Tri.kat << "\n";
    //cout << "Cél idő: " << X_Tri.sum << "\n";
    //X_Tri.lic='Z'; X_Tri.kat=10; X_Tri.sum=10000;
    //cout << "\nLicence: " << X_Tri.lic << "\nKategória: " << X_Tri.kat << "\n";
    //cout << "Cél idő: " << X_Tri.sum << "\n";
 }

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
 {
  in_ch A_tri('A',1200,4200,2300,123,1), B_tri('B',1300,4300,2400,125,2),\
           C_tri('C',1400,4400,2400,130,3); 
  A_tri.setSum(0); B_tri.setSum(0); C_tri.setSum(120);
  in_ch D_tri('D',1450,4400,2400,130,5); D_tri.setSum(0);
  in_gr_ch E_tri('E',1450,4400,2300,120,4,'F'); E_tri.setSum(180);
  mind1(A_tri); mind1(B_tri); mind1(C_tri); mind1(D_tri); mind1(E_tri);
  barat b;
  b.olvas(A_tri);
  return 0;
}

/***************************************************************************************/
member class/1
/********* Decl.hpp ************/
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class memb  /* tagok osztály */
 {
  private:
   char lic;
   int swim, cycle, run, depo;
  public:
   char getLic() const { return lic; }
   int getSwim() const { return swim; }
   int getCycle() const { return cycle; }
   int getRun() const { return run; }
   int getDepo() const { return depo; }
   void setLic(char lc) { lic=lc; }
   void setSwim(int sw) { swim=sw; }
   void setCycle(int cyc) { cycle=cyc; }
   void setRun(int rn) { run=rn; }
   void setDepo(int dp) { depo=dp; }
   memb() { }
   ~memb() { cout << "\nTöröltem a tag osztályt!"; }
 };

class tri_race /* szülő */
 {
   protected:
    memb tagok;
   private:
    int sum;
   public:
    tri_race()
     { tagok.setLic('-'); tagok.setSwim(0); tagok.setCycle(0);
       tagok.setRun(0); tagok.setDepo(0); }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) 
     { tagok.setLic(lc); tagok.setSwim(sw); tagok.setCycle(cyc);
       tagok.setRun(rn); tagok.setDepo(dp);
      cout << "\nA paraméteres objektum létrejött"; } 
   virtual void kiir()=0; 
   int getSum() const { return sum; }
	 void e_r();
   virtual ~tri_race() { cout << "\nTöröltem a szülő osztályt!"; }
	 tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;
	};

class h_m_s  /* átszámoló */
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

class in_ch : public tri_race, protected h_m_s    /* gyerek */
 {
  protected:
   int kat;
   int i_j;
  public:
   in_ch() : tri_race() { kat=0; }
   in_ch(char lc, int sw, int cyc, int rn, int dp, int kt, int ij) : \
          tri_race(lc, sw, cyc-ij, rn, dp) { kat=kt; i_j=ij;   }
   void kiir();
   ~in_ch() { cout << "\nTöröltem a gyerek-objektum saját adatait!"; }
 };

class in_gr_ch : public in_ch  /* unoka */
 {
  private:
   char nem;
  public:
   in_gr_ch() : in_ch(), nem('N') {  }
   in_gr_ch(char lc, int sw, int cyc, int rn, int dp, int kt, int ij, char nm)\
             : in_ch(lc, sw, cyc, rn, dp, kt, ij), nem(nm) {  }
   void kiir();
   ~in_gr_ch() { cout << "\nTöröltem az unoka-objektum saját adatait!"; }
 };

void mind1(tri_race& x_tri);

/********* 1.cpp ************/
#include "Decl.hpp"

void in_ch::kiir()
 {
  sps = { tagok.getSwim(),tagok.getCycle(),tagok.getDepo(),\
          tagok.getSwim()+tagok.getCycle()+tagok.getDepo(),\
          tagok.getRun(),getSum() };
  cout << "\nLicence: " << tagok.getLic();
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
  sps = { tagok.getSwim(),tagok.getCycle(),tagok.getDepo(),\
          tagok.getSwim()+tagok.getCycle()+tagok.getDepo(),\
          tagok.getRun(),getSum() };
  cout << "\nLicence: " << tagok.getLic();
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

void tri_race::e_r()
 { sum=tagok.getSwim()+tagok.getCycle()+tagok.getDepo()+tagok.getRun(); }

 void mind1(tri_race& x_tri)
 { x_tri.kiir(); cout << "\n" << endl; }

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
 {
  in_ch A_tri('A',1200,4200,2300,123,1,0), B_tri('B',1300,4300,2400,125,2,0),\
           C_tri('C',1400,4400,2400,130,3,120); 
  A_tri.e_r(); B_tri.e_r(); C_tri.e_r();
  in_ch D_tri('D',1450,4400,2400,130,5,0); D_tri.e_r();
  in_gr_ch E_tri('E',1450,4400,2300,120,4,180,'F'); E_tri.e_r();
  mind1(A_tri); mind1(B_tri); mind1(C_tri); mind1(D_tri); mind1(E_tri);
  return 0;
}
/***************************************************************************************/
member class/2
/********* Decl.hpp ************/
#pragma once
#include <iostream>
#include <vector>

using namespace std;

class tri_race /* szülő */
 {
  protected:
   class memb  /* tagok osztály */
    {
     private:
      char lic;
      int swim, cycle, run, depo;
    public:
     char getLic() const { return lic; }
     int getSwim() const { return swim; }
     int getCycle() const { return cycle; }
     int getRun() const { return run; }
     int getDepo() const { return depo; }
     void setLic(char lc) { lic=lc; }
     void setSwim(int sw) { swim=sw; }
     void setCycle(int cyc) { cycle=cyc; }
     void setRun(int rn) { run=rn; }
     void setDepo(int dp) { depo=dp; }
     memb() { }
     ~memb() { cout << "\nTöröltem a tag osztályt!"; }
    };
    memb tagok;
   private:
    int sum;
   public:
    tri_race()
     { tagok.setLic('-'); tagok.setSwim(0); tagok.setCycle(0);
       tagok.setRun(0); tagok.setDepo(0); }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) 
     { tagok.setLic(lc); tagok.setSwim(sw); tagok.setCycle(cyc);
       tagok.setRun(rn); tagok.setDepo(dp);
      cout << "\nA paraméteres objektum létrejött"; } 
   virtual void kiir()=0; 
   int getSum() const { return sum; }
	 void e_r();
   virtual ~tri_race() { cout << "\nTöröltem a szülő osztályt!"; }
	 tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;
	};

class h_m_s  /* átszámoló */
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

class in_ch : public tri_race, protected h_m_s    /* gyerek */
 {
  protected:
   int kat;
   int i_j;
  public:
   in_ch() : tri_race() { kat=0; }
   in_ch(char lc, int sw, int cyc, int rn, int dp, int kt, int ij) : \
          tri_race(lc, sw, cyc-ij, rn, dp) { kat=kt; i_j=ij;   }
   void kiir();
   ~in_ch() { cout << "\nTöröltem a gyerek-objektum saját adatait!"; }
 };

class in_gr_ch : public in_ch  /* unoka */
 {
  private:
   char nem;
  public:
   in_gr_ch() : in_ch(), nem('N') {  }
   in_gr_ch(char lc, int sw, int cyc, int rn, int dp, int kt, int ij, char nm)\
             : in_ch(lc, sw, cyc, rn, dp, kt, ij), nem(nm) {  }
   void kiir();
   ~in_gr_ch() { cout << "\nTöröltem az unoka-objektum saját adatait!"; }
 };
/***************************************************************************************/