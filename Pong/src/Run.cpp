#include "Run.h"

Run::Run()
{
	while (!WindowShouldClose())
	{
		if (IsKeyPressed(KEY_P))
		{
			bIsRunning = !bIsRunning;
		}
		BeginDrawing();

		ClearBackground(DARKGRAY);
		

		if (bIsRunning)
		{
			collision.CheckCollision(paddle, cpuPaddle, ball);

			//ball.Draw();
			ball.InitMoviment();
			//paddle.Draw();
			paddle.Control();
			//cpuPaddle.Draw();
			cpuPaddle.Control(ball);
		}
		else
		{
			DrawText("PAUSED", ((int)DM.GetDisplayWidth() / 2) - 80, ((int)DM.GetDisplayHeight() / 2) - 40, 40, WHITE);
		}

		EndDrawing();
	}
	CloseWindow();
}

Run::~Run() {}