Str / 1
/* Sorminta készítése, első nekifutás :) */
#include <iostream>
    using namespace std;

#define SK 4 /* Kiírandó sorok száma */

struct sor_minta /* Struktúra deklarációja */
{
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
};

int main(void)
{
  int i, j;
  struct sor_minta nyzj, es, zzj; /* Struktúrák definíciói */
  nyzj.kar = '[';
  nyzj.ism = 2;
  nyzj.sor = 2; /* Struktúrák tagjainak a kezdőértékei */
  es.kar = '&';
  es.ism = 3;
  es.sor = 3; /* Struktúrák tagjainak a kezdőértékei */
  zzj.kar = ']';
  zzj.ism = 4;
  zzj.sor = 1; /* Struktúrák tagjainak a kezdőértékei */
  cout << "\n"
       << endl;
  for (i = 0; i < SK; i++) /* Sorok kiírása */
  {
    for (j = 0; j < nyzj.ism; j++) /* Soron belüli kiírás */
    {
      if (i < nyzj.sor)
        cout << nyzj.kar;
      else
        cout << "-";
    }
    for (j = 0; j < es.ism; j++) /* Soron belüli kiírás */
    {
      if (i < es.sor)
        cout << es.kar;
      else
        cout << "-";
    }
    for (j = 0; j < zzj.ism; j++) /* Soron belüli kiírás */
    {
      if (i < zzj.sor)
        cout << zzj.kar;
      else
        cout << "-";
    }
    cout << "\n"
         << endl;
  }
  return 0;
}
/***************************************************************************************/
Str / 2
/* Sorminta készítése függvénnyel, amely egy globális struktúra tömböt kezel */
#include <iostream>
    using namespace std;

#define SK 4  /* Kiírandó sorok száma */
#define T_E 3 /* A tömb elemeinek a száma */

struct sor_minta /* Struktúra deklarációja */
{
  char kar; /* kiirandó karakter */
  int ism;  /* soron belüli ismétlődések száma */
  int sor;  /* sorok száma, amennyiben megjelenjen */
};

struct sor_minta str_tb[T_E] = {
    {'[', 2, 2},
    {'&', 3, 3},
    {']', 4, 1}};
/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */

void kiir(int kfv)
{
  int j, k;
  for (k = 0; k < T_E; k++) /* Soron belüli kiírás */
  {
    for (j = 0; j < str_tb[k].ism; j++) /* Soron belüli adott karakter kiírása */
    {
      if (kfv < str_tb[k].sor)
        cout << str_tb[k].kar;
      else
        cout << "-";
    }
  }
  cout << "\n"
       << endl;
  return;
}

int main(void)
{
  int i = 0;
  cout << "\n"
       << endl;
  for (i = 0; i < SK; i++) /* Sorok kiírása */
  {
    kiir(i);
  }
  return 0;
}
/***************************************************************************************/
Str / 3
/* Sorminta készítése függvénnyel, amely egy globális struktúra tömböt kezel
és nem csak változókat, hanem egy egy tömböt is tatalmaz. */
#include <iostream>
    using namespace std;

#define SK 4  /* Kiírandó sorok száma */
#define T_E 3 /* A tömb elemeinek a száma */

struct sor_minta /* Struktúra deklarációja */
{
  char kar;     /* kiirandó karakter */
  int ism;      /* soron belüli ismétlődések száma */
  bool sor[SK]; /* mely sorokban jelenjen meg */
};

struct sor_minta str_tb[T_E] = {
    {'[', 2, {1, 0, 1, 0}},
    {'&', 3, {1, 1, 1, 0}},
    {']', 4, {0, 0, 1, 1}}};
/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */

void kiir(int kfv)
{
  int j, k;
  cout << kfv + 1 << ". sor: ";
  for (k = 0; k < T_E; k++) /* Soron belüli kiírás */
  {
    for (j = 0; j < str_tb[k].ism; j++) /* Soron belüli adott karakter kiírása */
    {
      if (str_tb[k].sor[kfv])
        cout << str_tb[k].kar;
      else
        cout << "-";
    }
  }
  cout << "\n"
       << endl;
  return;
}

int main(void)
{
  int i = 0;
  cout << "\n"
       << endl;
  for (i = 0; i < SK; i++) /* Sorok kiírása */
  {
    kiir(i);
  }
  return 0;
}
/***************************************************************************************/
Str / 4
/* Sorminta készítése függvénnyel, amely egy globális struktúra tömböt kezel
és nem csak változókat, hanem egy-egy tömböt és egy alstruktúrát is tatalmaz. */
#include <iostream>
    using namespace std;

#define SK 4  /* Kiírandó sorok száma */
#define T_E 3 /* A tömb elemeinek a száma */

struct veg_sor /* Struktúra deklarációja */
{
  string vs_tb; /* végzáró karakterek */
};

