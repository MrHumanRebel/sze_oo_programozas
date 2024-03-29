https : // cplusplus.com/reference/stl/
        Templ /
        <vector> / 1
/********* Decl.hpp ************/
#include <iostream>
#include <vector>
        //#include <algorithm>

        using namespace std;

vector<int> hpmp(3);
// vector<int>::iterator ke; // un. "bejárók", az elemek címzéséhez

// komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény
// bool hasonlit(int i, int j) { return i<j; }
// bool szuro (int i) { return ((i%2)==1 /*or (i%2)==-1*/); }
// bool szuro2 (int i) { return ((i%2)==0 /*and i!=0*/); }

/***************************************************************************************/
#include "Decl.hpp"

int main(void)
{
  int i;
  hpmp[0] = -1;
  hpmp.push_back(6);
  for (i = 0; i < hpmp.size() /*10*/; i++)
  {
    cout << hpmp[i] << " "; /*hpmp.push_back(7+i);*/
  }
  cout << "\n";
  /*  for(i=0; i<hpmp.size(); i++) { cout << hpmp[i] << " "; }
    cout << "\n\n" << hpmp.size() << "\n";*/
  /*  hpmp.pop_back();
    cout << "\n" << hpmp.size() << "\n";*/
  /*  hpmp.resize(19);
    for(i=0; i<hpmp.size(); i++) { cout << hpmp[i] << " "; }
    cout << "\n";
    hpmp.push_back(20);*/
  // Típus felismerés a fordítóra bízva! Utolsó elem utánra mutat!
  // for(auto it = hpmp.begin(); it != hpmp.end(); it++) { cout << *it/*&(*it)*/ << " "; }
  // cout << "\n";
  // for(auto it = --hpmp.end(); it != --hpmp.begin(); it--) { cout << *it << " "; }
  /*cout << "\n";
  for(vector<int>::reverse_iterator it=hpmp.rbegin(); it!=hpmp.rend(); it++)
   { cout << *it << " "; }*/
  /*sort(hpmp.begin(), hpmp.end(), greater<int>()); cout << "\n";
  //sort(hpmp.begin(), hpmp.end(), hasonlit); cout << "\n";
  for(auto it = hpmp.cbegin(); it != hpmp.cend(); it++) { cout << *it << " "; }
  cout << "\n";*/
  // hpmp.insert(hpmp.begin()/*+4*//*,4*/,42);
  // hpmp.insert(hpmp.end()-2/*,2*/,42);
  // hpmp.insert(hpmp.begin(),hpmp.begin()+9,hpmp.begin()+15);
  /*for(auto it : hpmp) { cout << it << " "; } // Nincs '*'!
  cout << "\n";*/
  // remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
  // remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
  // hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
  // hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)),hpmp.end());
  /*for(auto it : hpmp) { cout << it << " "; }
  cout << "\n";*/
  // ke=find(hpmp.begin(), hpmp.end(), 20);
  // if(ke!=hpmp.end()) cout << *ke/*&(*ke)*/ << "\n\n";
  // cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  // cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  // cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
  // cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n\n";
  // cout << count(hpmp.begin(), hpmp.end(),0) << endl;
  // cout << count_if(hpmp.begin(), hpmp.end(),szuro2) << "\n";
  /*hpmp.clear();
    cout << "\n" << hpmp.size() << "\n";
    if(hpmp.empty()) cout << "Üres a vektor!\n";*/
  return 0;
}
/***************************************************************************************/
Templ / <vector> / 1 : eredmény
/********* Decl.hpp ************/
#include <iostream>
#include <vector>
#include <algorithm>

                       using namespace std;

vector<int> hpmp(3);
vector<int>::iterator ke; // un. "bejárók", az elemek címzéséhez

// komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvény
bool hasonlit(int i, int j) { return i < j; }
bool szuro(int i) { return ((i % 2) == 1 or (i % 2) == -1); }
bool szuro2(int i) { return ((i % 2) == 0 and i != 0); }

/***************************************************************************************/
#include "Decl.hpp"

