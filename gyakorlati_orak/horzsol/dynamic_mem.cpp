#include <iostream>
using namespace std;
#define MAX 256

int numbers(int array[])
{
    int size = 0;
    for (int i = 0; i < 256; i++)
    {
        array[i] = (i * 2) / 5;
        size++;
    }
    return size;
}

void out(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " A tömb " << i + 1 << ". eleme a(z): '";
        cout << array[i] << "' amely a(z) " << i << ". indexű!" << endl;
    }
}

main()
{
    int *pointer = new int[MAX]; // Define array
    int size = numbers(pointer);
    out(pointer, size);
    delete[] pointer; // Delete array
    return 0;
}