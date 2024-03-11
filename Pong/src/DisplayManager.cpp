#include "DisplayManager.h"

int DisplayManager::width = 800;
int DisplayManager::height = width / 4 * 3;
const char* DisplayManager::gameTitle = "Pong";
bool DisplayManager::isInitialized = false;

DisplayManager::DisplayManager()
{
	if (!isInitialized)
	{
		SetConfigFlags(!FLAG_WINDOW_RESIZABLE);
		SetConfigFlags(FLAG_VSYNC_HINT);
		InitWindow(width, height, gameTitle);
		isInitialized = true;
		HideCursor();
	}
	TraceLog(LOG_INFO, "**********************************************************************");
	TraceLog(LOG_INFO, "DISPLAY MANAGER HAS BEEN INITIALIZED!");
}

DisplayManager::~DisplayManager()
{
	
}

DisplayManager& DisplayManager::getInstance()
{
	static DisplayManager instance;
	return instance;
}

int DisplayManager::GetDisplayWidth()
{
	Update();
	return width;
}

int DisplayManager::GetDisplayHeight()
{
	Update();
	return height;
}

void DisplayManager::Update()
{
	width = GetScreenWidth();
	height = GetScreenHeight();
}