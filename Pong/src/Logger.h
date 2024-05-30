#pragma once

#include <iostream>
#include <fstream>

class Logger
{
public:
	static Logger& getInstance();
	Logger(Logger const&) = delete;
	void operator=(Logger const&) = delete;

	void Log(const std::string& message);
	void Log(const char* message);
	void saveToFile(const std::string& fileName);
private:
	Logger();
	~Logger();
	std::ofstream outputFile;
};