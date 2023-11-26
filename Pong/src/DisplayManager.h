#pragma once

#include <iostream>
#include "raylib.h"

class DisplayManager
{
public:
	static DisplayManager& getInstance();
	DisplayManager(const DisplayManager&) = delete;
	void operator=(DisplayManager const&) = delete;
	static int GetDisplayWidth();
	static int GetDisplayHeight();

private:
	DisplayManager();
	~DisplayManager();
	static int width, height;
	static const char* gameTitle;
	static bool isInitialized;
};