#pragma once
#include <ostream>
using namespace std;

class Cheltuiala {
private:
	int id,nr_ap,suma;
	char* tip;
public:
	Cheltuiala();
	Cheltuiala(int id, int nr_ap, int suma, char* tip);
	Cheltuiala(const Cheltuiala& c);
	~Cheltuiala();
	int getid();
	int getnr_ap();
	int getsuma();
	char* gettip();
	void setid(int id);
	void setnr_ap(int nr_ap);
	void setsuma(int suma);
	void settip(char* tip);
	Cheltuiala& operator=(const Cheltuiala& c);
	bool operator==(const Cheltuiala& c);
	friend ostream& operator<<(ostream& os, const Cheltuiala& c);
};