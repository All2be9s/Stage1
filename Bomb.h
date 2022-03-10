class Bomb {
private:
	int pos_x,pos_y;
	int cause_damage;
	int count_down;
public:
	void Count_Time();
	void Start_Bomb();
	void End_Bomb();
};
