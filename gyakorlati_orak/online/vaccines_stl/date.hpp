#pragma once

#include <string>

struct Date
{
    int year, month, day;
    Date(int y = 1970, int m = 1, int d = 1)
        : year(y), month(m), day(d)
    {
    }

    std::string toString() const
    {
        return std::to_string(year) + "." + (month < 10 ? "0" : "") + std::to_string(month) + "." + (day < 10 ? "0" : "") + std::to_string(day) + ".";
    }
};
