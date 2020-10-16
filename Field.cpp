#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

#include "Field.h"

Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
bool isRedTurn;
Cell winner;

using namespace std;



Field::Field(bool isRedFirst)
	{
		clear(isRedFirst);
	}
void Field::clear(bool isRedFirst)
{
	isRedTurn = isRedFirst;
	winner = EMPTY;
	for (int i=0; i<FIELD_WIDTH; i++)
        for (int j=0; j<FIELD_HEIGHT; j++)
            cells[i][j] = EMPTY;
}

bool Field::makeTurn(int column)
{
	if (winner != EMPTY ||
	column < 1 || column > FIELD_WIDTH)
	return false;
	int i=column-1;
	for (int j=0; j<FIELD_HEIGHT; j++)
	if (cells[i][j]==EMPTY)
	{
		cells[i][j] = isRedTurn ? RED : YELLOW;
		checkWinner();
		isRedTurn = !isRedTurn;
		return true;
	}
	return false;
}




const int DIR_NUMBER = 4;
const int di[] = { 1, 0, 1, 1 };
const int dj[] = { 0, 1, -1, 1 };
const int WIN_LENGTH = 4;

void Field::checkWinner()
{
	for (int i=0; i<FIELD_WIDTH; i++)
		for (int j=0; j<FIELD_HEIGHT; j++)
		{
			Cell start = cells[i][j];
			if (start==EMPTY) continue;
			for (int dir=0; dir<DIR_NUMBER; dir++)
			{
				int length=0, iline = i, jline = j;
				while (++length < WIN_LENGTH)
				{
					iline += di[dir];
					jline += dj[dir];
					if (iline < 0 || iline >= FIELD_WIDTH ||
					jline < 0 || jline >= FIELD_HEIGHT)
					break;
					if (cells[iline][jline]!=start) break;
				}
				if (length==WIN_LENGTH)
				{
					winner = start;
					return;
				}
			}
		}
}




bool Field::isOver() const
{
	if (winner != EMPTY)
	return true;
	for (int i=0; i<FIELD_WIDTH; i++)
		for (int j=0; j<FIELD_HEIGHT; j++)
			if (cells[i][j]==EMPTY)
				return false;
	return true;
}

bool Field::isRedTurnNow() const
{return isRedTurn;}

void Field::print() const
{
	for (int i = FIELD_HEIGHT - 1; i >= 0; i--)
	{
		for (int j = 0; j < FIELD_WIDTH; j++)
			cout << cells[j][i] << " ";
		cout << endl;
	}
}

void Field::printResult() const
{
	if (winner == 8)
		cout<<"Winner: YELLOW"<<endl;
	else
		cout<<"Winner: RED"<<endl;
}
