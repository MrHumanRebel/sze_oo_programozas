Keszitsen programot egy tarsashazi lakokozosseg modellezesere az alabbiak szerint:

2-es szinthez:

- A Tarstulajdonos osztaly:
... tarolja a tulajdonos nevet es tulajdoni hanyadat (egesz szam, tizezredek szama).
... van meg egy print() metodusa, ami nincs implementalva
... absztrakt osztaly, ezert nem peldanyosithato

- A BekesTulajdonos egyfajta Tarstulajdonos
... 2-es szinthez: implementalja a print() metodust (hogy mit ir ki, ahhoz ld. a Kozgyules.printJelenlevok() kimenetet)

- A PereskedoTulajdonos is egyfajta Tarstulajdonos
... 2-es szinthez: implementalja a print() metodust (hogy mit ir ki, ahhoz ld. a Kozgyules.printJelenlevok() kimenetet)

- A Kozgyules osztaly:
... 2-es szinthez eltarolja int-ekkent a kozgyules evszamat, honapjat es napjat
... 2-es szinthez eltarolja STL kontenerben a kozgyules resztvevoinek pointereit
... 2-es szinthez megvalositja az addJelenlevo() metodust
... 2-es szinthez megvalositja a printJelenlevok() metodust, amely az osszes jelenlevore meghivja sajat print() metodusat

- A Tarsashaz osztaly:
... STL kontenerben, hozzadas sorrendjeben tarolja a tulajdonosokra hivatkozo pointereket
... 2-es szinthez a Tarstulajdonosok pointereit az addTulajdonos() metodussal lehet hozzaadni
... 2-es szinthez megvalositja meg a holdKozgyules() metodust. Ez a metodus gondoskodik rola, hogy
    minden 2. pereskedo tulajdonos, es minden 3. bekes tulajdonos reszt vegyen a kozgyulesen (ehhez a kozgyules addJelenlevo() metodusat lehet hasznalni)

- 3-as szinthez:
Keszitsen a Kozgyules osztalyban egy printLetszam() metodust, amely a <numeric> header-ben talalhato
std::accumulate fuggveny segitsegevel kiirja a kozgyulesen resztvevok tulajdonosi hanyadainak osszeget.
Figyelem: az std::accumulate BinaryOperation parametere egy kezileg definialt osztaly peldanya kell, hogy legyen.
a kezileg definialt osztaly neve legyen SumJelenlevos(). Ez az osztaly meg kell, hogy valositsa az alabbi metodust:
int operator()(int acc, Tarstulajdonos* tp), ami visszaadja az acc es a tulajdonosi hanyad osszeget

4-es szinthez:
Keszitsen Meghatalmazas osztalyt, amely nyilvantartja, hogy melyik meghatalmazo melyik meghatalmazottnak
adott meghatalmazast.
Keszitsen a Kozgyules osztalyhoz egy submitMeghatalmazas() metodust, amely lehetove teszi egy adott
meghatalmazas benyujtasat. A Kozgyules osztaly tarolja el a meghatalmazasok pointereit
Ezt kovetoen keszitse el a Kozgyules osztaly printJelenlevokWithProxies() metodusat ugy, hogy a 
jelenlevok tulajdoni hanyada mellett az osszes altaluk kepviselt tulajdoni hanyad is kiirasra keruljon.
A printJelenlevokWithProxies() metodusban szinten az std::accumulate() fuggvenyt hasznalja az eltarolt
meghatalmazas-lista / vector folott vegig iteralva. Ehhez szuksege lesz egy SumMeghatis osztalyra is.

5-os szinthez:
Valositsa meg a PereskedoTulajdonos osztaly orditozik() metodusat.
A Kozgyules tarolja el az orditozok pointereit, ennek hozzaadasahoz keszitsen segedmetodust.
Ha egy kozgyulesen legalabb ketten orditoznak, a BekesTulajdonosoknak elmegy a kedvuk a reszveteltol,
es legkozelebb csak minden 4. BekesTulajdonos megy el a kozgyulesre.