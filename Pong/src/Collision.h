#pragma once
#include "Paddle.h"
#include "CpuPaddle.h"
#include "Ball.h"

typedef struct ThreeSegmentRectangle;

class Collision
{
public:
	Collision();
	void CheckCollision(Paddle &paddle, CpuPaddle &cpuPaddle, Ball &ball);
	ThreeSegmentRectangle ThreeSegmentCollision(Rectangle rect);
	void DrawCollisionSegment(ThreeSegmentRectangle rec);
private:
	bool paddleCollision;
	bool cpuPaddleCollision;
	const int offset = 1;
};

