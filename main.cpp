#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

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

		Sleep(10);
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
	srand(0);
}
void Time_Count(){
	global_counter++;
	int i=0;
	while(i<bombs.size()){
		int res=bombs[i].Count();
		if(res==-2)i++;
		else break;
	}
	bombs.erase(bombs.begin(),bombs.begin()+i);
	for(i=1;i<bombs.size();i++){
		bombs[i].Count();
	}
}