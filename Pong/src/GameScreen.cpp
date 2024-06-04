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

	ball.Update();
	paddle.Update();
	cpuPaddle.Update(ball);
}