#pragma once
#include <iostream>
using namespace std;

class Reversi
{
public:
	//x,y,Black or White return can turn point total
	int CheckputPoint(int,int,int,int);//1put 0check


	//black or white return total point
	int TotalPoint(int);

	int check(int x, int y, int wx, int wy, int pointtype,int times,int mode);


	Reversi(void);
	~Reversi(void);
	int board[10][10];
};

