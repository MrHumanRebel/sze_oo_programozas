#include <iostream>
#include <string>
#include <list>

using namespace std;

class YTChannel
{
public:
    string Name;
    int SubCount;
    YTChannel(string name, int subcount) // Contstructor
    {
        Name = name;
        SubCount = subcount;
    }
    bool operator==(const YTChannel &channel) const // Overload == operator
    {
        return this->Name == channel.Name;
    }
};

class MyCollection
{
public:
    list<YTChannel> myChannels;
    void operator+=(YTChannel &channel) // Overloading += operator
    {
        this->myChannels.push_back(channel);
    }
    void operator-=(YTChannel &channel) // Overloading -= operator
    {
        this->myChannels.remove(channel);
    }
};

ostream &operator<<(ostream &COUT, YTChannel &YTCHANNEL) // Overloading << operator
{
    COUT << "Name: " << YTCHANNEL.Name << endl;
    COUT << "Subs: " << YTCHANNEL.SubCount << endl;
    return COUT;
}

ostream &operator<<(ostream &COUT, MyCollection &collection) // Overloading << operator for collection list
{
    for (YTChannel ytchannel : collection.myChannels)
        COUT << ytchannel << endl;
    return COUT;
}

int main()
{
    YTChannel YT1 = YTChannel("Danci Studios", 5000);
    YTChannel YT2 = YTChannel("Danci Studios Reloaded", 1000);
    cout << YT1 << YT2;
    cout << "----------------------" << endl;
    // operator<<(cout, YT1);
    MyCollection collection;
    collection += YT1;
    collection += YT2;
    collection -= YT2;
    cout << collection;

    return 0;
}