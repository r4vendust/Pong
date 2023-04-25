#pragma once

#include "raylib.h"
#include "DisplayManager.h"

class Paddle
{
public:
	Paddle(DisplayManager& display);
	void Draw();
	virtual ~Paddle();

private:
	int paddleWidth, paddleHeight;
	int pos_x, pos_y;
	Color color;
	DisplayManager& display;
};