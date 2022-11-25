#include <iostream>
using namespace std;

class Car
{
    std::string description;

public:
    Car(const std::string &desc) : description(desc) {}
    virtual void getDescription() { std::cout << description << std::endl; }
};

class AudiA6 : public Car
{
public:
    AudiA6() : Car("Audi A6") {}
};

class RenaultClio : public Car
{
public:
    RenaultClio() : Car("RenaultClio") {}
};

class AbstractCarDecorator : public Car
{
protected:
    Car *mycar;

public:
    AbstractCarDecorator(Car *cp) : Car(""), mycar(cp) {}
    void getDescription() = 0;
};

class CarWithSoundSystem : public AbstractCarDecorator
{
public:
    CarWithSoundSystem(Car *cp) : AbstractCarDecorator(cp) {}
    void getDescription()
    {
        mycar->getDescription();
        std::cout << "\tThis car also has a sound system!" << std::endl;
    }
};

class CarWithAC : public AbstractCarDecorator
{
public:
    CarWithAC(Car *cp) : AbstractCarDecorator(cp) {}
    void getDescription()
    {
        mycar->getDescription();
        std::cout << "\tThis car also has an air conditioner!" << std::endl;
    }
};
int main()
{
    AudiA6 audi1;
    AudiA6 audi2proto0;
    CarWithAC audi2(&audi2proto0);
    RenaultClio rc1, rc2proto0;
    CarWithAC rc2proto1(&rc2proto0);
    CarWithSoundSystem rc2(&rc2proto1);
    audi1.getDescription();
    audi2.getDescription();
    rc1.getDescription();
    rc2.getDescription();
    // itt mindossze arra kell figyelni, hogy audi2proto0 meg rcproto0 es rcproto1
    // ne tunjenek el a memoriabol meg azelott, hogy audi2 es rc2 eltunnenek!
    // Pl.:
    std::cout << "Problem:" << std::endl;
    AudiA6 *audi3proto0 = new AudiA6;
    CarWithAC audi3(audi3proto0);
    audi3.getDescription();
    delete audi3proto0;
    audi3.getDescription(); // jo esetben crash!
// Erre nyujthat megoldast a smart pointerek hasznalata, mint std::unique_ptr
// Ez tulmutat a targy keretein, de az a lenyege, hogy ha audi3proto0 egy
// std::unique_ptr lenne, akkor az audi3 letrehozasakor "atruhazhato" lenne
// ennek a pointernek a birtoklasa az audi3 reszere ->
// innentol audi3 erteke nullptr es csak CarWithAC destruktora tudna felszabaditani.
https: // stackoverflow.com/questions/26318506/transferring-the-ownership-of-object-fromone-unique-ptr-to-another-unique-ptr-i
}