Készítsen programot mobiltelefonok és laptopok leltári nyilvántartására
az alábbiak szerint:

A Laptop és Mobil objektumok egyfajta Termekek
A Laptop példányosításakor meg kell adni a laptop nevét és árát
A Mobil példányosításakor meg kell adni a mobil nevét, árát és IMEI számát

A Keszlet osztály úgynevezett singleton osztály:
a) konstruktorát kívülről nem lehet meghívni
b) copy konstruktor és assignment le van tiltva
c) kizárólag a GetInstance() nevű statikus metóduson keresztül kérhető le egy példánya

A Keszlet osztály addTermek() metódusa egy Termekre mutató pointert és egy darabszámot vár
-- ami a készleten fellelhető darabok számát jelenti
A Keszlet osztály getQuantity() metódusa egy Termekre mutató pointert vár, és visszaadja, hogy
az adott Termekből hány darab lelhető fel a készletben

3-as jegyért:
A Keszlet osztály rendel() metódusa egy Termekre mutató pointert vár, illetve egy darabszámot,
és a készleten fellelhető darabok számát a megadott számmal csökkenti (mintha annyit rendeltek volna)

4-es jegyért:
Készítsen a Keszlet osztályhoz egy checkedRendel() metódust, ami ugyanúgy egy Termekre mutató
pointert és egy darabszámot vár, viszont kivételt dob, ha nincs a készleten elegendő darab a termékből

5-ös jegyzért:
Készítsen a Keszlet osztályhoz egy addTermekChecked() metódust, ami egy Termekre mutató pointert vár
amennyiben az adott termékkel azonos termék már szerepel a nyilvántartásban, annak darabszámát növelje új
Termek felvétele helyett
