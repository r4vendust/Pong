#include "Ball.h"

Ball::Ball(DisplayManager& display) : display(display)
{
	position.x = display.GetDisplayWidth() / 2.0;
	position.y = display.GetDisplayHeight() / 2.0;
	speed = { 300, 300 };
	radius = 5.0;
	color = WHITE;
}

Ball::~Ball()
{
	std::cout << ("LOG: Object Destroyed") << std::endl;
}

void Ball::Draw()
{
	DrawCircle((int)position.x, (int)position.y , radius, color);
}

void Ball::InitMoviment()
{
	position.x += speed.x * GetFrameTime();
	position.y += speed.y * GetFrameTime();
	Behavior();
}

void Ball::Behavior()
{
	if (position.x > GetScreenWidth())
	{
		position.x = GetScreenWidth();
		speed.x *= -1;
	}
	else if (position.x < 0)
	{
		position.x = 0;
		speed.x *= -1;
	}
	if (position.y > GetScreenHeight())
	{
		position.y = GetScreenHeight();
		speed.y *= -1;
	}
	else if (position.y < 0)
	{
		position.y = 0;
		speed.y *= -1;
	}
}