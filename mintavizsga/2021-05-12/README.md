Készítse el a szükséges osztályokat ahhoz, hogy a program kimenete az alábbi legyen:

Inbox for consumer Paul:
Dirk Abwernajthy wins 15th Grand Slam
No concerts at Carnegie Hall during lockdown
Museum of Fine Arts reopens following renovations
===
Cultural news for consumer Paul:
No concerts at Carnegie Hall during lockdown
Museum of Fine Arts reopens following renovations
===
Sports news for consumer Paul:
Dirk Abwernajthy wins 15th Grand Slam
===

Inbox for consumer Anna:
Lionel Quasar scores hat trick
No concerts at Carnegie Hall during lockdown
Museum of Fine Arts reopens following renovations
===
Cultural news for consumer Anna:
No concerts at Carnegie Hall during lockdown
Museum of Fine Arts reopens following renovations
===
Sports news for consumer Anna:
Lionel Quasar scores hat trick
===
A main függvény, mellyel a programnak működnie kell:

main.cpp-ben található



For example:

Test	Result
NewsSource ns1("News Source 1");
NewsSource ns2("News Source 2");

NewsConsumer dirk("Dirk");
NewsConsumer blaise("Blaise");

blaise.registerToSource(&ns1);
dirk.registerToSource(&ns2);

SportsNews nn1("sports for blaise");
SportsNews nn2("sports for dirk");
CulturalNews nn3("cultural news for blaise");
CulturalNews nn4("cultural news for dirk");

News* news1 = &nn1;
news1 = &nn3;

ns1.publishNews(&nn1); ns1.publishNews(news1);
ns2.publishNews(&nn2); ns2.publishNews(&nn4);

blaise.printInbox();
blaise.printCultural();
blaise.printSports();
dirk.printInbox();
dirk.printCultural();
dirk.printSports();
Inbox for consumer Blaise:
sports for blaise
cultural news for blaise
===
Cultural news for consumer Blaise:
cultural news for blaise
===
Sports news for consumer Blaise:
sports for blaise
===
Inbox for consumer Dirk:
sports for dirk
cultural news for dirk
===
Cultural news for consumer Dirk:
cultural news for dirk
===
Sports news for consumer Dirk:
sports for dirk
===