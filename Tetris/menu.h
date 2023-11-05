#pragma once
#include<iostream>
#include"title.h"

class menu : protected  title
{
public:
	void print_t()
	{
		cout << GAME_TITLE;
	}
	void print_h()
	{
		cout << Help;
	}
	void print_m()
	{
		cout << GAME_MENU;
	}
	int gamemode()
	{
		system("cls");
		int gm;
		cout << Game_Mode;
		cin >> gm;
		return gm;
	}
};



