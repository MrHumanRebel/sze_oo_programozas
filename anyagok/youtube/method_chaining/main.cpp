#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length;
    int width;
    string color;

    // Constructor
    Rectangle(int set_lenght, int set_width, string set_color)
    {
        length = set_lenght;
        width = set_width;
        color = set_color;
    }

    // Destructor
    ~Rectangle()
    {
    }

    // Functions
    void print()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Color: " << color << endl;
    }

    // Setters

    Rectangle &setColor(string set_color) // Add & after class name to avoid memory duplicates
    {
        color = set_color;
        return *this; // Return the object itself, a pointer to the object instance, a return of a reference of the object
    }
    Rectangle &setLength(int set_length) // Add & after class name to avoid memory duplicates
    {
        length = set_length;
        return *this; // Return the object itself, a pointer to the object instance, a return of a reference of the object
    }
    Rectangle &setWidth(int set_width) // Add & after class name to avoid memory duplicates
    {
        length = set_width;
        return *this; // Return the object itself, a pointer to the object instance, a return of a reference of the object
    }
};

int main()
{
    Rectangle rectangle1(4, 5, "red");
    rectangle1.print();

    cout << endl;

    rectangle1.setColor("orange").setLength(10).setWidth(30); // Method chaining
    rectangle1.print();

    return 0;
}