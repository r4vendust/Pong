#pragma once
#include "Paddle.h";
#include "Ball.h";

class CpuPaddle : public Paddle
{
public:
	CpuPaddle();
	void Control(Ball &ball);
private:
};