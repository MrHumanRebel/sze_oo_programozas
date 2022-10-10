// Próba_zh_v2/1

/********* Decl.hpp ************/
#pragma once
#include <iostream>

using namespace std;

class tri_race /* Osztály deklarációja */
{
private:
    string lic;
    int swim, cycle, run, depo, ij;
    int sum, h, p, mp;
    const int oRA, pRC;

public:
    tri_race() : oRA(3600), pRC(60)
    {
        lic = "--------";
        swim = 0;
        cycle = 0;
        run = 0;
        depo = 0;
        ij = 0;
        h = 0;
        p = 0;
        mp = 0;
        sum = 0;
    }
    tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60)
    {
        lic = lc;
        swim = sw;
        cycle = cyc;
        run = rn;
        depo = dp;
        ij = t;
        h = 0;
        p = 0;
        mp = 0;
        sum = 0;
    }
    int getIj() const { return ij; }
    tri_race &kiir_rajt();
    tri_race &kiir_cel();
    tri_race &setSum(int t);
    ~tri_race()
    {
        cout << "\nFelszabadítottam az objektum memóriacímét!";
    }
};

/************* 1.cpp *******************************************************************/
#include "Decl.hpp"

tri_race &tri_race::kiir_rajt()
{
    cout << "\nRajt idő: " << h << ":" << p << ":" << mp << " [h:m:s]";
    return *this;
}

tri_race &tri_race::kiir_cel()
{
    cout << "\nLicence: " << lic << "\nÚ: " << swim << "\nB: " << cycle
         << "\nF: " << run << "\nD: " << depo << "\nT-: " << ij;
    cout << "\nCél idő: " << h << ":" << p << ":" << mp << " [h:m:s]\n";
    return *this;
}

tri_race &tri_race::setSum(int t)
{
    sum = swim + cycle + run + depo - t;
    h = sum / oRA;
    p = (sum % oRA) / pRC;
    mp = (sum % oRA) % pRC;
    return *this;
}

/********** main.cpp *******************************************************************/
#include "Decl.hpp"

int main(void)
{
    tri_race alap,
        A_tri("M_V_1357", 1200, 4200, 2300, 123, 60),
        B_tri("V_G_2468", 1300, 4300, 2400, 125, 0),
        C_tri("B_G_9048", 1400, 4400, 2400, 130, 90); /* példányosítások */
    alap.kiir_rajt().setSum(alap.getIj()).kiir_cel();
    A_tri.kiir_rajt().setSum(A_tri.getIj()).kiir_cel(); /* láncolt hívások */
    B_tri.kiir_rajt().setSum(B_tri.getIj()).kiir_cel(); /* láncolt hívások */
    C_tri.kiir_rajt().setSum(C_tri.getIj()).kiir_cel(); /* láncolt hívások */
    cout << "\n"
         << endl;
    return 0;
}

// h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
// Az oRA értéke 3600 míg a pRC értéke 60.
/***************************************************************************************/

// Próba_zh_v2/2

/********* Decl.hpp ************/
#pragma once
#include <iostream>

using namespace std;

class tri_race /* Osztály deklarációja */
{
private:
    string lic;
    int swim, cycle, run, depo, ij;
    int sum, h, p, mp;
    const int oRA, pRC;

public:
    tri_race() : oRA(3600), pRC(60), h(0), p(0), mp(0), sum(0)
    {
        lic = "--------";
        swim = 0;
        cycle = 0;
        run = 0;
        depo = 0;
        ij = 0;
    }
    tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : oRA(3600), pRC(60),
                                                                  h(0), p(0), mp(0), sum(0)
    {
        lic = lc;
        swim = sw;
        cycle = cyc;
        run = rn;
        depo = dp;
        ij = t;
    }
    int getIj() const { return ij; }
    void kiir();
    tri_race &kiir_rajt();
    tri_race &kiir_cel();
    tri_race &setSum(int t);
    ~tri_race()
    {
        cout << "\nFelszabadítottam az objektum memóriacímét!";
    }
};

/************* 1.cpp *******************************************************************/


/********** main.cpp *******************************************************************/
#include "Decl.hpp"

int main(void)
{
    tri_race alap,
        A_tri("M_V_1357", 1200, 4200, 2300, 123, 60),
        B_tri("V_G_2468", 1300, 4300, 2400, 125, 0),
        C_tri("B_G_9048", 1400, 4400, 2400, 130, 90); /* példányosítások */
    alap.kiir_rajt().setSum(alap.getIj()).kiir_cel();
    A_tri.kiir_rajt().setSum(A_tri.getIj()).kiir_cel(); /* láncolt hívások */
    B_tri.kiir_rajt().setSum(B_tri.getIj()).kiir_cel(); /* láncolt hívások */
    C_tri.kiir_rajt().setSum(C_tri.getIj()).kiir_cel(); /* láncolt hívások */
    cout << "\n"
         << endl;
    return 0;
}

// h=sum/oRA; p=(sum%oRA)/pRC; mp=(sum%oRA)%pRC;
// Az oRA értéke 3600 míg a pRC értéke 60.
/***************************************************************************************/
