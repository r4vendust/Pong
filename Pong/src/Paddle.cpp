#include "Paddle.h"

Paddle::Paddle()
{
	DisplayManager& display = DisplayManager::getInstance();

	position.x = display.GetDisplayWidth() / display.GetDisplayWidth() + 9;
	position.y = display.GetDisplayHeight() / 2.5;
	dimention = { 15, 100 };

	paddle = { 
		position.x,
		position.y,
		dimention.x,
		dimention.y, 
	};
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
}

void Paddle::Control()
{
	std::map<int, std::function<void()>> keyMappings;

	keyMappings[KEY_UP] = [&]() { MoveUp(); };
	keyMappings[KEY_DOWN] = [&]() { MoveDown(); };
	keyMappings[KEY_LEFT_SHIFT] = [&]() { SetSpeed(1200); };

	for (const auto& [key, action] : keyMappings)
	{
		if (IsKeyDown(key))
		{
			action();
		}
		else if (IsKeyReleased(key))
		{
			SetSpeed(500);
		}

	}
}

void Paddle::MoveUp()
{
	DisplayManager& display = DisplayManager::getInstance();

	if (paddle.y > display.GetDisplayHeight() / display.GetDisplayHeight())
	{
		paddle.y -= speedY * GetFrameTime();
	}
}

void Paddle::MoveDown()
{
	DisplayManager& display = DisplayManager::getInstance();

	if (paddle.y < display.GetDisplayHeight() - dimention.y)
	{
		paddle.y += speedY * GetFrameTime();
	}
}

void Paddle::SetPosition(float x, float y)
{
	paddle.x = x;
	paddle.y = y;
}

Rectangle Paddle::GetPaddle()
{
	return paddle;
}

void Paddle::SetSpeed(int speed)
{
	speedY = speed;
}