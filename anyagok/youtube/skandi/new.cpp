#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

int random(int tol, int ig)
{
    return (tol + rand() % (ig - tol + 1));
}

int weightrand(double Weight[]) // https://stackoverflow.com/questions/1761626/weighted-random-numbers
{
    int sum_of_weight = 0;
    for (int i = 1; i <= 35; i++)
    {
        sum_of_weight += Weight[i];
    }
    cout << "Weight sum: " << sum_of_weight << endl;
    int rnd = random(0, sum_of_weight);
    cout << "Rand gen: " << rnd << endl;
    for (int i = 1; i <= 35; i++)
    {
        if (rnd < Weight[i])
            return i;
        rnd -= Weight[i];
    }
}
int main()
{
    // Initialize random generator
    int seed = rand();
    srand(time(NULL) + seed);

    // Define variables
    string filename = "/home/szeke/projects/sze_oo_programozas/anyagok/youtube/skandi/testdata.txt";

    // Define arrays
    int firstPlace[3500];
    int secondPlace[3500];
    int thirdPlace[3500];
    int fourthPlace[3500];
    int fifthPlace[3500];
    int sixthPlace[3500];
    int seventhPlace[3500];
    //##################################################################################################################

    // File read
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    int i5 = 0;
    int i6 = 0;
    int i7 = 0;
    int total = 0;
    int placecounter = -1;

    ifstream file(filename);
    string aktSor;

    if (file.is_open())
    {
        while (getline(file, aktSor))
        {
            for (long unsigned int j = 0; j < aktSor.length(); j++)
            {
                string akt = "\0";
                bool ok = false;

                if (placecounter == 6)
                {
                    placecounter = -1;
                }

                // Single digit
                if (isdigit(aktSor[j]) == true)
                {
                    if (isdigit(aktSor[j + 1]) != true)
                    {
                        akt += aktSor[j];
                        placecounter++;
                        ok = true;
                        // cout << "Single digit" << endl;
                    }
                }

                // Two digits
                if (isdigit(aktSor[j]) == true)
                {
                    if (isdigit(aktSor[j + 1]) == true)
                    {
                        akt += aktSor[j];
                        akt += aktSor[j + 1];
                        placecounter++;
                        j++;
                        ok = true;
                        // cout << "Two digits" << endl;
                    }
                }

                if (ok == true)
                {
                    int value = stoi(akt);

                    if (placecounter == 0 && value != 0)
                    {
                        firstPlace[i1] = value;
                        i1++;
                    }
                    if (placecounter == 1 && value != 0)
                    {
                        secondPlace[i2] = value;
                        i2++;
                    }
                    if (placecounter == 2 && value != 0)
                    {
                        thirdPlace[i3] = value;
                        i3++;
                    }
                    if (placecounter == 3 && value != 0)
                    {
                        fourthPlace[i4] = value;
                        i4++;
                    }
                    if (placecounter == 4 && value != 0)
                    {
                        fifthPlace[i5] = value;
                        i5++;
                    }
                    if (placecounter == 5 && value != 0)
                    {
                        sixthPlace[i6] = value;
                        i6++;
                    }
                    if (placecounter == 6 && value != 0)
                    {
                        seventhPlace[i7] = value;
                        i7++;
                    }
                    // cout << firstPlace[i1-1] << "\t" << secondPlace[i2-1] << "\t" << thirdPlace[i3-1] << "\t" << fourthPlace[i4-1] << "\t" << fifthPlace[i5-1] << "\t" << sixthPlace[i6-1] << "\t" << seventhPlace[i7-1] << "\t" << endl;
                    total++;
                }
            }
        }
    }
    else
    {
        cout << "File read error!" << endl;
    }
    //##################################################################################################################

    // Read logic test
    /*
    for (int i = 0; i < i7; i++)
    {
        cout << firstPlace[i] << "  ";
        cout << secondPlace[i] << "  ";
        cout << thirdPlace[i] << "  ";
        cout << fourthPlace[i] << "  ";
        cout << fifthPlace[i] << "  ";
        cout << sixthPlace[i] << "  ";
        cout << seventhPlace[i] << endl;
    }
    cout << endl;
    */
    //##################################################################################################################

    // Counter initialize
    int firstCounter[35];
    int secondCounter[35];
    int thirdCounter[35];
    int fourthCounter[35];
    int fifthCounter[35];
    int sixthCounter[35];
    int seventhCounter[35];

    for (int i = 0; i < 35; i++)
    {
        firstCounter[i] = 0;
        secondCounter[i] = 0;
        thirdCounter[i] = 0;
        fourthCounter[i] = 0;
        fifthCounter[i] = 0;
        sixthCounter[i] = 0;
        seventhCounter[i] = 0;
    }
    //##################################################################################################################

    // Counter logic
    for (int currentvalue = 1; currentvalue <= 35; currentvalue++)
    {
        for (int i = 0; i < i1; i++)
        {
            if (firstPlace[i] == currentvalue)
                firstCounter[currentvalue]++;
        }
        for (int i = 0; i < i2; i++)
        {
            if (secondPlace[i] == currentvalue)
                secondCounter[currentvalue]++;
        }
        for (int i = 0; i < i3; i++)
        {
            if (thirdPlace[i] == currentvalue)
                thirdCounter[currentvalue]++;
        }
        for (int i = 0; i < i4; i++)
        {
            if (fourthPlace[i] == currentvalue)
                fourthCounter[currentvalue]++;
        }
        for (int i = 0; i < i5; i++)
        {
            if (fifthPlace[i] == currentvalue)
                fifthCounter[currentvalue]++;
        }
        for (int i = 0; i < i6; i++)
        {
            if (sixthPlace[i] == currentvalue)
                sixthCounter[currentvalue]++;
        }
        for (int i = 0; i < i7; i++)
        {
            if (seventhPlace[i] == currentvalue)
                seventhCounter[currentvalue]++;
        }
    }
    //##################################################################################################################

    // Counter logic test
    /*
    for (int i = 1; i <= 35; i++)
    {
        cout << "Current value: " << i << " Counter: " << seventhCounter[i] << endl;
    }
    */
    //##################################################################################################################

    // Weight initilize
    double firstWeight[35];
    double secondWeight[35];
    double thirdWeight[35];
    double fourthWeight[35];
    double fifthWeight[35];
    double sixthWeight[35];
    double seventhWeight[35];

    for (int i = 0; i < 35; i++)
    {
        firstWeight[i] = 0.0;
        secondWeight[i] = 0.0;
        thirdWeight[i] = 0.0;
        fourthWeight[i] = 0.0;
        fifthWeight[i] = 0.0;
        sixthWeight[i] = 0.0;
        seventhWeight[i] = 0.0;
    }
    //##################################################################################################################

    // Weight logic

    for (int currentvalue = 1; currentvalue <= 35; currentvalue++)
    {

        firstWeight[currentvalue] = (firstCounter[currentvalue] * 1.0) / i1;
        cout << "At " << currentvalue << " the weight: " << firstWeight[currentvalue] << endl;
        secondWeight[currentvalue] = (secondCounter[currentvalue] * 1.0) / i2;
        thirdWeight[currentvalue] = (thirdCounter[currentvalue] * 1.0) / i3;
        fourthWeight[currentvalue] = (fourthCounter[currentvalue] * 1.0) / i4;
        fifthWeight[currentvalue] = (fifthCounter[currentvalue] * 1.0) / i5;
        sixthWeight[currentvalue] = (sixthCounter[currentvalue] * 1.0) / i6;
        seventhWeight[currentvalue] = (seventhCounter[currentvalue] * 1.0) / i7;
    }
    //##################################################################################################################

    // Random logic

    cout << "Total draws: " << i7 << endl;
    int firstRand = weightrand(firstWeight);
    cout << "First rand num: " << firstRand << endl;

    return 0;
}