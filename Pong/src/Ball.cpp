#include "Ball.h"

// Constructor
Ball::Ball(DisplayManager& display) : display(display)
{
	pos_x = display.GetDisplayWidth() / 2.0;
	pos_y = display.GetDisplayHeight() / 2.0;
	speedX = 300;
	speedY = 300;
	radius = 5.0;
	color = WHITE;

	Log("Ball Created");
}

Ball::~Ball()
{
	Log("Ball desctroyed");
}

void Ball::Draw()
{
	DrawCircle((int)pos_x, (int)pos_y, radius, color);
}

void Ball::InitMoviment()
{
	pos_x += speedX * GetFrameTime();
	pos_y += speedY * GetFrameTime();
	Behavior();
}

void Ball::Behavior()
{
	if (pos_x > GetScreenWidth())
	{
		pos_x = GetScreenWidth();
		speedX *= -1;
	}
	else if (pos_x < 0)
	{
		pos_x = 0;
		speedX *= -1;
	}
	if (pos_y > GetScreenHeight())
	{
		pos_y = GetScreenHeight();
		speedY *= -1;
	}
	else if (pos_y < 0)
	{
		pos_y = 0;
		speedY *= -1;
	}
}