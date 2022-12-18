#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class EtlapElem
{
protected:
    std::string nev;
    int ar;

public:
    EtlapElem(const std::string &name, int ar) : nev(name), ar(ar) {}
    virtual void print() = 0;
    virtual EtlapElem *copy() = 0;
    virtual ~EtlapElem() {}
};

class Leves : public EtlapElem
{
public:
    Leves(const std::string &name, int ar) : EtlapElem(name, ar) {}
    void print()
    {
        std::cout << nev << " - " << ar << " Ft" << std::endl;
    }
    EtlapElem *copy()
    {
        return new Leves(nev, ar);
    }
    ~Leves() {}
};

class Foetel : public EtlapElem
{
    std::string koret;

public:
    Foetel(const std::string &name, const std::string &koret, int ar)
        : EtlapElem(name, ar), koret(koret) {}
    void print()
    {
        std::cout << nev << " " << koret << " korettel"
                  << " - " << ar << " Ft" << std::endl;
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
    Ital(const std::string &name, int ar) : EtlapElem(name, ar) {}
    void print()
    {
        std::cout << nev << " - " << ar << " Ft" << std::endl;
    }
    EtlapElem *copy()
    {
        return new Ital(nev, ar);
    }
};

class Etlap
{
    std::vector<EtlapElem *> etelek;

public:
    Etlap() {}
    Etlap(const Etlap &etlap1)
    {
        for (EtlapElem *etel : etlap1.etelek)
        {
            etelek.push_back(etel->copy());
        }
    }
    void hozzaad(EtlapElem *etel)
    {
        etelek.push_back(etel);
    }
    void print()
    {
        std::cout << "Etlap: " << std::endl;
        for (EtlapElem *etel : etelek)
        {
            etel->print();
            if (dynamic_cast<Ital *>(etel))
            {
                std::cout << "Inni muszaj..." << std::endl;
            }
        }
    }
    ~Etlap()
    {
        for (EtlapElem *etel : etelek)
        {
            delete etel;
            etel = 0;
        }
    }
};
