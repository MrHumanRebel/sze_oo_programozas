#pragma once

#include "drink.hpp"
#include <map>
#include <ostream>

class OutOfStock : public std::exception
{
    std::string msg;

public:
    OutOfStock(const Drink &d)
        : msg(d.name + " kifogyott.")
    {
    }

    const char *what() const noexcept override
    {
        return msg.c_str();
    }
};

class SodaMachine
{
    // T�rolja, hogy milyen italok, azokb�l h�ny db van
    /*struct Supply {
        Drink drink;
        int count;
    };
    std::map<std::string, Supply> supply;
    std::map<std::string, std::pair<Drink, int>> supply;
    */
    std::map<Drink, int> drinks;

    // T�rolja a bedobott (felhaszn�latlan) p�nz�sszeget
    int credit;

public:
    // Ital hozz�ad�sa
    void addDrink(Drink d, unsigned count = 1)
    {
        auto iter = drinks.find(d);
        if (iter != drinks.end())
        { // found
            if (iter->first.price != d.price)
            { // old price is different
                // iter->first.price = d.price; // key is const!
                int supply = iter->second + count;
                drinks.erase(iter);
                // drinks.insert({ d, supply });
                drinks[d] = supply;
            }
            else
            {
                iter->second += count;
            }
        }
        else
        {
            drinks.insert(iter, {d, count});
        }
    }

    // Ital v�s�rl�sa
    Drink buy(const std::string &name)
    {
        Drink d = {name}; // price is undefined
        auto iter = drinks.find(d);
        if (iter != drinks.end())
        { // found
            if (iter->second == 0)
            {
                // std::cout << iter->first.name << " elfogyott!\n";
                // return Drink{};
                throw OutOfStock{d};
            }
            if (credit < iter->first.price)
            {
                // std::cout << "Nincs bedobva eleg penz!\n";
                // return Drink{};
                throw std::logic_error{"Nincs bedobva eleg penz!"};
            }
            iter->second -= 1;
            credit -= iter->first.price;
            std::cout << iter->first.name << " kiadva.\n";
            return iter->first;
        }
        else
        {
            // std::cout << "Nincs " << name << " nevu ital!\n";
            // return Drink{};
            throw std::invalid_argument(
                std::string("Nincs " + name + " nevu ital!"));
        }
    }

    // P�nzbedob�s
    void insertCoin(unsigned coin) { credit += coin; }

    // P�nz visszak�r�se
    int retrieveMoney()
    {
        int money = credit;
        credit = 0;
        return money;
    }

    // Italok ki�r�sa
    friend std::ostream &operator<<(std::ostream &o, const SodaMachine &sm)
    {
        o << "Italok:\n";
        for (const auto &drink : sm.drinks)
        {
            o << "  " << drink.first.name << " - " << drink.first.price
              << " Ft (" << drink.second << " db)\n";
        }
        o << "Bedobott penz: " << sm.credit << " Ft\n";
        return o;
    }
};