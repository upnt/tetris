#include"Bourd.hpp"
#include"GameMode.hpp"

GameMode toGameMode(int);
void toWidthAndHeight(int, int*, int*);

int main(){
	Bourd* bourd;
	int width, height, numMine;
	int place;
	int buf;
	GameMode gameMode = END;

	do{
		cout << "width:";
		cin >> width;

		cout << "height:";
		cin >> height;

		cout << "numMine:";
		cin >> numMine;

		bourd = new Bourd(numMine, width, height);

		do{
			cout << "startPlase(WidthHeight)(example 56):";
			cin >> place;

			toWidthAndHeight(place, &width, &height);

			bourd -> putMine(width, height);

			while(!(bourd -> getClear())){
				bourd -> show();

				cout << "plase(example 04):";
				cin >> place;

				toWidthAndHeight(place, &width, &height);

				bourd -> open(width, height, true);
			}

			do{
				cout << "Do you continue?(0:end, 1:continue, 2:reset):" ;
				cin >> buf;
				gameMode = toGameMode(buf);	
			}while(gameMode == NOGAME);

		}while(gameMode == CONTINUE);
	}while(gameMode == RESET);
	return 0;
}

GameMode toGameMode(int buf){
	switch(buf){
	case 0:
		return END;
	case 1:
		return CONTINUE;
	case 2:
		return RESET;
	default:
		return NOGAME;
	}
}

void toWidthAndHeight(int place, int *width, int *height){
	*height = place % 10;
	*width = place / 10;
}
