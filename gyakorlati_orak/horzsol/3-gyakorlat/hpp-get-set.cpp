h - g - s - k / 1
                /********* Decl.hpp ************/
                using namespace std;

#define SK 4 /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
{
private:
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
  int v_m;  /* változtatás mértéke az "ism"-re */
public:
  sor_minta()
  {
    kar = 'A';
    ism = 1;
    sor = 1, v_m = 0;
    cout << "\n Alapértelmezett konstruktor\n";
  }                                  /* Alapértelmezett konstruktor */
  sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
  {
    kar = kr;
    ism = im;
    sor = sr;
    cout << "\n Alapérték beállító konstruktor\n";
  }
  void kiir(int i);
  void elemek() { cout << kar << ism << sor << endl; }
  void v_i();
  /*~sor_minta()                                        Destruktor
     { cout << "A program hibátlanul lefutott!\n"; } */
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
  for (int j = 0; j < ism; j++) /* Soron belüli kiírás */
  {
    if (i < sor)
      cout << kar;
    else
      cout << "-";
  }
}

void sor_minta::v_i()
{
  do
  {
    cout << "\n Kérem a változtatás mértékét [+/-]: ";
    cin >> v_m;
  } while ((ism + v_m) <= 0);
  ism += v_m;
}

void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < SK; i++) /* Sorok kiírása */
  {
    nyzj.kiir(i);
    es.kiir(i);
    zzj.kiir(i);
    cout << "\n"
         << endl;
  }
}

int main(void)
{
  sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), alap; /* Objektumok példányosítása, beállítása */
  alap.elemek();
  es.elemek();
  cout << "\n"
       << endl;
  mind(nyzj, es, zzj);
  es.v_i();
  mind(nyzj, es, zzj);
  return 0;
}
/***************************************************************************************/
h - g - s - k / 2
                /********* Decl.hpp ************/
                using namespace std;

#define SK 4 /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
{
private:
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
  int v_m;  /* változtatás mértéke az "ism"-re */
public:
  sor_minta()
  {
    kar = 'A';
    ism = 1;
    sor = 1, v_m = 0;
  }                                  /* Alapértelmezett konstruktor */
  sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
  {
    kar = kr;
    ism = im;
    sor = sr;
  }
  void kiir(int i);
  void v_i();
  /*~sor_minta()                                        Destruktor
     { cout << "A program hibátlanul lefutott!\n"; } */
  int getIsm() { return ism; }
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
  for (int j = 0; j < ism; j++) /* Soron belüli kiírás */
  {
    if (i < sor)
      cout << kar;
    else
      cout << "-";
  }
}

void sor_minta::v_i()
{
  do
  {
    cout << "\n Kérem a változtatás mértékét [+/-]: ";
    cin >> v_m;
  } while ((ism + v_m) <= 0);
  ism += v_m;
}

void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < SK; i++) /* Sorok kiírása */
  {
    nyzj.kiir(i);
    es.kiir(i);
    zzj.kiir(i);
    cout << "\n"
         << endl;
  }
}

int main(void)
{
  sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), alap; /* Objektumok példányosítása, beállítása */
  cout << alap.getIsm() << "\n"
       << es.getIsm() << "\n"
       << endl;
  mind(nyzj, es, zzj);
  es.v_i();
  mind(nyzj, es, zzj);
  return 0;
}
/***************************************************************************************/
h - g - s - k / 3
                /********* Decl.hpp ************/
                using namespace std;

#define SK 4 /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
{
private:
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
  int v_m;  /* változtatás mértéke az "ism"-re */
public:
  sor_minta()
  {
    kar = 'A';
    ism = 1;
    sor = 1, v_m = 0;
  }                                  /* Alapértelmezett konstruktor */
  sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
  {
    kar = kr;
    ism = im;
    sor = sr;
  }
  void kiir(int i);
  /*~sor_minta()                                        Destruktor
     { cout << "A program hibátlanul lefutott!\n"; } */
  int getIsm() { return ism; }
  void setIsm(int im);
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
  for (int j = 0; j < ism; j++) /* Soron belüli kiírás */
  {
    if (i < sor)
      cout << kar;
    else
      cout << "-";
  }
}

