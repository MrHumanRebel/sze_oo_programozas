#include <iostream>
using namespace std;

class IntegerSingleton
{
    int value;
    IntegerSingleton() : value() {}
    IntegerSingleton(const IntegerSingleton &other) = delete;
    IntegerSingleton &operator=(const IntegerSingleton &other) = delete;
    static IntegerSingleton *instance;

public:
    void setValue(int v) { value = v; }
    static IntegerSingleton &GetInstance()
    {
        // static IntegerSingleton* instance = new IntegerSingleton; // ezzel 1 sor megsporolhato
        return *instance;
    }
};

IntegerSingleton *IntegerSingleton::instance = new IntegerSingleton(0);

int main()
{
    // IntegerSingleton is1 = IntegerSingleton::GetInstance(); // nincs copy constructor…
    IntegerSingleton::GetInstance().setValue(5);
    IntegerSingleton::GetInstance().print();
    IntegerSingleton::GetInstance().print();
    IntegerSingleton::GetInstance().setValue(6);
    IntegerSingleton::GetInstance().print();
    std::cout << "address of singleton: " << &IntegerSingleton::GetInstance() << std::endl;
    std::cout << "address of singleton: " << &IntegerSingleton::GetInstance() << std::endl;
}