int main(void)
{
  int i;
  hpmp[0] = -1;
  hpmp.push_back(6);
  for (i = 0; i < 10; i++)
  {
    cout << hpmp[i] << " ";
    hpmp.push_back(7 + i);
  }
  cout << "\n";
  for (i = 0; i < hpmp.size(); i++)
  {
    cout << hpmp[i] << " ";
  }
  cout << "\n\n"
       << hpmp.size() << "\n";
  hpmp.pop_back();
  cout << "\n"
       << hpmp.size() << "\n";
  hpmp.resize(19);
  for (i = 0; i < hpmp.size(); i++)
  {
    cout << hpmp[i] << " ";
  }
  cout << "\n";
  hpmp.push_back(20);
  // Típus felismerés a fordítóra bízva!
  for (auto it = hpmp.begin(); it != hpmp.end(); it++)
  {
    cout << (*it) /*(*it)*/ << " ";
  }
  cout << "\n";
  for (auto it = --hpmp.end(); it != --hpmp.begin(); it--)
  {
    cout << *it << " ";
  }
  cout << "\n";
  for (vector<int>::reverse_iterator it = hpmp.rbegin(); it != hpmp.rend(); it++)
  {
    cout << *it << " ";
  }
  // sort(hpmp.begin(), hpmp.end()); cout << "\n";
  sort(hpmp.begin(), hpmp.end(), hasonlit);
  cout << "\n";
  for (auto it = hpmp.cbegin(); it != hpmp.cend(); it++)
  {
    cout << *it << " ";
  }
  cout << "\n";
  // hpmp.insert(hpmp.begin(),4/*,4*/,42);
  // hpmp.insert(hpmp.end(),2/*,2*/,42);
  hpmp.insert(hpmp.begin(), hpmp.begin() + 9, hpmp.begin() + 15);
  for (auto it : hpmp)
  {
    cout << it << " ";
  } // Nincs '*'!
  cout << "\n";
  // remove(hpmp.begin(), hpmp.end(), 0); // NINCS törlés!
  // remove_if(hpmp.begin(), hpmp.end(), szuro); // NINCS törlés!
  // hpmp.erase((remove(hpmp.begin(), hpmp.end(), 0)),hpmp.end());
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(), szuro)), hpmp.end());
  for (auto it : hpmp)
  {
    cout << it << " ";
  }
  cout << "\n";
  ke = find(hpmp.begin(), hpmp.end(), 20);
  if (ke != hpmp.end())
    cout << *ke /*&(*ke)*/ << "\n\n";
  cout << *max_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(), hasonlit) << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).first << "\n";
  cout << *minmax_element(hpmp.begin(), hpmp.end()).second << "\n\n";
  cout << count(hpmp.begin(), hpmp.end(), 0) << endl;
  cout << count_if(hpmp.begin(), hpmp.end(), szuro2) << "\n";
  hpmp.clear();
  cout << "\n"
       << hpmp.size() << "\n";
  if (hpmp.empty())
    cout << "Üres a vektor!\n";
  return 0;
}
/***************************************************************************************/
Tri_vector / 1
/********* Decl.hpp ************/
#pragma once
#include <iostream>
#include <iomanip> // "cout" helyiértékhez!
#include <vector>

    using namespace std;

class tri_race
{
  int sum;

protected:
  class memb
  {
    string lic;
    int swim, cycle, run, depo, ij;

  public:
    string getLic() const { return lic; }
    int getSwim() const { return swim; }
    int getCycle() const { return cycle; }
    int getRun() const { return run; }
    int getDepo() const { return depo; }
    int getIj() const { return ij; }
    void setLic(string lc) { lic = lc; }
    void setSwim(int sw) { swim = sw; }
    void setCycle(int cyc) { cycle = cyc; }
    void setRun(int rn) { run = rn; }
    void setDepo(int dp) { depo = dp; }
    void setIj(int t) { ij = t; }
    memb() { cout << "\nAz alapértelmezett szülő-tag adatszerkezet létrejött: "; }
    ~memb() { cout << "\nFelszabadítottam a szülő-tag adatszerkezet memóriacímét: "; }
  };
  memb tagok;
  tri_race() : sum(0)
  {
    tagok.setLic("--------");
    tagok.setSwim(0);
    tagok.setCycle(0);
    tagok.setRun(0);
    tagok.setDepo(0);
    tagok.setIj(0);
    cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött: ";
  }
  tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0)
  {
    tagok.setLic(lc);
    tagok.setSwim(sw);
    tagok.setCycle(cyc);
    tagok.setRun(rn);
    tagok.setDepo(dp);
    tagok.setIj(t);
    cout << "\nA paraméteres szülő-adatszerkezet létrejött: ";
  }
  int getSum() const { return sum; }

public:
  tri_race &setSum();
  virtual tri_race &kiir_cel() = 0;
  virtual ~tri_race()
  {
    cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét: ";
  }
};

class h_m_s
{
  const int oRA, pRC;

protected:
  vector<int> hpmp = {0, 0, 0};
  vector<int> sps;
  vector<string> jelek = {"Ú:\t\t", "B:\t\t", "D:\t\t", "Ú+B+D:\t", "F:\t\t", "T-:\t\t", "Cél idő:"};
  vector<int>::iterator it;
  vector<string>::iterator j_it;
  h_m_s() : oRA(3600), pRC(60)
  {
    cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: ";
  }
  void s_hms(int s)
  {
    hpmp.push_back(s / oRA);
    hpmp.push_back((s % oRA) / pRC);
    hpmp.push_back((s % oRA) % pRC);
  }

public:
  void kiir_i1() const;
  virtual h_m_s &kiir_cel() = 0;
  ~h_m_s()
  {
    cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét: ";
  }
};

