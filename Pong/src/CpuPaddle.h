#pragma once
#include "Paddle.h";

class CpuPaddle : public Paddle
{
public:
	CpuPaddle();
	void Control(int ball_y);
};

