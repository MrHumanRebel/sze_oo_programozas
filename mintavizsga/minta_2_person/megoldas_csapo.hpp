#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

class Person
{
    std::string name;

public:
    Person(std::string n) : name(n) {}
    void notify(std::string msg, Person *sender)
    {
        std::cout << name << " megkapta " << sender->name << " uzenetet: " << msg;
        std::cout << std::endl;
    }
};

class Mediator
{
    std::vector<Person *> people;

public:
    void add(Person *pp) { people.push_back(pp); }
    void send(Person *senderp, std::string msg)
    {
        for (Person *pp : people)
        {
            if (pp != senderp)
                pp->notify(msg, senderp);
        }
    }
};