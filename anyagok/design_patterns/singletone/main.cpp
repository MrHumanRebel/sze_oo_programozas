#include <thread>
#include <iostream>
#include "singletone.hpp"
using namespace std;

int main()
{
    cout << "If you see the same value, then singleton was reused (yay!\n"
         << "If you see different values, then 2 singletons were created (booo!!)\n\n"
         << "RESULT:\n";
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}