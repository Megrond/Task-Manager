#include "TaskManager.h"
#include <iostream>

using namespace std;

TaskMenedger creatTask()
{
	TaskMenedger new_task = {};
	cout << "������� �������� ������" << endl;
	cin >> new_task.title;
	cout << "������� ���� ������" << endl;
	cin >> new_task.dateTask;

	return new_task;
}
void TaskMenedger::showTask()
{
	cout << "�������� ������ - " << title << endl;
	cout << "���� ������ - " << dateTask << endl;
}
