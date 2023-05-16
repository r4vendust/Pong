#include "DisplayManager.h"

Logger& logger = Logger::getInstance();

int DisplayManager::width = 800;
int DisplayManager::height = 600;
const char* DisplayManager::gameTitle = "Pong";
bool DisplayManager::isInitialized = false;

DisplayManager::DisplayManager()
{
	if (!isInitialized)
	{
		SetConfigFlags(FLAG_WINDOW_RESIZABLE);
		SetConfigFlags(FLAG_VSYNC_HINT);
		InitWindow(width, height, gameTitle);
		isInitialized = true;
	}
	logger.Log("**********************************************************************");
	logger.Log("LOG: DISPLAY MANAGER HAS BEEN INITIALIZED!");
}

DisplayManager::~DisplayManager()
{

}

int DisplayManager::GetDisplayWidth()
{
	return width;
}

int DisplayManager::GetDisplayHeight()
{
	return height;
}