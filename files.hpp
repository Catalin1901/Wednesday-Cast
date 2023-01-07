#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include "name_generator.hpp"
using namespace std;

template <class T>
class Fisier
{
private:
    string fname;
    vector<vector<T>> content;
    vector<T> row;
    string line, word;

public:
    void saveFile(string file_name);
    vector<vector<string>> get_content();
    void addLine(string file_name, string name, string role);
    void removeLine(string file_name, int ID);
    void removeLine(string file_name);
     void writeFile(string file_name, vector<vector<string>> matrix);
    void addLine_header(string file_name, T nr_zile, T cost_tot, T cost_transport, T cost_cazare, T cost_machiaj, T cost_mancare, T cost_chirie);
    void addLine_cost(string file_name, T nr_zile, T cost_tot, T cost_transport, T cost_cazare, T cost_machiaj, T cost_mancare, T cost_chirie);
    void addLine_head(string file_name, string tip, string soup, string fel, string dessert);

    void generare_figuratie()
    {
        for (int i = 0; i < 132; i++)
        {
            this->addLine("wednesdayCast.csv", gen_names(i), "figuratie");
        }
    }

    int get_no_of_people()
    {
        return this->content.size();
    }
};

template <class T>
vector<vector<string>> Fisier<T>::get_content()
{
    return this->content;
}

template <class T>
void Fisier<T>::saveFile(string file_name)
{
    this->fname = file_name;

    fstream file(fname, ios::in);
    try
    {
        if (file.is_open())
        {
            while (getline(file, line))
            {
                row.clear();

                stringstream str(line);

                while (getline(str, word, ','))
                    row.push_back(word);
                content.push_back(row);
            }
        }
        else
        {
            throw this->fname;
        }
    }
    catch (...)
    {
        cout << "File " << this->fname << " could not open properly!\n";
        exit;
    }
}

template <class T>
void Fisier<T>::addLine(string file_name, string name, string role)
{
    this->fname = file_name;

    content.clear();
    this->saveFile(fname);

    int id = stoi(content[content.size() - 1][0]);

    fstream file(fname, ios::app);

    try
    {
        if (file.is_open())
        {
            file << '\n';
            file << id + 1 << ',' << name << ',' << role << ',';
        }
        else
        {
            throw this->fname;
        }
    }

    catch (...)
    {
        cout << "File " << this->fname << " could not open properly!";
        exit;
    }
}

template <class T>
void Fisier<T>::addLine_header(string file_name, T nr_zile, T cost_tot, T cost_transport, T cost_cazare, T cost_machiaj, T cost_mancare, T cost_chirie)
{
    this->fname = file_name;

    content.clear();
    this->saveFile(fname);

    fstream file(file_name, ios::app);

    try
    {
        if (file.is_open())
        {
            file << "ID" << ',' << nr_zile << ',' << cost_tot << ',' << cost_transport << ',' << cost_cazare << ',' << cost_machiaj << ',' << cost_mancare << ',' << cost_chirie << ',';
        }
        else
        {
            throw;
        }
    }

    catch (...)
    {
        cout << "File " << this->fname << " could not open properly!";
        exit;
    }
}

template <class T>
void Fisier<T>::addLine_head(string file_name, string tip, string soup, string fel, string dessert)
{
    this->fname = file_name;

    content.clear();
    this->saveFile(fname);

    fstream file(file_name, ios::app);

    try
    {
    start:
        if (file.is_open())
        {
            file << tip << ',' << soup << ',' << fel << ',' << dessert << ',';
            file << '\n';
        }
        else
        {
            fstream file(file_name);
            goto start;
        }
    }

    catch (...)
    {
        cout << "File " << this->fname << " could not open properly!";
        exit;
    }
}

template <class T>
void Fisier<T>::addLine_cost(string file_name, T nr_zile, T cost_tot, T cost_transport, T cost_cazare, T cost_machiaj, T cost_mancare, T cost_chirie)
{
    this->fname = file_name;

    content.clear();
    this->saveFile(fname);

    int id = content.size();

    fstream file(file_name, ios::app);

    try
    {
        if (file.is_open())
        {
            file << '\n';
            file << id << ',' << nr_zile << ',' << cost_tot << ',' << cost_transport << ',' << cost_cazare << ',' << cost_machiaj << ',' << cost_mancare << ',' << cost_chirie << ',';
        }
        else
        {
            throw this->fname;
        }
    }

    catch (...)
    {
        cout << "File " << this->fname << " could not open properly!";
        exit;
    }
}

template <class T>
void Fisier<T>::removeLine(string file_name, int ID)
{

    content.clear();
    this->saveFile(file_name);

    int ok = 0;

    for (int i = 1; i < content.size() && ok == 0; i++)
    {
        if(ID == 0)
        {
            ok = 1;
            content.erase(content.begin());
            break;
        }
        else if (stoi(content[i][0]) == ID)
        {
            ok = 1;
            content.erase(content.begin() + i);
            break;
        }
    }

    this->writeFile(file_name, content);
}

template <class T>
void Fisier<T>::removeLine(string file_name)
{

    content.clear();
    this->saveFile(file_name);

    int ok = 0;

    content.erase(content.begin(), content.end());

    this->writeFile(file_name, content);
}

template <class T>
void Fisier<T>::writeFile(string file_name, vector<vector<string>> matrix)
{
    this->fname = file_name;

    fstream file(fname, ios::out);

    try
    {
        if (file.is_open())
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                for (int j = 0; j < matrix[i].size(); j++)
                {
                    file << matrix[i][j] << ',';
                }
                if (i != matrix.size() - 1)
                {
                    file << '\n';
                }
            }
        }
        else
            throw this->fname;
    }

    catch (...)
    {
        cout << "File " << this->fname << " cout not open properly";
    }

    file.close();
}

template <class T>
class Actor : Fisier<T>
{
private:
    string name;
    string role;
    string monster = "0";
    string menu;

public:
    int cost_autobuz()
    {
        return this->get_no_of_people();
    }

    Actor() = default;

    Actor(string name, string role, string menu)
    {
        this->name = name;
        this->role = role;
        this->menu = menu;
    };

    Actor(string name, string role, string monstru, string menu)
    {
        this->monster = monstru;
        this->name = name;
        this->role = role;
        this->menu = menu;
    }

    string getname()
    {
        return this->name;
    }
    string gettype()
    {
        return this->monster;
    }

    string getmenu()
    {
        return this->menu;
    }
};

// class Cost: Actor
// {
// public:
//     int cost_autobuz()
//     {
//         return this->cost_autobuz()/50 * 5680;
//     }

//     int cost_apa()
//     {

//     }
// };
