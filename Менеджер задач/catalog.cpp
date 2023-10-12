#include<iostream>
#include"catalog.h"


using namespace std;

void catalog::addTask()
{
	TaskMenedger* new_catalog = new TaskMenedger[size + 1];
	for (size_t i{}; i < size; i++)
	{
		new_catalog[i] = list[i];
	}

	new_catalog[size] = creatTask();

	delete[]list;
	list = new_catalog;
	size++;
}
void catalog::showCatalog()
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "--------------" << i + 1 << " Задача--------------" << endl;
		list[i].showTask();
	}
}

void catalog::editTask()
{
	cout << "Укажите название задачи для редактирования: ";
	char needle[256]{};
	cin >> needle;
	for (size_t i = 0; i < size; i++) 
	{
		if (strcmp(needle, list[i].title) == 0)
		{
			cout << "Введите новое название задачи: ";
			cin >> list[i].title;

			cout << "Введите новую дату задачи: ";
			cin >> list[i].dateTask;

			cout << "Задача успешно отредактирована." << endl;
		}
	}
}
void catalog::deleteTask()
{
	cout << "Укажите название задачи для удаления: ";
	char needle[256]{};
	cin >> needle;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size - 1; j++)
		{
			list[j] = list[j + 1];
		}
		size--; 
		cout << "Задача удалена." << endl;
	}
}
void catalog::searchData()
{
	cout << "Укажите дату задачи: ";
	char needle[256]{};
	cin >> needle;

	int flag = 1;
	for (size_t i{}; i < size; i++)
	{
		if (strcmp(needle, list[i].dateTask) == 0)
		{
			cout << "=========" << flag++ << " совпадение" << "=========" << endl;
			list[i].showTask();
		}
	}
}
bool catalog::saveData()
{
	FILE* myFile;
	fopen_s(&myFile, "TaskManager.txt", "w");

	if (myFile == NULL)
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (strlen(list[i].title) == 0)
		{
			break;
		}
		fprintf(myFile, "Название задачи: %s\nВремя задачи: %s\n==============================\n", list[i].title, list[i].dateTask);

	}
	cout << "Список задачно успешно выгружен в файл. " << endl;

	if (fclose(myFile) == 1)
	{
		cout << "Can,t close file!" << endl;
	}
	return true;
}





