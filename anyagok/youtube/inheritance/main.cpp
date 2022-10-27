#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel
{
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

protected:
    string OwnerName;

public:
    YouTubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }
    void GetInfo()
    {
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles)
        {
            cout << videoTitle << endl;
        }
    }
    void Subscribe()
    {
        SubscribersCount++;
    }
    void Unsubscribe()
    {
        if (SubscribersCount > 0)
            SubscribersCount--;
    }
    void PublishVideo(string title)
    {
        PublishedVideoTitles.push_back(title);
    }
};

class MacskaYTChannel : public YouTubeChannel // Derived class
{
public:
    MacskaYTChannel(string name, string ownername) : YouTubeChannel(name, ownername)
    {
    }
    void Practice()
    {
        cout << OwnerName << " Macska macskagol a kutya kutyagolasan....";
    }
};

int main()
{
    MacskaYTChannel Macska_YT("Danci Studios", "Daniel");
    Macska_YT.PublishVideo("Macska Ugatas");
    Macska_YT.PublishVideo("Kutya Nyavogas");
    for (int i = 0; i <= 50; i++)
    {
        Macska_YT.Subscribe();
    }
    Macska_YT.Unsubscribe();
    Macska_YT.GetInfo();
    Macska_YT.Practice();

    return 0;
}