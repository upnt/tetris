#include<iostream>
#include<random>
#include"Bourd.hpp"

using namespace std;

//constract
MineBourd::MineBourd(int numMine, int width, int height) 
	: MineBourd(width, height), numMine(numMine){
}


void MineBourd::putMine(int place){
	int preWidth, preHeight;
	toWidthAndHeight(place, &preWidth, &preHeight);

	putMine(preWidth, preHeight);
}





//interface
void MineBourd::show(){
	system("reset");
	cout << "  ";
	for(int i = 1; i <= width + 1; i++)
		cout << ' ' << i;

	int j = 1;
	for(int i = 0; i <= toVecId(width, height) ; i++){
		if(i % (width + 1) == 0){
			cout << endl;
			cout << ' ' << j;
			j++;
		}
		cout << ' ' << (panels[i].get() -> getNumMineAround());
	}
	cout << endl;
}






//process
void MineBourd::putMine(int preWidth, int preHeight){

	int i, bufVecId, bufX, bufY;
		
	clear = false;

	random_device rnd;
	mt19937 mt(rnd());

	sqrOpen(preWidth, preHeight, false);

	for(i = 0; i < numMine; i++){
		bufX = mt() % width;
		bufY = mt() % height;
		bufVecId = toVecId(bufX, bufY);
		
		if(panels[bufVecId].get() -> getBeOpened() 
			|| (panels[bufVecId].get() -> getBeMine()))
				continue;

		panels[bufVecId].get() -> putMine();
		calNumMineAround(bufX, bufY);
	}

	sqrOpen(preWidth, preHeight, true);

}


void MineBourd::open(int width, int height, bool playing){
	int vecId = toVecId(width, height);

	if((0 <= vecId) && ( vecId <= toVecId(this -> width, this -> height))){

		if(panels[vecId].get() -> getBeMine()){

			clear = true;
			playing = false;
		}

			panels[vecId].get() -> open();
	}
}



	
void MineBourd::addNumMineAround(int width, int height){
	if((0 <= width)	&& (width <= this -> width)){
		if((0 <= height) && (height <= this -> height))
			panels[toVecId(width, height)].get() -> incNumMineAround();
	}
}

void MineBourd::calNumMineAround(int width, int height){

	addNumMineAround(width - 1, height - 1);
	addNumMineAround(width - 1, height	  );
	addNumMineAround(width - 1, height + 1);
	addNumMineAround(width	  , height - 1);
	addNumMineAround(width	  , height + 1);
	addNumMineAround(width + 1, height - 1);
	addNumMineAround(width + 1, height	  );
	addNumMineAround(width + 1, height + 1);
		
}

void MineBourd::sqrOpen(int width, int height, bool playing){
	open(width - 1, height - 1, playing);
	open(width - 1, height	  , playing);
	open(width - 1, height + 1, playing);
	open(width	  , height - 1, playing);
	open(width	  , height	  , playing);
	open(width	  , height + 1, playing);
	open(width + 1, height - 1, playing);
	open(width + 1, height	  , playing);
	open(width + 1, height + 1, playing);
}
