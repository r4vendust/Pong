#pragma once
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Ball.h"

class Collision
{
public:
	Collision();
	void CheckCollision(Paddle &paddle, CpuPaddle &cpuPaddle, Ball &ball);
private:
	bool paddleCollision;
	bool cpuPaddleCollision;
};

