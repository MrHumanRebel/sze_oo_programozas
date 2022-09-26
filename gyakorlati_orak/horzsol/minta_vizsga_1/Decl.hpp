using namespace std;

class tri_race
{
private:
    char azonosito;
    int swim;
    int cycle;
    int run;
    int depo;
    int correction;
    const int ora;
    const int perc;

public:
    alap() : ora(3600), perc(60) // Alapértelmezett konstruktor + inicializáló lista
    {
        azonosito = "--------";
        swim = 0;
        cycle = 0;
        run = 0;
        depo = 0;
        correction = 0;
    }
    alap(char az, int sw, int cy, int ru, int de, int co) : ora(3600), perc(60) // Alapérték beállító konstruktor + inicializáló lista
    {
        azonosito = az;
        swim = sw;
        cycle = cy;
        run = ru;
        depo = de;
        correction = co;
    }
    ~tri_race() // Destruktor
    {
        cout << "A törléseket elvégeztem\n";
    }

    // Getter
    int getIj() const { return correction; } // Idő jóváírás getter

    // Setter
    int setSum(int sw, int cy, int ru, int de, int co)
    {
        int sum = sw + cy + ru + de - co;
        return const sum;
    };
};
