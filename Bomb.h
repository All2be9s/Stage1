#include <vector>
class Bomb {
protected:
	int pos_x,pos_y;
	int cause_damage;
	int count_down;
public:
	int Count();
	void Display(char a[40][40]);
	Bomb(int x,int y,int d){
		pos_x=x;
		pos_y=y;
		cause_damage=d;
		count_down=10;
	}
};
std::vector<Bomb> bombs;