struct sor_minta /* Struktúra deklarációja */
{
  char kar;          /* kiirandó karakter */
  int ism;           /* soron belüli ismétlődések száma */
  bool sor[SK];      /* mely sorokban jelenjen meg */
  struct veg_sor zk; /* sorvégi karakterek */
};

struct sor_minta str_tb[T_E] = {
    {'[', 2, {1, 0, 1, 0}, "╦╦╗"},
    {'&', 3, {1, 1, 1, 0}, "OUT"},
    {']', 4, {0, 0, 1, 1}, "END"}};
/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */

void kiir(int kfv)
{
  int j, k, l;
  cout << kfv + 1 << ". sor: ";
  for (k = 0; k < T_E; k++) /* Soron belüli kiírás */
  {
    for (j = 0; j < str_tb[k].ism; j++) /* Soron belüli adott karakter kiírása */
    {
      if (str_tb[k].sor[kfv])
        cout << str_tb[k].kar;
      else
        cout << "-";
    }
  }
  if (kfv >= T_E)
    kfv %= 3;
  cout << str_tb[kfv].zk.vs_tb << "\n";
  return;
}

int main(void)
{
  int i = 0, ksz;
  cout << "\n"
       << endl;
  for (i = 0; i < SK; i++) /* Sorok kiírása */
  {
    kiir(i);
  }
  return 0;
}
/***************************************************************************************/
Str / 5
/* Sorminta készítése függvénnyel, amely egy LOKÁLIS(!) struktúra tömböt kezel.
    A függvény, paraméterként kapja meg a struktúra tömb címét.
    Alstruktúra hívása. */
#include <iostream>
    using namespace std;

#define SK 4  /* Kiírandó sorok száma */
#define T_E 3 /* A tömb elemeinek a száma */

struct veg_sor /* Struktúra deklarációja */
{
  string vs_tb; /* végzáró karakterek */
};

struct sor_minta /* Struktúra deklarációja */
{
  string kar;        /* kiirandó karakter */
  int ism;           /* soron belüli ismétlődések száma */
  bool sor[SK];      /* mely sorokban jelenjen meg */
  struct veg_sor zk; /* sorvégi karakterek */
};

void kiir(int kfv, struct sor_minta *pnt)
{
  int j, k;
  cout << kfv + 1 << ". sor: ";
  for (k = 0; k < T_E; k++, pnt++) /* Soron belüli kiírás */
  {
    /*cout << "\n" << pnt << "\n";*/ /* Memória címek megjelenítése */
    for (j = 0; j < pnt->ism; j++)   /* Soron belüli adott karakter kiírása */
    {
      if (pnt->sor[kfv])
        cout << pnt->kar;
      else
        cout << "-";
    }
  }
  if (kfv >= T_E)
    kfv %= 3;
  if (kfv == 0)
    pnt -= 3;
  else if (kfv == 1)
    pnt -= 2;
  else if (kfv == 2)
    pnt -= 1;
  cout << pnt->zk.vs_tb << "\n";
  return;
}

int main(void)
{
  int i = 0;
  struct sor_minta str_tb[T_E] = {
      {"▲", 2, {1, 0, 1, 0}, "╦╦╗"},
      {"▼", 3, {1, 1, 1, 0}, "╬╬╣"},
      {"►", 4, {0, 0, 1, 1}, "╩╩╝"}};
  /* Struktúra tömb definíciója és az elemeinek a kezdőértékei */
  struct sor_minta *mutat;
  cout << "\n"
       << endl;
  for (i = 0, mutat = str_tb; i < SK; i++) /* Sorok kiírása */
  {
    kiir(i, mutat);
  }
  return 0;
}
/***************************************************************************************/
/***************************************************************************************/
#include <iostream>
using namespace std;

#define SK 4  /* Kiírandó sorok száma */
#define T_E 3 /* A tömb elemeinek a száma */

class sor_minta /*  deklarációja */
{
  char kar;     /* kiirandó karakter */
  int ism;      /* soron belüli ismétlődések száma */
  bool sor[SK]; /* mely sorokban jelenjen meg */
  void kiir(int kfv);
};

struct sor_minta str_tb[T_E] = {
    {'[', 2, {1, 0, 1, 0}},
    {'&', 3, {1, 1, 1, 0}},
    {']', 4, {0, 0, 1, 1}}};
/* Struktúra tömb definíciója és az elemeinek a kezdőértékei */

void sor_minta::kiir(int kfv)
{
  int j, k;
  cout << kfv + 1 << ". sor: ";
  for (k = 0; k < T_E; k++) /* Soron belüli kiírás */
  {
    for (j = 0; j < str_tb[k].ism; j++) /* Soron belüli adott karakter kiírása */
    {
      if (str_tb[k].sor[kfv])
        cout << str_tb[k].kar;
      else
        cout << "-";
    }
  }
  cout << "\n"
       << endl;
  return;
}

int main(void)
{
  int i = 0;
  cout << "\n"
       << endl;
  for (i = 0; i < SK; i++) /* Sorok kiírása */
  {
    kiir(i);
  }
  return 0;
}
