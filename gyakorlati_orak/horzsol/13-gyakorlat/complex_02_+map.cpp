complex / &referencia használata + map
/********* Decl.hpp ************/
#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

    using namespace std;

class tri_race
{
    int sum;

protected:
    class memb
    {
        string lic;
        int swim, cycle, run, depo, ij;

    public:
        string getLic() const { return lic; }
        int getSwim() const { return swim; }
        int getCycle() const { return cycle; }
        int getRun() const { return run; }
        int getDepo() const { return depo; }
        int getIj() const { return ij; }
        void setLic(string lc) { lic = lc; }
        void setSwim(int sw) { swim = sw; }
        void setCycle(int cyc) { cycle = cyc; }
        void setRun(int rn) { run = rn; }
        void setDepo(int dp) { depo = dp; }
        void setIj(int t) { ij = t; }
        memb() { cout << "\nAz alapértelmezett szülő-tag adatszerkezet létrejött."; }
        ~memb() { cout << "\nFelszabadítottam a szülő-tag adatszerkezet memóriacímét"; }
    };
    memb tagok;
    tri_race() : sum(0)
    {
        tagok.setLic("--------");
        tagok.setSwim(0);
        tagok.setCycle(0);
        tagok.setRun(0);
        tagok.setDepo(0);
        tagok.setIj(0);
        cout << "\nAz alapértelmezett szülő-adatszerkezet létrejött.";
    }
    tri_race(string lc, int sw, int cyc, int rn, int dp, int t) : sum(0)
    {
        tagok.setLic(lc);
        tagok.setSwim(sw);
        tagok.setCycle(cyc);
        tagok.setRun(rn);
        tagok.setDepo(dp);
        tagok.setIj(t);
        cout << "\nA paraméteres szülő-adatszerkezet létrejött.";
    }
    int getSum() const { return sum; }
    tri_race &setSum();
    virtual ~tri_race()
    {
        cout << "\nFelszabadítottam a szülő-adatszerkezet memóriacímét.";
    }

public:
    virtual tri_race &kiir_cel() = 0;
};

class h_m_s
{
    const int oRA, pRC;

protected:
    typedef pair<int, int> pmp;
    typedef pair<int, pmp> hpmp;      // a hpmp vector adat-helyei
    typedef pair<int, hpmp> s_hpmp;   // a sps vector adat-helye
    typedef pair<string, s_hpmp> j_s; // a jelek vector adat-helye
    map<int, j_s> cplx;               // a kulcs adat-helye
    h_m_s() : oRA(3600), pRC(60)
    {
        cout << "\nAz alapértelmezett átszámoló szülő-adatszerkezet létrejött.";
    }
    void s_hms(int s, int *h, int *p, int *mp)
    {
        *h = s / oRA;
        *p = (s % oRA) / pRC;
        *mp = (s % oRA) % pRC;
    }
    ~h_m_s()
    {
        cout << "\nFelszabadítottam az átszámoló szülő-adatszerkezet memóriacímét.";
    }
    virtual h_m_s &kiir_cel() {}
};

class in_ch : protected tri_race, protected h_m_s
{
    int kat;
    int getKat() const { return kat; }
    void setKat(int kt) { kat = kt; }
    vector<in_ch *> objs;

protected:
    in_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt) : tri_race(lc, sw, cyc, rn, dp, t)
    {
        setKat(kt);
        if (kt != 4)
            cout << "\nA paraméteres gyerek-objektum létrejött";
        else
            cout << "\nA paraméteres gyerek-adatszerkezet létrejött.";
    }
    void kiir_i4();
    void fuz(in_ch *);
    in_ch &kiir_cel() override;

public:
    in_ch() : tri_race()
    {
        setKat(0);
        cout << "\nAz alapértelmezett gyerek-objektum létrejött";
    }
    void ch_objs();
    void ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt);
    void ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm);
    void mind1();
    void b_mem(in_ch *, bool);
    virtual ~in_ch();
    in_ch(const in_ch &) = delete;
    in_ch &operator=(const in_ch &) = delete;
};

class in_gr_ch : public in_ch
{
    char nem;
    char getNem() const { return nem; }
    void setNem(char nm) { nem = nm; }

protected:
    in_gr_ch() : in_ch() { setNem('N'); }
    in_gr_ch(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm) : in_ch(lc, sw, cyc, rn, dp, t, kt)
    {
        setNem(nm);
        cout << "\nA paraméteres unoka-objektum létrejött";
    }
    in_gr_ch &kiir_cel() override;
    virtual ~in_gr_ch()
    {
        cout << "\nFelszabadítottam az unoka-objektum saját adatának a memóriacímét.";
    }
    friend void in_ch::ch_objs(string, int, int, int, int, int, int, char);
};

