#include <iostream>
#include <string.h>
#include "repo.h"
#include "tranzactie.h"
#include "service.h"

using namespace std;

Service::~Service() {
	this->che.~Repo();
}
void Service::add(int id, int nr_ap, int suma, char* tip) {
	Cheltuiala c(id, nr_ap, suma, tip);
	this->che.addCheltuiala(c);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}

void Service::ModificaCheltuiala(int id, int nr_ap, int suma, char* tip) {
	Cheltuiala c(id, nr_ap, suma, tip);
	this->che.updateCheltuiala(c);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}

void Service::EliminareCheltuieliAp(int nr_ap) {
	//reduce sumele cheltuielilor la 0 de la un apartament
	//input -nr_ap:int, numarul apartamentului la care trebuie facute modificari
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getnr_ap() == nr_ap)
			this->che.getAll()[i].setsuma(0);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}
void Service::EliminareInterval(int a, int b) {
	//reduce sumele cheltuielilor la 0 de la un interval de apartamente
	//input -a:int, inceputul intervalului
	//-b:int, sfarsitul intervalului
	for (int i = a; i <= b; i++)
		this->EliminareCheltuieliAp(i);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}
void Service::EliminareTip(char* tip) {
	//reduce sumele cheltuielilor la 0 pentru cele cu un anumit tip
	//input -tip:char*, tipul de cheltuiala care trebuie redusa
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(),tip) == 0)
			this->che.getAll()[i].setsuma(0);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}
void Service::StergeCheltuiala(int id) {
	this->che.delCheltuiala(id);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}
void Service::Inlocuire(int nr_ap, char* tip, int suma) {
	//modifica suma cheltuielii de la tipul de cheltuiala la un apartament
	//input -nr_ap:int,numarul apartamentului de modificat
	//-tip:char*,tipul cheltuielii care trebuie modificata
	//-suma:int,noua suma pentru cheltuiala
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) == 0 && this->che.getAll()[i].getnr_ap() == nr_ap)
			this->che.getAll()[i].setsuma(suma);
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}
Cheltuiala* Service::CheltuieliApartament(int nr_ap) {
	//arata cheltuielile unui singur apartament
	//input -nr_ap:int, numarul apartamentului
	//output -c:o lista cu cheltuielile apartamentului
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getnr_ap() == nr_ap) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;

}
Cheltuiala* Service::CheltuieliMare(int suma) {
	//arata cheltuielile care depasesc o anumita suma
	//input -suma:int, suma care trebuie depasita
	//output -c:lista de cheltuieli
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() > suma) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;
}
Cheltuiala* Service::CheltuieliMic(int suma) {
	//arata cheltuielile care nu depasesc o anumita suma
	//input -suma:int, suma care nu trebuie depasita
	//output -c:lista de cheltuieli
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() < suma) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;
}
Cheltuiala* Service::CheltuieliEgal(int suma) {
	//arata cheltuielile care au o anumita suma
	//input -suma:int, suma care trebuie
	//output -c:lista de cheltuieli
	Cheltuiala* c = new Cheltuiala[101];
	int x = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() == suma) {
			c[x] = this->che.getAll()[i];
			x++;
		}
	return c;
}
int Service::SumaTip(char* tip) {
	//calculeaza suma totala di tipul dat
	//input -tip:char*, tipul pentru care trebuie calculat
	//output -suma:int,suma totala a tipului
	int suma = 0;
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) == 0)
			suma += this->che.getAll()[i].getsuma();
	return suma;

}
Cheltuiala Service::MaxAp(int nr_ap) {
	//arata cea mai mare cheltuiala a unui apartament
	//input -nr_ap:int, numarul apartamentului pentru care trebuie aflata suma maxima
	//output -c:cheltuiala maxima a apartamentului
	Cheltuiala c;
	int suma = 0;
	for (int i = 0; i < this->che.n; i++)
		if (this->che.getAll()[i].getsuma() > suma) {
			suma = this->che.getAll()[i].getsuma();
			c = this->che.getAll()[i];
		}
	return c;
}
Cheltuiala* Service::SortTip(char* tip) {
	//da o lista cu cheltuieli doar dintr un tip
	//input -tip:char*,tipul  cheltuielilor
	//output -c:o lista cu cheltuielile cu tipul dat
	Cheltuiala* c = new Cheltuiala[101];
	int suma = 0,m=0;
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) == 0)
		{
			c[m] = this->che.getAll()[i];
			m++;
		}
	int ok = 0;
	while (!ok) {
		ok = 1;
		for (int i = 0; i < m; i++)
			if (c[i].getsuma() < c[i + 1].getsuma())
			{
				swap(c[i], c[i + 1]);
				ok = 0;
			}
	}

	return c;
	
}
void Service::FiltruTip(char* tip) {
	//pastreaza doar cheltuielile cu tipul dat
	//input -tip:char*,tipul care trebuie pastrat
	for (int i = 0; i < this->che.n; i++)
		if (strcmp(this->che.getAll()[i].gettip(), tip) != 0) this->che.delCheltuiala(this->che.getAll()[i].getid());
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
	
}
void Service::FiltruSuma(int suma) {
	//pastreaza chetuielile care au suma mai mica decat o constanta data
	//input -suma:int,suma maxima
	for (int i = 0; i < this->lungime(); i++)
		if(this->che.getAll()[i].getsuma()>=suma) this->che.delCheltuiala(this->che.getAll()[i].getid());
	this->i++;
	for (int j = 0; j < this->lungime(); j++) {
		this->undo_op[i][j] = this->getall()[j];
		this->lungimi[i] = j;
	}
}
void Service::Undo() {
	this->che.n = lungimi[i];
	for (int j = 0; j < this->lungimi[i]; j++) {
		Cheltuiala c = this->undo_op[i ][j];
		this->che.updateCheltuiala(c);
	}
	i--;
		//this->che.addCheltuiala(this->undo_op[i - 1][j]);
}

int Service::lungime() {
	return this->che.n;
}
Cheltuiala* Service::getall() {
	return this->che.getAll();
}


