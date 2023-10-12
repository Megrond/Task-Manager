#include "TaskManager.h"
#include <iostream>

using namespace std;

TaskMenedger creatTask()
{
	TaskMenedger new_task = {};
	cout << "Укажите название задачи" << endl;
	cin >> new_task.title;
	cout << "Укажите дату задачи" << endl;
	cin >> new_task.dateTask;

	return new_task;
}
void TaskMenedger::showTask()
{
	cout << "Название задачи - " << title << endl;
	cout << "Дата задачи - " << dateTask << endl;
}
