din - Destr / 1
/********* Decl.hpp ************/
#pragma once
#include <iostream>

          using namespace std;

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
    }                                  /* Alapértelmezett konstruktor  */
    sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor  */
    {
        kar = kr;
        ism = im;
        sor = sr;
    }
    int getIsm() const { return ism; }
    int getSor() const { return sor; }
    char getKar() const { return kar; }
    sor_minta &setIsm(int v_im);
    sor_minta &setSor(int v_sr);
    sor_minta &setKar(char v_kr);
};

class dm_kiir
{
private:
    sor_minta *mutat;
    const int sK;

public:
    dm_kiir() : sK(4) /* Alapértelmezett konstruktor + inicializáló lista  */
    {
        mutat = new sor_minta();
        /*cout << "Az alapértelmezett objektum címe: ";
        cout << mutat << endl;*/
    }
    dm_kiir(char kr, int im, int sr) : sK(4) /* Alapérték beállító konstruktor + inicializáló lista */
    {
        mutat = new sor_minta(kr, im, sr);
        /*cout << "A paraméteres objektum címe: ";
        cout << mutat << endl;*/
    }
    void kiir(int i) const;
    int getsK() const { return sK; }
    sor_minta *getMutat() const { return mutat; }
    ~dm_kiir() /* Destruktor */
    {
        delete mutat;
        /*cout << "Felszabadítottam az objektum memóriacímét, amely a: ";
        cout << mutat << endl;*/
    }
};

// void mind(const dm_kiir& nyzj, dm_kiir& es, dm_kiir& zzj, int s_K);

/*********** 1.cpp *************/
#include "Decl.hpp"

void dm_kiir::kiir(int i) const
{
    for (int j = 0; j < mutat->getIsm(); j++) /* Soron belüli kiírás */
    {
        if (i < mutat->getSor())
            cout << mutat->getKar();
        else
            cout << "-";
    }
}

sor_minta &sor_minta::setIsm(int v_im)
{
    if ((ism + v_im) > 0 and (ism + v_im) < 11)
        ism += v_im;
    else
        ism = 10;
    return *this;
}
sor_minta &sor_minta::setSor(int v_sr)
{
    if ((sor + v_sr) > 0 and (sor + v_sr) < 5)
        sor += v_sr;
    else
        sor = 4;
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

void mind(const dm_kiir &nyzj, dm_kiir &es, dm_kiir &zzj, int s_K)
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

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
    dm_kiir nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1) /*, alap*/; /* Objektumok példányosítása, beállítása */
    const dm_kiir alap;
    mind(nyzj, es, zzj, alap.getsK());
    es.getMutat()->setIsm(4).setSor(-1).setKar('@');
    // es.getIsm();
    mind(nyzj, es, zzj, alap.getsK());
    return 0;
}
/***************************************************************************************/
copy &assignment constr / 1
/********* Decl.hpp ************/
#pragma once
#include <iostream>

    using namespace std;

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
    }                                  /* Alapértelmezett konstruktor  */
    sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
    {
        kar = kr;
        ism = im;
        sor = sr;
    }
    int getIsm() const { return ism; }
    int getSor() const { return sor; }
    char getKar() const { return kar; }
    sor_minta &setIsm(int v_im);
    sor_minta &setSor(int v_sr);
    sor_minta &setKar(char v_kr);
};

class dm_kiir
{
private:
    sor_minta *mutat;
    const int sK;

public:
    dm_kiir() : sK(4) /* Alapértelmezett konstruktor + inicializáló lista  */
    {
        mutat = new sor_minta();
        cout << "Az alapértelmezett objektumot létrehoztam: ";
        cout << mutat << endl;
    }
    dm_kiir(char kr, int im, int sr) : sK(4) /* Alapérték beállító konstruktor + inicializáló lista */
    {
        mutat = new sor_minta(kr, im, sr);
        cout << "A paraméteres objektumot létrehoztam: ";
        cout << mutat << endl;
    }
    void kiir(int i) const;
    int getsK() const { return sK; }
    sor_minta *getMutat() const { return mutat; }
    ~dm_kiir() /* Destruktor */
    {
        delete mutat;
        cout << "Felszabadítottam az objektum memóriacímét, amely a: ";
        cout << mutat << endl;
    }
    // dm_kiir(const dm_kiir&) = delete;
    /* dm_kiir(const dm_kiir& masolat) : sK(4)  //Copy konstruktor + inicializáló lista
     {
      mutat = new sor_minta(masolat.mutat->getKar(), masolat.mutat->getIsm(), masolat.mutat->getSor());
      cout << "A klón objektumot létrehoztam: ";
      cout << mutat << endl;
     } */
    // dm_kiir& operator=(const dm_kiir&) = delete;
    /*dm_kiir& operator=(const dm_kiir& felir)  //Assignment konstruktor
      {
       delete mutat;
       cout << "Felszabadítottam a felülírandó objektum memóriacímét, amely a: ";
       cout << mutat << endl;
       mutat = new sor_minta(felir.mutat->getKar(), felir.mutat->getIsm(), felir.mutat->getSor());
       cout << "A felülírt objektumot létrehoztam: ";
       cout << mutat << endl;
       return *this;
      }  */
};

void mind(const dm_kiir &nyzj, dm_kiir &es, dm_kiir &zzj, int s_K);

