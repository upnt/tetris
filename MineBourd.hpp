#ifndef ___MINEBOURD_INCLUDED___
#define ___MINEBOURD_INCLUDED___
#include<iostream>
#include<memory>


class MineBourd{
public:
	MineBourd(int width , int height);

	bool isClear()			= 0;
	
	void putMine(int place)	= 0;

	void show()				= 0;

private:
	bool clear;
	
	int width;
	int height;

	std::vector<std::shared_ptr<Panel>> panels;

	bool isClear();

	virtual void putMine(int, int)	= 0;

	virtual void show()				= 0;

	int toVecId				(			int  width, int  height);
	int toWidthAndHeight	(int place, int* width, int* height);

};
