#define NOMINMAX
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <algorithm>

#include "person.hpp"

using namespace std;

int main()
{
    map<string, Person> people;
    string input;
    do
    {
        cout << "Enter a command (add, print, exit):\n";
        cin >> input;
        if (input == "add")
        {
            cout << "Enter the vaccinated person's name:\n";
            string name;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            // find person with this name
            /*size_t i = 0;
            while (i < people.size() && name != people[i].getName())
                i++;
            if (i == people.size()) {
                // not found, add new Person
            }*/
            /*list<Person>::iterator iter = people.begin();
            while (iter != people.end() && name != iter->getName())
                ++iter;*/
            auto iter = people.find(name);
            if (iter == people.end())
            {
                cout << "Person not found. Enter the personal details.\n";
                string SSN;
                cout << "Enter the SSN:\n";
                getline(cin, SSN);
                Date DOB;
                cout << "Enter the DOB:\n";
                cin >> DOB.year;
                cin >> DOB.month;
                cin >> DOB.day;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                // Person p(name, SSN, DOB);
                // people.push_back(p);
                /*people.emplace_back(name, SSN, DOB);
                iter = people.end();
                --iter;*/
                // people[name] = Person(name, SSN, DOB);
                iter = people.emplace_hint(iter, name, Person(name, SSN, DOB));
            }
            // read vaccination data
            string type;
            cout << "Enter the type of vaccine:\n";
            getline(cin, type);
            cout << "Enter the vaccination date:\n";
            Date date(1970, 1, 1);
            cin >> date.year;
            cin >> date.month;
            cin >> date.day;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // add Vaccination to Person
            // people[name].addVaccination(Vaccination(type, date));
            iter->second.addVaccination(Vaccination(type, date));
        }
        else if (input == "print")
        {
            for (const auto &p : people)
            {
                cout << p.second << endl;
            }
        }
    } while (input != "exit");
}