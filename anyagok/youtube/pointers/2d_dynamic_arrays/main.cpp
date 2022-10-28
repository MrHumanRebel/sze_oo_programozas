#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Rows, Cols: ";
    cin >> rows >> cols;

    int **table = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        table[i] = new int[cols];
    }

    table[1][2] = 88;

    for (int i = 0; i < rows; i++) // Deallocate the furthest/deepest data first
    {
        delete[] table[i];
    }
    delete[] table; // Deallocate array
    table = NULL;   // Deallocate pointer

    return 0;
}
