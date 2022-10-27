#include <iostream>

using namespace std;

class EqTriangle
{
private:
    float a;
    float circumference;
    float area;

public:
    void setA(float lenght) // Setter
    {
        a = lenght;
        circumference = a * 3;
        area = (1.73 * a * a) / 4;
    }
    // friend void PrintResults(EqTriangle); // Only works for global functions by its own
    friend class Homework;
};

class Homework
{
public:
    void PrintResults(EqTriangle et)
    {
        cout << "circumference: " << et.circumference << endl;
        cout << "area: " << et.area << endl;
    }
};

int main()
{
    EqTriangle et;
    et.setA(3);
    // PrintResults(et);
    Homework h;
    h.PrintResults(et);

    return 0;
}