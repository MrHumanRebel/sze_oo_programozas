din_cast / referenciával
/********* Decl.hpp ************/
#pragma once
#include <iostream>

    using namespace std;

class tri_race // szülő osztály deklarációja
{
protected:
  string lic;
  int swim, cycle, run, depo, ij, h, p, mp, sum;

private:
  const int oRA, pRC;

public:
  tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0)
  {
    lic = "--------";
    swim = 0;
    cycle = 0;
    run = 0;
    depo = 0;
    ij = 0;
    cout << "\nAz alapértelmezett objektum létrejött";
  }
  tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),
                                                                h(0), p(0), mp(0), sum(0)
  {
    lic = lc;
    swim = sw;
    cycle = cyc;
    run = rn;
    depo = dp;
    ij = t;
    cout << "\nA paraméteres objektum létrejött";
  }
  int getIj() const { return ij; }
  string getLic() const { return lic; }
  void kiir_i1() const;
  void kiir_i2() const;
  void kiir_i3() const;
  virtual tri_race &kiir_rajt();
  virtual tri_race &kiir_cel();
  tri_race &setSum(int t);
  virtual ~tri_race()
  {
    cout << "\nFelszabadítottam a szülő-objektum memóriacímét!";
  }
  tri_race(const tri_race &) = delete;
  tri_race &operator=(const tri_race &) = delete;
};

class in_ch : public tri_race // származtatott gyerek osztály deklarációja
{
  int kat;

public:
  in_ch() : tri_race() { kat = 0; }
  in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : tri_race(lc, sw, cyc, rn, dp, t) { kat = kt; }
  void kiir_i4() const;
  virtual in_ch &kiir_rajt();
  virtual in_ch &kiir_cel();
  ~in_ch()
  {
    cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét!";
  }
};

class in_gr_ch : public in_ch // származtatott unoka osztály deklarációja
{
private:
  char nem;

public:
  in_gr_ch() : in_ch(), nem('N') {}
  in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm) {}
  virtual in_gr_ch &kiir_rajt();
  virtual in_gr_ch &kiir_cel();
  ~in_gr_ch()
  {
    cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét!";
  }
};

void mind1(tri_race &x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void tri_race::kiir_i1() const
{
  cout << h << ":" << p << ":" << mp << " [h:m:s]\n";
}

void tri_race::kiir_i2() const
{
  cout << "Licence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo;
}

void tri_race::kiir_i3() const
{
  cout << "\nF: " << run << "\nT-: " << ij << "\nCél idő: ";
}

void in_ch::kiir_i4() const
{
  kiir_i2();
  cout << "\nÚ+B+D: " << swim + cycle + depo;
  kiir_i3();
  kiir_i1();
  cout << "Kategória: " << kat << endl;
}

tri_race &tri_race::kiir_rajt()
{
  cout << "\nSzülő rajt idő: ";
  kiir_i1();
  return *this;
}

tri_race &tri_race::kiir_cel()
{
  kiir_i2();
  kiir_i3();
  kiir_i1();
  return *this;
}

in_ch &in_ch::kiir_rajt()
{
  cout << "\nGyerek rajt idő: ";
  kiir_i1();
  return *this;
}

in_ch &in_ch::kiir_cel()
{
  kiir_i4();
  return *this;
}

in_gr_ch &in_gr_ch::kiir_rajt()
{
  cout << "\nUnoka rajt idő: ";
  kiir_i1();
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
  h = sum / oRA;
  p = (sum % oRA) / pRC;
  mp = (sum % oRA) % pRC;
  return *this;
}

void mind1(tri_race &x_tri)
{
  cout << endl;
  x_tri.kiir_rajt().setSum(x_tri.getIj()).kiir_cel();
  try
  {
    tri_race &rp = dynamic_cast<tri_race &>(x_tri); // in_ch
    cout << "\nSzülő objektum vagyok: " << rp.getLic() << endl;
    /*in_gr_ch& rp = dynamic_cast<in_gr_ch&>(x_tri);
    cout << "\nUnoka objektum vagyok: " << rp.getLic() << endl;*/
  }
  catch (bad_cast)
  {
    cout << "\nNem vagyok gyerek objektum!" << endl;
    /*cout << "\nNem vagyok unoka objektum!" << endl;
     try
      {
       in_ch& rp = dynamic_cast<in_ch&>(x_tri);
       cout << "Gyerek objektum vagyok: " << rp.getLic() << endl;
      }
     catch(bad_cast)
      {
       cout << "Nem vagyok gyerek objektum!" << endl;
       tri_race& rp = dynamic_cast<tri_race&>(x_tri);
       cout << "Szülő objektum vagyok: " << rp.getLic() << endl;
      }*/
  }
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  tri_race alap,
      A_tri("M_V_1357", 1200, 4200, 2300, 123, 60),
      B_tri("V_G_2468", 1300, 4300, 2400, 125, 0),
      C_tri("B_G_9048", 1400, 4400, 2400, 130, 90);
  in_ch D_tri("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  in_gr_ch E_tri("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
  mind1(alap);
  mind1(A_tri);
  mind1(B_tri);
  mind1(C_tri);
  mind1(D_tri);
  mind1(E_tri);
  return 0;
}
/***************************************************************************************/
din_cast / pointer - rel
/********* Decl.hpp ************/
#pragma once
#include <iostream>

    using namespace std;

class tri_race // szülő osztály deklarációja
{
protected:
  string lic;
  int swim, cycle, run, depo, ij, h, p, mp, sum;

private:
  const int oRA, pRC;

public:
  tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0)
  {
    lic = "--------";
    swim = 0;
    cycle = 0;
    run = 0;
    depo = 0;
    ij = 0;
    cout << "\nAz alapértelmezett szülő-objektum létrejött: ";
  }
  tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),
                                                                h(0), p(0), mp(0), sum(0)
  {
    lic = lc;
    swim = sw;
    cycle = cyc;
    run = rn;
    depo = dp;
    ij = t;
    cout << "\nA paraméteres szülő-objektum létrejött: ";
  }
  int getIj() const { return ij; }
  string getLic() const { return lic; }
  void kiir_i1() const;
  void kiir_i2() const;
  void kiir_i3() const;
  virtual tri_race &kiir_rajt();
  virtual tri_race &kiir_cel();
  tri_race &setSum(int t);
  virtual ~tri_race()
  {
    cout << "\nFelszabadítottam a szülő-objektum memóriacímét: ";
  }
  tri_race(const tri_race &) = delete;
  tri_race &operator=(const tri_race &) = delete;
};

