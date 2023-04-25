#include "Run.h"


Run::Run() : ball(display), paddle(display)
{

	Ball ball(display);
	Paddle paddle(display);

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		ball.Draw();
		paddle.Draw();
		ball.InitMoviment();

		EndDrawing();
	}
	CloseWindow();
}

Run::~Run() {}