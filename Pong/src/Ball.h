#pragma once

#include <iostream>
#include "raylib.h"
#include "DisplayManager.h"

class Ball
{
public:
	Ball(DisplayManager& display);
	void Draw();
	void InitMoviment();
	void Behavior();
	virtual ~Ball();
private:
	Vector2 position;
	Vector2 speed;
	float radius;
	Color color;
	DisplayManager& display;
};