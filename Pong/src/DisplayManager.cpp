#include "DisplayManager.h"

int DisplayManager::width = 800;
int DisplayManager::height = 600;
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
	}
	std::cout << ("**********************************************************************\n");
	std::cout << ("LOG: DISPLAY MANAGER HAS BEEN INITIALIZED!") << std::endl;
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