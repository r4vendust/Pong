#include "Run.h"

Run::Run()
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		collision.CheckCollision(paddle, cpuPaddle, ball);

		ball.Draw();
		ball.InitMoviment();
		paddle.Draw();
		paddle.Control();
		cpuPaddle.Draw();
		cpuPaddle.Control(ball);

		EndDrawing();
	}
	CloseWindow();
}

Run::~Run() {}