#include"list.h"

template <class T> Player* List<T>::_searchT(double punteggio)
{
	Player *tmp = this->header->getNext();
	while(tmp!=trailer && tmp->getPunteggio()< punteggio) tmp = tmp->getNext();//potrei usare il confronto fra Players tramite l'operatore < , ma per sicurezza vado coi valori esatti
	if(tmp==trailer) return NULL;
	if(tmp->getPunteggio() == punteggio) return tmp;
	return NULL;
}

template <class T> Player* List<T>::_searchF(double punteggio)
{
	Player *tmp = this->header->getNext();
	while(tmp!=trailer && tmp->getPunteggio()< punteggio) tmp = tmp->getNext();//potrei usare il confronto fra Players tramite l'operatore >=, ma per sicurezza vado coi valori esatti
	if(tmp==trailer) return NULL;
	if(tmp->getPunteggio() == punteggio) return tmp;
	return NULL;
}

template <class T> List<T>::List(bool order)
{
	this->order = order;
	this->n=0;
	this->header= new Player();
	this->trailer = new Player();
	this->header->setNext(this->trailer);
	this->trailer->setPrev(this->header);
	this->current = NULL;
}

template <class T> List<T>& List<T>::ins(std::string nome , std::string cognome , std::string circolo , double punteggio , int anno)
{
	if(this->order)
	{
		Player *tmp = this->header->getNext();
		while(tmp!=this->trailer && tmp->getPunteggio() < punteggio) tmp = tmp->getNext();
		Player *x = new Player(nome,cognome,circolo,punteggio,anno);
		n++;
		//devo inserire la chiave prima di tmp
		x->setNext(tmp);
		x->setPrev(tmp->getPrev());		
	 	tmp->getPrev()->setNext(x);
		tmp->setPrev(x);				
		return *this;
	}
	else
	{
		Player *tmp = this->header->getNext();
		while(tmp!=this->trailer && tmp->getPunteggio() >= punteggio) tmp = tmp->getNext();
		Player *x = new Player(nome,cognome,circolo,punteggio,anno);
		n++;
		//devo inserire la chiave prima di tmp
		x->setNext(tmp);
		x->setPrev(tmp->getPrev());		
	 	tmp->getPrev()->setNext(x);
		tmp->setPrev(x);				
		return *this;
	}
	return *this;
}

template <class T> List<T>& List<T>::canc(double punteggio)
{
	if(this->order)
	{
		Player *x =_searchT(punteggio);
		if(x!=NULL){
			Player *y = x->getPrev();
			Player *z = x->getNext();
			y->setNext(z);
			z->setPrev(y);
			this->n = this->n-1;
			//std::cout << *x << std::endl;
			delete x;
		}	
		return *this;
	}
	else
	{
		Player *x =_searchF(punteggio);
		if(x!=NULL){
			Player *y = x->getPrev();
			Player *z = x->getNext();
			y->setNext(z);
			z->setPrev(y);
			this->n = this->n-1;
			//std::cout << *x << std::endl;
			delete x;
		}	
		return *this;
	}
	return *this;
}

template <class T> int List<T>::search(double punteggio)
{
	if(this->order)
		return (_searchT(punteggio)!=NULL);
	else
		return (_searchF(punteggio)!=NULL);	
}

template <class T> int List<T>::isEmpty()
{
	return (this->n==0);
}

//iteratore

template <class T> void List<T>::reset()
{
	current = this->header->getNext();	
}

template <class T> int List<T>::hasNext()
{
	return (this->current != this->trailer);
}

template <class T> Player* List<T>::next()
{
	if(hasNext())
	{
			Player *tmp = new Player(current->getNome(),current->getCognome(),current->getCircolo(),current->getPunteggio(),current->getAnno());
			current = current->getNext();
			return tmp;
	}
		else return NULL;
}

template <class T> void List<T>::printCognome(std::string cognome)
{
		Player *tmp = this->header->getNext();
		while(tmp!=trailer && tmp->getCognome() != cognome) tmp = tmp->getNext();
		if(tmp==trailer) std::cout << "COGNOME NON IN LISTA\n";
		if(tmp->getCognome() == cognome) std::cout << *tmp <<std::endl;	
}

template <class T> void List<T>::printCognome2(std::string cognome)
{
		Player *tmp = this->header->getNext();
		while(tmp!=trailer && tmp->getCognome() != cognome) tmp = tmp->getNext();
		if(tmp==trailer) std::cout << "COGNOME NON IN LISTA\n";
		if(tmp->getCognome() == cognome) std::cout << *tmp <<std::endl;
		double points = tmp->getPunteggio();
		Player *tmp1 = this->header->getNext();
		if(this->order)
		{
			while(tmp1!=trailer )
			{
				if(tmp1->getPunteggio() == points)
				{
					std::cout << *tmp1 << std::endl;
				}
				tmp1 = tmp1->getNext();	
			}
		}
		else
		{
			while(tmp1!=trailer)
			{
				if(tmp1->getPunteggio() == points)
				{
					std::cout << *tmp1 << std::endl;
				}
				tmp1 = tmp1->getNext();	
			}
		}
				
}

template <class T> List<T>& List<T>::cancAllPunteggio(double punteggio)
{
	int num = 0;
	if(this->order)
	{	
		Player *tmp = this->header->getNext();
		while(tmp!=trailer && tmp->getPunteggio()< punteggio) tmp = tmp->getNext();//potrei usare il confronto fra Players tramite l'operatore < , ma per sicurezza vado coi valori esatti
		if(tmp->getPunteggio() == punteggio) num++;
	}
	
	else
	{
		Player *tmp = this->header->getNext();
		while(tmp!=trailer && tmp->getPunteggio() >= punteggio) tmp = tmp->getNext();//potrei usare il confronto fra Players tramite l'operatore >=, ma per sicurezza vado coi valori esatti
		if(tmp->getPunteggio() == punteggio) num++;
	}
	while(num >= 0)
	{
		this->canc(punteggio);
		num--;
	}
	
	return *this;
}


//overloading operatore di redirezione dell'output

template <class T> std::ostream& operator<<(std::ostream& out, const List<T>& l)
{
	List<T> tmp = l;
	tmp.reset();
	out<< "ECCO LA LISTA AGGIORNATA :\n";
	while(tmp.hasNext()){
		out << *(tmp.next()) << "\n"; 
	}
	return out;
}
