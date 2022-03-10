class Character {
private:
	int pos_x,pos_y;
	int buff_status;
	int hit_point;
public:
	void Move(int direction);
	void Hit(int damage);
	void Fire();
};

class Player : public Character {
public:
	void Keyboard_Response(char key);
};

class Robot : public Character {
public:
	void Decide_Movement();
};