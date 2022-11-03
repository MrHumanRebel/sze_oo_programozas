#include <iostream>
using namespace std;

class Base
{
public:
    Base() {}
    virtual ~Base() {}
};

class Derived : public Base
{
public:
    Derived() {}
    ~Derived() {}
};

class AnotherClass : public Base
{
public:
    AnotherClass() {}
    ~AnotherClass() {}
};

int main()
{
    double value0 = 5.25;
    int a0 = (int)value0;
    cout << a0 << endl;

    //#############################//

    double value1 = 5.25;
    double a1 = (int)value1 + 5.3;
    cout << a1 << endl;

    //#############################//

    double s0 = static_cast<int>(value1) + 5.3;
    cout << s0 << endl;

    //#############################//

    // double s1 = static_cast<AnotherClass*>(&value1) + 5.3; INVALID!
    // cout << s1 << endl;

    //#############################//

    Derived *derived0 = new Derived();
    Base *base0 = derived0;
    Derived *ac0 = dynamic_cast<Derived *>(base0); // Dynamic cast
    cout << ac0 << endl;

    return 0;
}