#pragma once

#include "raylib.h"
#include "DisplayManager.h"
#include "Logger.h"

class Ball
{
public:
	Ball(DisplayManager& display);
	void Draw();
	void InitMoviment();
	void Behavior();
	virtual ~Ball();
private:
	float pos_x, pos_y;
	float radius;
	float speedX, speedY;
	Color color;
	DisplayManager& display;
};