/********* 1.cpp ************/
#include "Decl.hpp"

void in_ch::ch_objs()
{
    in_ch *alap = new in_ch();
    fuz(alap);
}

void in_ch::ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt)
{
    in_ch *x_tri = new in_ch(lc, sw, cyc, rn, dp, t, kt);
    fuz(x_tri);
}

void in_ch::ch_objs(string lc, int sw, int cyc, int rn, int dp, int t, int kt, char nm)
{
    in_gr_ch *x_tri = new in_gr_ch(lc, sw, cyc, rn, dp, t, kt, nm);
    fuz(x_tri);
}

void in_ch::fuz(in_ch *x_tri)
{
    objs.push_back(x_tri);
    cout << ", a címe: " << x_tri << endl;
}

void in_ch::kiir_i4()
{
    const int &tgS = tagok.getSwim(), &tgC = tagok.getCycle(), &tgD = tagok.getDepo(),
              &tgR = tagok.getRun(), &tgI = tagok.getIj();
    cout << "\nLicence: " << tagok.getLic() << endl;
    cplx = {{0, {"Rajt idő:", {0, {0, {0, 0}}}}},
            {1, {"Ú:\t\t ", {tgS, {0, {0, 0}}}}},
            {2, {"B:\t\t ", {tgC, {0, {0, 0}}}}},
            {3, {"D:\t\t ", {tgD, {0, {0, 0}}}}},
            {4, {"Ú+B+D:\t ", {tgS + tgC + tgD, {0, {0, 0}}}}},
            {5, {"F:\t\t ", {tgR, {0, {0, 0}}}}},
            {6, {"T-:\t\t ", {tgI, {0, {0, 0}}}}},
            {7, {"Cél idő: ", {getSum(), {0, {0, 0}}}}}};
    for (auto it = cplx.begin(); it != cplx.end(); it++)
    {
        string &m_ris = it->second.first;
        int &m_s = it->second.second.first,
            &m_h = it->second.second.second.first,
            &m_p = it->second.second.second.second.first,
            &m_mp = it->second.second.second.second.second;
        s_hms(m_s, &m_h, &m_p, &m_mp);
        cout << m_ris << " ";
        cout << setw(2) << m_h << ":" << setw(2) << m_p << ":"
             << setw(2) << m_mp << " [h:m:s]\n";
    }
    cout << "Kategória: " << getKat() << endl;
}

in_ch &in_ch::kiir_cel()
{
    kiir_i4();
    return *this;
}

in_gr_ch &in_gr_ch::kiir_cel()
{
    kiir_i4();
    cout << "Nem: " << getNem() << endl;
    return *this;
}

tri_race &tri_race::setSum()
{
    sum = tagok.getSwim() + tagok.getCycle() + tagok.getRun() + tagok.getDepo() - tagok.getIj();
    return *this;
}

void in_ch::mind1()
{
    cout << endl;
    for (auto it : objs)
    {
        in_gr_ch *rp = dynamic_cast<in_gr_ch *>(it);
        if (rp != nullptr)
        {
            cout << "\nUnoka ";
        }
        else
        {
            in_ch *rp = dynamic_cast<in_ch *>(it);
            if (rp != nullptr)
            {
                cout << "\nGyerek ";
            }
        }
        cout << "objektum;";
        it->setSum().kiir_cel();
    }
}

in_ch::~in_ch()
{
    for (vector<in_ch *>::reverse_iterator it = objs.rbegin();
         it != objs.rend(); it++)
    {
        delete *it;
        cout << ", amely: " << *it << endl;
        *it = 0;
    }
    cout << "\nFelszabadítottam a gyerek-objektum saját adatának a memóriacímét. ";
}

void in_ch::b_mem(in_ch *b, bool ev)
{
    cout << ", base = " << b << endl;
    if (ev)
        b = 0;
}

/********* main.cpp ************/
#include "Decl.hpp"

int main(void)
{
    in_ch *base = new in_ch();
    base->b_mem(base, 0);
    base->ch_objs();
    base->ch_objs("M_V_1357", 1200, 4200, 2300, 123, 60, 6);
    base->ch_objs("V_G_2468", 1300, 4300, 2400, 125, 0, 6);
    base->ch_objs("B_G_9048", 1400, 4400, 2400, 130, 90, 6);
    base->ch_objs("C_H_1234", 1450, 4400, 2400, 130, 30, 5);
    base->ch_objs("G_R_4321", 1500, 4450, 2350, 120, 0, 4, 'F');
    base->mind1();
    delete base;
    base->b_mem(base, 1);
    return 0;
}
/***************************************************************************************/
