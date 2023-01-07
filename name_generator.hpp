#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include "vectors.hpp"
using namespace std;


string gen_names(int x)
{

	srand(x + (unsigned)time(NULL));
	int i = rand() % 60;
	int j = rand() % 120;

	string nume;
	nume = names[i] + " " + surnames[j];


	return nume;
}
