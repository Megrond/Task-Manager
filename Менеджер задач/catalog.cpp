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
		cout << "--------------" << i + 1 << " ������--------------" << endl;
		list[i].showTask();
	}
}

void catalog::editTask()
{
	cout << "������� �������� ������ ��� ��������������: ";
	char needle[256]{};
	cin >> needle;
	for (size_t i = 0; i < size; i++) 
	{
		if (strcmp(needle, list[i].title) == 0)
		{
			cout << "������� ����� �������� ������: ";
			cin >> list[i].title;

			cout << "������� ����� ���� ������: ";
			cin >> list[i].dateTask;

			cout << "������ ������� ���������������." << endl;
		}
	}
}
void catalog::deleteTask()
{
	cout << "������� �������� ������ ��� ��������: ";
	char needle[256]{};
	cin >> needle;

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size - 1; j++)
		{
			list[j] = list[j + 1];
		}
		size--; 
		cout << "������ �������." << endl;
	}
}
void catalog::searchData()
{
	cout << "������� ���� ������: ";
	char needle[256]{};
	cin >> needle;

	int flag = 1;
	for (size_t i{}; i < size; i++)
	{
		if (strcmp(needle, list[i].dateTask) == 0)
		{
			cout << "=========" << flag++ << " ����������" << "=========" << endl;
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
		fprintf(myFile, "�������� ������: %s\n����� ������: %s\n==============================\n", list[i].title, list[i].dateTask);

	}
	cout << "������ ������� ������� �������� � ����. " << endl;

	if (fclose(myFile) == 1)
	{
		cout << "Can,t close file!" << endl;
	}
	return true;
}





