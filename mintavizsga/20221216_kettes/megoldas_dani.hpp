#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class EtlapElem
{
protected:
    string nev;
    int ar;

public:
    EtlapElem(const string nev, const int ar)
    {
        this->nev = nev;
        this->ar = ar;
    }
    EtlapElem()
    {
        nev = "NAN";
        ar = 0;
    }
    virtual ~EtlapElem()
    {
    }
    virtual void print() = 0;
};

class Leves : public EtlapElem
{
public:
    Leves(const string nev, const int ar) : EtlapElem(nev, ar)
    {
    }
    void print()
    {
        cout << nev << " - " << ar << " Ft" << endl;
    }
};

class Foetel : public EtlapElem
{
protected:
    string koret;

public:
    Foetel(const string nev, const string koret, const int ar) : EtlapElem(nev, ar)
    {
        this->koret = koret;
    }
    void print()
    {
        cout << nev << ' ' << koret << " korettel - " << ar << " Ft" << endl;
    }
};