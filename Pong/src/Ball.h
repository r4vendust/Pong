#pragma once

#include <iostream>
#include "raylib.h"
#include "DisplayManager.h"

class Ball
{
public:
	Ball();
	void Draw();
	void InitMoviment();
	void Behavior();
	virtual ~Ball();
	float GetVerticalPosition();
private:
	Vector2 position;
	Vector2 speed;
	float radius;
	Color color;
};