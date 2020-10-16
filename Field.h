#pragma once
#ifndef _Field_H
#define _Field_H

using namespace std;

const int FIELD_WIDTH = 7;
const int FIELD_HEIGHT = 6;

enum Cell
{
	EMPTY=0,
	RED=2,
	YELLOW=8
};

class Field
{
	Cell cells[FIELD_WIDTH][FIELD_HEIGHT];
	bool isRedTurn;
	Cell winner;

public:
	Field(bool isRedFirst);
	void clear(bool isRedFirst);
	bool makeTurn(int column);
	bool isWon(bool red) const;
	bool isOver() const;
	Cell getCell(int i, int j) const;
	bool isRedTurnNow() const;
	void print() const;
	void checkWinner();
	void printResult() const;
};
#endif
