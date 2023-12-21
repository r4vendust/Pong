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
	Vector2 GetPosition();
	float GetRadius();
	void InvertSpeed();
	Vector2 GetSpeed();
	void SetSpeedX(float x);
	void SetSpeedY(float y);

private:
	Vector2 position;
	Vector2 speed;
	float radius;
	Color color;
};