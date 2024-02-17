#pragma once

#include <string>

class GUNK_API Logger {
private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }

public:
	// Constructors
	Logger();
	~Logger();

	// ... means PrintLog can take in as many WCHAR pointers as we send it.
	static VOID PrintLog(const WCHAR* fmt, ...);
	static std::wstring LogDirectory();
	static std::wstring LogFile();

	/* prints a line of characters to separate debug files */
	static VOID PrintDebugSeparator();
	

	/* Check to see if MTail is already Running */
	static BOOL MTailRunning();

	/* Start MTail Application */
	static VOID StartMTail();
};