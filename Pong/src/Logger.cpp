#include "Logger.h"

Logger::Logger()
{
	outputFile.open("log.txt", std::ios_base::app);
}

Logger::~Logger()
{
	outputFile.close();
}

Logger& Logger::getInstance()
{
	static Logger instance;
	return instance;
}

void Logger::Log(const std::string& message)
{
	std::cout << message << std::endl;
	outputFile << message << std::endl;
}

void Logger::Log(const char* message)
{
	Log(std::string(message));
}

void Logger::saveToFile(const std::string& fileName)
{
	std::ifstream inputFile("log.txt");
	std::ofstream outputFile(fileName);
	outputFile << inputFile.rdbuf();
	inputFile.close();
	outputFile.close();
}