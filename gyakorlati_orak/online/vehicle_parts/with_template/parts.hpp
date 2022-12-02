#pragma once

#include <ostream>
#include <string>

template <typename T = int>
class Part
{
    const std::string name;
    const T lifespan;
    T age = 0;

public:
    Part(const std::string &name, T lifespan)
        : name(name), lifespan(lifespan)
    {
    }
    void amortize() { ++age; }
    bool isHealthy() const { return age <= lifespan; }
    void repair() { age = 0; }
    const std::string &getName() const { return name; }
    T getAge() const { return age; }
    friend std::ostream &operator<<(std::ostream &o, const Part &p)
    {
        o << p.name << " (" << p.age << " years old)";
        if (!p.isHealthy())
            o << " - Needs repair!";
        return o;
    }
};