full/1
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
/***/
#include "Decl.hpp"

int main()
{
  BaseClass* bc = new DerivedClass;
  bc->print();
  delete bc;
  return 0;
}
/*********************/
full/2/1
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clonable {
public:
    virtual ~Clonable() = default;
    virtual Clonable* clone() const = 0;
};

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
#include "Decl.hpp"

int main()
{
 const ClonableString str1("text");
 string testStr = str1.getString();
 cout << "str1 = " << testStr << endl;
 ClonableString* str2 = str1.clone();
 cout << "str2 = " << str2->getString() << endl;

 const ClonableNumber num1(3.14);
 double testNum = num1.getNumber();
 cout << "num1 = " << testNum << endl;
 ClonableNumber* num2 = num1.clone();
 cout << "num2 = " << num2->getNumber() << endl;

 delete str2;
 delete num2;
 return 0;
}
/******/
full/2/2
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clonable {
public:
    virtual ~Clonable() = default;
    virtual Clonable* clone() const = 0;
};

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
/***/
#include "Decl.hpp"

int main()
{
 const ClonableString str1("szo");
 const ClonableString str2("szoveg");
 const ClonableString str3("word");

 const ClonableNumber num1(4.2);
 const ClonableNumber num2(-6.66);

 CloneContainer clones;
 clones.push_back(str1);
 clones.push_back(num1);
 clones.push_back(str2);
 cout << clones.size() << " clones have been made\n";

 Clonable& i1 = clones[0];
 string testStr = dynamic_cast<ClonableString*>(&i1)->getString();
 cout << "Item 1: " << testStr << endl;

 ClonableNumber* i2 = dynamic_cast<ClonableNumber*>(&clones[1]);
 cout << "Item 2: " << i2->getNumber() << endl;

 ClonableString& i3 = dynamic_cast<ClonableString&>(clones[2]);
 cout << "Item 3: " << i3.getString() << endl;

 clones.push_back(str3);
 clones.push_back(num2);
 cout << clones.size() << " clones have been made\n";

 ClonableString* i4 = dynamic_cast<ClonableString*>(&clones[3]);
 cout << "Item 4: " << i4->getString() << endl;

 ClonableNumber& i5 = dynamic_cast<ClonableNumber&>(clones[4]);
 cout << "Item 5: " << i5.getNumber() << endl;
 return 0;
}
/*********************/
full/3
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
/***/
#include "Decl.hpp"

int main()
{
 const FieldPlayer* fp1 = new FieldPlayer("C. Ronaldo", 90, 85, 95, 91, 76);
 const FieldPlayer* fp2 = new FieldPlayer("L. Messi", 88, 93, 75, 88, 96);
 const Goalkeeper* gk = new Goalkeeper("M. Neuer", 89, 87, 94, 95);

 const SoccerPlayer* p1 = fp1;
 const SoccerPlayer* p2 = fp2;
 const SoccerPlayer* p3 = gk;

 cout << p1->getName() << endl;
 cout << p1->getSpeed() << endl;
 cout << p1->getStamina() << endl;
 cout << fp1->getShooting() << endl;
 cout << fp1->getPassing() << endl;
 cout << fp1->getTackling() << endl;
 cout << p1->getOverall() << endl;
 cout << endl;

 cout << fp2->getName() << endl;
 cout << fp2->getSpeed() << endl;
 cout << fp2->getStamina() << endl;
 cout << fp2->getShooting() << endl;
 cout << fp2->getPassing() << endl;
 cout << fp2->getTackling() << endl;
 cout << fp2->getOverall() << endl;
 cout << endl;

 cout << gk->getName() << endl;
 cout << gk->getSpeed() << endl;
 cout << gk->getStamina() << endl;
 cout << gk->getReflexes() << endl;
 cout << gk->getAgility() << endl;
 cout << gk->getOverall() << endl;
 cout << endl;

 cout << *p1 << endl;
 cout << *p2 << endl;
 cout << *p3 << endl;

 delete p1;
 delete fp2;
 delete gk;
 return 0;
}
