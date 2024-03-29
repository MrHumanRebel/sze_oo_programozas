op_ovrld
/********* Decl.hpp ************/
#include <iostream>

    using namespace std;

class tort
{
  int szaml, nevz;                      // másolatok az objektumok mem. területein
  void setSzaml(int sz) { szaml = sz; } // szaml=szaml => this->szaml=szaml
  void setNevz(int nv) { nevz = nv; }   // nevz=nevz => this->nevz=nevz
public:                                 // a metódusok egyediek, minden objektum ezeket használja => *this
  tort(int sz, int nv)
  {
    setSzaml(sz);
    setNevz(nv);
  }
  int getSzaml() const { return szaml; }
  int getNevz() const { return nevz; }
  tort operator*(tort m_t)
  {
    return tort(szaml * m_t.getSzaml(), nevz * m_t.getNevz());
  }
  /*    tort& operator*=(tort m_t) {
                     tort e_t = *this * m_t;
                     return *this = e_t; }*/
  //    tort operator*(int i) { return tort(szaml * i, nevz); }
  /*    tort& operator*=(int i) {
                     tort e_t = *this * i;
                     return *this = e_t; }*/
  ~tort() {}
  //	  friend istream& operator>>(istream& be, tort& t);
};

/*tort operator*(tort e_t, tort m_t) {
    return tort(e_t.getSzaml() * m_t.getSzaml(),
                e_t.getNevz() * m_t.getNevz()); }*/

/*tort& tort::operator*=(tort m_t) {
                   tort e_t = *this * m_t;
                   return *this = e_t; }*/

/*tort operator*(tort e_t, int i) {
    return tort(e_t.getSzaml() * i,
                e_t.getNevz()); }*/

/*tort& tort::operator*=(int i) {
                   tort e_t = *this * i;
                   return *this = e_t; }*/

/*tort operator*(int i, tort m_t) {
    return tort(i * m_t.getSzaml(),
                m_t.getNevz()); }*/

/*ostream& operator<<(ostream& ki, const tort& t) {
  return ki << t.getSzaml() << "/" << t.getNevz(); }*/

/*istream& operator>>(istream& be, tort& t) {
  cout << "\nKérem a tört számlálóját: "; be >> t.szaml;
  cout << "  Kérem a tört nevezőjét: "; be >> t.nevz;
  return be; }*/

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  tort t1(2, 3);
  tort t2(4, 5);
  // cin >> t1 >> t2; // -2/6 és 8/-5
  tort t3 = t1 * t2; // ambiguous esete
  // tort t3 = t1.operator*(t2); // egyszerre mindkettő
  // t3 = operator*(t1, t3); // egyszerre mindhárom
  cout << "\n Alap kiírása a törtnek ('*'):\n\t\t t3 = "
       << t3.getSzaml() << "/" << t3.getNevz() << endl;
  /*  cout << "\n Túlterhelt kiírása a törteknek ('*');\n\t\t t1 = "\
         << t1 << "\n\t\t t2 = " << t2 << "\n\t\t t3 = " << t3 << endl;
    t3 *= t2;
    cout << "\n Túlterhelt kiírása a törtnek ('*='):\n\t\t t3 = " << t3 << endl;
    int i = 2 * 3;
    cout << "\n Alap kiírása az egésznek:\n\t\t i = " << i << endl;
    tort t4 = t1 * i; // *2 illetve 2 * t1!? és 2 * t1 * 2
    cout << "\n Túlterhelt 'operator*' egész szorzással:\n\t\t t4 = "\
         << t4 << endl;
    t4 *= 2;
    cout << "\n Túlterhelt 'operator*=' egész szorzással:\n\t\t t4 = "\
         << t4 << endl;
    cout << "\n" << t1 << " és " << t2 << " és " << t3 << " és " << t4 << endl;*/
  return 0;
}

/***************************************************************************************/
op_ovrld : eredmény(Fejlesztés
                    : előjelek és 0 nevező kezelése !)
/********* Decl.hpp ************/
#include <iostream>

               using namespace std;

class tort
{
  int szaml, nevz;
  void setSzaml(int szaml) { this->szaml = szaml; }
  void setNevz(int nevz) { this->nevz = nevz; }

public:
  tort(int szaml, int nevz)
  {
    setSzaml(szaml);
    setNevz(nevz);
  }
  int getSzaml() const { return szaml; }
  int getNevz() const { return nevz; }
  //    tort operator*(tort m_t) {
  //      return tort(szaml * m_t.getSzaml(), nevz * m_t.getNevz()); }
  tort &operator*=(tort m_t); /* {
                 tort e_t = *this * m_t;
                 return *this = e_t; }*/
                              //    tort operator*(int i) { return tort(szaml * i, nevz); }
  tort &operator*=(int i);    /* {
                    tort e_t = *this * i;
                    return *this = e_t; }*/
  ~tort() {}
  friend istream &operator>>(istream &be, tort &t);
};

tort operator*(tort e_t, tort m_t)
{
  return tort(e_t.getSzaml() * m_t.getSzaml(),
              e_t.getNevz() * m_t.getNevz());
}

tort &tort::operator*=(tort m_t)
{
  tort e_t = *this * m_t;
  return *this = e_t;
}

