#include "MenuScreen.h"

MenuScreen* MenuScreen::instance = nullptr;

MenuScreen* MenuScreen::GetInstance()
{
	if (!instance)
	{
		instance = new MenuScreen();
	}
	return instance;
}

MenuScreen::MenuScreen()
{
	bStartClicked = false;
	bExitClicked = false;
	bOptionsClicked = false;

	width = static_cast<float>(GetScreenWidth() / 2) - (static_cast<float>(GetScreenWidth() / 8));
	height = static_cast<float>(GetScreenHeight() / 4);

	button = Button({ width, height }, "START");
	button2 = Button({ width, height + 100 }, "OPTIONS");
	button3 = Button({ width, height + 200 }, "EXIT");

	button.SetButtonSize(170, 60);
	button2.SetButtonSize(170, 60);
	button3.SetButtonSize(170, 60);

	button.SetColors(RED, WHITE, MAROON, GRAY, DARKPURPLE, BLACK);
	button2.SetColors(GREEN, WHITE, LIME, GRAY, DARKPURPLE, BLACK);
	button3.SetColors(SKYBLUE, WHITE, BLUE, GRAY, DARKPURPLE, BLACK);
}

void MenuScreen::DestroyScreen()
{
	delete instance;
	instance = nullptr;
}

void MenuScreen::Draw()
{
	ClearBackground(RAYWHITE);

	button.Draw();
	button.Update();
	button2.Draw();
	button2.Update();
	button3.Draw();
	button3.Update();

	//DrawTexture(cursorDefaultTexture, GetMouseX() - 7, GetMouseY() - 2, RAYWHITE);
}

void MenuScreen::Control()
{
	if (button.IsClicked())
	{
		bStartClicked = true;
	}
	if (button2.IsClicked())
	{
		bOptionsClicked = true;
	}
	if (button3.IsClicked())
	{
		bExitClicked = true;
	}
}

void MenuScreen::Update()
{
	Draw();
	Control();
}

bool MenuScreen::IsStartClicked()
{
	return bStartClicked;
}

bool MenuScreen::IsExitClicked()
{
	return bExitClicked;
}

bool MenuScreen::IsOptionsClicked()
{
	return bOptionsClicked;
}

void MenuScreen::ResetStartClicked()
{
	bStartClicked = false;
}

void MenuScreen::ResetExitClicked()
{
	bExitClicked = false;
}

void MenuScreen::ResetOptionsClicked()
{
	bOptionsClicked = false;
}