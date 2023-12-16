#pragma once

#include "raylib.h"
#include "DisplayManager.h"
#include "Ball.h"
#include "Paddle.h"
#include "CpuPaddle.h";
#include "Collision.h";

class Run
{
public:
	Run();
	virtual ~Run();
private:
	Ball ball;
	Paddle paddle;
	CpuPaddle cpuPaddle;
	Collision collision;
};