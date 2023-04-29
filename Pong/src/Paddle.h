#pragma once

#include "raylib.h"
#include "DisplayManager.h"

class Paddle
{
public:
	Paddle(DisplayManager& display);
	virtual ~Paddle();
	void Draw();
	void InitControl();
	void MoveUp();
	void MoveDown();

private:
	int paddleWidth, paddleHeight;
	int pos_x, pos_y;
	int speedY;
	Color color;
	DisplayManager& display;
};