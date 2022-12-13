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
    Person()
    {
        nev = "";
    }
    void notify(const string uzenet, Person ptr)
    {
        cout << ptr.nev << " megkapta " << nev << " uzenetet: " << uzenet << endl;
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
    Mediator(const string nev) : Person(nev)
    {
    }
    Mediator() : Person()
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
            // cout << "A vector aktuális címe: " << *it << endl;
            // cout << "A kapott aktuális cím: " << ptr << endl;
            if (*it != ptr)
                ptr->notify(uzenet, **it);
        };
    }
};
