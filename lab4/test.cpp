#include <assert.h>
#include <string.h>
#include "service.h"
#include "repo.cpp"
#include "test.h"
using namespace std;

void test_repo()
{
	Repo ch;
	char* tip2 = new char[10];
	char* tip1 = new char[10];
	strcpy_s(tip1, sizeof "gaz", "gaz");
	strcpy_s(tip2, sizeof "apa", "apa");
	Cheltuiala c1(1, 23, 100, tip1), c2(2, 10, 100, tip2);
	ch.addCheltuiala(c1);
	ch.addCheltuiala(c2);
	Cheltuiala* a = new Cheltuiala[10];
	a = ch.getAll();
	assert(a[0].getid() == 1&&a[0].getnr_ap()==23&&a[0].getsuma()==100);
	assert(a[1].getid() == 2);
	Cheltuiala c3(2, 10, 200, tip2);
	ch.updateCheltuiala(c3);
	//delete[] a;
	Cheltuiala* b = new Cheltuiala[10];
	b = ch.getAll();
	assert(b[1].getsuma() == 200);
	c3.settip(tip1);
	assert(strcmp(c3.gettip(),tip1)==0);
	ch.delCheltuiala(1);
	b = ch.getAll();
	assert(b[0].getid() == 2);
	
	
}

void test_serv()
{
	Service serv;
	char* tip1 = new char[10];
	strcpy_s(tip1, sizeof "gaz", "gaz");
	serv.add(1, 12, 100, tip1);
	Cheltuiala* a = new Cheltuiala[10];
	a = serv.getall();
	assert(a[0].getid() == 1 && a[0].getnr_ap() == 12 && a[0].getsuma() == 100);
	char* tip2 = new char[10];
	strcpy_s(tip2, sizeof "apa", "apa");
	serv.add(2, 12, 200, tip2);
	serv.add(3, 13, 200, tip2);
	serv.EliminareCheltuieliAp(12);
	Cheltuiala* b = new Cheltuiala[10];
	b = serv.getall();
	assert(b[0].getsuma() == 0 && b[1].getsuma() == 0 && b[2].getsuma() == 200);
	serv.add(4, 14, 200, tip2);
	Cheltuiala* c = new Cheltuiala[10];
	serv.ModificaCheltuiala(1, 12, 100, tip1);
	serv.ModificaCheltuiala(2, 12, 200, tip2);
	c = serv.getall();
	assert(c[0].getsuma() == 100 && c[1].getsuma() == 200);
	serv.EliminareInterval(12, 13);
	c = serv.getall();
	assert(c[0].getsuma() == 0 && c[1].getsuma() == 0 && c[2].getsuma() == 0 && c[3].getsuma() == 200);
	serv.ModificaCheltuiala(1, 12, 100, tip1);
	serv.ModificaCheltuiala(2, 12, 200, tip2);
	serv.ModificaCheltuiala(3, 13, 200, tip2);
	serv.EliminareTip(tip2);
	c = serv.getall();
	assert(c[1].getsuma() == 0 && c[2].getsuma() == 0 && c[3].getsuma() == 0);
	serv.Inlocuire(12, tip2, 300);
	c = serv.getall();
	assert(c[1].getsuma() == 300 && c[0].getsuma() == 100);
	c = serv.CheltuieliApartament(12);
	assert(c[0].getid() == 1 && c[1].getid() == 2);
	serv.ModificaCheltuiala(1, 12, 100, tip1);
	serv.ModificaCheltuiala(2, 12, 200, tip2);
	serv.ModificaCheltuiala(3, 13, 200, tip2);
	c = serv.CheltuieliMare(199);
	assert(c[0].getid() == 2 && c[1].getid() == 3 );
	assert(serv.SumaTip(tip2) == 400);
	assert(serv.MaxAp(12).getid() == 2);
	serv.ModificaCheltuiala(3, 13, 300, tip2);
	serv.ModificaCheltuiala(4, 14, 400, tip2);
	c=serv.SortTip(tip2);
	//assert(c[0].getid() == 4 && c[1].getid() == 3 && c[2].getid() == 2);
	
	//sortare in UI:
	
}