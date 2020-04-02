#include "ui.h"
#include "service.h"
#include <cstring>
using namespace std;

void UI::show_menu() {
	cout << "~Cheltuieli" << '\n';
	cout << "1.Adauga cheltuiala" << '\n';
	cout << "2.Modificare cheltuiala" << '\n';
	cout << "3.Sterge cheltuiala" << '\n';
	cout << "4.Identificare cheltuieli" << '\n';
	cout << "5.Caracteristi cheltuieli" << '\n';
	cout << "6.Filtrare cheltuieli" << '\n';
	cout << "7.UNDO" << '\n';
	cout << "a.Afisare cheltuieli" << '\n';
	cout << "x.Iesire" << '\n';
	cout << '\n';
}


void UI::menu_update() {
	cout << "1.Elimina toate cheltuielile de la un apartament" << '\n';
	cout << "2.Elimana toate cheltuielile dintr un interval de apartamente" << '\n';
	cout << "3.Elimina toate cheltuielile de la un tip" << '\n';
	cout << "4.Inlocuieste suma tipul de cheltuiala de la un apartament" << '\n';
	cout << "b.Back" << '\n';
	cout << '\n';
}


void UI::inlocuire() {
	int nr_ap, suma;
	char* tip=new char[20];
	cout << "Dati numarul apartamentului: "; cin >> nr_ap;
	cout << "Dati tipul: "; cin >> tip;
	cout << "Dati noua suma: "; cin >> suma;
	this->serv.Inlocuire(nr_ap, tip, suma);
	cout << "Modificare efectuata!" << '\n' << '\n';
}


void UI::eliminare_tip() {
	char* tip = new char[20];
	cout << "Dati tipul pentru eliminare: "; cin >> tip;
	this->serv.EliminareTip(tip);
	cout << "Modificare efectuata!" << '\n' << '\n';
}


void UI::eliminare_interval() {
	int a, b;
	cout << "Dati capetele intervalului(cu spatiu intre ele): "; cin >> a >> b;
	this->serv.EliminareInterval(a, b);
	cout << "Modificare efectuata!" << '\n' << '\n';
}


void UI::eliminare() {
	int nr_ap;
	cout << "Dati numarul apartamentului: "; cin >> nr_ap;
	this->serv.EliminareCheltuieliAp(nr_ap);
	cout << "Modificare efectuata!" << '\n' << '\n';
}


void UI::update() {
	char op;
	menu_update();
	cout << "Alege: "; cin >> op;
	while (op != 'b') {
		if (op == '1') eliminare();
		else if (op == '2') eliminare_interval();
		else if (op == '3') eliminare_tip();
		else if (op == '4') inlocuire();
		else cout << "Comanda invalida!" << '\n';
		cout << '\n';
		menu_update();
		cout << "Alege: "; cin >> op;
	}
}


void UI::handle_add() {

	int id, nr_ap, suma;
	char* tip1=new char[20];
	cout << "Dati id(nu poate fi 0): "; cin >> id;
	cout << "Dati numarul apartamentului: "; cin >> nr_ap;
	cout << "Dati suma: "; cin >> suma;
	cout << "Dati tipul: "; cin>>tip1;

	this->serv.add(id, nr_ap, suma, tip1);
	cout << "Cheltuiala adaugata!" << '\n';
	cout << '\n';
	
}


void menu_indentificare() {
	cout << "1.Arata cheltuielile unui apartament" << '\n';
	cout << "2.Arata toate cheltuielile mai mari decat o constanta" << '\n';
	cout << "3.Arata toate cheltuielile mai mici decta o constanta" << '\n';
	cout << "4.Arata toate cheltuielile egale cu o constanta" << '\n';
	cout << "b.Back" << '\n';
	cout << '\n';
}


void UI::cheltuieliap() {
	int nr_ap;
	cout << "Dati numarul apartamentului: "; cin >> nr_ap;
	this->show_list(this->serv.CheltuieliApartament(nr_ap));
}


void UI::cheltuielimari() {
	int suma;
	cout << "Dati suma: "; cin >> suma;
	this->show_list(this->serv.CheltuieliMare(suma));
}


void UI::cheltuielimici() {
	int suma;
	cout << "Dati suma: "; cin >> suma;
	this->show_list(this->serv.CheltuieliMic(suma));
}


void UI::cheltuieliegal() {
	int suma;
	cout << "Dati suma: "; cin >> suma;
	this->show_list(this->serv.CheltuieliEgal(suma));
}


