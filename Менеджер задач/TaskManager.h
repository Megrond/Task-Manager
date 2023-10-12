#pragma once

struct TaskMenedger
{
	char title[256];
	char dateTask[20];

	void showTask();
};

TaskMenedger creatTask();