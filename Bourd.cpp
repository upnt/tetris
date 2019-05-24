#include<iostream>
#include<random>
#include"Bourd.hpp"

using namespace std;

Bourd::Bourd(int numMine, int width, int height) 
	: clear(false), numMine(numMine), width(width - 1), height(height - 1){
	vecInit(toVecId(width, height));

}

void Bourd::vecInit(int vecId){
	panels.erase(panels.begin(), panels.end());

	for(int i = 0; i <= vecId; i++){ 
		shared_ptr<Panel> bufPanelPtr(new Panel());

		panels.push_back(bufPanelPtr);
	}
}

int Bourd::toVecId(int width, int height){
	return (this -> width + 1) * height + width;
}

void Bourd::open(int width, int height, bool playing){
	int vecId = toVecId(width, height);
	if((0 <= vecId) &&( vecId <= toVecId(this -> width, this -> height))){
		if(panels[vecId].get() -> getBeMine()){
			clear = true;
			playing = false;
		}

			panels[vecId].get() -> open();
		}
}

void Bourd::sqrOpen(int width, int height, bool playing){
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

bool Bourd::getClear(){
	return clear;
}

void Bourd::putMine(int preWidth, int preHeight){

	int i, bufVecId, bufX, bufY;
		
	vecInit(toVecId(width, height));
	clear = false;

	random_device rnd;
	mt19937 mt(rnd());

	sqrOpen(preWidth, preHeight, false);

	for(i = 0; i < numMine; i++){
		bufX = mt() % width;
		bufY = mt() % height;
		bufVecId = toVecId(bufX, bufY);
		
		if(panels[bufVecId].get() -> getBeOpened() || (panels[bufVecId].get() -> getBeMine()))
			continue;

		panels[bufVecId].get() -> putMine();
		calNumMineAround(bufX, bufY);
	}

	sqrOpen(preWidth, preHeight, true);
	
}

void Bourd::addNumMineAround(int width, int height){
	if((0 <= width)	&& (width <= this -> width)){
		if((0 <= height) && (height <= this -> height))
			panels[toVecId(width, height)].get() -> incNumMineAround();
	}
}

void Bourd::calNumMineAround(int width, int height){

	addNumMineAround(width - 1, height - 1);
	addNumMineAround(width - 1, height	  );
	addNumMineAround(width - 1, height + 1);
	addNumMineAround(width	  , height - 1);
	addNumMineAround(width	  , height + 1);
	addNumMineAround(width + 1, height - 1);
	addNumMineAround(width + 1, height	  );
	addNumMineAround(width + 1, height + 1);
		
}

void Bourd::show(){
	system("reset");
	cout << "  ";
	for(int i = 0; i <= width; i++)
		cout << ' ' << i;

	int j = 0;
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
			