void sor_minta::setIsm(int im)
{
  do
  {
    cout << "\n Kérem a változtatás mértékét [1-10]: " << im << " +-= ";
    cin >> v_m;
  } while ((im + v_m) <= 0);
  ism += v_m;
}

void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < SK; i++) /* Sorok kiírása */
  {
    nyzj.kiir(i);
    es.kiir(i);
    zzj.kiir(i);
    cout << "\n"
         << endl;
  }
}

int main(void)
{
  sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), alap; /* Objektumok példányosítása, beállítása */
  cout << alap.getIsm() << "\n"
       << es.getIsm() << "\n"
       << endl;
  mind(nyzj, es, zzj);
  es.setIsm(es.getIsm());
  mind(nyzj, es, zzj);
  return 0;
}
/***************************************************************************************/
h - g - s - k / 4
                /********* Decl.hpp ************/
                using namespace std;

#define SK 4 /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
{
private:
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
  int v_m;  /* változtatás mértéke az "ism"-re */
public:
  sor_minta()
  {
    kar = 'A';
    ism = 1;
    sor = 1, v_m = 0;
  }                                  /* Alapértelmezett konstruktor */
  sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
  {
    kar = kr;
    ism = im;
    sor = sr;
  }
  void kiir(int i);
  /*~sor_minta()                                        Destruktor
     { cout << "A program hibátlanul lefutott!\n"; } */
  int getIsm() { return ism; }
  sor_minta &setIsm(int im);
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
  for (int j = 0; j < ism; j++) /* Soron belüli kiírás */
  {
    if (i < sor)
      cout << kar;
    else
      cout << "-";
  }
}

sor_minta &sor_minta::setIsm(int im)
{
  do
  {
    cout << "\n Kérem a változtatás mértékét [1-10]: " << im << " +-= ";
    cin >> v_m;
  } while ((im + v_m) <= 0 or (im + v_m) > 10);
  ism += v_m;
  return *this;
}

void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < SK; i++) /* Sorok kiírása */
  {
    nyzj.kiir(i);
    es.kiir(i);
    zzj.kiir(i);
    cout << "\n"
         << endl;
  }
}

int main(void)
{
  sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), alap; /* Objektumok példányosítása, beállítása */
  cout << alap.getIsm() << "\n"
       << es.getIsm() << "\n"
       << endl;
  mind(nyzj, es, zzj);
  es.setIsm(es.getIsm());
  mind(nyzj, es, zzj);
  return 0;
}
/***************************************************************************************/
h - g - s - k / 5
                /********* Decl.hpp ************/
                using namespace std;

#define SK 4 /* Kiírandó sorok száma */

class sor_minta /* Osztály deklarációja */
{
private:
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
public:
  sor_minta()
  {
    kar = 'A';
    ism = 1;
    sor = 1;
  }                                  /* Alapértelmezett konstruktor */
  sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
  {
    kar = kr;
    ism = im;
    sor = sr;
  }
  void kiir(int i);
  /*~sor_minta()                                        Destruktor
     { cout << "A program hibátlanul lefutott!\n"; } */
  int getIsm() { return ism; }
  sor_minta &setIsm(int v_im);
  sor_minta &setSor(int v_sr);
  sor_minta &setKar(char v_kr);
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
  for (int j = 0; j < ism; j++) /* Soron belüli kiírás */
  {
    if (i < sor)
      cout << kar;
    else
      cout << "-";
  }
}

sor_minta &sor_minta::setIsm(int v_im)
{
  if ((ism + v_im) > 0 and (ism + v_im) < 11)
    ism += v_im;
  return *this;
}
sor_minta &sor_minta::setSor(int v_sr)
{
  if ((sor + v_sr) > 0 and (sor + v_sr) < 5)
    sor += v_sr;
  return *this;
}
sor_minta &sor_minta::setKar(char v_kr)
{
  if (v_kr != kar)
    kar = v_kr;
  return *this;
}

void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < SK; i++) /* Sorok kiírása */
  {
    nyzj.kiir(i);
    es.kiir(i);
    zzj.kiir(i);
    cout << "\n"
         << endl;
  }
}

int main(void)
{
  sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), alap; /* Objektumok példányosítása, beállítása */
  mind(nyzj, es, zzj);
  es.setIsm(4).setSor(-1).setKar('@');
  mind(nyzj, es, zzj);
  return 0;
}
/***************************************************************************************/
