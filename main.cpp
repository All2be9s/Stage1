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
		system("cls");
		game_map.Display_Map();

		printf("\n\n\n");
		printf("          |  Hit Point  |    Speed    |    Power   |\n");
		printf(" player1  |");player_1.Status();
		printf(" player2  |");player_2.Status();
		printf(" robot 1  |");robot_1.Status();
		printf(" robot 2  |");robot_2.Status();

		Sleep(500);
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