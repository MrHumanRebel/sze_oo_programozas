#pragma once
using namespace std;

class Circle
{
public:
    // Constructor
    Circle()
    {

    }
    // Destructor
    ~Circle()
    {
        // cout << "\nDestructor OK!" << endl;
    }
    // Disable copy constructor
    Circle &operator=(const Circle &) = delete;
    Circle(const Circle &) = delete;
    Circle() = delete;
};