#include <iostream>
using namespace std;

int getMin(int numbers[], int size)
{
    int min = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < min)
            min = numbers[i];
    }
    return min;
}
int getMax(int numbers[], int size)
{
    int max = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}

void getMinMax(int numbers[], int size, int *min, int *max)
{
    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > *max)
            *max = numbers[i];
        if (numbers[i] < *min)
            *min = numbers[i];
    }
}

int main()
{
    int numbers[5] = {5, 4, -2, 29, 6};
    cout << "Minimum: " << getMin(numbers, 5) << endl;
    cout << "Maximum: " << getMax(numbers, 5) << endl;

    cout << "---------------" << endl;

    int min, max = numbers[0];
    getMinMax(numbers, 5, &min, &max);
    cout << "Minimum: " << min << endl;
    cout << "Maximum: " << max << endl;

    return 0;
}
