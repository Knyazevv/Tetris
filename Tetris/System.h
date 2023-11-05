#pragma once
#include <random>
#include <conio.h>
class System
{
public:

	int random(int max)
	{
		return (rand() * (max + 1) / RAND_MAX);
	}
	int getkey();	
};

int System::getkey()
{
	int c;
	if (_kbhit())
	{
		if ((c = _getch()) == 224)
			c = _getch();
		return c;
	}
	return 0;
}