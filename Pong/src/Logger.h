#pragma once

#include <iostream>

class Logger
{
public:
	Logger();
	~Logger();
	void Log(const char* message);
	void Warn(const char* message);
	void Error(const char* message);
};

