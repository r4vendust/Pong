#include "Logger.h"

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::Log(const char* message)
{
	std::cout << "[LOG]: " << message << std::endl;
}

void Warn(const char* message)
{
	std::cout << "[WARNING]: " << message << std::endl;
}

void Error(const char* message)
{
	std::cerr << "[ERROR]: " << message << std::endl;
}