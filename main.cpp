#include "list.h"
#include "player.h"
#include "list.cpp"
#include "player.cpp"
#include <fstream>
#include <iostream>
#include<string>
#include<sstream>
#include<stdio.h>

using namespace std;

int getNumLines(ifstream& in);

template <class T> static void getData(ifstream& in,List<T> *l);


int main()
{
	ifstream in("Punteggi.txt");
	List<Player> *lista = new List<Player>(true);
	getData(in,lista);
	//cout << *lista << endl;
	std::string cognome = "SARI";
	//lista->printCognome(cognome); ok!
	lista->printCognome2(cognome);
	double punteggio = 125;
	//cout << lista->search(punteggio);
	//lista->cancAllPunteggio(punteggio); ok!
	
}



template <class T> static void getData(ifstream& in,List<T> *l)
{
	//l = new List<T>(false);
	for(int task = 0; task < 21; task++)
	{
		string nome,cognome,circolo;
		double punteggio;
		int anno;
		std::string line = "";
		getline(in,line);
		//std::cout << line << std::endl;
		std::string delim = ";";
		std::string *tokens = new std::string[5];
		size_t pos = 0;
		int i = 0;
		std::string token;
		while ((pos = line.find(delim)) != std::string::npos)
		{
	   		token = line.substr(0, pos);
	   		tokens[i] = token; 
	   		line.erase(0, pos + delim.length());
	   		i++;	
		}
		tokens[i] = line;
		for(int i = 0; i< 5; i++)
		{
			switch(i){
				case 0:
				{
					cognome = tokens[i];
					/*std::cout << cognome << endl;
					std::cout << tokens[i] <<std::endl;*/
					continue;
				}
				case 1:
				{
					nome = tokens[i];
					/*std::cout << nome << endl;
					std::cout << tokens[i] <<std::endl;*/
					continue;
				}
				case 2:
				{
					circolo = tokens[i];
					/*std::cout << circolo << endl;
					std::cout << tokens[i] <<std::endl;*/
					continue;
				}
				case 3:
				{
					punteggio = (double) stod(tokens[i]);
					/*std::cout << punteggio << endl;
					std::cout << tokens[i] <<std::endl;*/
					continue;
				}
				case 4:
				{
					anno = (int) stoi(tokens[i]);
					/*std::cout << anno << endl;
					std::cout << tokens[i] <<std::endl;*/
					continue;
				}
			}		
		}
		l->ins(nome,cognome,circolo,punteggio,anno);
	}
	
	
		
}

int getNumLines(ifstream& in)
{
	string line;
	int n = 0;
	while(getline(in,line))
	{
		n++;
	}
	return n;
}


