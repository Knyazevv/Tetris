#include <iostream>
#include<stdio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include"shapes.h"
#include"Base.h"
#include"System.h"
#include"Screen.h"
#include"title.h"
#include"menu.h"
#include"Tetris1.h"
using namespace std;



void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

class Tetris {
private:
	shapes x;
	int screen[16][20];
	int map[4][4];
	int px, py;
	int score, nextmap;


public:
	int valnewpos(int x, int y)
	{
		int i, j;
		if (x < 0)
			return 0;
		for (i = 0; i < 4; i++)
		{
			
			for (j = 0; j < 4; j++)
			{
				if (map[j][i])
				{
					if ((j + x >= 16) || (i + y >= 20))
						return 0;
					if (screen[j + x][i + y])
					{
						return 0;
					}
				}
			}
		}
		return 1;
	}

	void moveDownStep(int px, int py)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (map[j][i])
					screen[px + j][py + i] = 1;
			}
		}
	}
	void moveDownFast(int screen[16][20])
	{
		for (; valnewpos(px, py + 1); py++);
		{
			moveDownStep(px, py);
		}
	}
	void rotatemap()
	{
		int _map[4][4];
		int i, j, sx = 4, sy = 4;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
			{
				_map[j][i] = map[j][i];
				if (map[j][i])
				{
					if (i < sx)
						sx = i;
					if ((-j + 3) < sy)
						sy = (-j + 3);
				}
				map[j][i] = 0;
			}

		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				if (_map[(-i + 3)][j])
					map[j - sx][i - sy] = 1;

		if (!valnewpos(px, py))
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					map[j][i] = _map[j][i];
	}
	void deleteline(int screen[16][20])
	{
		int i, j, k, flag;
		System s;
		Base print;
		for (i = 20 - 1; i >= 0; i--)
		{
			flag = 1;
			for (j = 0, flag = 1; j < 16; j++)
			{
				if (!screen[j][i])
					flag = 0;
			}
			if (flag)
			{
				gotoxy(0, i);
				for (k = 0; k < 16; k++)
				{
					cout << "_";
					Sleep(20);
				}

				score += (((i * (-1)) + 20) * 10);

				for (k = i; k > 0; k--)
				{
					for (j = 0; j < 16; j++)
					{
						screen[j][k] = screen[j][k - 1];
					}
				}
				i++;
				print.print(screen, map, px, py, score);
			}
		}
	}
	void createmap()
	{

		System s;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				map[j][i] = x._shapes(nextmap, i, j);
		py = 0;
		px = 8;
		Base print;
		nextmap = s.random(6);
		print.nextmap(x, nextmap);
	}
	inline void  Delay(int ms)
	{


	}
	void startGame(int GM)
	{
		int i, j, c;
		ShowConsoleCursor(false);
		system("cls");
		System s;
		Base print;
		time_t tm;
		px = 8;
		py = 0;
		score = 0;
		nextmap = s.random(6);
		createmap();
		tm = clock();
		while (1)
		{
			System s;
			c = s.getkey();
			switch (c)
			{
			case 32:
				rotatemap();
				break;
			case 80:
				moveDownFast(screen);
				print.print(screen, map, px, py, score);
				deleteline(screen);
				createmap();
				break;
			case 75:
				if (valnewpos(px - 1, py))
					px--;
				break;
			case 77:
				if (valnewpos(px + 1, py))
					px++;
				break;
			case 'p':
				_getch();
				break;
			case 27:
				return;
			}

			/*			if (GM==1)
			{
			tm = clock();

			if ((clock() - tm) >800)
			{
			tm = clock();

			if (!(valnewpos(px, py + 1)))
			{
			moveDownStep(px, py);
			createmap();
			deleteline(screen);
			}
			else py++;
			}
			}
			if (GM==2)
			{
			tm = clock();

			if ((clock() - tm) >600)
			{
			tm = clock();

			if (!(valnewpos(px, py + 1)))
			{
			moveDownStep(px, py);
			createmap();
			deleteline(screen);
			}
			else py++;
			}
			}
			if (GM==3)
			{
			tm = clock();

			if ((clock() - tm) >400)
			{
			tm = clock();

			if (!(valnewpos(px, py + 1)))
			{
			moveDownStep(px, py);
			createmap();
			deleteline(screen);
			}
			else py++;
			}
			}
			if (GM == 4)
			{
			tm = clock();

			if ((clock() - tm) >250)
			{
			tm = clock();

			if (!(valnewpos(px, py + 1)))
			{
			moveDownStep(px, py);
			createmap();
			deleteline(screen);
			}
			else py++;
			}
			}*/
			
			if (GM)
			{
				int A;
				if (GM == 1)
					A = 700;
				else if (GM == 2)
					A = 500;
				else if (GM == 3)
					A = 300;
				else if (GM == 4)
					A = 200;
				if ((clock() - tm) > A)
				{
					tm = clock();

					if (!(valnewpos(px, py + 1)))
					{
						moveDownStep(px, py);
						createmap();
						deleteline(screen);
					}
					else py++;
				}
			}
			print.print(screen, map, px, py, score);

			for (i = 0; i < 16; i++)
			{
				if (screen[i][0])
				{
					system("cls");
					gotoxy(2, 8);
					printf("Game Over! :(");
					return;
				}
			}
		}
	}

public:
	void gameMenu()
	{
		Base print;
		Screen scr;
		title* Ti;
		menu St, Gm;
		int p = 1, c = 0, GM;

		system("cls");
		St.print_t();
		St.print_m();
		while (1) {

			c = _getch();
			system("color 70");
			switch (c) {
			case '1':
			case '2':
			case '3':
			case '4':
				p = c - 48;
			case 13:
				switch (p)
				{
				case 1:
					scr.clear(screen);
					GM = Gm.gamemode();
					scr.clear(screen);
					startGame(GM);
					gotoxy(0, 20);
					cout << "Press ESC to return main menu..\n \a";
					while (_getch() != 27);
					break;
				case 2:
					GM = Gm.gamemode();
					startGame(GM);
					gotoxy(0, 20);
					cout << "Press ESC to return main menu..\n \a";
					while (_getch() != 27);
					break;
				case 3:
					system("cls");
					St.print_t();
					St.print_h();
					_getch();
					if (_kbhit())
						_getch();
					break;

				case 4: return;
				}

				system("cls");
				St.print_t();
				St.print_m();
				p = 1;
				break;
			case 80:
				if (p < 4) p++;
				break;
			case 27:
				return;
			}

		}
	}
	void gameTitle()
	{
		menu Ti;
		Ti.print_t();
		_getch();
		printf("Press any key to continue...");
		Tetris::gameMenu();
		system("color 58");
		_getch();
		if (_kbhit())
			_getch();

	}
};

int main()
{
	Tetris tetris;
	tetris.gameTitle();

    return 0;
}

