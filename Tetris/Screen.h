#pragma once
#include"System.h"

class Screen : public System
{
public:
	void clear(int screen[16][20]);
};
void Screen::clear(int screen[16][20])
{
	int i, j;
	for (i = 0; i < 20; i++)
	for (j = 0; j < 16; j++)
	screen[j][i] = 0;
}