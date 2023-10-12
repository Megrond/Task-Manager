#include "menu.h"
#include<iostream>

using namespace std;

void menu::add(const char* option)
{
	char** new_options = new char* [menu::sizeOptions + 1];
	for (int i{}; i < menu::sizeOptions; i++)
	{
		new_options[i] = menu::options[i];
	}
	new_options[menu::sizeOptions] = new char[256] {*option};
	strcpy_s(new_options[menu::sizeOptions], 256, option);

	delete[] menu::options;
	menu::options = new_options;
	menu::sizeOptions++;
}

void menu::show()
{
	//system("cls");
	cout << endl;
	cout << "Укажите вариант действия" << endl;
	for (int i{}; i < menu::sizeOptions; i++)
	{
		cout << i << " - " << menu::options[i] << endl;
	}
}

