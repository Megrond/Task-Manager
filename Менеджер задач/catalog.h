#pragma once
#include "TaskManager.h"
#include<iostream>

struct catalog
{
	TaskMenedger* list;
	size_t size{};

	void addTask();
	void showCatalog();
	void deleteTask();
	void searchData();
	bool saveData();
public:
	void editTask();
};

