#include <iostream>
#include <vector>
using namespace std;

int getNum()
{
    return 5;
}

int Sum(int a, int b)
{
    return a + b;
}

bool ascComp(int a, int b)
{
    return a < b;
}
bool descComp(int a, int b)
{
    return a > b;
}
void sortAsc(vector<int> &numbersVector)
{
    for (long unsigned int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for (long unsigned int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if (ascComp(numbersVector[currentIndex], numbersVector[bestIndex]))
                bestIndex = currentIndex;
        }
        swap(numbersVector[startIndex], numbersVector[bestIndex]);
    }
}
void sortDesc(vector<int> &numbersVector)
{
    for (long unsigned int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for (long unsigned int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if (descComp(numbersVector[currentIndex], numbersVector[bestIndex]))
                bestIndex = currentIndex;
        }
        swap(numbersVector[startIndex], numbersVector[bestIndex]);
    }
}

void printNum(vector<int> &numbersVector)
{
    for (long unsigned int i = 0; i < numbersVector.size(); i++)
    {
        cout << numbersVector[i] << " ";
    }
    cout << endl;
}

void sortCustom(vector<int> &numbersVector, bool (*compareFuncPtr)(int, int)) // Receives also a function pointer
{
    for (long unsigned int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
    {
        int bestIndex = startIndex;
        for (long unsigned int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
        {
            if (compareFuncPtr(numbersVector[currentIndex], numbersVector[bestIndex]))
                bestIndex = currentIndex;
        }
        swap(numbersVector[startIndex], numbersVector[bestIndex]);
    }
}

int main()
{
    int (*funcPtr)() = getNum;
    cout << funcPtr() << endl;

    cout << "---------------" << endl;

    int (*funcPtr2)(int, int) = Sum;
    cout << funcPtr2(876, 923) << endl;

    cout << "---------------" << endl;

    vector<int> myNumbers = {2, 5, 1, 3, 6, 4};
    printNum(myNumbers);
    sortAsc(myNumbers);
    printNum(myNumbers);
    sortDesc(myNumbers);
    printNum(myNumbers);

    cout << "---------------" << endl;

    vector<int> myNumbers2 = {21, 59, 11, 35, 69, 444};
    printNum(myNumbers2);
    sortCustom(myNumbers2, descComp);
    printNum(myNumbers2);
    sortCustom(myNumbers2, ascComp);
    printNum(myNumbers2);

    bool (*funcPtr3)(int, int) = descComp;
    sortCustom(myNumbers2, funcPtr3);
    printNum(myNumbers2);

    return 0;
}
