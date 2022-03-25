class Map {
protected:
	char table[40][40];
public:
	void Display_Map();
	void Bomb_Effect(int pos_x,int pos_y);
	int Check_Movement(int pos_x, int pos_y);
	Map(){
		srand(time(NULL));
		for(int i=4;i<=36;i++)
			for(int j=4;j<=36;j++)
				table[i][j]=' ';
		for(int i=0;i<150;i++){
			int x=rand()%33+4;
			int y=rand()%33+4;
			if((x-4)*(x-36)*(y-4)*(y-36)==0){
				i--;
				continue;
			}
			table[x][y]='#';
		}
		for(int i=0;i<80;i++){
			int x=rand()%33+4;
			int y=rand()%33+4;
			if((x-4)*(x-36)*(y-4)*(y-36)==0){
				i--;
				continue;
			}
			table[x][y]='$';
		}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++){
				table[i+4][j+4]=' ';
				table[i+4][36-j]=' ';
				table[36-i][j+4]=' ';
				table[36-i][36-j]=' ';
			}
	}
};
Map game_map;
