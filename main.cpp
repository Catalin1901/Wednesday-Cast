#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include "files.hpp"
#include "vectors.hpp"
using namespace std;

float calcul_cazare()
{
    Fisier<string> act;

    act.saveFile("wednesdayCast.csv");
    int rooms_two = round((act.get_no_of_people() - 132) / 2 + 0.5);
    int rooms_three = round(132 / 3);

    float cost_total;

    cost_total = 350 * rooms_two + 420 * rooms_three;

    return cost_total / 4.65;
}

float cost_chirie(int zile)
{
    float cost = 0;

    cost = zile * 10000;

    int reducere;
    reducere = floor(zile / 10) * 2000;

    cost = (cost - reducere) / 4.65;

    return cost;
}

int main()
{

    // Prices per day
    float cost_total_dolari = 0;
    float cost_machiaj_dolari = 0;
    float cost_mancare_dolari = 0;
    float cost_spatiu_dolari = 0;
    float cost_cazare_dolari = 0;
    float cost_transport_dolari = 0;

    Fisier<string> fis;
    vector<vector<string>> matrix;

    // stergerea figuratiei generate precedent
    for (int i = 736; i < 868; i++)
    {
        fis.removeLine("wednesdayCast.csv", i);
    }

    // stergerea costurilor generate anterior
    fis.removeLine("cost_final.csv");

    // stergerea meniului creat anterior

    fis.removeLine("menu.csv");

    fis.generare_figuratie();

    matrix = fis.get_content();

    vector<Actor<string>> People;

    // generare costume si mancare
    for (int i = 0; i < matrix.size(); i++)
    {
        int mon = rand() % 5;
        int men = rand() % 3;

        if (matrix[i][2].find("actor") != string::npos || matrix[i][2].find("figuratie") != string::npos)
        {
            Actor<string> fis(matrix[i][1], matrix[i][2], monsters[mon], menu[men]);

            // costul pentru machiaj per zi
            switch (mon)
            {

            case 0:
                cost_machiaj_dolari += 230 / 4.65;
            case 1:
                cost_machiaj_dolari += 555 / 4.65;
            case 2:
                cost_machiaj_dolari += 345 / 4.65;
            case 3:
                cost_machiaj_dolari += 157 / 4.65;
            case 4:
                cost_machiaj_dolari += 55 / 4.65;
            }

            // costul pentru mancare per zi
            switch (men)
            {
            case 0:
                cost_mancare_dolari += 40 / 4.65;
            case 1:
                cost_mancare_dolari += 33 / 4.65;
            case 2:
                cost_mancare_dolari += 46 / 4.65;
            }

            // costul de mancare plus apa
            cost_mancare_dolari += 3 / 4.65 + 15 / 4.65 + 3.2 / 4.65;

            People.push_back(fis);
        }
        else
        {
            Actor<string> fis(matrix[i][1], matrix[i][2], menu[men]);

            switch (men)
            {
            case 0:
                cost_mancare_dolari += 40 / 4.65;
            case 1:
                cost_mancare_dolari += 33 / 4.65;
            case 2:
                cost_mancare_dolari += 46 / 4.65;
            }

            cost_mancare_dolari += 3 / 4.65 + 15 / 4.65 + 3.2 / 4.65;

            People.push_back(fis);
        }
    }

    cost_transport_dolari = ((ceil(fis.get_no_of_people() / 50 + 0.5) * 5680) / 4.65);

    cost_cazare_dolari = calcul_cazare();

    cost_mancare_dolari = (unsigned)cost_mancare_dolari;
    cost_cazare_dolari = (unsigned)cost_cazare_dolari;
    cost_machiaj_dolari = (unsigned)cost_machiaj_dolari;
    cost_transport_dolari = (unsigned)cost_transport_dolari;
    cost_total_dolari = cost_cazare_dolari + cost_machiaj_dolari + cost_mancare_dolari + cost_transport_dolari;

    // Creare CSV cu costuri finale
    Fisier<string> final, meniu;

    cout << "English or Romanian(E/R): ";
    char lang;
    int s, f, d, i, j;
    srand((unsigned)time(NULL));

start:
    cin >> lang;

    // selectare limba
    switch (lang)
    {
    case 'E':
        final.addLine_header("cost_final.csv", "NO_Days", "Total Cost", "Transportation Cost", "Accomodation Cost", "Makeup Cost", "Food and water Cost", "Palace Rental Cost");
        meniu.addLine_head("menu.csv", "Type", "Soup", "Main course", "Dessert");

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                s = rand() % 3;
                f = rand() % 3;
                d = rand() % 3;
                if (i == 0)
                    meniu.addLine_head("menu.csv", menu[i], soupn_eng[s], feln_eng[f], desertn_eng[d]);
                else if (i == 1)
                    meniu.addLine_head("menu.csv", menu[i], soupv_eng[s], felv_eng[f], desertv_eng[d]);
                else
                    meniu.addLine_head("menu.csv", menu[i], soupf_eng[s], felf_eng[f], desertf_eng[d]);
            }
        }
        break;
    case 'R':
        final.addLine_header("cost_final.csv", "NR ZILE", "Cost Total", "Cost Transport", "Cost Cazare", "Cost Machiaj", "Cost Mancare", "Cost Chirie");
        meniu.addLine_head("menu.csv", "Tip", "Supa", "Fel principal", "Desert");

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                s = rand() % 3;
                f = rand() % 3;
                d = rand() % 3;
                if (i == 0)
                    meniu.addLine_head("menu.csv", menu[i], soupn[s], feln[f], desertn[d]);
                else if (i == 1)
                    meniu.addLine_head("menu.csv", menu[i], soupv[s], felv[f], desertv[d]);
                else
                    meniu.addLine_head("menu.csv", menu[i], soupf[s], felf[f], desertf[d]);
            }
        }
        break;
    default:
        cout << "Wrong input. Please try again!\n";
        goto start;
    }

    final.addLine_cost("cost_final.csv", to_string(30), to_string((cost_total_dolari * 30 + cost_chirie(30))), to_string(cost_transport_dolari),
                       to_string(cost_cazare_dolari * 30), to_string(cost_machiaj_dolari * 30), to_string(cost_mancare_dolari * 30), to_string(cost_chirie(30)));

    final.addLine_cost("cost_final.csv", to_string(45), to_string((cost_total_dolari * 45 + cost_chirie(45))), to_string(cost_transport_dolari),
                       to_string(cost_cazare_dolari * 45), to_string(cost_machiaj_dolari * 45), to_string(cost_mancare_dolari * 45), to_string(cost_chirie(45)));

    final.addLine_cost("cost_final.csv", to_string(60), to_string((cost_total_dolari * 60 + cost_chirie(60))), to_string(cost_transport_dolari),
                       to_string(cost_cazare_dolari * 60), to_string(cost_machiaj_dolari * 60), to_string(cost_mancare_dolari * 60), to_string(cost_chirie(60)));

    final.addLine_cost("cost_final.csv", to_string(100), to_string((cost_total_dolari * 100 + cost_chirie(100))), to_string(cost_transport_dolari),
                       to_string(cost_cazare_dolari * 100), to_string(cost_machiaj_dolari * 100), to_string(cost_mancare_dolari * 100), to_string(cost_chirie(100)));
}