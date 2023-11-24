#pragma once

#include <iostream>
#include "raylib.h"

class DisplayManager
{
public:
	DisplayManager();
	static int GetDisplayWidth();
	static int GetDisplayHeight();
	virtual ~DisplayManager();

private:
	static int width, height;
	static const char* gameTitle;
	static bool isInitialized;
};