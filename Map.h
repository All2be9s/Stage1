class Map {
protected:
	char table[40][40];
public:
	void Display_Map();
	void Bomb_Effect(int pos_x,int pos_y);
	int Check_Movement(int pos_x, int pos_y);
	Map(){
		for(int i=4;i<=36;i++)
			for(int j=4;j<=36;j++)
				table[i][j]=' ';
		for(int i=0;i<100;i++){
			int x=rand()%33+4;
			int y=rand()%33+4;
			if((x-4)*(x-36)*(y-4)*(y-36)==0){
				i--;
				continue;
			}
			table[x][y]='#';
		}
		for(int i=0;i<50;i++){
			int x=rand()%33+4;
			int y=rand()%33+4;
			if((x-4)*(x-36)*(y-4)*(y-36)==0){
				i--;
				continue;
			}
			table[x][y]='$';
		}
	}
};
Map game_map;
