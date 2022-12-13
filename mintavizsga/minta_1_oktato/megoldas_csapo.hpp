#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Oktato
{
protected:
    std::string lastname;
    std::string firstname;

public:
    Oktato(std::string lname, std::string fname) : lastname(lname), firstname(fname) {}
    virtual ~Oktato() {}
    virtual void print() = 0;
};

class Professzor : public Oktato
{
public:
    Professzor(std::string lname, std::string fname) : Oktato(lname, fname) {}
    void print()
    {
        std::cout << "Professzor: " << lastname << ", " << firstname << std::endl;
    }
};

class Tanarseged : public Oktato
{
public:
    Tanarseged(std::string lname, std::string fname) : Oktato(lname, fname) {}
    void print()
    {
        std::cout << "Tanarseged: " << lastname << ", " << firstname << std::endl;
    }
};