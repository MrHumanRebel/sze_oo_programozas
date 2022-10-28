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
    unique_ptr<int> unPtr1 = make_unique<int>(25); // Create unique pointer to int, and assigned 25 to it
    cout << "Adress: " << &unPtr1 << endl;         // Get adress
    cout << "Value: " << *unPtr1 << endl;          // Get value

    cout << "----------------" << endl;

    unique_ptr<int> unPtr2 = move(unPtr1); // Move ownership, previous owner becomes NULL PTR
    cout << "Adress: " << &unPtr2 << endl; // Get adress
    cout << "Value: " << *unPtr2 << endl;  // Get value

    cout << "----------------" << endl;

    unique_ptr<MyClass> unPtr3 = make_unique<MyClass>();

    return 0;
}
