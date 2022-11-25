#include <iostream>
#include <vector>
using namespace std;

// ez az osztaly azert kell, hogy az Observable osztalyban
// el tudjuk tarolni, valamint hogy interfeszt adjon a kommunikaciohoz...
class Observer
{
public:
    virtual void update(string &, double, int) = 0;
};

class Observable
{ // subject-nek is hivhato
protected:
    vector<Observer *> observers;

public:
    void registerObserver(Observer *ob) { observers.push_back(ob); }
    void deregisterObserver(Observer *ob)
    {
        observers.erase(
            remove(
                observers.begin(), observers.end(), ob),
            observers.end());
    }
};

class Environment : public Observable
{
    string name;

public:
    Environment(const string &nm) : name(nm) {}
    void updateInfo(double temp, int humi)
    {
        for (auto elem : observers)
        {
            elem->update(name, temp, humi);
        }
    }
};

class WeatherDataObserverEng : public Observer
{
public:
    void update(string &observableNm, double temp, int humi)
    {
        cout << "WeatherDataObserver for ";
        cout << observableNm << ": temperature is " << temp << " deg C - ";
        cout << humi << "% humidity" << endl;
    }
};

class WeatherDataObserverHun : public Observer
{
public:
    void update(string &observableNm, double temp, int humi)
    {
        cout << "WeatherDataObserver ";
        cout << observableNm << " kornyezetre: a homerseklet " << temp << " fok C - ";
        cout << humi << "% paratartalom" << endl;
    }
};
int main()
{
    Environment e1("nappali");
    Environment e2("haloszoba");
    Environment e3("jatszoter");
    Observer *wdoe = new WeatherDataObserverEng;
    Observer *wdoh = new WeatherDataObserverHun;
    e1.registerObserver(wdoe);
    e2.registerObserver(wdoe);
    e2.registerObserver(wdoh);
    e3.registerObserver(wdoh);
    e1.updateInfo(22, 50);
    e2.updateInfo(20.5, 48);
    e3.updateInfo(33, 81);
    e2.deregisterObserver(wdoe);
    e2.updateInfo(20.3, 49);
}