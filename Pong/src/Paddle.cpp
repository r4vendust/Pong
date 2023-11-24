#include "Paddle.h"

Paddle::Paddle(DisplayManager& display) : display(display)
{
	position.x = display.GetDisplayWidth() / display.GetDisplayWidth() + 9;
	position.y = display.GetDisplayHeight() / 2.5;
	dimention = { 15, 100 };

	paddle = { 
		position.x,
		position.y,
		dimention.x,
		dimention.y, 
	};

	/*
	sidePaddle = {
		position.x + dimention.x,
		position.y + dimention.y,
		dimention.y,
		dimention.x,
	};
	*/
	speedY = 500;
	color = WHITE;

	Draw();
}

Paddle::~Paddle()
{

}

void Paddle::Draw()
{
	DrawRectangleRec(paddle, color);
	//DrawRectangleRec(sidePaddle, GREEN);
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
	if (paddle.y > display.GetDisplayHeight() / display.GetDisplayHeight())
	{
		paddle.y -= speedY * GetFrameTime();
		//sidePaddle.y -= speedY * GetFrameTime();
	}
}

void Paddle::MoveDown()
{
	if (paddle.y < display.GetDisplayHeight() - dimention.y)
	{
		paddle.y += speedY * GetFrameTime();
		//sidePaddle.y += speedY * GetFrameTime();
	}
}