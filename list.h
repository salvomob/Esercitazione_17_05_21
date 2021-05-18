#ifndef LIST_H
#define LIST_H
#include"player.h"
#include<string>
template <class T> class List
{
private:
	int n;//numero elementi nella lista
	bool order;
	Player *header,*trailer,*current;
	
	Player* _searchT(double punteggio);//ricerca nel caso in cui order sia true e quindi lista ordinata in ordine di punteggio crescente last ->  -> first
	Player* _searchF(double punteggio);//ricerca nel caso in cui order sia false e quindi lista ordinata in ordine decrescente first ->  -> last
	

public:
	List(bool order);
	
	List<T>& ins(std::string nome , std::string cognome , std::string circolo , double punteggio , int anno);
	
	List<T>& canc(double punteggio);
	
	int search(double punteggio);
	
	int nPunteggio(double punteggio);
	
	//iteratore
	
	void reset();
	
	int hasNext();
	
	Player* next();	
	
	int isEmpty();
	
	void printCognome(std::string cognome);
	
	void printCognome2(std::string cognome);
	
	List<T>& cancAllPunteggio(double punteggio);

};

#endif

template <class T> std::ostream& operator<<(std::ostream& , const List<T>& l);
