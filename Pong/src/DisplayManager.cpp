#include "DisplayManager.h"
#include <iostream>

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
	std::cout << "**********************************************************************\n";
	std::cout << "LOG: DISPLAY MANAGER HAS BEEN INITIALIZED!" << std::endl;
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

void Resize()
{

}