#include <iostream>
using namespace std;

class Instrument // Abstract class => At least one pure virtual class
{
public:
    virtual void MakeSound() = 0; // Pure virtual function
};

class Accordion : public Instrument
{
public:
    void MakeSound()
    {
        cout << "Accordion is playing...." << endl;
    }
};

class Piano : public Instrument
{
public:
    void MakeSound()
    {
        cout << "Piano is playing...." << endl;
    }
};

int main()
{

    Instrument *I1 = new Accordion();
    // I1->MakeSound();
    Instrument *I2 = new Piano();
    // I2->MakeSound();

    Instrument *INST[2] = {I1, I2};
    for (int i = 0; i < 2; i++)
    {
        INST[i]->MakeSound();
    }

    return 0;
}