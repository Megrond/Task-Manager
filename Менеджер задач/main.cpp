#include<iostream>
#include<Windows.h>
#include "TaskManager.h"
#include"menu.h"
#include"catalog.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	catalog list_task{};
	menu main_menu{};

	main_menu.add("�������� ������");
	main_menu.add("�������� ������");
	main_menu.add("������������� ������");
	main_menu.add("������� ������");
	main_menu.add("�������� ��� ������ �� ����");
	main_menu.add("��������� ������ � ����");
	main_menu.add("������� 9 ��� ������ �� ���������");


	int option{};
	while (option != 9)
	{
		main_menu.show();
		cin >> option;

		switch (option)
		{
		case 0:
			list_task.addTask();
			break;
		case 1:
			list_task.showCatalog();
			break;
		case 2:
			list_task.editTask();
			break;
		case 3:
			list_task.deleteTask();
			break;
		case 4:
			list_task.searchData();
			break;
		case 5:
			list_task.saveData();
			break;
		default:
			break;
		}
	}

	return 0;
}