tort operator*(tort e_t, int i)
{
  return tort(e_t.getSzaml() * i,
              e_t.getNevz());
}

tort &tort::operator*=(int i)
{
  tort e_t = *this * i;
  return *this = e_t;
}

tort operator*(int i, tort m_t)
{
  return tort(i * m_t.getSzaml(),
              m_t.getNevz());
}

ostream &operator<<(ostream &ki, const tort &t)
{
  return ki << t.getSzaml() << "/" << t.getNevz();
}

istream &operator>>(istream &be, tort &t)
{
  cout << "\nKérem a tört számlálóját: ";
  be >> t.szaml;
  cout << "  Kérem a tört nevezőjét: ";
  be >> t.nevz;
  return be;
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  tort t1(2, 3);
  tort t2(4, 5);
  cin >> t1 >> t2;   // -2/6 és 8/-5
  tort t3 = t1 * t2; // ambiguous esete
  // tort t3 = t1.operator*(t2);
  // t3 = operator*(t1, t3);
  cout << "\n Alap kiírása a törtnek ('*'):\n\t\t t3 = "
       << t3.getSzaml() << "/" << t3.getNevz() << endl;
  cout << "\n Túlterhelt kiírása a törteknek ('*');\n\t\t t1 = "
       << t1 << "\n\t\t t2 = " << t2 << "\n\t\t t3 = " << t3 << endl;
  t3 *= t2;
  cout << "\n Túlterhelt kiírása a törtnek ('*='):\n\t\t t3 = " << t3 << endl;
  int i = 2 * 3;
  cout << "\n Alap kiírása az egésznek:\n\t\t i = " << i << endl;
  tort t4 = 2 * t1 * 2; // *2 illetve 2 * t1!? és 2 * t1 * 2
  cout << "\n Túlterhelt 'operator*' egész szorzással:\n\t\t t4 = "
       << t4 << endl;
  t4 *= 2;
  cout << "\n Túlterhelt 'operator*=' egész szorzással:\n\t\t t4 = "
       << t4 << endl;
  cout << "\n"
       << t1 << " és " << t2 << " és " << t3 << " és " << t4 << endl;
  return 0;
}

/***************************************************************************************/
[] - lambda kifejezés
/********* Decl.hpp ************/
#include <iostream>
#include <vector>
#include <algorithm>

    using namespace std;

vector<int> hpmp(3);

// komparátor/predikátum (összehasonlító/tulajdonság hozzárendelő) függvények
// megvalósítása; lambda kifejezésekkel.
// [] - a lambda kifejezés, egy ideiglenes, névtelen függvény objektum

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
  hpmp[0] = -1;
  hpmp.push_back(6);
  for (int i = 0; i < 10; i++)
  {
    hpmp.push_back(7 + i);
  }
  hpmp.pop_back();
  hpmp.resize(19);
  hpmp.push_back(20);
  for (auto it = hpmp.begin(); it != hpmp.end(); it++)
  {
    cout << (*it) << " ";
  }
  cout << "\n";
  // lambda kifejezések, metódus és fgv. paraméterként
  sort(hpmp.begin(), hpmp.end(),
       [](int i, int j) -> bool
       { return i > j; });
  cout << "\n";
  for (auto it = hpmp.cbegin(); it != hpmp.cend(); it++)
  {
    cout << *it << " ";
  }
  cout << "\n";
  hpmp.erase((remove_if(hpmp.begin(), hpmp.end(),
                        [](int i) -> bool
                        { return ((i % 2) == 1 or (i % 2) == -1); })),
             hpmp.end());
  for (auto it = hpmp.cbegin(); it != hpmp.cend(); it++)
  {
    cout << *it << " ";
  }
  cout << "\n";
  cout << *max_element(hpmp.begin(), hpmp.end(),
                       [](int i, int j) -> bool
                       { return i < j; })
       << "\n";
  cout << *min_element(hpmp.begin(), hpmp.end(),
                       [](int i, int j) -> bool
                       { return i <= j; })
       << "\n";
  cout << count_if(hpmp.begin(), hpmp.end(),
                   [](int i) -> bool
                   { return ((i % 2) == 0 && i != 0); })
       << "\n";
  cout << "\n";
  // önálló lambda kifejezések, a v.é. típusa a fordítóra bízva
  cout << [](int x)
  { return x * x; }(5)
       << endl;
  cout << [](int x)
  { return x * x; }(count_if(hpmp.begin(), hpmp.end(),
                             [](int i)
                             { return ((i % 2) == 0 && i != 0); }))
       << "\n\n";
  // [=] érték ill. [&] referencia szerinti változó-átvétel
  int j = 7, k = 10;
  cout << [=](int x)
  { return x * k + j; }(5)
       << "\tj = " << j << "\tk = " << k << endl;
  cout << [&](int x)
  { return x * (k++) + (++j)++; }(5)
       << "\tj = " << j << "\tk = " << k << endl;
  //  cout << [=,&j](int x){ return x*(k++) + (++j)++; }(5)\
//       << "\tj = " << j << "\tk = " << k << endl;
  return 0;
}
/***************************************************************************************/