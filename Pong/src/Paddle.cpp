#include "Paddle.h"

Paddle::Paddle(DisplayManager& display) : display(display)
{
	Draw();
}

Paddle::~Paddle()
{

}

void Paddle::Draw()
{

	pos_x = display.GetDisplayWidth() / display.GetDisplayWidth() + 9;
	pos_y = display.GetDisplayHeight() / 2.5;
	paddleWidth = 15;
	paddleHeight = 100;
	color = WHITE;

	DrawRectangle(pos_x, pos_y, paddleWidth, paddleHeight, color);
}