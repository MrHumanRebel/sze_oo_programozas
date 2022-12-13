#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Oktato
{
protected:
    string lastName;
    string firstName;

public:
    Oktato(const string lastName, const string firstName)
    {
        this->lastName = lastName;
        this->firstName = firstName;
    }
    virtual void print() = 0;
    virtual ~Oktato()
    {
    }
};

class Professzor : public Oktato
{
public:
    Professzor() : Oktato(lastName, firstName)
    {
    }
    void print()
    {
        cout << "Professzor: " << lastName << ", " << firstName << endl;
    }
};

class Tanarseged : public Oktato
{
public:
    Tanarseged() : Oktato(lastName, firstName)
    {
    }
    void print()
    {
        cout << "Tanarseged: " << lastName << ", " << firstName << endl;
    }
};