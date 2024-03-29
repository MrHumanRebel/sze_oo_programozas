#include <iostream>
#include <type_traits>
#include "megoldas_csapo.hpp"

// Keszitsen el egy Blog osztalyt, amelyet a blog cimevel lehet peldanyositani.
// Keszitsen el egy absztrakt BlogEntry osztalyt, melynek void print() metodusa
// ... nincs kifejtve
// Keszitsen el egy BlogTextEntry es BlogVideoEntry osztalyt, melyek a BlogEntry
// osztaly megvalositasai
// Forduljon le a program es irja ki a megfelelo dolgokat!

int main()
{
    Blog myblog("Interesting Stuff on OOP");
    static_assert(std::is_abstract<BlogEntry>(), "BlogEntry osztaly nem absztrakt!");
    BlogTextEntry entry1("Why is OOP useful?", 2022, 10, 3);
    BlogVideoEntry entry2("Demonstration1", 2022, 10, 5);

    GuestAuthor bajorm("Bajor Miska", "Salesforce", "@bmisk");
    BlogTextEntry entry3("History of OOP", 2022, 12, 1, &bajorm);

    //BlogAudioEntry entry4("Interview with Bjarne Stroustrup", 2022, 12, 2); //AUDIO

    myblog.addEntry(&entry1);
    myblog.addEntry(&entry2);
    myblog.addEntry(&entry3);
    //myblog.addEntry(&entry4); //AUDIO

    // myblog.duplicateEntry(&entry1, 2022, 12, 2);

    myblog.print(); // irja ki az alabbit:
    // Blog: Interesting Stuff on OOP
    // ---
    // 2022/10/3 - Why is OOP useful?
    // 2022/10/5 - Demonstration 1 - Play - Download
    // 2022/12/1 - History of OOP (Bajor Miska, Salesforce, @bmisk)
    // 2022/12/2 - Interview with Bjarne Stroustrup - Listen
}