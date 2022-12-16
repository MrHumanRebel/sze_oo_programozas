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
    virtual string print() = 0;
};

class Etlap
{
protected:
    vector<EtlapElem *> etel;

public:
    void hozzaad(EtlapElem *ptr)
    {
        etel.push_back(ptr);
    }
    string print()
    {
        cout << "Etlap:" << endl;
        for (auto it = begin(etel); it != end(etel); ++it)
        {
            string akt = "\0";
            akt = (*it)->print();
            cout << akt << endl;
        };
        return "\0";
    }
    /*~Etlap()
    {
        for (vector<EtlapElem *>::reverse_iterator it = etel.rbegin();
             it != etel.rend(); it++)
        {
            delete *it;
            *it = 0;
        }
    }/*
};

class Leves : public EtlapElem
{
public:
    Leves(const string nev, const int ar) : EtlapElem(nev, ar)
    {
    }
    string print()
    {
        string akt = nev + " - " + to_string(ar) + " Ft";
        // cout << nev << " - " << ar << " Ft" << endl;
        return akt;
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
    string print()
    {
        string akt = nev + ' ' + koret + " korettel - " + to_string(ar) + " Ft";
        // cout << nev << ' ' << koret << " korettel - " << ar << " Ft" << endl;
        return akt;
    }
};