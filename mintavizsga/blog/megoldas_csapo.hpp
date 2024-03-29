#pragma once
#include <string>
#include <vector>

class GuestAuthor
{
    std::string name;
    std::string workplace;
    std::string twitterHandle;

public:
    GuestAuthor(const std::string &name, const std::string &work, const std::string &twitter) : name(name), workplace(work), twitterHandle(twitter) {}
    std::string toString()
    {
        return name + ", " + workplace + ", " + twitterHandle;
    }
};

class BlogEntry
{
protected:
    std::string title;
    int year;
    int month;
    int day;
    GuestAuthor *optionalGuestAuthor;
    std::vector<BlogEntry *> duplicates;

public:
    BlogEntry(const std::string &title, int yr, int mo, int dy) : title(title), year(yr), month(mo), day(dy) {}
    BlogEntry(const std::string &title, int yr, int mo, int dy, GuestAuthor *gap) : title(title), year(yr), month(mo), day(dy), optionalGuestAuthor(gap) {}
    virtual void print() = 0;
    virtual ~BlogEntry() {}
};

class Blog
{
    std::string title;
    std::vector<BlogEntry *> entries;

public:
    Blog(const std::string &t) : title(t) {}
    void addEntry(BlogEntry *ent) { entries.push_back(ent); }
    void print()
    {
        std::cout << "Blog: " << title << std::endl;
        std::cout << "---" << std::endl;
        for (BlogEntry *bep : entries)
        {
            bep->print();
        }
    }
    // void duplicateEntry(BlogEntry* bep, int yr, int mo, int dy) {

    // Ez ket okbol sem jo:
    // - BlogEntry absztrakt osztaly, tehat nem peldanyosithato direktben
    // - Nagyobbik gond: new-val a heapen hozzuk letre, de az osszes tobbi
    // bejegyzes a stack-en van (csak ezt kene delete-elni!)

    /*BlogEntry* newEntry = nullptr;
    for (BlogEntry* entry : entries) {
        if (bep == entry) {
            std::string newTitle = bep->getTitle() + " (duplicate)";
            GuestAuthor* optGuestAuth = bep->getGuestAuthor();
            newEntry = new BlogEntry(newTitle, yr, mo, dy, optGuestAuth);
        }
    }
    if (newEntry) {
        entries.push_back(newEntry);
    }*/
    //}
};

class BlogTextEntry : public BlogEntry
{
public:
    BlogTextEntry(const std::string &title, int yr, int mo, int dy) : BlogEntry(title, yr, mo, dy) {}
    BlogTextEntry(const std::string &title, int yr, int mo, int dy, GuestAuthor *gap) : BlogEntry(title, yr, mo, dy, gap) {}
    void print() override
    {
        std::cout << year << "/" << month << "/" << day;
        std::cout << " - " << title;
        if (optionalGuestAuthor)
        {
            std::cout << " (";
            std::cout << optionalGuestAuthor->toString();
            std::cout << ")";
        }
        std::cout << std::endl;
    }
};

class BlogVideoEntry : public BlogEntry
{
public:
    BlogVideoEntry(const std::string &title, int yr, int mo, int dy) : BlogEntry(title, yr, mo, dy) {}
    void print() override
    {
        std::cout << year << "/" << month << "/" << day;
        std::cout << " - " << title;
        std::cout << " - Play - Download" << std::endl;
    }
};