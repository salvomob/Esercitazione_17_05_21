#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include<iostream>

class Player
{
private:
	std::string *cognome;
	std::string *nome;
	std::string *circolo;
	double *punteggio;
	int *anno;
	Player *next,*prev;
	
public:
	Player(std::string nome, std::string cognome , std::string circolo , double punteggio , int anno);
	
	Player();
	//metodi set
	
	void setNome(std::string nome);
	
	void setCognome(std::string cognome);
	
	void setCircolo(std::string circolo);
	
	void setPunteggio(double punteggio);
	
	void setAnno(int anno);
	
	void setNext(Player* next);
	
	void setPrev(Player* prev);
	
	//metodi get
	
	std::string getNome() const;
	
	std::string getCognome() const;
	
	std::string getCircolo() const;
	
	double getPunteggio() const;
	
	int getAnno() const;
	
	Player* getNext() const;
	
	Player* getPrev() const;
	
	bool operator>=(Player& p);
	
	bool operator<(Player& p);
	
	void operator=(Player& p);

};

#endif

std::ostream& operator<<(std::ostream& out, const Player& p);

std::istream& operator>>(std::istream& in, Player& p);
