class Map {
private:
	char table[233][233];
public:
	void Display_Map();
	void Bomb_Effect(int pos_x,int pos_y);
	bool Check_Movement(int pos_x,int pos_y);
};
