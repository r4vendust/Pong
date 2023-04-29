#pragma once

#include "raylib.h"
#include "Logger.h"

class DisplayManager : public Logger
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