#ifndef ___PANEL_INCLUDED___
#define ___PANEL_INCLUDED___
#include<string>
using namespace std;

class Panel{
public:
	Panel();

	bool getBeOpened();
	bool getBeMine();

	void open();
	void putMine();
	void incNumMineAround();

	string getNumMineAround();

private:
	int numMineAround;
	bool beOpened;
	bool beMine;
};

#endif
