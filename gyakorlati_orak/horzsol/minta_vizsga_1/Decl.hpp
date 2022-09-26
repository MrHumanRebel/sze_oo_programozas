#include <iostream>
#include "1.cpp"

class tri_race
{
private:
    char azonosito;
    int swim;
    int cycle;
    int run;
    int depo;
    int correction;

public:
    alap() : ora(0), perc(0) // Alapértelmezett konstruktor + inicializáló lista
    {
        azonosito = "--------";
        swim = 0;
        cycle = 0;
        run = 0;
        depo = 0;
        correction = 0;
    }
    alap(char az, int sw, int cy, int ru, int de, int co) : ora(0), perc(0) // Alapérték beállító konstruktor + inicializáló lista
    {
        azonosito = az;
        swim = sw;
        cycle = cy;
        run = ru;
        depo = de;
        correction = co;
    }
    ~tri_race() // Destruktor
    {
        cout << "A törléseket elvégeztem\n";
    }
    // Getter
    int getIj() { return ij; } // Idő jóváírás getter
    // Setter
    tri_race &setSum(int sum);
};
