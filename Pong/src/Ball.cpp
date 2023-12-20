#include "Ball.h"

Ball::Ball()
{
	DisplayManager& display = DisplayManager::getInstance();

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
	// Right
	if (position.x > GetScreenWidth())
	{
		position.x = GetScreenWidth();
		speed.x *= -1;
	}
	// Left
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

float Ball::GetVerticalPosition()
{
	return this->position.y;
}

Vector2 Ball::GetPosition()
{
	return this->position;
}

float Ball::GetRadius()
{
	return this->radius;
}

void Ball::SetSpeed()
{
	this->speed.x *= -1;
}

Vector2 Ball::GetSpeed()
{
	return speed;
}