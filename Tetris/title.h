#pragma once
#include"Tetris1.h"

class title
{
public:
	const char* GAME_TITLE =
		"TTTTTTTTTTT  EEEEEEEEE  TTTTTTTTTTT  RRRRRRRR  IIIIIIII  SSSSSSSS \n"
		"TT   TT  TT  EE         TT   TT  TT  RR    RR     II     SS       \n"
		"TT   TT  TT  EE         TT   TT  TT  RR    RR     II     SS       \n"
		"     TT      EEEEEEEEE       TT      RRRRRRRR     II     SSSSSSSS \n"
		"     TT      EE              TT      RR   RR      II           SS \n"
		"     TT      EE              TT      RR    RR     II           SS \n"
		"   TTTTTT    EEEEEEEEE     TTTTTT   RRRR     RR IIIIIIII  SSSSSSS \n\n";
	const char* GAME_MENU =
		"                        1===================== Start\n\n"
		"                        2===================== Continue\n\n"
		"                        3===================== Help\n\n"
		"                        4===================== Exit :(\n\n ";
	const char* Help =
		"           \x11===========Left   \n"
		"           \x10===========Right  \n"
		"           \x1F===========Down   \n"
		"           Space ======Rotate\n"
		"           P===========Pause  \n"
		"           ESC=========Exit   \n"
		"           \n\nPress any key...\n";
	const char* Game_Mode =
		"1=============Easy\n"
		"2=============Normal\n"
		"3=============Hard\n"
		"4=============Extreme\n"
		"Please Enter Your Game Mode : ";
public:
	virtual void print_t() = 0;
	virtual void print_h() = 0;
	virtual void print_m() = 0;

};

