complex/1
/********* Decl.hpp ************/
#pragma once
#include <iostream>
#include <vector>
#include <map>

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
     ~memb() { cout << "\nTöröltem a tag osztályra -> memóriát!"; }
    };
    memb tagok;
   private:
    int sum;
   protected:
    tri_race()
     { tagok.setLic('-'); tagok.setSwim(0); tagok.setCycle(0);
       tagok.setRun(0); tagok.setDepo(0); cout << "\nAz alapértelmezett objektum létrejött"; }  
    tri_race(char lc, int sw, int cyc, int rn, int dp) 
     { tagok.setLic(lc); tagok.setSwim(sw); tagok.setCycle(cyc);
       tagok.setRun(rn); tagok.setDepo(dp);
      cout << "\nA paraméteres objektum létrejött"; } 
   virtual void kiir()=0; 
   int getSum() const { return sum; }
	 void e_r();
  public: 
   virtual ~tri_race() { cout << "\nTöröltem a szülő osztályra -> memóriát!"; }
	 tri_race(const tri_race&) = delete;
   tri_race& operator=(const tri_race&) = delete;
	};

class h_m_s  /* átszámoló */
 {
  protected:
  typedef pair<int, int> pmp;
  typedef pair<int, pmp> hpmp;
  typedef pair<string, hpmp> j_s;
  map<int, j_s> sps;
  const int oRA, pRC;
  h_m_s() : oRA(3600),pRC(60) { }
  ~h_m_s() { cout << "\nTöröltem az átszámoló osztályra -> memóriát!"; }
 };

class in_ch : public tri_race, protected h_m_s    /* gyerek */
 {
  protected: 
   int kat;
   int i_j;
   vector<in_ch*> objs;
   in_ch(char lc, int sw, int cyc, int rn, int dp, int kt, int ij) : \
          tri_race(lc, sw, cyc-ij, rn, dp) { kat=kt; i_j=ij;   }
   void kiir();
   void b_ki();
   void b_c_o(in_ch*);
  public:
   in_ch() : tri_race() { kat=0; }
   void ch_objs(char lc, int sw, int cyc, int rn, int dp, int kt, int ij);
   void ch_objs(char lc, int sw, int cyc, int rn, int dp, int kt, int ij, char nm);
   void mind1();
   ~in_ch();
 };

class in_gr_ch : public in_ch  /* unoka */
 {
  protected:
   char nem;
   in_gr_ch() : in_ch(), nem('N') {  }
   in_gr_ch(char lc, int sw, int cyc, int rn, int dp, int kt, int ij, char nm)\
             : in_ch(lc, sw, cyc, rn, dp, kt, ij), nem(nm) {  }
   friend void in_ch::ch_objs(char, int, int, int, int, int, int, char);
   void kiir();
  public:
   ~in_gr_ch() { cout << "\nTöröltem az unoka-objektum saját memóriáját!"; }
 };

/********* 1.cpp ************/
#include "Decl.hpp"

void in_ch::ch_objs(char lc, int sw, int cyc, int rn, int dp, int kt, int ij)
 {
  in_ch* n_c_o = new in_ch(lc, sw, cyc-ij, rn, dp, kt, ij);
  b_c_o(n_c_o);
 }

void in_ch::ch_objs(char lc, int sw, int cyc, int rn, int dp, int kt, int ij, char nm)
 {
  in_gr_ch* n_c_o = new in_gr_ch(lc, sw, cyc, rn, dp, kt, ij, nm);
  b_c_o(n_c_o);
 }

void in_ch::b_c_o(in_ch* n_c_o)
 {
  objs.push_back(n_c_o); cout << ", a címe: " << n_c_o;
  n_c_o->e_r();
 }

void in_ch::mind1()
 {
  for(auto it : objs) { it->kiir(); cout << "\n" << endl; } 
  //for(int i=0; i<objs.size(); i++)  { objs[i]->kiir(); cout << "\n" << endl; }
 }

void in_ch::kiir()
 { b_ki(); }

void in_gr_ch::kiir()
 { b_ki(); cout << "\nNem: " << nem; }

void in_ch::b_ki()
 {
  const int &tgS=tagok.getSwim(), &tgC=tagok.getCycle(), &tgD=tagok.getDepo(), &tgR=tagok.getRun(); 
  sps = {{1, {"Ú: ", {tgS/oRA, {(tgS%oRA)/pRC, (tgS%oRA)%pRC}}}},\
         {2, {"B: ", {tgC/oRA, {(tgC%oRA)/pRC, (tgC%oRA)%pRC}}}},\
         {3, {"D: ", {tgD/oRA, {(tgD%oRA)/pRC, (tgD%oRA)%pRC}}}},\
         {4, {"Ú+B+D: ", {(tgS+tgC+tgD)/oRA, {((tgS+tgC+tgD)%oRA)/pRC, ((tgS+tgC+tgD)%oRA)%pRC}}}},\
         {5, {"F: ", {tgR/oRA, {(tgR%oRA)/pRC, (tgR%oRA)%pRC}}}},\
         {6, {"Cél idő: ", {getSum()/oRA, {(getSum()%oRA)/pRC, (getSum()%oRA)%pRC}}}}};
  cout << "\nLicence: " << tagok.getLic();
  for(auto it : sps)
   {
    cout << "\n" << it.second.first; 
    cout << it.second.second.first << ":" << it.second.second.second.first << ":" << it.second.second.second.second << " [h:m:s]";
   }
  cout << "\nKategória: " << kat; 
 }

void tri_race::e_r()
 { sum=tagok.getSwim()+tagok.getCycle()+tagok.getDepo()+tagok.getRun(); }

in_ch::~in_ch()
 { 
  //for(auto it : objs)
  for (vector<in_ch*>::reverse_iterator it = objs.rbegin(); it != objs.rend(); it++) // "*it"!!!
   { 
    cout << "\n\nCím: " << *it; 
    in_gr_ch* rp = dynamic_cast<in_gr_ch*>(*it);
    if(rp==nullptr) cout << "\nTöröltem a gyerek-objektum saját adatait&metódusait!";
    delete *it;
   }
  if(tagok.getLic() == '-') cout << "\n\nTöröltem az alapértelmezett gyerek-objektum saját memóriáját!";  
  if(tagok.getLic() == 'E') cout << "\nTöröltem a gyerek osztályra -> memóriát!";
 }

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
 {
  in_ch alap;
  alap.ch_objs('A',1200,4200,2300,123,1,0);
  alap.ch_objs('B',1300,4300,2400,125,2,0);
  alap.ch_objs('C',1400,4400,2400,130,3,120);
  alap.ch_objs('D',1450,4400,2400,130,5,0);
  alap.ch_objs('E',1450,4400,2300,120,4,180,'F');
  alap.mind1();
  //in_ch A_Tri('A',1200,4200,2300,123,1,0);
  //in_gr_ch gr_alap;
  //in_gr_ch E_tri('E',1450,4400,2300,120,4,180,'F');
  return 0;
}

/***************************************************************************************/
