#include "PauseScreen.h"

PauseScreen* PauseScreen::instance = nullptr;

PauseScreen* PauseScreen::GetInstance()
{
	if (!instance)
	{
		instance = new PauseScreen();
	}
	return instance;
}

PauseScreen::PauseScreen()
{
	bExitClicked = false;
	bBackClicked = false;

	posX = static_cast<float>((GetScreenWidth() / 2) - 80);
	posY = static_cast<float>((GetScreenHeight() / 6) - 40);
	text = "PAUSED";

	textOffset = 50;
	pauseOffset = 100;

	button = Button({ posX - 100, posY + pauseOffset }, "Vsync: ON");
	button2 = Button({ posX - 100, posY + pauseOffset * 1.6f}, "FullScreen: OFF");
	button3 = Button({ posX - 100, posY + pauseOffset * 2.2f}, "Back");
	button4 = Button({ posX - 100, posY + pauseOffset * 3.2f}, "Exit");

	button.SetColors(BLACK, WHITE, MAROON, GRAY, DARKPURPLE, BLACK);
	button2.SetColors(BLACK, WHITE, MAROON, GRAY, DARKPURPLE, BLACK);
	button3.SetColors(BLACK, WHITE, MAROON, GRAY, DARKPURPLE, BLACK);
	button4.SetColors(BLACK, WHITE, MAROON, GRAY, DARKPURPLE, BLACK);

	button.SetFontSize(40);
	button2.SetFontSize(40);
	button3.SetFontSize(40);
	button4.SetFontSize(40);

	button.DisableResize();
	button2.DisableResize();
	button3.DisableResize();
	button4.DisableResize();

	button.SetButtonSize(350, 50);
	button2.SetButtonSize(350, 50);
	button3.SetButtonSize(350, 50);
	button4.SetButtonSize(350, 50);
}

PauseScreen::~PauseScreen()
{
	TraceLog(LOG_INFO, "PauseScreen destroyed");
}

void PauseScreen::Draw()
{
	ClearBackground(BLACK);

	DrawText(text, posX, posY, 40, WHITE);

	button.Draw();
	button.Update();

	button2.Draw();
	button2.Update();

	button3.Draw();
	button3.Update();

	button4.Draw();
	button4.Update();

	if (IsWindowState(FLAG_VSYNC_HINT))
	{
		button.SetText("Vsync: ON");
	}
	else
	{
		button.SetText("Vsync: OFF");
	}

	if (IsWindowState(FLAG_FULLSCREEN_MODE))
	{
		button2.SetText("FullScreen: ON");
	}
	else
	{
		button2.SetText("FullScreen: OFF");
	}
}

void PauseScreen::Control()
{
	if (button.IsClicked())
	{
		SetVsync();
	}
	if (button2.IsClicked())
	{
		SetFullScreen();
	}
	if (button3.IsClicked())
	{
		bBackClicked = true;
	}
	if (button4.IsClicked())
	{
		bExitClicked = true;
	}
}

void PauseScreen::Update()
{
	Draw();
	Control();
}

void PauseScreen::SetVsync()
{
	if (!IsWindowState(FLAG_VSYNC_HINT))
	{
		SetWindowState(FLAG_VSYNC_HINT);
		TraceLog(LOG_INFO, "Vsync is ON");
	}
	else
	{
		ClearWindowState(FLAG_VSYNC_HINT);
		TraceLog(LOG_INFO, "Vsync is OFF");
	}
}

void PauseScreen::SetFullScreen()
{
	if (!IsWindowState(FLAG_FULLSCREEN_MODE))
	{
		SetWindowState(FLAG_FULLSCREEN_MODE);
		TraceLog(LOG_INFO, "FullScreen is ON");
	}
	else
	{
		ClearWindowState(FLAG_FULLSCREEN_MODE);
		TraceLog(LOG_INFO, "FullScreen is OFF");
	}
}

bool PauseScreen::IsExitClicked()
{
	return bExitClicked;
}

void PauseScreen::ResetExitClick()
{
	this->bExitClicked = false;
}

bool PauseScreen::IsBackClicked()
{
	return bBackClicked;
}

void PauseScreen::ResetBackClick()
{
	this->bBackClicked = false;
}


void PauseScreen::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}