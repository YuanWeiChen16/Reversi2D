#include "Reversi.h"

int Reversi::check(int x, int y, int wx, int wy, int pointtype, int times, int mode)
{
	if (((x + wx) > 8) || ((x + wx) < 1))
	{
		return 0;
	}
	if (((y + wy) > 8) || ((y + wy) < 1))
	{
		return 0;
	}
	int othertype = 2;
	if (pointtype == 2)
	{
		othertype = 1;
	}

	if (this->board[x + wx][y + wy] == othertype)
	{
		return check(x + wx, y + wy, wx, wy, pointtype, times + 1, mode);
	}
	else if (this->board[x + wx][y + wy] == pointtype)
	{
		if (times == 0)
		{
			return 0;
		}
		else
		{
			if (mode == 1)
			{
				board[x][y] = pointtype;
				check(x - wx, y - wy, wx, wy, pointtype, times - 1, mode);
			}
			return times;
		}
	}
	else 
	{
		return 0;
	}
	return 0;
}

int Reversi::CheckputPoint(int x, int y, int pointtype, int mode)
{
	int ch = 0;
	if ((this->board[x][y] != 1)&& (this->board[x][y] != 2))
	{
		if (mode == 1)
		{
			this->board[x][y] = pointtype;
		}
		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if ((i == 0) && (j == 0))
				{
				}
				else
				{
					ch = ch + check(x, y, i, j, pointtype, 0, mode);
				}
			}
		}
	}
	return ch;
}

int Reversi::TotalPoint(int pointtype)
{
	int total = 0;
	for (int i = 1; i < 9; i++)
	{
		for (int j = 1; j < 9; j++)
		{
			if (Reversi::board[i][j] == pointtype)
			{
				total = total + 1;
			}
		}
	}
	return total;
}

Reversi::Reversi(void)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Reversi::board[i][j] = 0;
		}
	}
	Reversi::board[4][4] = 1;
	Reversi::board[5][5] = 1;
	Reversi::board[4][5] = 2;
	Reversi::board[5][4] = 2;
}


Reversi::~Reversi(void)
{
}
