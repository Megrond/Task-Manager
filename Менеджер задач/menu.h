#pragma once

struct menu
{
	char** options;
	int sizeOptions = 0;

	void add(const char* option);
	void show();
};
