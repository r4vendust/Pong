#include "CpuPaddle.h";

CpuPaddle::CpuPaddle()
{
	SetPosition(GetScreenWidth() - 27, GetScreenHeight() / 2.5);
}

void CpuPaddle::Control(int ball_y)
{
	if (GetPaddle().y + GetPaddle().height / 2 > ball_y)
	{
		MoveUp();
	}
	if (GetPaddle().y + GetPaddle().height / 2 <= ball_y)
	{
		MoveDown();
	}
}