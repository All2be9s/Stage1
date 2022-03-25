#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

#include "header.h"

void Initialize();
void Time_Count();
void Status_Display();
void Game_Over(int mask);

int main(){
	Initialize();
	while(1){
		system("cls");
		game_map.Display_Map();
		Status_Display();

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
	srand(time(0));
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
void Status_Display(){
	int mask=0;
	printf("\n\n\n");
	printf("          |  Hit Point  |    Speed    |    Power   |\n");
	printf(" player1  |");mask|=(player_1.Status()?0:1);
	printf(" player2  |");mask|=(player_2.Status()?0:2);
	printf(" robot 1  |");mask|=(robot_1.Status()?0:4);
	printf(" robot 2  |");mask|=(robot_2.Status()?0:8);
	if(__builtin_popcount(mask)<=1)Game_Over(mask);
}
void Game_Over(int mask){
	system("cls");
	Sleep(3000);
	if(mask==0){
		printf("And Then There Were None.\n\n\n");
		Sleep(3000);
		system("cls");
		printf("无人生还.");
	}
	else {
		if(mask<3)printf("Player %d wins!",mask);
		else printf("Robot %d wins!",mask/4);
	}
	Sleep(3000);
	exit(0);
}