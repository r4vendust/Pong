#include "Paddle.h"
#include <iostream>

Paddle::Paddle(DisplayManager& display) : display(display)
{
	pos_x = display.GetDisplayWidth() / display.GetDisplayWidth() + 9;
	pos_y = display.GetDisplayHeight() / 2.5;
	paddleWidth = 15;
	paddleHeight = 100;
	speedY = 500;
	color = WHITE;

	Draw();
}

Paddle::~Paddle()
{

}

void Paddle::Draw()
{
	DrawRectangle(pos_x, pos_y, paddleWidth, paddleHeight, color);
}

void Paddle::InitControl()
{
	if (IsKeyDown(KEY_UP))
	{
		MoveUp();
	}
	
	if (IsKeyDown(KEY_DOWN))
	{
		MoveDown();
	}
}

void Paddle::MoveUp()
{
	if (pos_y > display.GetDisplayHeight() / display.GetDisplayHeight())
	{
		pos_y -= speedY * GetFrameTime();
	}
}

void Paddle::MoveDown()
{
	if (pos_y < display.GetDisplayHeight() - paddleHeight)
	{
		pos_y += speedY * GetFrameTime();
	}
}