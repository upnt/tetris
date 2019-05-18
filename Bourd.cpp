#include<iostream>
#include"Bourd.hpp"

Bourd::Bourd(int numMine, int width, int height) : numMine(numMine), width(width), height(height){
	std::cout << numMine << width << height << std::endl;
}

