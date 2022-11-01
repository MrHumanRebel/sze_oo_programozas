multi_in / 1 = > "din_cast/pointer-rel kiir_rajt() kiváltással, absztrakt osztály" + átszámoló osztály(átalakítás órai munkával !)
/********* Decl.hpp ************/
#pragma once
#include <iostream>

                                                                                         using namespace std;

class tri_race
{
protected:
  string lic;
  int swim, cycle, run, depo, ij, sum;

public:
  tri_race() : sum(0)
  {
    lic = "--------";
    swim = 0;
    cycle = 0;
    run = 0;
    depo = 0;
    ij = 0;
    cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött: ";
  }
  tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0)
  {
    lic = lc;
    swim = sw;
    cycle = cyc;
    run = rn;
    depo = dp;
    ij = t;
    cout << "\nA paraméteres szülő-adatszerkezet létrejött: ";
  }
  int getIj() const { return ij; }
  string getLic() const { return lic; }
  virtual tri_race &kiir_cel() = 0;
  tri_race &setSum(int t);
  virtual ~tri_race()
  {
    cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét: ";
  }
};

class h_m_s // átszámoló osztály deklarációja
{
  const int oRA, pRC;

protected:
  int h, p, mp;

public:
  h_m_s() : oRA(3600), pRC(60), h(0), p(0), mp(0)
  {
    cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: ";
  }
  void kiir_i1() const;
  void s_hms(int s)
  {
    h = s / oRA;
    p = (s % oRA) / pRC;
    mp = (s % oRA) % pRC;
  }
  // virtual h_m_s& kiir_cel()=0; // megvalósított metódus lehet csak!
  ~h_m_s() // "virtual" nem kötelező!
  {
    cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét: ";
  }
};

