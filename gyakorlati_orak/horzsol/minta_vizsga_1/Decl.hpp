#include <iostream>
using namespace std;

class tri_race
{
private:
    // Alap változó lista
    char azonosito;
    int swim;
    int cycle;
    int run;
    int depo;
    int correction;
    const int ora;
    const int perc;

public:
    // Alapértelmezett konstruktor + inicializáló lista
    tri_race() : ora(3600), perc(60)
    {
        azonosito = "---------";
        swim = 0;
        cycle = 0;
        run = 0;
        depo = 0;
        correction = 0;
    }

    // Alapérték beállító konstruktor + inicializáló lista
    tri_race(char az, int sw, int cy, int ru, int de, int co) : ora(3600), perc(60)
    {
        azonosito = az;
        swim = sw;
        cycle = cy;
        run = ru;
        depo = de;
        correction = co;
    }

    // Destruktor
    ~tri_race()
    {
        cout << "A törléseket elvégeztem\n";
    }

    // Getters
    int getIj() const // Fontos hogy const legyen, ne legyen a művelet után módosítható a memóriában
    {
        return correction; // Idő jóváírás getter
    }

    // Setters
    int setSum(int sw, int cy, int ru, int de, int co) const // Fontos hogy const legyen, ne legyen a művelet után módosítható a memóriában
    {
        int sum = sw + cy + ru + de - co;
        return sum;
    };

    // Kiírások

    void kiir_rajt(int i, int sum, int sw, int cy, int ru, int de, int co) const; // Fontos hogy const legyen, ne legyen a művelet után módosítható a memóriában

    void kiir_cel(int i, int sum) const; // Fontos hogy const legyen, ne legyen a művelet után módosítható a memóriában
};
