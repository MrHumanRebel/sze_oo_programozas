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
    virtual EtlapElem *copy() = 0;
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
    EtlapElem *copy()
    {
        return new Leves(nev, ar);
    }
    ~Leves() {}
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
        cout << nev << " " << koret << " korettel"
             << " - " << ar << " Ft" << endl;
    }
    EtlapElem *copy()
    {
        return new Foetel(nev, koret, ar);
    }
    ~Foetel() {}
};

class Ital : public EtlapElem
{
public:
    Ital(const string &nev, int ar) : EtlapElem(nev, ar)
    {
    }
    void print()
    {
        cout << nev << " - " << ar << " Ft" << endl;
    }
    EtlapElem *copy()
    {
        return new Ital(nev, ar);
    }
    ~Ital() {}
};

class Etlap
{
protected:
    vector<EtlapElem *> etel;

public:
    Etlap()
    {
    }
    Etlap(const Etlap &akt)
    {
        for (EtlapElem *etel : akt.etel)
        {
            this->etel.push_back(etel->copy());
        }
    }
    void hozzaad(EtlapElem *ptr)
    {
        etel.push_back(ptr);
    }
    void print()
    {
        cout << "Etlap:" << endl;
        for (auto it = begin(etel); it != end(etel); ++it)
        {
            (*it)->print();
            if (dynamic_cast<Ital *>(*it))
            {
                cout << "Inni muszaj..." << endl;
            }
        };
    }
    ~Etlap()
    {
        for (vector<EtlapElem *>::reverse_iterator it = etel.rbegin();
             it != etel.rend(); it++)
        {
            delete *it;
            *it = 0;
        }
    }
};