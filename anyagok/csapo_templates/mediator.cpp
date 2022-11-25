#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Mediator
{
    vector<T *> entities;

public:
    void addEntity(T *ep) { entities.push_back(ep); }
    void distributeMessage(T *sender, const string &msg)
    {
        for (auto elem : entities)
        {
            if (elem != sender)
            {
                elem->receiveMsg(sender, msg);
            }
        }
    }
};

class Colleague
{
    string name;

public:
    Colleague(const string &nm) : name(nm) {}
    void sendMsg(Mediator<Colleague> *mp, const string &msg)
    {
        mp->distributeMessage(this, msg);
    }
    void receiveMsg(Colleague *cp, const string &msg)
    {
        cout << name << " received message from " << cp->name;
        cout << endl
             << "\t" << msg << endl;
    }
};

int main()
{
    Colleague adam("Szabo Adam");
    Colleague eva("Kuti Eva");
    Colleague utalatos("Hernyo Guszti");
    Mediator<Colleague> baratok;
    baratok.addEntity(&adam);
    baratok.addEntity(&eva);
    Mediator<Colleague> mindenki;
    mindenki.addEntity(&adam);
    mindenki.addEntity(&eva);
    mindenki.addEntity(&utalatos);
    adam.sendMsg(&mindenki, "Talalkozzunk holnap 3-kor");
    eva.sendMsg(&baratok, "OK, de Gusztit meg ne hivd ebedre!");
}