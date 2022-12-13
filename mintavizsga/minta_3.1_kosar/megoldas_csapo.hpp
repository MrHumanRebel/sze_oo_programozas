#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Termek
{
protected:
    double mennyiseg;
    int ar;
    std::string mertekegyseg;

public:
    Termek(double m, int a, std::string megy) : mennyiseg(m), ar(a), mertekegyseg(megy) {}
    virtual ~Termek() {}
    virtual double getTotal()
    {
        return mennyiseg * ar;
    }
};

class Kosar
{
    std::vector<Termek *> tartalom;

public:
    ~Kosar()
    {
        for (Termek *t : tartalom)
        {
            delete t;
        }
    }
    void add(Termek *t) { tartalom.push_back(t); }
    void total()
    {
        std::cout << "Kosar erteke: ";
        double teljesErtek = 0.0;
        bool elsoTermek = true;
        // for ciklus:
        for (Termek *tp : tartalom)
        {
            double reszOsszeg = tp->getTotal();
            teljesErtek += reszOsszeg;
            if (elsoTermek)
            {
                std::cout << reszOsszeg;
                elsoTermek = false;
            }
            else
            {
                std::cout << " + " << reszOsszeg;
            }
        }
        std::cout << " = " << teljesErtek << std::endl;
    }
};

class Barack : public Termek
{
public:
    Barack(double m, int ar, std::string megy) : Termek(m, ar, megy) {}
};

class Tej : public Termek
{
    double zsirtartalom;

public:
    Tej(double m, double zs, int ar, std::string megy) : Termek(m, ar, megy), zsirtartalom(zs) {}
};

class TrappistaSajt : public Termek
{
    double kedvezmeny;

public:
    TrappistaSajt(double m, int ar, std::string megy, double kedv) : Termek(m, ar, megy), kedvezmeny(kedv) {}
    double getTotal()
    {
        return mennyiseg * ar * (1.0 - kedvezmeny);
    }
};