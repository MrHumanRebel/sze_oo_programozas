Keszitse el a Point2D, Shape, Rectangle es Circle osztalyokat ugy, hogy az alabbi kod forduljon és az elvárt kimenetet adja.
Fontos, hogy a Shape osztály absztrakt legyen! - különben a static_assert nem fog lefordulni.

Tovabbi megjegyzesek:

A Rectangle inicializálásakor feltetelezheti, hogy az argumentumok egy teglalap 4 sarkat hatarozzak meg
az alabbi sorrendben: bal felso, bal also, jobb also, jobb felso.

A kor terulete: r negyzet pi. pi erteke legyen siman 3.14, beegetve.

2 pont, a es b tavolsaga: sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))

sqrt es pow a math.h konyvtarban megtalalhatoak, azaz: #include <math.h>


Az elvart kimenet az alabbi (a tavolsagok, teruletek nyilvan nem kell, hogy az utolso ezrelekig azonosak legyenek):
2 - es jegyert :
myPoint1 es myPoint2 kozotti tavolsag : 2.23607
s1 terulete : 8
s2 terulete : 12.56
3 - as jegyert : egyszeruen le kell hogy forduljon amikor SZINT_3 makro 1 - re van allitva
4 - es jegyert :
Teglalap kisebb teruletu, mint Kor
5 - os jegyert :
A Teglalap alakzatnak 4 sarka van.
A Kor alakzatnak viszont 0 sarka van.

Tovabbi megjegyzesek:
A kor terulete: r negyzet pi. pi erteke lehet siman 3.14, beegetve.
2 pont, a es b tavolsaga: sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2))
sqrt es pow a math.h konyvtarban megtalalhatoak, azaz: #include <math.h>