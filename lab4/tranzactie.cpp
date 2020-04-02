#include "tranzactie.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Cheltuiala::Cheltuiala() {
	this->id = 0;
	this->nr_ap = 0;
	this->suma = 0;
	this->tip = NULL;
}

Cheltuiala::Cheltuiala(int id,int nr_ap, int suma, char* tip)
{
	this->id = id;
	this->nr_ap = nr_ap;
	this->suma = suma;
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, 1 + strlen(tip), tip);
	
}

Cheltuiala::Cheltuiala(const Cheltuiala &c)
{
	this->id = c.id;
	this->nr_ap = c.nr_ap;
	this->suma = c.suma;
	this->tip = new char[20];
	strcpy_s(this->tip, strlen(c.tip)+1, c.tip);
	
	
}

Cheltuiala::~Cheltuiala() {
	if (this->id) {
		this->id = 0;
		this->nr_ap = 0;
		this->suma = 0;
		delete[] this->tip;
		this->tip = NULL;
	}
}

int Cheltuiala::getid() {
	return this->id;
}

int Cheltuiala::getnr_ap() {
	return this->nr_ap;
}

int Cheltuiala::getsuma() {
	return this->suma;
}

char* Cheltuiala::gettip() {
	return this->tip;
}


void Cheltuiala::setid(int id) {
	this->id = id;
}

void Cheltuiala::setnr_ap(int nr_ap){
	this->nr_ap = nr_ap;
}

void Cheltuiala::setsuma(int suma) {
	this->suma = suma;
}

void Cheltuiala::settip(char* tip) {
	if (this->tip) {
		delete[] this->tip;
	}
	this->tip = new char[strlen(tip) + 1];
	strcpy_s(this->tip, strlen(tip) + 1, tip);
}


Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c) {
	this->setid(c.id);
	this->setnr_ap(c.nr_ap);
	this->setsuma(c.suma);
	this->settip(c.tip);
	return *this;
}

bool Cheltuiala:: operator==(const Cheltuiala& c) {
	return this->id == c.id;
}

ostream& operator<<(ostream& os, const Cheltuiala& c)
{
	os << c.id << ". " << c.nr_ap << ": " << c.suma << " lei " << c.tip ;
	return os;
}