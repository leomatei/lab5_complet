#pragma once
#include "tranzactie.h"
#include "tranzactie.cpp"

class Repo {
private:
	Cheltuiala cheltuieli[101];
public:
	
	int n;
	Repo();
	~Repo();
	void addCheltuiala(Cheltuiala c);
	void updateCheltuiala(Cheltuiala c);
	void delCheltuiala(int id);
	Cheltuiala* getAll();
};
