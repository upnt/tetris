nclude <iostream>
#include <string>
#include <time.h>
using namespace std;

#define		N_MINE		10			//	爆弾数
#define		BD_WD		9			//	盤面横数
#define		BD_HT		9			//	盤面縦数

bool	g_open[BD_WD+2][BD_HT+2];		//	マス目を開いているかどうか
bool	g_mine[BD_WD+2][BD_HT+2];		//	爆弾があるかどうか
char	g_nMine[BD_WD+2][BD_HT+2];		//	0-8: 周りの爆弾の数

//	盤面初期化
void init_board()
{
	for (int x = 0; x < BD_WD+2; ++x) {
		for (int y = 0; y < BD_HT+2; ++y) {
			g_mine[x][y] = false;		//	爆弾無し
			g_nMine[x][y] = 0;			//	周りの爆弾数は0
			g_open[x][y] = false;		//	マス目は閉じた状態
		}
	}
	//	爆弾を配置
	for (int i = 0; i < N_MINE; ++i) {
		int x, y;
		do {
			x = rand() % BD_WD + 1;		//	[1, BD_WD]
			y = rand() % BD_HT + 1;		//	[1, BD_HT]
		} while (g_mine[x][y]);		//	既に爆弾が置いてある
		g_mine[x][y] = true;			//	爆弾配置
		//	8近傍の爆弾数をインクリメント
		g_nMine[x-1][y-1] += 1;
		g_nMine[x][y-1] += 1;
		g_nMine[x+1][y-1] += 1;
		g_nMine[x-1][y] += 1;
		g_nMine[x+1][y] += 1;
		g_nMine[x-1][y+1] += 1;
		g_nMine[x][y+1] += 1;
		g_nMine[x+1][y+1] += 1;
	}
}
const char *digitStr[] = {
	"１", "２", "３", "４", "５", "６", "７", "８", "９",
};
void print_board()
{
	cout << "\n　ａｂｃｄｅｆｇｈｉ\n";
	for (int y = 1; y <= BD_HT; ++y) {
		cout << digitStr[y - 1];
		for (int x = 1; x <= BD_WD; ++x) {
			//if( g_mine[x][y] )		//	for test
			//	cout << "★";
			//else
			if( !g_open[x][y] )		//	開いていない
				cout << "■";
			else if( g_mine[x][y] )		//	地雷有り
				cout << "★";
			else if( !g_nMine[x][y] )		//	周りに地雷無し
				cout << "・";
			else		//	周りに地雷有り
				cout << " " << (int)g_nMine[x][y];
		}
		cout << "\n";
	}
	cout << "\n";
}
//	(x, y) を開く、x は [1, BD_WD], y は [1, BD_HT] の範囲
//	周りの爆弾数がゼロならば、周りも開く
void open(int x, int y)
{
	if( x < 1 || x > BD_WD || y < 1 || y > BD_HT )		//	範囲外の場合
		return;
	if( g_open[x][y] )	//	既に開いている場合
		return;
	g_open[x][y] = true;
	if( !g_mine[x][y] && !g_nMine[x][y] ) {		//	そこに爆弾が無く、周りにも爆弾が無い場合
		open(x-1, y-1);		//	周りも開く
		open(x, y-1);
		open(x+1, y-1);
		open(x-1, y);
		open(x+1, y);
		open(x-1, y+1);
		open(x, y+1);
		open(x+1, y+1);
	}
}
//	爆弾箇所以外が全て開いていれば、成功
bool checkSweeped()
{
	for (int x = 1; x <= BD_WD; ++x) {
		for (int y = 1; y <= BD_HT; ++y) {
			if( !g_mine[x][y] && !g_open[x][y] )		//	爆弾が無いのに未だ開いていない
				return false;
		}
	}
	return true;
}
int main()
{
	srand((int)time(0));
	string buffer;
	cout << "MineSweeper version 0.001\n";
	cout << "writen by N.Tsuda\n\n";
	for (;;) {
		init_board();
		bool sweeped = false;
		while (!sweeped) {
			print_board();
			int x, y;		//	開く場所
			for(;;) {
				cout << "where will you open ? [a-i][1-9]\n";
				cin >> buffer;
				if( buffer == "q" ) return 0;	//	"q" で強制終了
				if( buffer.size() < 2 ) continue;
				if( buffer[0] >= 'a' && buffer[0] <= 'i' )
					x = buffer[0] - 'a' + 1;
				else if( buffer[0] >= 'A' && buffer[0] <= 'I' )
					x = buffer[0] - 'A' + 1;
				else
					continue;
				if( buffer[1] >= '1' && buffer[1] <= '9' )
					y = buffer[1] - '0';
				else
					continue;
				break;
			}
			open(x, y);
			if( g_mine[x][y] )		//	爆弾にあたってしまった場合
				break;
			sweeped = checkSweeped();
		}
		print_board();
		if( sweeped )
			cout << "Good-Job !!!  you've sweeped all Mines in success.\n";
		else
			cout << "Oops !!! You've stepped on a Mine...\n\n";
		cout << "\ntry again ?[Y/N]";
		cin >> buffer;
		if( buffer == "n" || buffer == "N" )
			break;
	}
	return 0;
}

