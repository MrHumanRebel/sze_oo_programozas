#include <iostream>
using namespace std;

void printNumber(int *numberPtr)
{
    cout << "The stored number: " << *numberPtr << endl;
}

void printChar(char *charPtr)
{
    cout << "The stored character: " << *charPtr << endl;
}

void printAnydata(void *ptr, char type)
{
    switch (type)
    {
    case 'i':
        cout << "The stored number: " << *((int *)ptr) << endl;
        break;
    case 'c':
        cout << "The stored character: " << *((char *)ptr) << endl;
        break;
    }
    cout << "The data mem adress: " << ptr << endl;
}

int main()
{

    int number = 5;
    // printNumber(&number);

    char letter = 'a';
    // printChar(&letter);

    printAnydata(&number, 'i');
    printAnydata(&letter, 'c');

    return 0;
}