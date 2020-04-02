#pragma once
#include "service.h"

class UI {
private:
	Service serv;
public:
	void update();
	void menu_update();
	void eliminare();
	void eliminare_interval();
	void eliminare_tip();
	void inlocuire();
	void identificare();
	void cheltuielimari();
	void cheltuielimici();
	void cheltuieliegal();
	void caract();
	void sumtot();
	void chelmax();
	void cheltip();
	void filtr();
	void filtip();
	void filsum();
	void cheltuieliap();
	void sterge();
	void undo();
	void def();
	void show_menu();
	void handle_add();
	void show_list(Cheltuiala* lista);
	void run();
};