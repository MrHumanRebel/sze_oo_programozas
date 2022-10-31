#pragma once
#include <iostream>
using namespace std;

class Sports
{
protected:
    const int calc0 = 60;
    const int calc1 = 100;
    const int calc2 = 1000;
    const int calc3 = 3600;

public:
    virtual void computeSaveAndPrintAverage() = 0;

    virtual ~Sports()
    {
    }
};

class Swimming : public Sports
{
private:
    double masodperc;
    double meter;

public:
    Swimming(double masodperc, double meter)
    {
        this->masodperc = masodperc;
        this->meter = meter;
    }
    Swimming()
    {
        masodperc = 0;
        meter = 0;
    }
    ~Swimming()
    {
    }
    void computeSaveAndPrintAverage()
    {
        double calc = masodperc / (meter / calc1);
        cout << "Az uszas atlaga: " << calc << " s / 100 m" << endl;
    }
};

class Cycling : public Sports
{
private:
    double kilometer = 0;
    double ora = 0;

public:
    Cycling(double kilometer, double ora)
    {
        this->kilometer = kilometer;
        this->ora = ora;
    }
    Cycling()
    {
        kilometer = 0;
        ora = 0;
    }
    ~Cycling()
    {
    }
    void computeSaveAndPrintAverage()
    {
        double calc = (kilometer / calc2) / (ora / calc3);
        cout << "A kerekparozas atlaga: " << calc << " km / h" << endl;
    }
};

class Running : public Sports
{
private:
    double perc = 0;
    double kilometer = 0;

public:
    Running(double perc, double kilometer)
    {
        this->perc = perc;
        this->kilometer = kilometer;
    }
    Running()
    {
        perc = 0;
        kilometer = 0;
    }
    ~Running()
    {
    }
    void computeSaveAndPrintAverage()
    {
        double calc = (perc / calc0) / (kilometer / calc2);
        cout << "A futas atlaga:: " << calc << " min / km" << endl;
    }
};