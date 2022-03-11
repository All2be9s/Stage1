#include <vector>
class Bomb {
private:
	int pos_x,pos_y;
	int cause_damage;
	int count_down;
public:
	int Count();
	void Start();
	void End();
	void Display(char a[40][40]);
	Bomb(int x,int y,int d){
		pos_x=x;
		pos_y=y;
		cause_damage=d;
		count_down=5;
	}
};
std::vector<Bomb> bombs;