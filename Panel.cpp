#include"Panel.hpp"
#include<iostream>
#include<string>

using namespace std;

Panel::Panel() 
	: numMineAround(0), beOpened(false), beMine(false){
}

bool Panel::getBeOpened(){
	return beOpened;
}

bool Panel::getBeMine(){
	return beMine;
}

void Panel::open(){
	beOpened = true;
}

void Panel::putMine(){
	beMine = true;
}

void Panel::incNumMineAround(){
	++numMineAround;
	return;
}

string Panel::getNumMineAround(){
	if(!beOpened)
		return "*";
	else if(beMine)
		return "!";
	else{
		return to_string(numMineAround);
	}
}