class in_ch : public tri_race // származtatott gyerek osztály deklarációja
{
  int kat;

public:
  in_ch() : tri_race() { kat = 0; }
  in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : tri_race(lc, sw, cyc, rn, dp, t)
  {
    kat = kt;
    cout << "\nA paraméteres gyerek-objektum létrejött: ";
  }
  void kiir_i4() const;
  virtual in_ch &kiir_rajt();
  virtual in_ch &kiir_cel();
  virtual ~in_ch()
  {
    cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: ";
  }
};

class in_gr_ch : public in_ch // származtatott unoka osztály deklarációja
{
private:
  char nem;

public:
  in_gr_ch() : in_ch(), nem('N') {}
  in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : in_ch(lc, sw, cyc, rn, dp, t, kt), nem(nm)
  {
    cout << "\nA paraméteres unoka-objektum létrejött: ";
  }
  virtual in_gr_ch &kiir_rajt();
  virtual in_gr_ch &kiir_cel();
  virtual ~in_gr_ch()
  {
    cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét: ";
  }
};

void mind1(tri_race *x_tri);
void felsz(tri_race *x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void tri_race::kiir_i1() const
{
  cout << h << ":" << p << ":" << mp << " [h:m:s]\n";
}

void tri_race::kiir_i2() const
{
  cout << "Licence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo;
}

void tri_race::kiir_i3() const
{
  cout << "\nF: " << run << "\nT-: " << ij << "\nCél idő: ";
}

void in_ch::kiir_i4() const
{
  kiir_i2();
  cout << "\nÚ+B+D: " << swim + cycle + depo;
  kiir_i3();
  kiir_i1();
  cout << "Kategória: " << kat << endl;
}

tri_race &tri_race::kiir_rajt()
{
  cout << "\nSzülő rajt idő: ";
  kiir_i1();
  return *this;
}

tri_race &tri_race::kiir_cel()
{
  kiir_i2();
  kiir_i3();
  kiir_i1();
  return *this;
}

in_ch &in_ch::kiir_rajt()
{
  cout << "\nGyerek rajt idő: ";
  kiir_i1();
  return *this;
}

in_ch &in_ch::kiir_cel()
{
  kiir_i4();
  return *this;
}

in_gr_ch &in_gr_ch::kiir_rajt()
{
  cout << "\nUnoka rajt idő: ";
  kiir_i1();
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
  h = sum / oRA;
  p = (sum % oRA) / pRC;
  mp = (sum % oRA) % pRC;
  return *this;
}

void mind1(tri_race *x_tri)
{
  cout << endl;
  x_tri->kiir_rajt().setSum(x_tri->getIj()).kiir_cel();
  in_gr_ch *rp = dynamic_cast<in_gr_ch *>(x_tri);
  if (rp != nullptr)
  {
    cout << "\nUnoka objektum vagyok: " << rp->getLic() << endl;
  }
  else
  {
    cout << "\nNem vagyok unoka objektum!" << endl;
    in_ch *rp = dynamic_cast<in_ch *>(x_tri);
    if (rp != nullptr)
    {
      cout << "\nGyerek objektum vagyok: " << rp->getLic() << endl;
    }
    else
    {
      cout << "\nNem vagyok gyerek objektum!" << endl;
      tri_race *rp = dynamic_cast<tri_race *>(x_tri);
      cout << "\nSzülő objektum vagyok: " << rp->getLic() << endl;
    }
  }
}

void felsz(tri_race *x_tri)
{
  delete x_tri;
  cout << x_tri << endl;
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  tri_race *alap = new tri_race;
  cout << "alap = " << alap << endl;
  tri_race *A_tri = new tri_race("M_V_1357", 1200, 4200, 2300, 123, 60);
  cout << "A_tri = " << A_tri << endl;
  tri_race *B_tri = new tri_race("V_G_2468", 1300, 4300, 2400, 125, 0);
  cout << "B_tri = " << B_tri << endl;
  tri_race *C_tri = new tri_race("B_G_9048", 1400, 4400, 2400, 130, 90);
  cout << "C_tri = " << C_tri << endl;
  in_ch *D_tri = new in_ch("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  cout << "D_tri = " << D_tri << endl;
  in_gr_ch *E_tri = new in_gr_ch("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
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
din_cast / pointer - rel, kiir_rajt() kiváltással, absztrakt osztály
/********* Decl.hpp ************/
#pragma once
#include <iostream>

    using namespace std;

class tri_race
{
protected:
  string lic;
  int swim, cycle, run, depo, ij, h, p, mp, sum;

private:
  const int oRA, pRC;

public:
  tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0)
  {
    lic = "--------";
    swim = 0;
    cycle = 0;
    run = 0;
    depo = 0;
    ij = 0;
    cout << "\nAz alapértelmezett szülő-objektum létrejött: ";
  }
  tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),
                                                                h(0), p(0), mp(0), sum(0)
  {
    lic = lc;
    swim = sw;
    cycle = cyc;
    run = rn;
    depo = dp;
    ij = t;
    cout << "\nA paraméteres szülő-objektum létrejött: ";
  }
  int getIj() const { return ij; }
  string getLic() const { return lic; }
  void kiir_i1() const;
  void kiir_i2() const;
  void kiir_i3() const;
  virtual tri_race &kiir_cel(); // =0; // absztrakt osztály, tisztán virtuális
  tri_race &setSum(int t);
  virtual ~tri_race()
  {
    cout << "\nFelszabadítottam a szülő-objektum memóriacímét: ";
  }
  tri_race(const tri_race &) = delete;
  tri_race &operator=(const tri_race &) = delete;
};

class in_ch : public tri_race
{
  int kat;

public:
  in_ch() : tri_race() { kat = 0; }
  in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : tri_race(lc, sw, cyc, rn, dp, t)
  {
    kat = kt;
    cout << "\nA paraméteres gyerek-objektum létrejött: ";
  }
  void kiir_i4() const;
  virtual in_ch &kiir_cel();
  virtual ~in_ch()
  {
    cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét: ";
  }
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

void mind1(tri_race *x_tri);
void felsz(tri_race *x_tri);

/*********** 1.cpp *************/
#include "Decl.hpp"

void tri_race::kiir_i1() const
{
  cout << h << ":" << p << ":" << mp << " [h:m:s]\n";
}

void tri_race::kiir_i2() const
{
  cout << "Licence: " << lic << "\nÚ: " << swim << "\nB: " << cycle << "\nD: " << depo;
}

void tri_race::kiir_i3() const
{
  cout << "\nF: " << run << "\nT-: " << ij << "\nCél idő: ";
}

void in_ch::kiir_i4() const
{
  kiir_i2();
  cout << "\nÚ+B+D: " << swim + cycle + depo;
  kiir_i3();
  kiir_i1();
  cout << "Kategória: " << kat << endl;
}

tri_race &tri_race::kiir_cel()
{
  kiir_i2();
  kiir_i3();
  kiir_i1();
  return *this;
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
  h = sum / oRA;
  p = (sum % oRA) / pRC;
  mp = (sum % oRA) % pRC;
  return *this;
}

void mind1(tri_race *x_tri)
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
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  tri_race *alap = new tri_race;
  cout << "alap = " << alap << endl;
  tri_race *A_tri = new tri_race("M_V_1357", 1200, 4200, 2300, 123, 60);
  cout << "A_tri = " << A_tri << endl;
  tri_race *B_tri = new tri_race("V_G_2468", 1300, 4300, 2400, 125, 0);
  cout << "B_tri = " << B_tri << endl;
  tri_race *C_tri = new tri_race("B_G_9048", 1400, 4400, 2400, 130, 90);
  cout << "C_tri = " << C_tri << endl;
  in_ch *D_tri = new in_ch("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
  cout << "D_tri = " << D_tri << endl;
  in_gr_ch *E_tri = new in_gr_ch("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
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