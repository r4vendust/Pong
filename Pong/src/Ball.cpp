#include "Ball.h"

Ball::Ball()
{
	DisplayManager& display = DisplayManager::getInstance();

	position.x = display.GetDisplayWidth() / 2.0;
	position.y = display.GetDisplayHeight() / 2.0;
	speed = { 300, 300 };
	radius = 5.0;
	color = WHITE;

	horizontalCollision = 0;
}

Ball::~Ball()
{
	TraceLog(LOG_INFO, "Ball Destroyed");
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
	horizontalCollision = 0;
	// Right
	if (position.x > GetScreenWidth())
	{
		position.x = GetScreenWidth();
		speed.x *= -1;
		horizontalCollision = 1;

	}
	// Left
	else if (position.x < 0)
	{
		position.x = 0;
		speed.x *= -1;
		horizontalCollision = -1;
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

void Ball::InvertSpeed()
{
	this->speed.x *= -1;
}

Vector2 Ball::GetSpeed()
{
	return speed;
}

void Ball::SetSpeedX(float x)
{
	this->speed.x = x;
}

void Ball::SetSpeedY(float y)
{
	this->speed.y = y;
}

void Ball::Update()
{
	Draw();
	InitMoviment();
}

int Ball::getHCollision()
{
	return horizontalCollision;
}