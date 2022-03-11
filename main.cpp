#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

#include "header.h"

void Initialize();
void Time_Count();

int main(){
	Initialize();
	while(1){
		game_map.Display_Map();
		Sleep(100);
		Time_Count();
		char key=_getch();
		player_1.Keyboard_Response(key);
		player_2.Keyboard_Response(key);
		robot_1.Decide_Movement();
		robot_2.Decide_Movement();
	}
    return 0;
}

void Initialize(){



}
void Time_Count(){



}