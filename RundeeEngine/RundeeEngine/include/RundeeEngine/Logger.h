//Project Name: RundeeEngine
//File Name: Logger.h
//Author: Haneul Lee (a.k.a Rundee)
//Date: 2025.05.17
//Description: Logger class header file

#pragma once
#include <string>

namespace RundeeEngine 
{
	enum class LogLevel 
	{
		Info = 0,
		Warning,
		Error,
		Count
	};

	class Logger 
	{
	public:
		static void Log(const std::string& message, LogLevel level = LogLevel::Info);
		static void Info(const std::string& message);
		static void Warning(const std::string& message);
		static void Error(const std::string& message);

	private:
		static void Print(const std::string& tag, const std::string& message);
	};
}