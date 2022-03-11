#include "Character.h"
#include "Bomb.h"
#include "Map.h"

int global_counter=0;

const int direc_x[5]={-1,0,1,0,0},direc_y[5]={0,-1,0,1,0};

void Character::Move(int direction) {
	int npos_x=pos_x+direc_x[direction];
	int npos_y=pos_y+direc_y[direction];
	int res=game_map.Check_Movement(npos_x, npos_y);
	if(res!=-1){
		pos_x=npos_x;
		pos_y=npos_y;
		buff_status|=res;
	}
}
void Character::Display(char a[40][40]) {
	a[pos_x][pos_y]=represent_char;
}
void Character::Fire() {
	Bomb nbomb(pos_x,pos_y,(buff_status&2)/2+1);
	bombs.push_back(nbomb);
}
void Character::Hit(int bo_x,int bo_y,int damage) {
	if(abs(bo_x-pos_x)+abs(bo_y-pos_y)<=1){
		hit_point-=damage;
	}
}
void Character::Status() {
	printf("      %d      |      %d      |      %d     |\n",hit_point,(buff_status&1)+1,((buff_status&2)>>1)+1);
}

void Player::Keyboard_Response(char key) {
	if(global_counter%2==0&&(buff_status&1)!=1)return ;
	if(key_map.find(key)==key_map.end())return;
	if(key_map[key]==4)Fire();
	else Move(key_map[key]);
}
void Robot::Decide_Movement() {

}


void Bomb::Display(char a[40][40]) {
	if(count_down>0){
		a[pos_x][pos_y]='!';
	}
	else if(count_down>-2){
		a[pos_x][pos_y]='O';
		for(int i=0;i<4;i++){
			a[pos_x+direc_x[i]][pos_y+direc_y[i]]=(i%2?'-':'|');
		}
	}
}
int Bomb::Count() {
	count_down--;
	if(count_down<=0&&count_down>-2){
		game_map.Bomb_Effect(pos_x,pos_y);
		player_1.Hit(pos_x,pos_y,cause_damage);
		player_2.Hit(pos_x,pos_y,cause_damage);
		robot_1.Hit(pos_x,pos_y,cause_damage);
		robot_2.Hit(pos_x,pos_y,cause_damage);
	}
	return count_down;
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
	for(int i=0;i<5;i++){
		int x=pos_x+direc_x[i];
		int y=pos_y+direc_y[i];
		if(table[x][y]=='$'){
			int r=rand()%8;
			if(r>3)r=0;
			printf("\n-----------------%d-----------------\n",r);
			if(r==0)table[x][y]=' ';
			else table[x][y]=r+'0';
		}
	}
}
int Map::Check_Movement(int pos_x, int pos_y) {
	if(pos_x<4||pos_x>36||pos_y<4||pos_y>36)return -1;
	if(table[pos_x][pos_y]=='#'||table[pos_x][pos_y]=='$')return -1;
	if(table[pos_x][pos_y]==' ')return 0;
	int ret=table[pos_x][pos_y]-'0';
	table[pos_x][pos_y]=' ';
	return ret;
}