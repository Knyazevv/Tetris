#pragma once
#include<iostream>
#include "shapes.h"

using namespace std;

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

class Base
{
public:
	void print(int screen[16][20], int map[4][4], int px, int py, int score);
	
	void nextmap(shapes x, int nextmap);	
};

void Base::print(int screen[16][20], int map[4][4], int px, int py, int score)
{
	int i, j;
	int buff[16][20];

	for (i = 0; i < 20; i++)
		for (j = 0; j < 16; j++)
			buff[j][i] = screen[j][i];
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (map[j][i])
				buff[j + px][i + py] = 1;
	gotoxy(0, 0);
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 16; j++)
		{
			if (buff[j][i] == 0)
				cout << " ";
			else
				cout << "0";
		}
		cout << "\n";
	}
	for (size_t i = 0; i < 16; i++)
	{
		gotoxy(i, 20);
		cout << "\xDB";
	}

	gotoxy(16 + 2, 0);
	cout << "Your Score: " << score;
	for (int i = 0; i < 20 + 1; i++)
	{
		gotoxy(16, i);
		cout << "\xDB";
	}
}

inline void Base::nextmap(shapes x, int nextmap)
{
	int i, j;
	gotoxy(16 + 2, 2);
	cout << "Next: ";

	for (i = 0; i < 4; i++)
	{
		gotoxy(16 + 2, i + 3);
		for (j = 0; j < 4; j++)
		{
			if (x._shapes(nextmap, j, i) == 0)
				cout << "\176";
			else
				cout << "0";
		}
	}
}
