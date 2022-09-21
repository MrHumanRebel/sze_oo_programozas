#include <iostream>
#include "Decl.hpp"

void sor_minta::kiir(int i)
{
    for (int j = 0; j < ism; j++) /* Soron belüli kiírás */
    {
        if (i < sor)
            cout << kar;
        else
            cout << "-";
    }
}

void sor_minta::setIsm(int im)
{
    do
    {
        cout << "\n Kérem az ismétlődés változtatás mértékét [1-10]: " << im << " +-= ";
        cin >> v_m;
    } while (((im + v_m) <= 0) && ((im + v_m) > 10) && ((im + v_m) < 1));
    ism += v_m;
}
void sor_minta::setKar(char kr)
{
    cout << "\n Kérem a karakter változtatást: " << kr << " : ";
    cin >> v_m;
    kar = '\0';
    kar = v_m;
}
void sor_minta::setSor(int sr)
{
    do
    {
        cout << "\n Kérem a sor változtatás mértékét [1-10]: " << sr << " +-= ";
        cin >> v_m;
    } while (((sr + v_m) <= 0) && ((sr + v_m) > 10) && ((sr + v_m) < 1));
    sor += v_m;
}

void mind(sor_minta nyzj, sor_minta es, sor_minta zzj)
{
    cout << "\n"
         << endl;
    for (int i = 0; i < SK; i++) /* Sorok kiírása */
    {
        nyzj.kiir(i);
        es.kiir(i);
        zzj.kiir(i);
        cout << "\n"
             << endl;
    }
}

int main(void)
{
    sor_minta nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1), alap; /* Objektumok példányosítása, beállítása */
    /*cout << alap.getIsm() << "\n"
         << es.getIsm() << "\n"
         << endl;*/
    cout << "Nyzj: " << nyzj.getIsm() << nyzj.getKar() << nyzj.getSor() << '\n';
    cout << "Es: " << es.getIsm() << es.getKar() << es.getSor() << '\n';
    cout << "Zzj: " << zzj.getIsm() << zzj.getKar() << zzj.getSor() << '\n';
    mind(nyzj, es, zzj);
    es.setIsm(es.getIsm());
    es.setKar(es.getKar());
    es.setSor(es.getSor());
    mind(nyzj, es, zzj);
    return 0;
}