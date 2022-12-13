#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Termek
{
protected:
    double mennyiseg;
    int ar;
    string mertekegyseg;

public:
    Termek(double mennyiseg, int ar, string mertekegyseg)
    {
        this->mennyiseg = mennyiseg;
        this->ar = ar;
        this->mertekegyseg = mertekegyseg;
    }
    Termek()
    {
        mennyiseg = 0.0;
        ar = 0.0;
        mertekegyseg = "NAN";
    }
    virtual ~Termek()
    {
    }
    virtual double getTotal()
    {
        return ar * mennyiseg;
    }
};

class Kosar
{
    vector<Termek *> kosartartalma;

public:
    void add(Termek *ptr)
    {
        kosartartalma.push_back(ptr);
    }
    void total()
    {
        double sum = 0.0;
        cout << "Kosar erteke: ";
        for (auto it = begin(kosartartalma); it != end(kosartartalma); ++it)
        {
            double akt = 0.0;
            akt = (*it)->getTotal(); // Precedencia. A -> előbb hajtódik végre, mint a * vagyis a gép zárójelek nélkül azt látná, hogy *(it->getTotal())
            if (it != (end(kosartartalma)) - 1)
                cout << akt << " + ";
            else
                cout << akt;
            sum += akt;
        };
        cout << " = " << sum << endl;
    }
};

class Barack : public Termek
{

public:
    Barack(double mennyiseg, int ar, string mertekegyseg) : Termek(mennyiseg, ar, mertekegyseg)
    {
    }
};

class Tej : public Termek
{
    double tipus;

public:
    Tej(double mennyiseg, double tipus, int ar, string mertekegyseg) : Termek(mennyiseg, ar, mertekegyseg)
    {
        this->tipus = tipus;
    }
    Tej() : Termek(mennyiseg, ar, mertekegyseg)
    {
        tipus = 0.0;
    }
};

class TrappistaSajt : public Termek
{
    double kedvezmeny;

public:
    TrappistaSajt(double mennyiseg, int ar, string mertekegyseg, double kedvezmeny) : Termek(mennyiseg, ar, mertekegyseg)
    {
        this->kedvezmeny = kedvezmeny;
    }
    TrappistaSajt() : Termek(mennyiseg, ar, mertekegyseg)
    {
        kedvezmeny = 0.0;
    }
    double getTotal() override
    {
        return ar * mennyiseg * (1 - kedvezmeny);
    }
};