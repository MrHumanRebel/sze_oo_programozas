#pragma once

#include <string>
#include <vector>

#include "date.hpp"
#include "vaccination.hpp"

class Person
{
    std::string name;
    std::string SSN;
    Date DOB;

    std::vector<Vaccination> vaccines;

public:
    Person(const std::string &name, const std::string &SSN, Date dob)
        : name(name), SSN(SSN), DOB(dob)
    {
    }

    void addVaccination(const Vaccination &v)
    {
        vaccines.push_back(v);
    }

    const std::string &getName() const
    {
        return name;
    }

    friend std::ostream &operator<<(std::ostream &o, const Person &p)
    {
        o << p.getName()
          << "\n\tSSN: " << p.SSN
          << "\n\tDOB: " << p.DOB.toString();
        for (const auto &v : p.vaccines)
        {
            o << "\n\t" << v.type << " (" << v.date.toString() << ")";
        }
        return o << "\n";
    }
};
