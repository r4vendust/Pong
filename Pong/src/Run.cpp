#include "Run.h";


Run::Run()
{;
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		ball.Draw();
		ball.InitMoviment();
		paddle.Draw();
		paddle.Control();
		cpuPaddle.Draw();
		cpuPaddle.Control(ball.GetVerticalPosition());

		EndDrawing();
	}
	CloseWindow();
}

Run::~Run() {}