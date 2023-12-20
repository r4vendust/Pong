#include "Collision.h"

Collision::Collision()
{
	paddleCollision = false;
	cpuPaddleCollision = false;
}

void Collision::CheckCollision(Paddle &paddle, CpuPaddle &cpuPaddle, Ball &ball)
{
	paddleCollision = CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), paddle.GetPaddle());
	cpuPaddleCollision = CheckCollisionCircleRec(ball.GetPosition(), ball.GetRadius(), cpuPaddle.GetPaddle());

	if (paddleCollision || cpuPaddleCollision)
	{
		ball.InvertSpeed();
	}
}