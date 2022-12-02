#pragma once

#include "parts.hpp"

#include <iostream>
#include <string>
#include <vector>

template <typename T = int>
class Vehicle
{
    const std::string name;
    std::vector<Part<T> *> parts;

public:
    Vehicle(const std::string &name)
        : name(name)
    {
    }
    Vehicle(const Vehicle<T> &other)
    {
        *this = other;
        /*for (auto& p : other.parts) {
            parts.push_back(new Part<T>(*p));
        }*/
    }
    Vehicle<T> &operator=(const Vehicle<T> &other)
    {
        if (this == &other)
            return *this;
        for (auto &p : parts)
        {
            delete p;
        }
        parts.clear();
        for (auto &p : other.parts)
        {
            parts.push_back(new Part<T>(*p));
        }
        return *this;
    }
    ~Vehicle()
    {
        for (auto &p : parts)
        {
            delete p;
        }
    }
    const std::string &getName() const { return name; }
    void addPart(Part<T> *p) { parts.push_back(p); }
    virtual void print() const = 0;
    void amortizeParts()
    {
        for (auto &p : parts)
        {
            p->amortize();
        }
    }
    void repairParts()
    {
        for (auto &p : parts)
        {
            if (!p->isHealthy())
                p->repair();
        }
    }
};

template <typename T>
void Vehicle<T>::print() const
{
    std::cout << name << " with " << parts.size() << " parts:\n";
    for (const auto p : parts)
    {
        // std::cout << "\t" << p->getName() << " (" << p->getAge() << " years old)\n";
        std::cout << "\t" << *p << '\n';
    }
}

template <typename T = int>
class Car : public Vehicle<T>
{
public:
    Car(const std::string &name)
        : Vehicle<T>(name)
    {
        Vehicle<T>::addPart(new Part<T>("Front left wheel", 5));
        Vehicle<T>::addPart(new Part<T>("Front right wheel", 5));
        Vehicle<T>::addPart(new Part<T>("Rear left wheel", 5));
        Vehicle<T>::addPart(new Part<T>("Rear right wheel", 5));
    }
    void print() const
    {
        std::cout << "Car named ";
        Vehicle<T>::print();
    }
};

template <typename T = int>
class MotorBike : public Vehicle<T>
{
public:
    MotorBike(const std::string &name)
        : Vehicle<T>(name)
    {
        Vehicle<T>::addPart(new Part<T>("Front wheel", 4));
        Vehicle<T>::addPart(new Part<T>("Rear wheel", 4));
    }
    void print() const
    {
        std::cout << "Motorbike named ";
        Vehicle<T>::print();
    }
};

template <typename T = int>
class VehiclePark
{
    std::vector<Vehicle<T> *> v;

public:
    ~VehiclePark()
    {
        for (auto veh : v)
        {
            delete veh;
        }
    }
    VehiclePark() {}
    VehiclePark(const VehiclePark &vhp)
    {
        *this = vhp;
        /*for (auto veh : vhp.v) {
            Car<T>* c = dynamic_cast<Car<T>*>(veh);
            MotorBike<T>* mb = dynamic_cast<MotorBike<T>*>(veh);
            if (c)
                v.push_back(new Car<T>(*c));
            else if (mb)
                v.push_back(new MotorBike<T>(*mb));
        }*/
    }
    VehiclePark<T> operator=(const VehiclePark<T> &vhp)
    {
        if (this == &vhp)
            return *this;
        for (auto veh : v)
        {
            delete veh;
        }
        v.clear();
        for (auto veh : vhp.v)
        {
            Car<T> *c = dynamic_cast<Car<T> *>(veh);
            MotorBike<T> *mb = dynamic_cast<MotorBike<T> *>(veh);
            if (c)
                v.push_back(new Car<T>(*c));
            else if (mb)
                v.push_back(new MotorBike<T>(*mb));
        }
        return *this;
    }
    void addVehicle(Vehicle<T> *vp) { v.push_back(vp); }
    void printVehicles() const
    {
        for (auto veh : v)
        {
            veh->print();
        }
    }
    void amortize()
    {
        for (auto veh : v)
        {
            veh->amortizeParts();
        }
    }
    void repairCars()
    {
        for (Vehicle<T> *veh : v)
        {
            if (dynamic_cast<Car<T> *>(veh))
                veh->repairParts();
        }
    }
    void repairBikes()
    {
        for (Vehicle<T> *veh : v)
        {
            MotorBike<T> *mb = dynamic_cast<MotorBike<T> *>(veh);
            if (mb)
                mb->repairParts();
        }
    }
    template <class TT>
    void repairVehicles()
    {
        for (Vehicle<T> *veh : v)
        {
            if (dynamic_cast<TT *>(veh))
                veh->repairParts();
        }
    }
};