#pragma once

#include "raylib.h"
#include "DisplayManager.h"

class Paddle
{
public:
	Paddle();
	virtual ~Paddle();
	void Draw();
	void Control();
	void MoveUp();
	void MoveDown();
	void SetPosition(float x, float y);
	Rectangle GetPaddle();

private:
	Vector2 dimention;
	Vector2 position;
	Rectangle paddle;
	Rectangle sidePaddle;
	int speedY;
	Color color;
};