class in_ch : public tri_race, public h_m_s
{
  int kat;

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
  void kiir_i2();
  void kiir_i3();
  void kiir_i4();
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
private:
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

void mind1(in_ch *x_tri);
void felsz(tri_race *x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void h_m_s::kiir_i1() const
{
  cout << h << ":" << p << ":" << mp << " [h:m:s]\n";
}

void in_ch::kiir_i2()
{
  cout << "Licence: " << lic << "\nÚ: ";
  s_hms(swim);
  kiir_i1();
  cout << "B: ";
  s_hms(cycle);
  kiir_i1();
  cout << "D: ";
  s_hms(depo);
  kiir_i1();
}

void in_ch::kiir_i3()
{
  cout << "F: ";
  s_hms(run);
  kiir_i1();
  cout << "T-: ";
  s_hms(ij);
  kiir_i1();
  cout << "Cél idő: ";
}

void in_ch::kiir_i4()
{
  kiir_i2();
  s_hms(swim + cycle + depo);
  cout << "Ú+B+D: ";
  kiir_i1();
  kiir_i3();
  s_hms(sum);
  kiir_i1();
  cout << "Kategória: " << kat << endl;
}

/*tri_race& tri_race::kiir_cel()
 { kiir_i2(); kiir_i3(); kiir_i1(); return *this; }*/

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

tri_race &tri_race::setSum(int t)
{
  sum = swim + cycle + run + depo - t;
  return *this;
}

void mind1(in_ch *x_tri)
{
  cout << endl;
  in_gr_ch *rp = dynamic_cast<in_gr_ch *>(x_tri);
  if (rp != nullptr)
  {
    cout << "\nUnoka ";
  }
  else
  {
    in_ch *rp = dynamic_cast<in_ch *>(x_tri);
    if (rp != nullptr)
    {
      cout << "\nGyerek ";
    }
    else
    {
      tri_race *rp = dynamic_cast<tri_race *>(x_tri);
      cout << "\nSzülő ";
    }
  }
  cout << "rajt idő: ";
  x_tri->kiir_i1();
  x_tri->setSum(x_tri->getIj()).kiir_cel();
}

void felsz(tri_race *x_tri)
{
  delete x_tri;
  cout << x_tri << endl;
  x_tri = 0;
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  in_ch *alap = new in_ch;
  cout << "alap = " << alap << endl; // "h_m_s"-sel lehet!
  in_ch *A_tri = new in_ch("M_V_1357", 1200, 4200, 2300, 123, 60, 6);
  cout << "A_tri = " << A_tri << endl;
  in_ch *B_tri = new in_ch("V_G_2468", 1300, 4300, 2400, 125, 0, 6);
  cout << "B_tri = " << B_tri << endl;
  in_ch *C_tri = new in_ch("B_G_9048", 1400, 4400, 2400, 130, 90, 6);
  cout << "C_tri = " << C_tri << endl;
  in_ch *D_tri = new in_ch("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  cout << "D_tri = " << D_tri << endl;
  in_ch *E_tri = new in_gr_ch("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
  cout << "E_tri = " << E_tri << endl;
  mind1(alap);
  mind1(A_tri);
  mind1(B_tri);
  mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri);
  felsz(E_tri);
  felsz(D_tri);
  felsz(C_tri);
  felsz(B_tri);
  felsz(A_tri);
  felsz(alap);
  return 0;
}
/***************************************************************************************/
multi_in / 2 = > / 1 - es átdolgozása
/********* Decl.hpp ************/
#pragma once
#include <iostream>

                     using namespace std;

class tri_race
{
  string lic;
  int swim, cycle, run, depo, ij, sum;

public:
  tri_race() : sum(0)
  {
    lic = "--------";
    swim = 0;
    cycle = 0;
    run = 0;
    depo = 0;
    ij = 0;
    cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött: ";
  }
  tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0)
  {
    lic = lc;
    swim = sw;
    cycle = cyc;
    run = rn;
    depo = dp;
    ij = t;
    cout << "\nA paraméteres szülő-adatszerkezet létrejött: ";
  }
  int getIj() const { return ij; }
  string getLic() const { return lic; }
  int getSwim() const { return swim; }
  int getCycle() const { return cycle; }
  int getRun() const { return run; }
  int getDepo() const { return depo; }
  int getSum() const { return sum; }
  virtual tri_race &kiir_cel() = 0;
  tri_race &setSum(int t);
  virtual ~tri_race()
  {
    cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét: ";
  }
};

class h_m_s
{
  const int oRA, pRC;
  int h, p, mp;

public:
  h_m_s() : oRA(3600), pRC(60), h(0), p(0), mp(0)
  {
    cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: ";
  }
  void kiir_i1() const;
  void s_hms(int s)
  {
    h = s / oRA;
    p = (s % oRA) / pRC;
    mp = (s % oRA) % pRC;
  }
  virtual h_m_s &kiir_cel() = 0;
  ~h_m_s()
  {
    cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét: ";
  }
};

class in_ch : public tri_race, public h_m_s
{
  int kat;

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
  void kiir_i4();
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

void mind1(in_ch *x_tri);
void felsz(tri_race *x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void h_m_s::kiir_i1() const
{
  cout << h << ":" << p << ":" << mp << " [h:m:s]\n";
}

void in_ch::kiir_i4()
{
  cout << "Licence: " << getLic() << "\nÚ: ";
  s_hms(getSwim());
  kiir_i1();
  cout << "B: ";
  s_hms(getCycle());
  kiir_i1();
  cout << "D: ";
  s_hms(getDepo());
  kiir_i1();
  s_hms(getSwim() + getCycle() + getDepo());
  cout << "Ú+B+D: ";
  kiir_i1();
  cout << "F: ";
  s_hms(getRun());
  kiir_i1();
  cout << "T-: ";
  s_hms(getIj());
  kiir_i1();
  cout << "Cél idő: ";
  s_hms(getSum());
  kiir_i1();
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

tri_race &tri_race::setSum(int t)
{
  sum = swim + cycle + run + depo - t;
  return *this;
}

void mind1(in_ch *x_tri)
{
  cout << endl;
  in_gr_ch *rp = dynamic_cast<in_gr_ch *>(x_tri);
  if (rp != nullptr)
  {
    cout << "\nUnoka ";
  }
  else
  {
    in_ch *rp = dynamic_cast<in_ch *>(x_tri);
    if (rp != nullptr)
    {
      cout << "\nGyerek ";
    }
    else
    {
      tri_race *rp = dynamic_cast<tri_race *>(x_tri);
      cout << "\nSzülő ";
    }
  }
  cout << "rajt idő: ";
  x_tri->kiir_i1();
  x_tri->setSum(x_tri->getIj()).kiir_cel();
}

void felsz(tri_race *x_tri)
{
  delete x_tri;
  cout << x_tri << endl;
  x_tri = 0;
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  in_ch *alap = new in_ch;
  cout << "alap = " << alap << endl;
  in_ch *A_tri = new in_ch("M_V_1357", 1200, 4200, 2300, 123, 60, 6);
  cout << "A_tri = " << A_tri << endl;
  in_ch *B_tri = new in_ch("V_G_2468", 1300, 4300, 2400, 125, 0, 6);
  cout << "B_tri = " << B_tri << endl;
  in_ch *C_tri = new in_ch("B_G_9048", 1400, 4400, 2400, 130, 90, 6);
  cout << "C_tri = " << C_tri << endl;
  in_ch *D_tri = new in_ch("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  cout << "D_tri = " << D_tri << endl;
  in_ch *E_tri = new in_gr_ch("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
  cout << "E_tri = " << E_tri << endl;
  mind1(alap);
  mind1(A_tri);
  mind1(B_tri);
  mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri);
  felsz(E_tri);
  felsz(D_tri);
  felsz(C_tri);
  felsz(B_tri);
  felsz(A_tri);
  felsz(alap);
  return 0;
}
/***************************************************************************************/
multi_in / 3 = > / 2 - es tagosztályosítása, védettség növelése
/********* Decl.hpp ************/
#pragma once
#include <iostream>

    using namespace std;

class tri_race
{
  int sum;

protected:
  class memb /* tagok osztály */
  {
    string lic;
    int swim, cycle, run, depo, ij;

  public: // protected?
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
  int h, p, mp;

protected:
  h_m_s() : oRA(3600), pRC(60), h(0), p(0), mp(0)
  {
    cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött: ";
  }
  void s_hms(int s)
  {
    h = s / oRA;
    p = (s % oRA) / pRC;
    mp = (s % oRA) % pRC;
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

void mind1(in_ch *x_tri);
void felsz(tri_race *x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void h_m_s::kiir_i1() const
{
  cout << h << ":" << p << ":" << mp << " [h:m:s]\n";
}

void in_ch::kiir_i4()
{
  cout << "Licence: " << tagok.getLic() << "\nÚ: ";
  s_hms(tagok.getSwim());
  kiir_i1();
  cout << "B: ";
  s_hms(tagok.getCycle());
  kiir_i1();
  cout << "D: ";
  s_hms(tagok.getDepo());
  kiir_i1();
  s_hms(tagok.getSwim() + tagok.getCycle() + tagok.getDepo());
  cout << "Ú+B+D: ";
  kiir_i1();
  cout << "F: ";
  s_hms(tagok.getRun());
  kiir_i1();
  cout << "T-: ";
  s_hms(tagok.getIj());
  kiir_i1();
  cout << "Cél idő: ";
  s_hms(getSum());
  kiir_i1();
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

void mind1(in_ch *x_tri)
{
  cout << endl;
  in_gr_ch *rp = dynamic_cast<in_gr_ch *>(x_tri);
  if (rp != nullptr)
  {
    cout << "\nUnoka ";
  }
  else
  {
    in_ch *rp = dynamic_cast<in_ch *>(x_tri);
    if (rp != nullptr)
    {
      cout << "\nGyerek ";
    }
    else
    {
      tri_race *rp = dynamic_cast<tri_race *>(x_tri);
      cout << "\nSzülő ";
    }
  }
  cout << "rajt idő: ";
  x_tri->kiir_i1();
  x_tri->setSum().kiir_cel();
}

void felsz(tri_race *x_tri)
{
  delete x_tri;
  cout << x_tri << endl;
  x_tri = 0;
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  in_ch *alap = new in_ch;
  cout << "alap = " << alap << endl;
  in_ch *A_tri = new in_ch("M_V_1357", 1200, 4200, 2300, 123, 60, 6);
  cout << "A_tri = " << A_tri << endl;
  in_ch *B_tri = new in_ch("V_G_2468", 1300, 4300, 2400, 125, 0, 6);
  cout << "B_tri = " << B_tri << endl;
  in_ch *C_tri = new in_ch("B_G_9048", 1400, 4400, 2400, 130, 90, 6);
  cout << "C_tri = " << C_tri << endl;
  in_ch *D_tri = new in_ch("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  cout << "D_tri = " << D_tri << endl;
  in_ch *E_tri = new in_gr_ch("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
  cout << "E_tri = " << E_tri << endl;
  mind1(alap);
  mind1(A_tri);
  mind1(B_tri);
  mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri);
  felsz(E_tri);
  felsz(D_tri);
  felsz(C_tri);
  felsz(B_tri);
  felsz(A_tri);
  felsz(alap);
  return 0;
}
/***************************************************************************************/