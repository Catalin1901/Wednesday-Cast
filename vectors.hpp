#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string monsters[] = {"Vampire", "Wolf", "Mermaids", "Witch", "Human"};
string menu[] = {"normal", "veggie", "flexi"};

string desertn[] = {"tiramisu", "lava cake", "tort de ciocolata"};
string desertn_eng[] = {"tiramisu", "lava cake", "chocolate cake"};

string desertv[] = {"cheescake cu lamaie", "budinca", "placina cu mere"};
string desertv_eng[] = {"lemon cheescake", "pudding", "apple pie"};

string desertf[] = {"tort de mere", "compot de caiase", "tarta cu lamaie"};
string desertf_eng[] = {"apple cake", "apricot compote", "lemon tart"};

string soupn[] = {"supa de pui", "ciorba de vita", "ciorba a la grec"};
string soupn_eng[] = {"chicken soup", "beef soup", "soup a la grec"};

string soupv[] = {"supa de rosii", "supa crema de ciuperci", "supa de brocoli"};
string soupv_eng[] = {"tomato soup", " cream of mushroom soup", "brocoli soup"};

string soupf[] = {"supa de rosii", "supa crema de ciuperci", "supa de brocoli"};
string soupf_eng[] = {"tomato soup", " cream of mushroom soup", "brocoli soup"};

string feln[] = {"burgeri", "coaste de miel", "pui in 3 culori"};
string feln_eng[] = {"burgers", "lamb chops", "3 colors chicken"};

string felv[] = {"orez indian", "cartofi dulci gratinati", "lasagna cu ciuperci"};
string felv_eng[] = {"fried indian rice", "baked sweet potatoes", "lasagna with mushrooms"};

string felf[] = {"tacos cu ton", "paste cu rosii si praz", "burgeri cu somon"};
string felf_eng[] = {"tuna tacos", "pasta with tomatoes and leeks", "salmon burgers"};

vector<string> names = {"Sophia", "Sanjay", "Jacob", "Jon", "Isabella", "Guido", "Emma", "William", "Jayden", "Mehmet", "Emily", "Mia", "Noah", "Michael", "Ethan",
					   "Chloe", "Aiden", "Daniel", "Elizabeth", "Ava", "Avery", "Benjamin", "Gennady", "David", "Sofia", "Grace", "Andrew", "Bjarne", "Logan", "Zoey", "Alexis", "Lucas", "Gabriel",
					   "Kaylee", "Isaac", "Taylor", "Evan", "Landon", "Jack", "Alexa", "Fabrice", "Aaron", "Brandon", "Linus", "Steve", "Dough", "Connor", "Arianna", "Scarlett", "Eva", "Bourne",
					   "Dennis", "James", "Adam", "John", "Anders", "Stephen", "Jeff", "Ian", "Tim", "Brian", "Ken", "Ferhat", "Richard", "Petr", "Donald"};

vector<string> surnames = {"Smith", "Johnson", "Williams", "Brown", "Jones", "Rossum", "Watson", "Stone", "Miller", "Davis", "Torvalds", "Garcia", "Rodrigez", "Wilson", "Ethan",
						  "Anderson", "Clarke", "Thomas", "Lee", "Ava", "White", "Moore", "Hernandez", "Harris", "Sofia", "Grace", "Lewis", "Stroustrup", "Hall", "Zoey",
						  "Walker", "Perez", "Gabriel", "Lopez", "Newton", "Edison", "Evan", "Robinson", "Dorsey", "Alexa", "Fabrice", "Eder", "Fischer", "Clark", "Jobs",
						  "Doug", "Connor", "Arianna", "Scarlett", "Eva", "Again", "Schwarz", "Maier", "Mayr", "Egger", "Claes", "Nielsen", "Petersen", "Madsen", "Ilves",
						  "Robert", "Leroy", "Lion", "Martin", "Hawking", "Meyer", "Weber", "Schulz", "Becker", "Hoffmann", "Samaras", "koufos", "Kritikos", "Papp", "Jensen",
						  "Waage", "Kvaran", "Rossi", "Russo", "Ferrari", "Esposito", "Bianchi", "Romano", "Emine", "Egzon", "Arben", "Yilmaz", "Demir", "Sahin", "Celik", "Kaya",
						  "Aydin", "Ozdemir", "Arslan", "Dogan", "Kilic", "Yildiz", "Ozturk", "Yildirim", "Melnyk", "Kovalenko", "Boyko", "Koval", "Moroz", "Petrenko", "Robinson", "Wood",
						  "Ritchie", "Gosling", "Gontier", "John", "Anders", "Bezos", "Ian", "Cook", "Brian", "Gecdogan", "Richard", "Petr", "Donald"};


#endif