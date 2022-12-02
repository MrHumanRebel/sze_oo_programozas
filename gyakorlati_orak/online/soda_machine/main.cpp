#include <iostream>

#include "sodamachine.hpp"

using namespace std;

int main()
{
    SodaMachine m;
    Drink cola = {"Cola", 350};
    m.addDrink(cola, 5);
    m.addDrink(Drink{"Fanta", 380});
    m.addDrink(cola, 5);
    m.addDrink(Drink{"Fanta", 420});
    m.insertCoin(200);
    cout << m;
    try
    {
        Drink d = m.buy("Cola");
        // d.drink();
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
    m.insertCoin(1000);
    cout << m;
    try
    {
        m.buy("Fanta");
    }
    catch (OutOfStock &e)
    {
        cerr << e.what() << endl;
        m.addDrink({"Fanta", 420});
    }
    cout << m;
    try
    {
        m.buy("Fanta");
    }
    catch (OutOfStock &e)
    {
        cerr << e.what() << endl;
        m.addDrink({"Fanta", 420});
    }
    cout << m;
    try
    {
        m.buy("Fanta");
    }
    catch (OutOfStock &e)
    {
        cerr << e.what() << endl;
        m.addDrink({"Fanta", 420});
    }
    catch (std::invalid_argument &e)
    {
        cerr << e.what() << endl;
    }
    catch (std::logic_error &e)
    {
        cerr << e.what() << endl;
        cout << "Valasszon masikat!\n";
    }
    try
    {
        m.buy("Pepsi");
    }
    catch (OutOfStock &e)
    {
        cerr << e.what() << endl;
        m.addDrink({"Pepsi", 420});
    }
    catch (std::invalid_argument &e)
    {
        cerr << e.what() << endl;
    }
    catch (std::logic_error &e)
    {
        cerr << e.what() << endl;
        cout << "Valasszon masikat!\n";
    }
}