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
    int ContentQuality;

public:
    YouTubeChannel(string name, string ownerName)
    {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
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
    void CheckAnalytics()
    {
        if (ContentQuality < 5)
        {
            cout << Name << " - Has bad quality content!" << endl;
        }
        else
        {
            cout << Name << " - Has good quality content!" << endl;
        }
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
        cout << OwnerName << " Macska macskagol...." << endl;
        ContentQuality++;
    }
};

class KutyaYTChannel : public YouTubeChannel // Derived class
{
public:
    KutyaYTChannel(string name, string ownername) : YouTubeChannel(name, ownername)
    {
    }
    void Practice()
    {
        cout << OwnerName << " Kutya kutyagolasan...." << endl;
        ContentQuality++;
    }
};

int main()
{
    MacskaYTChannel Macska_YT("Danci Studios", "Cirmoska");
    Macska_YT.PublishVideo("Macska Ugatas");
    for (int i = 0; i <= 50; i++)
    {
        Macska_YT.Subscribe();
    }
    Macska_YT.Unsubscribe();
    Macska_YT.GetInfo();
    Macska_YT.Practice();

    cout << endl;

    KutyaYTChannel Kutya_YT("Danciii Studios", "Dikabuksi");

    Kutya_YT.PublishVideo("Kutya Nyavogas");
    Kutya_YT.GetInfo();
    Kutya_YT.Practice();
    Kutya_YT.Practice();
    Kutya_YT.Practice();
    Kutya_YT.Practice();
    Kutya_YT.Practice();

    YouTubeChannel *YT1 = &Macska_YT;
    YouTubeChannel *YT2 = &Kutya_YT;

    YT1->CheckAnalytics();
    YT2->CheckAnalytics();

    return 0;
}