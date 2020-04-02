#pragma once
#include "tranzactie.h"
#include "repo.h"

class Service
{
private:
	Repo che;
	Cheltuiala undo_op[100][100];
	int lungimi[100];
	int i = 0;
public:
	~Service();
	void add(int id, int nr_ap, int suma, char* tip);
	void ModificaCheltuiala(int id, int nr_ap, int suma, char* tip);
	void StergeCheltuiala(int id);
	void EliminareCheltuieliAp(int nr_ap);
	void EliminareInterval(int a, int b);
	void EliminareTip(char* tip);
	void Inlocuire(int nr_ap, char* tip, int suma);
	Cheltuiala* CheltuieliApartament(int nr_ap);
	Cheltuiala* CheltuieliMare(int suma);
	Cheltuiala* CheltuieliMic(int suma);
	Cheltuiala* CheltuieliEgal(int suma);
	int SumaTip(char* tip);
	Cheltuiala MaxAp(int nr_ap);
	Cheltuiala* SortTip(char* tip);
	void FiltruTip(char* tip);
	void FiltruSuma(int suma);
	int lungime();
	Cheltuiala* getall();
	void Undo();
	

};
