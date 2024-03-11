#include "Run.h"

Run::Run()
{
	// Default Cursor Image
	cursorDefaultImage = LoadImage("./assets/cursor-default.png");
	ImageResize(&cursorDefaultImage, 25, 25);
	cursorDefaultTexture = LoadTextureFromImage(cursorDefaultImage);

	UnloadImage(cursorDefaultImage);

	// Select Cursor Image
	cursorSelectImage = LoadImage("./assets/cursor-select.png");
	ImageResize(&cursorSelectImage, 25, 25);
	cursorSelectTexture = LoadTextureFromImage(cursorSelectImage);

	UnloadImage(cursorSelectImage);

	// Load Song test
	InitAudioDevice();
	Music music = LoadMusicStream("./assets/sounds/Kitchen Ace (And Taking Names).mp3");
	PlayMusicStream(music);

	bIsRunning = false;
	enum Screens {menu, ingame, options};
	Screens screen = menu;
	Screens prevScreen;

	while (!WindowShouldClose())
	{
		BeginDrawing();

		if (bIsRunning)
		{
			//UpdateMusicStream(music);

			screen = ingame;

			GameScreen::GetInstance()->Draw();
			GameScreen::GetInstance()->Update();

			if (IsKeyPressed(KEY_P))
			{
				bIsRunning = !bIsRunning;
				prevScreen = ingame;
				screen = options;
			}
			DrawTexture(cursorDefaultTexture, GetMouseX() - 7, GetMouseY() - 2, RAYWHITE);
		}
		else
		{
			if (screen == menu)
			{
				MenuScreen::GetInstance()->Update();

				DrawTexture(cursorDefaultTexture, GetMouseX() - 7, GetMouseY() - 2, RAYWHITE);

				if (MenuScreen::GetInstance()->IsStartClicked())
				{
					bIsRunning = !bIsRunning;
				}
				else if (MenuScreen::GetInstance()->IsOptionsClicked())
				{
					prevScreen = menu;
					screen = options;
					MenuScreen::GetInstance()->ResetOptionsClicked();
				}
				else if (MenuScreen::GetInstance()->IsExitClicked())
				{
					break;
				}
			}
			else if (screen == options)
			{
				PauseScreen::GetInstance()->Update();

				if (PauseScreen::GetInstance()->IsBackClicked() && prevScreen == menu)
				{
					PauseScreen::GetInstance()->ResetBackClick();
					screen = menu;
				}
				else if ((PauseScreen::GetInstance()->IsBackClicked() || IsKeyPressed(KEY_P)) && prevScreen == ingame)
				{
					bIsRunning = !bIsRunning;
					PauseScreen::GetInstance()->ResetBackClick();
					screen = ingame;
				}
				else if (PauseScreen::GetInstance()->IsExitClicked())
				{
					break;
				}

				DrawTexture(cursorSelectTexture, GetMouseX() - 10, GetMouseY(), RAYWHITE);
			}
		}

		EndDrawing();
	}

	UnloadTexture(cursorDefaultTexture);
	UnloadTexture(cursorSelectTexture);
	UnloadMusicStream(music);
	CloseAudioDevice();

	CloseWindow();

}

Run::~Run() 
{
	GameScreen::GetInstance()->DestroyScreen();
	MenuScreen::GetInstance()->DestroyScreen();
	PauseScreen::GetInstance()->DestroyInstance();
}