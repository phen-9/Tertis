
#pragma once
#include "tetromino.hpp"

//definitions for different tetromino blocks
class SquareBlock : public Tetromino {
public:
	SquareBlock();
	void rotate();
	SquareBlock* clone();
private:

};

class LineBlock : public Tetromino {
public:
	LineBlock();
	void rotate();
	LineBlock* clone();
private:

};

class LBlock : public Tetromino {
public:
	LBlock();
	void rotate();
	LBlock* clone();
private:

};

class JBlock : public Tetromino {
public:
	JBlock();
	void rotate();
	JBlock* clone();
private:

};

class TBlock : public Tetromino {
public:
	TBlock();
	void rotate();
	TBlock* clone();
private:

};

class SBlock : public Tetromino {
public:
	SBlock();
	void rotate();
	SBlock* clone();
private:

};

class ZBlock : public Tetromino {
public:
	ZBlock();
	void rotate();
	ZBlock* clone();
private:

};