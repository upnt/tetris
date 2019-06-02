#ifndef ___GAMEMODE_INCLUDED___
#define ___GAMEMODE_INCLUDED___

#include<iostream>

class GameMode{

public:

	enum Type{
		End,
		Continue,
		Reset,
		Null
	} type;

	GameMode(enum Type);

	static GameMode toGameMode(int buf);

	bool		operator==(const GameMode& gameMode);
	GameMode& 	operator =(const GameMode& gameMode);

	//Don't use without using interface

};

#endif

