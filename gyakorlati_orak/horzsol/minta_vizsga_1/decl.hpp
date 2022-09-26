#include <iostream>
using namespace std;

class tri_race
{
private:
    // Alap változó lista
    string azonosito;
    int swim;
    int cycle;
    int run;
    int depo;
    int correction;
    int sum;
    int hour;
    int sec;
    int msec;
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
        sum = 0;
    }

    // Alapérték beállító konstruktor + inicializáló lista
    tri_race(string az, int sw, int cy, int ru, int de, int com) : ora(3600), perc(60)
    {
        azonosito = az;
        swim = sw;
        cycle = cy;
        run = ru;
        depo = de;
        correction = com;
    }

    // Destruktor
    ~tri_race()
    {
        cout << "A törléseket elvégeztem\n";
    }

    // Getters
    int getIj();

    // Setters
    tri_race &setSum(int co);

    // Kiírások

    tri_race &kiir_rajt();
    tri_race &kiir_cel();
};
