#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Give the start array size: " << endl;
    cin >> size;
    int *myArray = new int[size]; // Allocate

    for (int i = 0; i < size; i++)
    {
        cout << "Give data to Array[" << i << "] ";
        cin >> myArray[i];
    }

    cout << "--------------" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Data at Array[" << i << "]: " << myArray[i] << endl;
    }
    delete[] myArray; // Deallocate
    myArray = NULL;   // Free up pointer

    return 0;
}
