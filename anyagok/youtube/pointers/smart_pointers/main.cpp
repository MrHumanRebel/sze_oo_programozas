#include <iostream>
#include <memory> //Smart PTRs, memory deallocates automatically
using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "Constructor invoked..." << endl;
    }
    ~MyClass()
    {
        cout << "Destructor invoked..." << endl;
    }
};

int main()
{
    // Normal Smart PTR
    unique_ptr<int> unPtr1 = make_unique<int>(25); // Create unique pointer to int, and assigned 25 to it
    cout << "Adress: " << &unPtr1 << endl;         // Get adress
    cout << "Value: " << *unPtr1 << endl;          // Get value

    cout << "----------------" << endl;

    unique_ptr<int> unPtr2 = move(unPtr1); // Move ownership, previous owner becomes NULL PTR
    cout << "Adress: " << &unPtr2 << endl; // Get adress
    cout << "Value: " << *unPtr2 << endl;  // Get value

    cout << "----------------" << endl;

    unique_ptr<MyClass> unPtr3 = make_unique<MyClass>();

    cout << "----------------" << endl;
    // Shared Smart PTR

    shared_ptr<MyClass> shPtr1 = make_shared<MyClass>();    // Shared PTR
    cout << "Shared count: " << shPtr1.use_count() << endl; // Give number of owners
    shared_ptr<MyClass> shPtr2 = shPtr1;
    cout << "Shared count: " << shPtr1.use_count() << endl;

    cout << "----------------" << endl;

    // Weak Smart PTR

    weak_ptr<int> wPtr1;
    {
        shared_ptr<int> shPtr4 = make_shared<int>(50);
        wPtr1=shPtr4;
    }

    return 0;
}
