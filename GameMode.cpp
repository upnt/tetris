#include"GameMode.hpp"

GameMode::GameMode(enum Type type) : type(type){};

GameMode GameMode::toGameMode(int buf){
	switch(buf){
	case 0:
		return GameMode::End;
	case 1:
		return GameMode::Continue;
	case 2:
		return GameMode::Reset;

	default:
		return GameMode::Null;
	}

}




bool		GameMode::operator==(const GameMode& gameMode){
	return type == gameMode.type;
}

GameMode&	GameMode::operator =(const GameMode& gameMode){
	type  = gameMode.type;
	return *this;
}