class in_ch : public tri_race, public h_m_s
{
  int kat;

protected:
  void kiir_i4();

public:
  in_ch() : tri_race()
  {
    kat = 0;
    cout << "\nAz alapértelmezett gyerek-objektum létrejött: ";
  }
  in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : tri_race(lc, sw, cyc, rn, dp, t)
  {
    kat = kt;
    cout << "\nA paraméteres gyerek-objektum létrejött: ";
  }
  virtual in_ch &kiir_cel();
  virtual ~in_ch()
  {
    cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: ";
  }
  in_ch(const in_ch &) = delete;
  in_ch &operator=(const in_ch &) = delete;
};

class in_gr_ch : public in_ch
{
  char nem;

public:
  in_gr_ch() : in_ch(), nem('N') {}
  in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm)
  {
    cout << "\nA paraméteres unoka-objektum létrejött: ";
  }
  virtual in_gr_ch &kiir_cel();
  virtual ~in_gr_ch()
  {
    cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét: ";
  }
};

void mind1(vector<in_ch *> x_tri);
void felsz(vector<in_ch *> x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void h_m_s::kiir_i1() const
{
  int f = 0;
  for (auto itb : hpmp)
  {
    cout << setw(2) << itb;
    if (f != 2)
    {
      cout << ":";
      f++;
    }
    else
      cout << " [h:m:s]\n";
  }
}

void in_ch::kiir_i4()
{
  sps = {tagok.getSwim(), tagok.getCycle(), tagok.getDepo(), tagok.getSwim() + tagok.getCycle() + tagok.getDepo(),
         tagok.getRun(), tagok.getIj(), getSum()};
  cout << "Licence: " << tagok.getLic() << endl;
  for (it = sps.begin(), j_it = jelek.begin(); it != sps.end(); it++, j_it++)
  {
    hpmp.clear();
    s_hms(*it);
    cout << *j_it << " ";
    kiir_i1();
  }
  cout << "Kategória: " << kat << endl;
}

in_ch &in_ch::kiir_cel()
{
  kiir_i4();
  return *this;
}

in_gr_ch &in_gr_ch::kiir_cel()
{
  kiir_i4();
  cout << "Nem: " << nem << endl;
  return *this;
}

tri_race &tri_race::setSum()
{
  sum = tagok.getSwim() + tagok.getCycle() + tagok.getRun() + tagok.getDepo() - tagok.getIj();
  return *this;
}

void mind1(vector<in_ch *> x_tri)
{
  cout << endl;
  for (auto it : x_tri)
  {
    in_gr_ch *rp = dynamic_cast<in_gr_ch *>(it);
    if (rp != nullptr)
    {
      cout << "\nUnoka ";
    }
    else
    {
      in_ch *rp = dynamic_cast<in_ch *>(it);
      if (rp != nullptr)
      {
        cout << "\nGyerek ";
      }
      else
      {
        tri_race *rp = dynamic_cast<tri_race *>(it);
        cout << "\nSzülő ";
      }
    }
    cout << "rajt idő: ";
    it->kiir_i1();
    it->setSum().kiir_cel();
  }
}

void felsz(vector<in_ch *> x_tri)
{
  for (vector<in_ch *>::reverse_iterator it = x_tri.rbegin();
       it != x_tri.rend(); it++)
  {
    delete *it;
    cout << *it << endl;
    *it = 0;
  }
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  vector<in_ch *> objs;
  in_ch *alap = new in_ch;
  objs.push_back(alap);
  cout << "alap = " << alap << endl;
  in_ch *A_tri = new in_ch("M_V_1357", 1200, 4200, 2300, 123, 60, 6);
  objs.push_back(A_tri);
  cout << "A_tri = " << A_tri << endl;
  in_ch *B_tri = new in_ch("V_G_2468", 1300, 4300, 2400, 125, 0, 6);
  objs.push_back(B_tri);
  cout << "B_tri = " << B_tri << endl;
  in_ch *C_tri = new in_ch("B_G_9048", 1400, 4400, 2400, 130, 90, 6);
  objs.push_back(C_tri);
  cout << "C_tri = " << C_tri << endl;
  in_ch *D_tri = new in_ch("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  objs.push_back(D_tri);
  cout << "D_tri = " << D_tri << endl;
  in_ch *E_tri = new in_gr_ch("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
  objs.push_back(E_tri);
  cout << "E_tri = " << E_tri << endl;
  mind1(objs);
  felsz(objs);
  return 0;
}
/***************************************************************************************/
