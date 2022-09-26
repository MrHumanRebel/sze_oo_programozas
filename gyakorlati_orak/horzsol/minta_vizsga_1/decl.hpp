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
    int minute;
    int sec;
    const int metric_hour;
    const int metric_min;

public:
    // Alapértelmezett konstruktor + inicializáló lista
    tri_race() : metric_hour(3600), metric_min(60)
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
    tri_race(string azonosito, int swim, int cycle, int run, int depo, int correction) : metric_hour(3600), metric_min(60)
    {
        this->azonosito = azonosito;
        this->swim = swim;
        this->cycle = cycle;
        this->run = run;
        this->depo = depo;
        this->correction = correction;
    }

    // Destruktor
    ~tri_race()
    {
        cout << "A törléseket elvégeztem\n";
    }

    // Getters
    int getIj() const;

    // Setters
    tri_race &setSum(int co);

    // Kiírások

    tri_race &kiir_rajt();
    tri_race &kiir_cel();
};
