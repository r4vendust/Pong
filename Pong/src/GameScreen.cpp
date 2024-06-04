#include "GameScreen.h"

GameScreen* GameScreen::instance = nullptr;

GameScreen* GameScreen::GetInstance()
{
	if (!instance)
	{
		instance = new GameScreen();
	}
	return instance;
}

GameScreen::GameScreen()
{
	width = static_cast<float>(GetScreenWidth() / 2) - (static_cast<float>(GetScreenWidth() / 8));
	height = static_cast<float>(GetScreenHeight() / 4);

	playerScore = 0;
	cpuScore = 0;
}

void GameScreen::DestroyScreen()
{
	delete instance;
	instance = nullptr;
}

void GameScreen::Draw()
{
	ClearBackground(DARKGRAY);
}

void GameScreen::Update()
{
	collision.CheckCollision(paddle, cpuPaddle, ball);

	//ball.InitMoviment();
	//paddle.Control();
	//cpuPaddle.Control(ball);

	DrawText(TextFormat("%i", playerScore), width / 2, 50, 30, WHITE);
	DrawText(TextFormat("%i", cpuScore), width * 2, 50, 30, WHITE);

	ball.Update();
	paddle.Update();
	cpuPaddle.Update(ball);

	if (ball.getHCollision() == 1)
	{
		playerScore++;
	}
	else if (ball.getHCollision() == -1)
	{
		cpuScore++;
	}
}