#include <map>

class Character {
protected:
	int pos_x,pos_y;
	int buff_status;
	int hit_point;
	char represent_char;
public:
	void Move(int direction);
	void Hit(int bo_x,int bo_y,int damage);
	void Fire();
	void Display(char a[40][40]);
	void Status();
	Character(int x, int y, int r) {
		pos_x=x;
		pos_y=y;
		buff_status=0;
		hit_point=5;
		represent_char=r;
	}
};

class Player : public Character {
protected:
	std::map<char,int> key_map;
public:
	void Keyboard_Response(char key);
	Player(int x, int y, char r, char up, char left, char down, char right, char bomb) : Character(x,y,r) {
		key_map[up]=0;
		key_map[left]=1;
		key_map[down]=2;
		key_map[right]=3;
		key_map[bomb]=4;
	}
};

class Robot : public Character {
public:
	void Decide_Movement();
	Robot(int x, int y, char r) : Character(x,y,r) {}
};

Player player_1(4,4,'A',119,97,115,100,32);
Player player_2(36,36,'B',105,106,107,108,13);

Robot robot_1(4,36,'C');
Robot robot_2(36,4,'D');