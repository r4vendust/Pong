#include "Run.h"


Run::Run() : ball(display), paddle(display)
{
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);

		ball.Draw();
		ball.InitMoviment();
		paddle.Draw();
		paddle.InitControls();

		EndDrawing();
	}
	CloseWindow();
}

Run::~Run() {}