void UI::identificare() {
	char op;
	menu_indentificare();
	cout << "Alege: "; cin >> op;
	while (op != 'b') {
		if (op == '1') this->cheltuieliap();
		else cout << "Comanda invalida!" << '\n';
		cout << '\n';
		menu_indentificare();
		cout << "Alege: "; cin >> op;
	}
}


void show_caract() {
	cout << "1.Suma totala pentru un tip" << '\n';
	cout << "2.Cheltuiala maxima pentru un apartament" << '\n';
	cout << "3.Afisaza cheltuieli dintr un singur tip" << '\n';
	cout << "b.Back" << '\n';
}


void UI::sumtot() {
	char* t = new char[20];
	cout << "Dati tipul: "; cin >> t;
	cout << "In total pentru " << t << " se vor plati: " << this->serv.SumaTip(t) << " lei!" << '\n' << '\n';
}


void UI::chelmax() {
	int nr_ap;
	cout << "Dati numarul apartamentului: "; cin >> nr_ap;
	cout << "cea mai mare cheltuiala pentru apartamentul: " << nr_ap << " este: " << this->serv.MaxAp(nr_ap)<<'\n' << '\n';
}


void UI::cheltip() {
	char* tip = new char[20];
	cout << "Dati tipul: "; cin >> tip;
	this->show_list(this->serv.SortTip(tip));
}


void UI::caract() {
	char op;
	show_caract();
	cout << "Alege: " << '\n'; cin >> op;
	while (op != 'b') {
		if (op == '1') this->sumtot();
		else if (op == '2') this->chelmax();
		else if (op == '3') this->cheltip();
		else cout << "Comanda invalida!" << '\n';
		show_caract();
		cout << "Alege: "; cin >> op; cout << '\n';
	}
}


void menu_filtr() {
	cout << "1.Pastreaza cheltuielile cu un tip anume" << '\n';
	cout << "2.Pastreaza cheltuielile cu suma mai mica de o constanta" << '\n';
	cout << "b.Back" << '\n';
}


void UI::filtip() {
	char* tip = new char[20];
	cout << "Dati tipul: "; cin >> tip;
	this->serv.FiltruTip(tip);
	cout << "Filtrarea a fost efectuata!" << '\n' << '\n';
}


void UI::filsum() {
	int suma;
	cout << "Dati suma: "; cin >> suma;
	this->serv.FiltruSuma(suma);
	cout << "Filtrarea a fost efectuata!" << '\n' << '\n';
}


void UI::filtr() {
	char op;
	menu_filtr();
	cout << "Alege: "; cin >> op;
	while (op != 'b') {
		if (op == '1') this->filtip();
		else if (op == '2') this->filsum();
		else cout << "Comanda invalida!" << '\n';
		menu_filtr();
		cout << "Alege: "; cin >> op;
	}
}


void UI::undo() {
	this->serv.Undo();
	cout << "UNDO efectuat!" << '\n';
}


void UI::show_list(Cheltuiala* lista) {
	for (int i = 0; i < this->serv.lungime(); i++)
		if (lista[i].getid() != 0)
			cout << lista[i]<<'\n';
	cout << '\n';

}
void UI::def() {
	char* tip1 = new char[10];
	strcpy_s(tip1, sizeof "gaz", "gaz");
	char* tip2 = new char[10];
	strcpy_s(tip2, sizeof "apa", "apa");
	this->serv.add(1, 10, 100, tip1);
	this->serv.add(2, 11, 110, tip2);
	this->serv.add(3, 11, 200, tip1);
	this->serv.add(4, 10, 200, tip2);
	this->serv.add(5, 12, 200, tip1);
}
void UI::sterge() {
	int id;
	cout << "Dati id ul cheltuielii de sters: "; cin >> id;
	this->serv.StergeCheltuiala(id);
	cout << "Cheltuiala a fost stearsa!" << '\n' << '\n';
}
void UI::run() {
	char op;
	show_menu();
	cout << "Alege: "; cin >> op; cout << '\n';
	while (op != 'x')
	{
		if (op == '1') this->handle_add();
		else if (op == '2') this->update();
		else if (op == '3') this->sterge();
		else if (op == '4') this->identificare();
		else if (op == '5') this->caract();
		else if (op == '6') this->filtr();
		else if (op == '7') this->undo();
		else if (op == 'a') this->show_list(this->serv.getall());
		else cout << "Comanda invalida!"<<'\n';
		show_menu();
		cout << "Alege: "; cin >> op; cout << '\n';
		
	}
}
