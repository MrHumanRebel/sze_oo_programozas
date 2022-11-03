#include <iostream>
using namespace std;

class Sports
{
protected:
    const int cacl0 = 60;
    const int calc1 = 100;
    const int calc2 = 1000;
    const int calc3 = 3600;

    double time;
    double distance;

public:
    Sports(int distance, int time)
    {
        this->distance = distance;
        this->time = time;
    }
    Sports()
    {
        distance = 0;
        time = 0;
    }
    virtual ~Sports()
    {
    }
    virtual void computeSaveAndPrintAverage() = 0;
    virtual string getNameOfSports() = 0;
};

class Swimming : public Sports
{
private:
    double swimdata;

public:
    Swimming(int distance, int time) : Sports(distance, time)
    {
    }
    Swimming() : Sports(distance, time)
    {
        swimdata = 0;
    }
    ~Swimming()
    {
    }
    void computeSaveAndPrintAverage()
    {
        swimdata = time / (distance / calc1);
        cout << "Az uszas atlaga: " << swimdata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Uszas";
    }
};

class Cycling : public Sports
{
private:
    double cycldata;

public:
    Cycling(int distance, int time) : Sports(distance, time)
    {
    }
    Cycling() : Sports(distance, time)
    {
        cycldata = 0;
    }
    ~Cycling()
    {
    }
    void computeSaveAndPrintAverage()
    {
        cycldata = (distance / calc2) / (time / calc3);
        cout << "A kerekparozas atlaga: " << cycldata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Kerekpar";
    }
};

class Running : public Sports
{
private:
    double rundata;

public:
    Running(int distance, int time) : Sports(distance, time)
    {
    }
    Running() : Sports(distance, time)
    {
        rundata = 0;
    }
    ~Running()
    {
    }
    void computeSaveAndPrintAverage()
    {
        rundata = (time / cacl0) / (distance / calc2);
        cout << "A futas atlaga: " << rundata << " s / 100 m" << endl;
    }
    string getNameOfSports()
    {
        return "Futas";
    }
};

void printNamesOfSports(Sports *sportname)
{
    cout << sportname->getNameOfSports() << endl;
}

void felszabadit(Sports *torol)
{
    delete torol;
    torol = 0;
}