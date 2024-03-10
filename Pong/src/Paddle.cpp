#include "Paddle.h"

Paddle::Paddle()
{
	DisplayManager& display = DisplayManager::getInstance();

	width = static_cast<float>(display.GetDisplayWidth());
	height = static_cast<float>(display.GetDisplayHeight());

	position.x = width / height + 9;
	position.y = height / 2.5f;
	dimention = { 15, 100 };

	paddle = {
		position.x,
		position.y,
		dimention.x,
		dimention.y,
	};
	speedY = 500;
	color = WHITE;
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

	// Keyboard

	keyMappings[KEY_UP] = [&]() { MoveUp(); };
	keyMappings[KEY_DOWN] = [&]() { MoveDown(); };
	keyMappings[KEY_LEFT_SHIFT] = [&]() { SetSpeed(1200); };

	// GamePad

	keyMappings[GAMEPAD_BUTTON_LEFT_FACE_UP] = [&]() { MoveUp(); };
	keyMappings[GAMEPAD_BUTTON_LEFT_FACE_DOWN] = [&]() { MoveDown(); };
	keyMappings[GAMEPAD_BUTTON_RIGHT_FACE_DOWN] = [&]() { SetSpeed(1200); };


	for (const auto& [key, action] : keyMappings)
	{
		if (IsKeyDown(key) || IsGamepadButtonDown(0, key))
		{
			action();
		}
		else if (IsKeyReleased(key) || IsGamepadButtonReleased(0, key))
		{
			SetSpeed(500);
		}
	}
}

void Paddle::MoveUp()
{
	DisplayManager& display = DisplayManager::getInstance();

	if (paddle.y > height / height)
	{
		paddle.y -= speedY * GetFrameTime();
	}
}

void Paddle::MoveDown()
{
	DisplayManager& display = DisplayManager::getInstance();

	if (paddle.y < height - dimention.y)
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

void Paddle::Update()
{
	Draw();
	Control();
}

void Paddle::GamepadAxisDirection(int gamepad)
{
	if (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y) > 0.5)
	{
		MoveDown();
	}
	else if (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y) < -0.5)
	{
		MoveUp();
	}
	else if (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER) > 0)
	{
		SetSpeed(1200);
	}
	else if (GetGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER) < 0)
	{
		SetSpeed(500);
	}
}