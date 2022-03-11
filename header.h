#include "Character.h"
#include "Bomb.h"
#include "Map.h"

void Character::Move(int direction) {

}
void Character::Buff(int buff) {

}
void Character::Display(char a[40][40]) {

}
void Character::Fire() {

}
void Character::Hit(int damage) {

}
void Character::Status() {
	printf("      %d      |      %d      |      %d     |\n",hit_point,(buff_status&1)+1,(buff_status&2)+1);
}

void Player::Keyboard_Response(char key) {

}
void Robot::Decide_Movement() {

}


void Bomb::Display(char a[40][40]) {

}
int Bomb::Count() {
	return 0;
}
void Bomb::Start() {

}
void Bomb::End() {

}


void Map::Display_Map() {
	char display[40][40];
	memcpy(display,table,sizeof(table));
	for(int i=0;i<bombs.size();i++){
		bombs[i].Display(display);
	}
	player_1.Display(display);
	player_2.Display(display);
	robot_1.Display(display);
	robot_2.Display(display);
	for(int i=4;i<=36;i++){
		for(int j=4;j<=36;j++)
			printf("%c",display[i][j]);
		printf("\n");
	}
}
void Map::Bomb_Effect(int pos_x, int pos_y) {

}
bool Map::Check_Movement(int pos_x, int pos_y) {

}