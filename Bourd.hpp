#ifndef ___BOURD_INCLUDED___
#define ___BOURD_INCLUDED___
#include<iostream>
#include<vector>
#include<memory>
#include"Panel.hpp"

using namespace std;

class Bourd{

public:

	 Bourd(int, int, int);

	bool isClear();

	void putMine(int);
	void putMine(int, int);

	void open(int, bool);
	void open(int, int, bool);

	void show();

private:

	bool clear;
	int  numMine;

	int  width;
	int  height;

	vector<shared_ptr<Panel>> panels;

	void vecInit(int);
	
	int  toVecId			(			int  width, int  height);
	void toWidthAndHeight	(int place, int* width, int* height);

	void addNumMineAround(int, int);
	void calNumMineAround(int, int);

	void sqrOpen(int, int, bool);

};

#endif
