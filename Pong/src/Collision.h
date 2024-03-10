#pragma once
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Ball.h"
#include <deque>

class Collision
{
public:
	Collision();
	void CheckCollision(Paddle &paddle, CpuPaddle &cpuPaddle, Ball &ball);
	void DrawCollisionSegment(std::deque<Rectangle> rec);
private:
	bool paddleCollision;
	bool cpuPaddleCollision;
};

