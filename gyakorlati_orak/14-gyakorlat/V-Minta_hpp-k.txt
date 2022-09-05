.hpp/1
/*********************/
#include <iostream>

using namespace std;

class BaseClass {
  public:
   virtual void print()=0;
   virtual ~BaseClass() {}
};

class DerivedClass : public BaseClass {
  public:
   void print() override {  cout << "Derived" << endl; }
};
/*********************/
.hpp/2/1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ClonableString : public Clonable {
    string str;
public:
    ClonableString(const string& str) : str(str) { }
    ClonableString* clone() const override { return new ClonableString(*this); }
    const string& getString() const { return str; }
};

class ClonableNumber : public Clonable {
    double num;
public:
    ClonableNumber(const double& num) : num(num) {}
    ClonableNumber* clone() const override { return new ClonableNumber(*this); }
    const double& getNumber() const { return num; }
};
/***/
.hpp/2/2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ClonableString : public Clonable {
    string str;
public:
    ClonableString(const string& str) : str(str) { }
    ClonableString* clone() const override { return new ClonableString(*this); }
    const string& getString() const { return str; }
};

class ClonableNumber : public Clonable {
    double num;
public:
    ClonableNumber(const double& num) : num(num) {}
    ClonableNumber* clone() const override { return new ClonableNumber(*this); }
    const double& getNumber() const { return num; }
};

class CloneContainer {
    vector<Clonable*> ptrs;
public:
    CloneContainer() { };
    ~CloneContainer() {
        for (size_t i = 0; i < ptrs.size(); ++i)  /* size_t: unsigned int */
            delete ptrs[i];
    }
    void push_back(const Clonable& c) { ptrs.push_back(c.clone()); }
    size_t size() const { return ptrs.size(); }
    Clonable& operator[](size_t index) const { return *ptrs[index]; }
};
/*********************/
.hpp/3
#include <iostream>
#include <string>

using namespace std;

class SoccerPlayer {
    const std::string name;
    short speed;
    short stamina;
  public:
    SoccerPlayer(const std::string& name, short speed, short stamina); //TODO
    virtual ~SoccerPlayer() = default;
    const std::string& getName() const { return name; }
    short getSpeed() const { return speed; }
    short getStamina() const { return stamina; }
    virtual short getOverall() const = 0;
};

SoccerPlayer::SoccerPlayer(const string& name, short speed, short stamina)
    : name(name), speed(speed), stamina(stamina) { }

class FieldPlayer : public SoccerPlayer {
    short shooting, passing, tackling;
  public:
    FieldPlayer(const string& name, short speed, short stamina, short shooting, short passing, short tackling)
        : SoccerPlayer(name, speed, stamina), shooting(shooting), passing(passing), tackling(tackling) { }
    short getShooting() const { return shooting; }
    short getPassing() const { return passing; }
    short getTackling() const { return tackling; }
    short getOverall() const override { return (getSpeed() + getStamina() + shooting + passing + tackling) / 5; }
};

class Goalkeeper : public SoccerPlayer {
    short reflexes, agility;
  public:
    Goalkeeper(const string& name, short speed, short stamina, short reflexes, short agility)
        : SoccerPlayer(name, speed, stamina), reflexes(reflexes), agility(agility) { }
    short getReflexes() const { return reflexes; }
    short getAgility() const { return agility; }
    short getOverall() const { return (getSpeed() + getStamina() + reflexes + agility) / 4; }
};

ostream& operator<<(ostream& out, const SoccerPlayer& p) {
    return out << p.getName() << " (" << p.getOverall() << ")";
}