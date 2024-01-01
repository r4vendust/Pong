#include "Collision.h"

typedef struct ThreeSegmentRectangle
{
	Rectangle top, middle, bottom;
};

Collision::Collision()
{
	paddleCollision = false;
	cpuPaddleCollision = false;
}

void Collision::CheckCollision(Paddle &paddle, CpuPaddle &cpuPaddle, Ball &ball)
{
	ThreeSegmentRectangle paddleSegment = ThreeSegmentCollision(paddle.GetPaddle());
	ThreeSegmentRectangle cpuPaddleSegment = ThreeSegmentCollision(cpuPaddle.GetPaddle());

	DrawCollisionSegment(paddleSegment);
	DrawCollisionSegment(cpuPaddleSegment);

	DrawCircleLines(ball.GetPosition().x, ball.GetPosition().y, ball.GetRadius(), RED);

	if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddleSegment.top)
		|| CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddleSegment.top))
	{
		ball.SetSpeedY(
			ball.GetSpeed().y * -1
		);
		ball.InvertSpeed();
		TraceLog(LOG_INFO, "Top Collision");
	}
	else if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddleSegment.middle)
		|| CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddleSegment.middle))
	{
		ball.InvertSpeed();
		TraceLog(LOG_INFO ,"Middle Collision");
	}
	else if (CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddleSegment.bottom)
		|| CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddleSegment.bottom))
	{
		ball.SetSpeedY(
			ball.GetSpeed().y * -1
		);
		ball.InvertSpeed();
		TraceLog(LOG_INFO, "Bottom Collision");
	}
}

ThreeSegmentRectangle Collision::ThreeSegmentCollision(Rectangle rect)
{
	float rect1Height = rect.height / 4;
	float rect2Height = rect.height / 2;
	float rect3Height = rect1Height;

	ThreeSegmentRectangle threeSegmentRectangle;

	Rectangle paddleTop = { rect.x, rect.y, rect.width, rect1Height };
	Rectangle paddleMiddle = { rect.x, rect.y + rect1Height, rect.width + offset, rect2Height };
	Rectangle paddleBottom = { rect.x, rect.y + rect1Height + rect2Height, rect.width, rect3Height };

	threeSegmentRectangle.top = paddleTop;
	threeSegmentRectangle.middle = paddleMiddle;
	threeSegmentRectangle.bottom = paddleBottom;

	return threeSegmentRectangle;
}

void Collision::DrawCollisionSegment(ThreeSegmentRectangle rec)
{
	DrawRectangleLines(rec.top.x, rec.top.y, rec.top.width, rec.top.height, RED);
	DrawRectangleLines(rec.middle.x, rec.middle.y, rec.middle.width, rec.middle.height, GREEN);
	DrawRectangleLines(rec.bottom.x, rec.bottom.y, rec.bottom.width, rec.bottom.height, BLUE);
}