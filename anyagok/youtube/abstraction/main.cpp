#include <iostream>
using namespace std;

class SmartPhone
{
public:
    virtual void TakeSelfie() = 0; // Pure virtual function, no implementation here
    virtual void MakeCall() = 0;
};

class Android : public SmartPhone
{
public:
    void TakeSelfie()
    {
        cout << "Android selfie..." << endl;
    }
    void MakeCall()
    {
        cout << "Android calling..." << endl;
    }
};

class iOS : public SmartPhone
{
public:
    void TakeSelfie()
    {
        cout << "iOS selfie..." << endl;
    }
    void MakeCall()
    {
        cout << "iOS calling..." << endl;
    }
};

int main()
{
    SmartPhone *S1 = new Android();
    S1->TakeSelfie();
    S1->MakeCall();
    SmartPhone *S2 = new iOS();
    S2->TakeSelfie();
    S2->MakeCall();
    return 0;
}

/*1. Abstract classes are an abstraction around base classes which can be used to enforce certain functionality in all base classes.
2. Abstract classes can be instantiated using pointers only and not by creating objects of the abstract class.
3. Abstract class pointers can point to memory addresses of instances of any of its base class
4. Pure virtual functions can be used to enforce certain functionality in all base classes of an abstract class.
5. Pure virtual functions will not have an implementation in the abstract class definitions, but will use a pure specifier (= 0)
6. Virtual functions can have an implementation in the abstract class (think of it like the default functionality if none of the base classes have an implementation of that function)*/