#include <iostream>
using namespace std;

class AbstractEmployee
{
    virtual void askforpromotion() = 0; // Virtual abstract function
};

class Employee : AbstractEmployee
{
private: // Default
    string Company;
    int Age;

protected: // Accessable in derived classes!
    string Name;

public:
    // Setters
    void setName(string name)
    {
        Name = name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    void setAge(int age)
    {
        if (age >= 18)
            Age = age;
    }

    // Getters
    string getName()
    {
        return Name;
    }
    string getCompany()
    {
        return Company;
    }
    int getAge()
    {
        return Age;
    }

    // Abstraction

    void askforpromotion()
    {
        if (Age > 30)
            cout << Name << " - Got promoted!" << endl;
        else
            cout << Name << " - Promotion denied!" << endl;
    }

    // Functions
    void introduction()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    virtual void work() // Virtual function, if derived exists, the most derived function will be executed
    {
        cout << Name << " is checking e-mail, task backlog, performing tasks..." << endl;
    }

    // Constructor
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }

    // Destructor
    ~Employee()
    {
        // cout << "\nDestructor OK!" << endl;
    }
};

class Developer : public Employee // Child class (Employee is the parent class)
{
public:
    string FavProgLang;

    // Constructor
    Developer(string name, string company, int age, string favproglang) : Employee(name, company, age)
    {
        FavProgLang = favproglang;
    }

    // Destructor
    ~Developer()
    {
        // cout << "\nDestructor OK!" << endl;
    }

    // Functions
    void fixbug()
    {
        cout << getName() << " Fixed bug using " << FavProgLang << endl;
    }
    void work()
    {
        cout << Name << " is writing " << FavProgLang << " code..." << endl;
    }
};

class Teacher : public Employee
{
public:
    string Subject;

    // Functions
    void PrepareLesson()
    {
        cout << Name << " is preparing " << Subject << " lesson!" << endl;
    }
    void work()
    {
        cout << Name << " is teaching " << Subject << " at the moment..." << endl;
    }

    // Constructor
    Teacher(string name, string company, int age, string subject) : Employee(name, company, age)
    {
        Subject = subject;
    }

    // Destructor
    ~Teacher()
    {
        // cout << "\nDestructor OK!" << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Bela", "Martin Audio", 18);
    employee1.introduction();
    employee1.askforpromotion();

    cout << endl;

    Employee employee2 = Employee("Pista", "OTP Bank", 31);
    employee2.introduction();
    employee2.askforpromotion();

    cout << endl;

    Developer dev = Developer("Barnabas", "KTM Bikes", 18, "C++");
    dev.fixbug();
    dev.askforpromotion();

    cout << endl;

    Teacher teach = Teacher("Laszlo", "SZE", 55, "IT");
    teach.PrepareLesson();
    teach.askforpromotion();

    cout << endl;

    dev.work();
    teach.work();

    cout << endl;

    Employee *e1 = &dev; // Base class pointer to a derived class object
    Employee *e2 = &teach;

    e1->work(); // Pointer to work function
    e2->work();

    /*employee1.setAge(39);
    employee1.setAge(15); // Not going to work => setter conditions
    cout << employee1.getName() << " is " << employee1.getAge() << " years old" << endl;
    */

    /*
    Employee employee1;
    employee1.Name = "Béla";
    employee1.Company = "Martin Audio";
    employee1.Age = 18;
    employee1.introduction();

    Employee employee2;
    employee2.Name = "Pista";
    employee2.Company = "OTP Bank";
    employee2.Age = 20;
    employee2.introduction();
    */
    return 0;
}