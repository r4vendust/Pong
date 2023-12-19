#include "CpuPaddle.h";

CpuPaddle::CpuPaddle()
{
	SetPosition(GetScreenWidth() - 27, GetScreenHeight() / 2.5);
}

void CpuPaddle::Control(Ball &ball)
{
	if (ball.GetSpeed().x > 0)
	{
		if (GetPaddle().y + GetPaddle().height / 2 > ball.GetVerticalPosition())
		{
			MoveUp();
		}
		if (GetPaddle().y + GetPaddle().height / 2 <= ball.GetVerticalPosition())
		{
			MoveDown();
		}
		
	}
}