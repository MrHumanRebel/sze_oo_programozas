#include <iostream>
using namespace std;

int main()
{

    int n = 5;

    cout << "Normal N: " << n << endl;
    cout << "Adress of N: " << &n << endl;
    cout << "------------" << endl;

    int *ptr = &n;

    cout << "Ptr value: " << ptr << endl;
    cout << "Ptr data: " << *ptr << endl;
    cout << "------------" << endl;

    *ptr = 10;

    cout << "Ptr value: " << ptr << endl;
    cout << "Ptr data: " << *ptr << endl;
    cout << "------------" << endl;

    cout << "Normal N: " << n << endl;
    cout << "Adress of N: " << &n << endl;
    cout << "------------" << endl;

    /*
    int *ptr2; //Wrong!
    *ptr2 = 7;
    */

    int v;
    int *ptr2 = &v;
    *ptr2 = 7;

    cout << "Normal V: " << v << endl;
    cout << "Adress of V: " << &v << endl;
    cout << "------------" << endl;    

    return 0;
}