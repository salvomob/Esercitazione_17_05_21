#include"player.h"
#include <sstream>

inline Player::Player(std::string nome, std::string cognome , std::string circolo , double punteggio , int anno)
{
	this->nome = new std::string(nome);
	this->cognome = new std::string(cognome);
	this->circolo = new std::string(circolo);
	this->punteggio = new double(punteggio);
	this->anno = new int(anno);
	this->next = NULL;
	this->prev = NULL;
}

inline Player::Player()
{
	this->nome = NULL;
	this->cognome = NULL;
	this->circolo = NULL;
	this->punteggio = NULL;
	this->anno = NULL;
	this->next = NULL;
	this->prev = NULL;
}
	
//metodi set
	
inline void Player::setNome(std::string nome)
{
	*(this->nome) = nome;
}
	
inline void Player::setCognome(std::string cognome)
{
	*(this->cognome) = cognome;
}
	
inline void Player::setCircolo(std::string circolo)
{
	*(this->circolo) = circolo;
}
	
inline void Player::setPunteggio(double punteggio)
{
	*(this->punteggio) = punteggio;
}	

inline void Player::setAnno(int anno)
{
	*(this->anno) = anno;
}

inline void Player::setNext(Player* next)
{
	this->next = next;
}
	
inline void Player::setPrev(Player* prev)
{
	this->prev = prev;
}	

//metodi get
	
inline std::string Player::getNome() const
{
	return *(this->nome);
}
	
inline std::string Player::getCognome() const
{
	return *(this->cognome);
}
	
inline std::string Player::getCircolo() const
{
	return *(this->circolo);
}
	
inline double Player::getPunteggio() const
{
	return *(this->punteggio);
}
	
inline int Player::getAnno() const
{
	return *(this->anno);
}
	
inline Player* Player::getNext() const
{
	return this->next;
}
	
inline Player* Player::getPrev() const
{
	return this->prev;
}

inline bool Player::operator>=(Player& p)
{
	return (*(this->punteggio) >= p.getPunteggio());
}
	
inline bool Player::operator<(Player& p)
{
	return (*(this->punteggio) < p.getPunteggio());
}

inline void Player::operator=(Player& p)
{
	*(this->nome) = p.getNome();
	*(this->cognome) = p.getCognome();
	*(this->circolo) = p.getCircolo();
	*(this->punteggio) = p.getPunteggio();
	*(this->anno) = p.getAnno();
	this->next = p.getNext();
	this->prev = p.getPrev();
}

std::ostream& operator<<(std::ostream& out, const Player& p)
{
	Player tmp = p;
	out << "Nome : " << p.getNome() << "\n";	
	out << "Cognome : " << p.getCognome() << "\n";	
	out << "Circolo : " << p.getCircolo() << "\n";	
	out << "Punteggio : " << p.getPunteggio() << "\n";
	out << "Anno : " << p.getAnno() << "\n";
	return out;				
}

std::istream& operator>>(std::istream& in, Player& p)
{
	std::string line = "";
	getline(in,line);
	std::cout << line << std::endl;
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
				p.setCognome(tokens[i]);
				std::cout << tokens[i] << std::endl;
				continue;
			}
			case 1:
			{
				p.setNome(tokens[i]);
				std::cout << tokens[i] << std::endl;
				continue;
			}
			case 2:
			{
				p.setCircolo(tokens[i]);
				std::cout << tokens[i] << std::endl;
				continue;
			}
			case 3:
			{
				p.setPunteggio((double)stoi(tokens[i]));
				std::cout << tokens[i] << std::endl;
				continue;
			}
			case 4:
			{
				p.setAnno((int)stoi(tokens[i]));
				std::cout << tokens[i] << std::endl;
				continue;
			}
		}		
	}
	
	return in;
}
