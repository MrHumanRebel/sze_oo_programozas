#include "classes.cpp"

int main()
{
    NewsSource ap("Associated Press");
    NewsSource nhh("Nenzeti Hirkozlesi Hatosag");

    NewsConsumer paul("Paul");
    NewsConsumer anna("Anna");

    paul.registerToSource(&ap);
    anna.registerToSource(&nhh);

    SportsNews n1("Dirk Abwernajtly wins 1StM1 Grand Slam");
    SportsNews n2("Lionel Quasar scores hat trick");
    CulturalNews n3("No concerts at Carnegie Hall during lockdown");
    CulturalNews n4("Museum of Fine Arts reopens following renovations");

    ap.publishNews(&n1);
    ap.publishNews(&n3);
    ap.publishNews(&n4);
    nhh.publishNews(&n2);
    nhh.publishNews(&n3);
    nhh.publishNews(&n4);

    paul.printInbox();
    paul.printCultural();
    paul.printSports();
    std::cout << std : endl;

    anna.printInbox();
    anna.printCultural();
    anna.printSports();
}