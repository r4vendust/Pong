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
	Vector2 dimention;
	Vector2 position;
	Rectangle paddle;
	Rectangle sidePaddle;
	int speedY;
	Color color;
	DisplayManager& display;
};