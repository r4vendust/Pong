#pragma once

#include "raylib.h"
#include "DisplayManager.h"
#include "Ball.h"
#include "Paddle.h"

class Run
{
public:
	Run();
	virtual ~Run();
private:
	DisplayManager display;
	Ball ball;
	Paddle paddle;
};