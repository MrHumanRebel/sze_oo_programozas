#include <iostream>
using namespace std;

class Printable
{
public:
    virtual void print() = 0;
};
class Person : public Printable
{
public:
    void print() { std::cout << "I am a person" << std::endl; }
};
class Animal
{
public:
    void saySomething() { std::cout << "Hi I am an animal!" << std::endl; }
};
void printSomething(Printable *prp)
{
    prp->print();
}
class AnimalPrintableAdapter : public Printable
{
    Animal *animal;

public:
    AnimalPrintableAdapter(Animal *ap) : animal(ap) {}
    void print() { animal->saySomething(); }
};
int main()
{
    Person p;
    printSomething(&p);
    Animal a;
    // printSomething(&a); // animal nem egyfajta Printable
    AnimalPrintableAdapter apa(&a);
    printSomething(&apa);
}