/*********** 1.cpp *************/
#include "Decl.hpp"

void dm_kiir::kiir(int i) const
{
    for (int j = 0; j < mutat->getIsm(); j++) /* Soron belüli kiírás */
    {
        if (i < mutat->getSor())
            cout << mutat->getKar();
        else
            cout << "-";
    }
}

sor_minta &sor_minta::setIsm(int v_im)
{
    if ((ism + v_im) > 0 and (ism + v_im) < 11)
        ism += v_im;
    else
        ism = 10;
    return *this;
}
sor_minta &sor_minta::setSor(int v_sr)
{
    if ((sor + v_sr) > 0 and (sor + v_sr) < 5)
        sor += v_sr;
    else
        sor = 4;
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

void mind(const dm_kiir &nyzj, dm_kiir &es, dm_kiir &zzj, int s_K)
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

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
    dm_kiir nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1) /* , felul , alap*/; /* Objektumok példányosítása, beállítása */
    const dm_kiir alap;
    dm_kiir clone(nyzj);
    mind(nyzj /*felul*/, es, clone, alap.getsK());
    // felul =(zzj);
    // mind(felul,es,clone,alap.getsK());
    es.getMutat()->setIsm(4).setSor(-1).setKar('@');
    // felul.getMutat()->setIsm(4).setSor(2).setKar('F');
    mind(nyzj /*felul*/, es, clone, alap.getsK());
    return 0;
}
/***************************************************************************************/
copy &assignment constr : eredmény
/********* Decl.hpp ************/
#pragma once
#include <iostream>

                          using namespace std;

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
    }                                  /* Alapértelmezett konstruktor  */
    sor_minta(char kr, int im, int sr) /* Alapérték beállító konstruktor */
    {
        kar = kr;
        ism = im;
        sor = sr;
    }
    int getIsm() const { return ism; }
    int getSor() const { return sor; }
    char getKar() const { return kar; }
    sor_minta &setIsm(int v_im);
    sor_minta &setSor(int v_sr);
    sor_minta &setKar(char v_kr);
};

class dm_kiir
{
private:
    sor_minta *mutat;
    const int sK;

public:
    dm_kiir() : sK(4) /* Alapértelmezett konstruktor + inicializáló lista  */
    {
        mutat = new sor_minta();
        cout << "Az alapértelmezett objektumot létrehoztam: ";
        cout << mutat << endl;
    }
    dm_kiir(char kr, int im, int sr) : sK(4) /* Alapérték beállító konstruktor + inicializáló lista */
    {
        mutat = new sor_minta(kr, im, sr);
        cout << "A paraméteres objektumot létrehoztam: ";
        cout << mutat << endl;
    }
    void kiir(int i) const;
    int getsK() const { return sK; }
    sor_minta *getMutat() const { return mutat; }
    ~dm_kiir() /* Destruktor */
    {
        delete mutat;
        cout << "Felszabadítottam az objektum memóriacímét, amely a: ";
        cout << mutat << endl;
    }
    // dm_kiir(const dm_kiir&) = delete;
    dm_kiir(const dm_kiir &masolat) : sK(4) // Copy konstruktor + inicializáló lista
    {
        mutat = new sor_minta(masolat.mutat->getKar(), masolat.mutat->getIsm(), masolat.mutat->getSor());
        cout << "A klón objektumot létrehoztam: ";
        cout << mutat << endl;
    }
    // dm_kiir& operator=(const dm_kiir&) = delete;
    dm_kiir &operator=(const dm_kiir &felir) // Assignment konstruktor
    {
        delete mutat;
        cout << "Felszabadítottam a felülírandó objektum memóriacímét, amely a: ";
        cout << mutat << endl;
        mutat = new sor_minta(felir.mutat->getKar(), felir.mutat->getIsm(), felir.mutat->getSor());
        cout << "A felülírt objektumot létrehoztam: ";
        cout << mutat << endl;
        return *this;
    }
};

void mind(const dm_kiir &nyzj, dm_kiir &es, dm_kiir &zzj, int s_K);

/*********** 1.cpp *************/
#include "Decl.hpp"

void dm_kiir::kiir(int i) const
{
    for (int j = 0; j < mutat->getIsm(); j++) /* Soron belüli kiírás */
    {
        if (i < mutat->getSor())
            cout << mutat->getKar();
        else
            cout << "-";
    }
}

sor_minta &sor_minta::setIsm(int v_im)
{
    if ((ism + v_im) > 0 and (ism + v_im) < 11)
        ism += v_im;
    else
        ism = 10;
    return *this;
}
sor_minta &sor_minta::setSor(int v_sr)
{
    if ((sor + v_sr) > 0 and (sor + v_sr) < 5)
        sor += v_sr;
    else
        sor = 4;
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

void mind(const dm_kiir &nyzj, dm_kiir &es, dm_kiir &zzj, int s_K)
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

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
    dm_kiir nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), felul /* , alap*/; /* Objektumok példányosítása, beállítása */
    const dm_kiir alap;
    dm_kiir clone(nyzj);
    mind(felul, es, clone, alap.getsK());
    felul = (zzj);
    mind(felul, es, clone, alap.getsK());
    felul.getMutat()->setIsm(4).setSor(2).setKar('F');
    mind(felul, es, clone, alap.getsK());
    return 0;
}
/***************************************************************************************/