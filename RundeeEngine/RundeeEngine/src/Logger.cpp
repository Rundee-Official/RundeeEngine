//Project Name: RundeeEngine
//File Name: Logger.cpp
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Logger class implementation file

#include "../include/RundeeEngine/Logger.h"
#include <iostream>
#include <mutex>
#include <chrono>
#include <ctime>
#include <iomanip>

#ifdef _WIN32
#include <Windows.h>
#endif

namespace RundeeEngine 
{
	static std::mutex logMutex;

	void Logger::Log(const std::string& message, LogLevel level) {
		switch (level)
		{
		case LogLevel::Info: Info(message); 
			break;
		case LogLevel::Warning: Warning(message);
			break;
		case LogLevel::Error: Error(message);
			break;
		default:
			break;
		}
	}

	void Logger::Info(const std::string& message) 
	{
		Print("INFO", message);
	}

	void Logger::Warning(const std::string& message)
	{
		Print("WARNING", message);
	}

	void Logger::Error(const std::string& message)
	{
		Print("ERROR", message);
	}

	void Logger::Print(const std::string& tag, const std::string& message) 
	{
		#ifdef _WIN32
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // Default: White

		if (tag == "INFO") 
		{
			color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
		}
		else if (tag == "WARNING")
		{
			color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
		}
		else if (tag == "ERROR")
		{
			color = FOREGROUND_RED | FOREGROUND_INTENSITY;
		}

		SetConsoleTextAttribute(hConsole, color);
		#endif

		std::lock_guard<std::mutex> lock(logMutex);

		auto now = std::chrono::system_clock::now();
		std::time_t t = std::chrono::system_clock::to_time_t(now);
		std::tm tm;
		localtime_s(&tm, &t);

		std::cout << "[" << std::put_time(&tm, "%H:%M:%S") << "] "
			<< "[" << tag << "] " << message << std::endl;
		
		#ifdef _WIN32
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		#endif
	}
}