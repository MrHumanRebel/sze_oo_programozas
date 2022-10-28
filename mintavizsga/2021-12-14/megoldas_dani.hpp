#pragma once
#include <math.h>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual float area() = 0;
};

class Point2D : public Shape
{
    // protected:
    int a;
    int b;

public:
    // Constructor
    Point2D(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    // Default Constructor
    Point2D()
    {
        a = 0;
        b = 0;
    }
    // Destructor
    ~Point2D()
    {
        // cout << "\nDestructor OK!" << endl;
    }
    float distance(Point2D ujpont)
    {
        return sqrt((b - a) ^ 2 + (ujpont.b - ujpont.a) ^ 2);
    }
    float area()
    {
        return 0.0;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};

class Rectangle : public Point2D
{
    // protected:
    Point2D a;
    Point2D b;
    Point2D c;
    Point2D d;

public:
    // Constructor
    Rectangle(Point2D a, Point2D b, Point2D c, Point2D d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    // Destructor
    ~Rectangle()
    {
        // cout << "\nDestructor OK!" << endl;
    }
    // Disable copy Constructor
    Rectangle &operator=(const Rectangle &) = delete;
    Rectangle(const Rectangle &) = delete;
    // Rectangle() = default;

    float area()
    {
        float calc;
        int id1 = a.getA();
        int id2 = d.getA();
        int egyikoldalhossz = id2 - id1;
        id1 = a.getB();
        id2 = b.getB();
        int masikoldalhossz = id2 - id1;
        calc = egyikoldalhossz * masikoldalhossz;
        return abs(calc);
    }
    Rectangle() = delete;
};

class Circle : public Point2D
{
    // protected:
    Point2D a;
    int b;

public:
    // Constructor
    Circle(Point2D a, int b)
    {
        this->a = a;
        this->b = b;
    }
    // Destructor
    ~Circle()
    {
        // cout << "\nDestructor OK!" << endl;
    }
    // Disable copy Constructor
    Circle &operator=(const Circle &) = delete;
    Circle(const Circle &) = delete;
    // Circle() = default;
    float area()
    {
        float calc = M_PI * pow(b, 2);
        return calc;
    }
};