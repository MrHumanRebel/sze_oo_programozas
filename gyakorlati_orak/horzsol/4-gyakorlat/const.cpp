const / 1 - 2(const objektum)-3(ref arg + Destruktor ill.const arg) using namespace std;

class sor_minta /* Osztály deklarációja */
{
private:
  char kar;     /* kiirandó karakter */
  int ism;      /* soron belüli ismétlődések száma */
  int sor;      /* sorok száma, amennyiben megjelenjen */
  const int sK; // sK=5;
public:
  sor_minta() : sK(4)
  {
    kar = 'A';
    ism = 1;
    sor = 1;
  }                                          /* Alapértelmezett konstruktor + inicializáló lista  */
  sor_minta(char kr, int im, int sr) : sK(4) /* Alapérték beállító konstruktor + inicializáló lista */
  {
    kar = kr;
    ism = im;
    sor = sr;
  }
  void kiir(int i) /*const*/;
  /*~sor_minta()                                        Destruktor
     { cout << "A törléseket elvégeztem\n"; } */
  int getIsm() { return ism; }
  sor_minta &setIsm(int v_im);
  sor_minta &setSor(int v_sr);
  sor_minta &setKar(char v_kr);
  int getsK() /*const*/ { return sK; }
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i) /*const*/
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
  if ((ism + v_im) > 0 and (ism + v_im) <= 10)
    ism += v_im;
  else
    ism = 10;
  return *this;
}
sor_minta &sor_minta::setSor(int v_sr)
{
  if ((sor + v_sr) > 0 and (sor + v_sr) <= sK)
    sor += v_sr;
  else
    sor = sK;
  return *this;
}
sor_minta &sor_minta::setKar(char v_kr)
{
  if (v_kr != kar)
    kar = v_kr;
  else
    kar = '!';
  return *this;
}

void mind(/*const*/ sor_minta /*&*/ nyzj, sor_minta /*&*/ es, sor_minta /*&*/ zzj, int const s_K)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < s_K; i++) /* Sorok kiírása */
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
                                                                  // const sor_minta alap;
  mind(nyzj, es, zzj, alap.getsK());
  es.setIsm(14).setSor(4).setKar('&');
  mind(nyzj, es, zzj, alap.getsK());
  return 0;
}
/***************************************************************************************/
const / 1 - 2(const objektum)-3(ref arg + Destruktor ill.const arg)
                Esetek kifejtése
    /********* Decl.hpp ************/
    using namespace std;

class sor_minta /* Osztály deklarációja */
{
private:
  char kar;     /* kiirandó karakter */
  int ism;      /* soron belüli ismétlődések száma */
  int sor;      /* sorok száma, amennyiben megjelenjen */
  const int sK; // sK=5;
public:
  sor_minta() : sK(4)
  {
    kar = 'A';
    ism = 1;
    sor = 1;
  }                                          /* Alapértelmezett konstruktor + inicializáló lista  */
  sor_minta(char kr, int im, int sr) : sK(4) /* Alapérték beállító konstruktor + inicializáló lista */
  {
    kar = kr;
    ism = im;
    sor = sr;
  }
  void kiir(int i) const;
  ~sor_minta()
  {
    cout << "A törléseket elvégeztem\n";
  }
  int getIsm() const { return ism; }
  sor_minta &setIsm(int v_im);
  sor_minta &setSor(int v_sr);
  sor_minta &setKar(char v_kr);
  int getsK() const { return sK; }
};
/***************************************************************************************/
#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i) const
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
  if ((ism + v_im) > 0 and (ism + v_im) <= 10)
    ism += v_im;
  else
    ism = 10;
  return *this;
}
sor_minta &sor_minta::setSor(int v_sr)
{
  if ((sor + v_sr) > 0 and (sor + v_sr) <= sK)
    sor += v_sr;
  else
    sor = sK;
  return *this;
}
sor_minta &sor_minta::setKar(char v_kr)
{
  if (v_kr != kar)
    kar = v_kr;
  else
    kar = '!';
  return *this;
}

void mind(const sor_minta &nyzj, const sor_minta &es, const sor_minta &zzj, int const s_K)
{
  cout << "\n"
       << endl;
  for (int i = 0; i < s_K; i++) /* Sorok kiírása */
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
  sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1); /* Objektumok példányosítása, beállítása */
  const sor_minta alap;
  mind(nyzj, es, zzj, alap.getsK());
  es.setIsm(14).setSor(4).setKar('@');
  mind(nyzj, es, zzj, alap.getsK());
  return 0;
}
/***************************************************************************************/
