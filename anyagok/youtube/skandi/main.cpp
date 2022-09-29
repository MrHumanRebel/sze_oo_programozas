#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

using namespace std;

int fileread(int array[7][3000], string filename)
{
    int i = 0;
    int ugras = 0;
    int total = 0;

    ifstream file(filename);
    string aktSor;

    if (file.is_open())
    {
        while (getline(file, aktSor))
        {
            for (long unsigned int j = 0; j < aktSor.length(); j += 2)
            {
                if (ugras == 7)
                {
                    cout << endl;
                    ugras = 0;
                    i -= 6;
                }
                // cout << aktSor << endl;
                string akt = "\0";
                akt += aktSor[j];
                if (isdigit(aktSor[j + 1]) == true)
                {
                    akt += aktSor[j + 1];
                    j++;
                }
                array[ugras][i] = stoi(akt);
                cout << array[ugras][i] << '\t';
                //    cout << "Hely: " << ugras << "Hely2: " << i << endl;

                ugras++;
                i++;
                total++;
            }
            cout << endl;
        }
    }
    else
    {
        cout << "File read error!" << endl;
    }
    return total;
}

void counter(int numbers[7][3000], int appearance[7][35][2], int size)
{

    for (int i = 1; i <= 35; i++)
    {
        int id = 0;
        for (int k = 0; k < 7; k++)
        {
            for (int j = 0; j <= size; j++)
            {
                if (numbers[k][j] == i)
                {
                    appearance[k][id][0] = i;
                    appearance[k][id][1]++;
                }
            }
            if (appearance[k][id][1] != 0)
                cout << "Appearence of " << i << " in position " << k + 1 << " in data: " << appearance[k][id][1] << " db" << endl;
            id++;
        }
    }
}

int main()
{
    // Initialize variables

    int numbers[7][3000];
    int appearance[7][35][2];
    int sum_weight = 0;

    // Initialize arrays
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 35; j++)
        {
            appearance[i][j][0] = 0;
            appearance[i][j][1] = 0;
        }
    }
    for (int i = 0; i < 7; i++)
    {

        for (int j = 0; j < 3000; j++)
        {
            numbers[i][j] = 0;
        }
    }

    // Read file and get the number of draws
    int total_draws = fileread(numbers, "/home/szeke/projects/sze_oo_programozas/anyagok/youtube/skandi/testdata.txt");
    int total_picks = total_draws / 7;

    /*for (int i = 0; i < total_draws; i++)
    {
        cout << numbers[0][i] << endl;
    }*/

    cout << "Total draws: " << total_draws << endl;
    cout << "Total picks: " << total_picks << endl;

    counter(numbers, appearance, total_picks);

    /*
    for (int i = 0; i < num_choices; i++)
    {
        sum_of_weight += choice_weight[i];
    }
    int rnd = random(sum_of_weight);
    for (int i = 0; i < num_choices; i++)
    {
        if (rnd < choice_weight[i])
            return i;
        rnd -= choice_weight[i];
    }
    */
    return 0;
}
