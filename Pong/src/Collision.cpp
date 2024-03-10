#include "Collision.h"

Collision::Collision()
{
	paddleCollision = false;
	cpuPaddleCollision = false;
}

void Collision::CheckCollision(Paddle &paddle, CpuPaddle &cpuPaddle, Ball &ball)
{
	float rect1Height = paddle.GetPaddle().height / 4;
	float rect2Height = paddle.GetPaddle().height / 2;
	float rect3Height = rect1Height;

	paddle.GetPaddle();
	std::deque<Rectangle> paddleSegment = {
		{paddle.GetPaddle().x, paddle.GetPaddle().y, paddle.GetPaddle().width, rect1Height},
		{paddle.GetPaddle().x, paddle.GetPaddle().y + rect1Height, paddle.GetPaddle().width, rect2Height},
		{paddle.GetPaddle().x, paddle.GetPaddle().y + rect1Height + rect2Height, paddle.GetPaddle().width, rect3Height},
	};

	std::deque<Rectangle> cpuPaddleSegment = {
	{cpuPaddle.GetPaddle().x, cpuPaddle.GetPaddle().y, cpuPaddle.GetPaddle().width, rect1Height},
	{cpuPaddle.GetPaddle().x, cpuPaddle.GetPaddle().y + rect1Height, cpuPaddle.GetPaddle().width, rect2Height},
	{cpuPaddle.GetPaddle().x, cpuPaddle.GetPaddle().y + rect1Height + rect2Height, cpuPaddle.GetPaddle().width, rect3Height},
	};

	DrawCollisionSegment(paddleSegment);
	DrawCollisionSegment(cpuPaddleSegment);

	DrawCircleLines(ball.GetPosition().x, ball.GetPosition().y, ball.GetRadius(), RED);

	if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddleSegment[0])
		|| CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddleSegment[0]))
	{
		ball.SetSpeedY(ball.GetSpeed().y * -1);
		ball.InvertSpeed();
		TraceLog(LOG_INFO, "Top Collision");
	}
	else if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddleSegment[1])
		|| CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddleSegment[1]))
	{
		ball.InvertSpeed();
		TraceLog(LOG_INFO ,"Middle Collision");
	}
	else if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddleSegment[2])
		|| CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddleSegment[2]))
	{
		ball.SetSpeedY(ball.GetSpeed().y * -1);
		ball.InvertSpeed();
		TraceLog(LOG_INFO, "Bottom Collision");
	}
}

void Collision::DrawCollisionSegment(std::deque<Rectangle> rec)
{
		DrawRectangleLines(rec[0].x, rec[0].y, rec[0].width, rec[0].height, RED);
		DrawRectangleLines(rec[1].x, rec[1].y, rec[1].width, rec[1].height, GREEN);
		DrawRectangleLines(rec[2].x, rec[2].y, rec[2].width, rec[2].height, BLUE);
}