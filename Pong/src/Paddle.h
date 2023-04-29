#pragma once

#include "raylib.h"
#include "DisplayManager.h"
#include "Logger.h"

class Paddle : public Logger
{
public:
	Paddle(DisplayManager& display);
	virtual ~Paddle();
	void Draw();
	void InitControls();
	void MoveUp();
	void MoveDown();

private:
	int paddleWidth, paddleHeight;
	int pos_x, pos_y;
	int speedY;
	Color color;
	DisplayManager& display;
};