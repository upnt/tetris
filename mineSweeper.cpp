#include"Bourd.hpp"
#include"GameMode.hpp"

int main(){
	Bourd* bourd;
	GameMode gameMode = GameMode::End;

	do{
		int width = 1, height = 1, numMine = 0;

		cout << "width:";
		cin  >>  width;

		cout << "height:";
		cin  >>  height;

		cout << "numMine:";
		cin  >>  numMine;

		bourd = new Bourd(numMine, width, height);

		do{
			int startPlace = 11;
			do{

				cout << "startPlase(WidthHeight)(example 56):";
				cin  >> startPlace;

			}while(!(11 <= startPlace));

			bourd -> putMine(startPlace);

			while(!(bourd -> isClear())){
				int place = 11;
				do{
					bourd -> show();

					cout << "plase(example 14):";
					cin  >> place;

					bourd -> open(place, true);
				}while(!(11 <= place));
			}

			do{
				int buf = 3;

				cout << "Do you continue?(0:end, 1:continue, 2:reset):" ;
				cin  >> buf;
				gameMode = GameMode::toGameMode(buf);

			}while(gameMode == GameMode::Null);
		}while(gameMode == GameMode::Continue);

		delete bourd;

	}while(gameMode == GameMode::Reset);

	return 0;
}
