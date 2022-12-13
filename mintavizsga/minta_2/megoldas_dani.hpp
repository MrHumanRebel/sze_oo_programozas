#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Person
{
protected:
    string nev;
    string uzenet;

public:
    Person(const string nev)
    {
        this->nev = nev;
    }
    void notify(const string uzenet, Person ptr)
    {
        cout << nev << " megkapta " << ptr.nev << " uzenetet: " << uzenet << endl;
    }
    virtual ~Person()
    {
    }
};

class Mediator : public Person
{
private:
    vector<Person *> feliratkozottak;

public:
    Mediator() //: Person(nev)
    {
    }
    void add(Person *ptr)
    {
        feliratkozottak.push_back(ptr);
    }
    void send(Person *ptr, const string uzenet)
    {
        for (auto it = begin(feliratkozottak); it != end(feliratkozottak); ++it)
        {
            if (*it != ptr)
                ptr->notify(uzenet, *ptr);
        };
    }
};
