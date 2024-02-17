#include "GunkEngine.h"
#include <fstream>
#include <ShlObj.h>
#include <cstdio>
#include <tlhelp32.h>

// Declare instance and connect it to the class
Logger* Logger::inst;

Logger::Logger()
{
	// Initialize a static instance of this class for other programs to reference.
	inst = this;
}

Logger::~Logger()
{
}

VOID Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buffer[4096];	// Setup buffer for the string to use
	va_list args;		// A list of arguments to pass into the buffer

	// Take all the arguments and put them in the buffer
	va_start(args, fmt);
	vswprintf_s(buffer, fmt, args);
	va_end(args);

	OutputDebugString(buffer);

	std::wfstream outfile;

	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		std::wstring s = buffer;
		outfile << L"[" << Time::GetDateTimeString() << L"]" << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
}

/// <summary>
/// Get and Create Log Directory in %AppData%/$ProjectName/Log
/// </summary>
/// <returns>The path of the log directory</returns>
std::wstring Logger::LogDirectory() {
	WCHAR Path[1024];
	WCHAR* AppDataLocal;
	SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
	wcscpy_s(Path, AppDataLocal);
	wcscat_s(Path, L"\\");
	wcscat_s(Path, PerGameSettings::GameName());
	CreateDirectory(Path,NULL);
	wcscat_s(Path, L"\\Log");
	CreateDirectory(Path, NULL);
	return Path;
}


std::wstring Logger::LogFile()
{
	WCHAR file[1024];
	wcscpy_s(file, PerGameSettings::GameName());	// Copy the name into the file buffer
	wcscat_s(file, PerGameSettings::BootTime());	// Add the boot time to the end of the buffer
	wcscat_s(file, L".log");						// Add .log to the end
	return file;
}

/* Print a seperator line without time stamp */
VOID Logger::PrintDebugSeparator()
{
	std::wstring s = L"\n------------------------------------------------------------------------------------\n\n";

#ifdef _DEBUG
	std::wfstream outfile;
	outfile.open(std::wstring(LogDirectory() + L"/" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		outfile << s;
		outfile.close();
	}
	else {
		MessageBox(NULL, L"Unable to open log file...", L"Log Error", MB_OK);
	}
#endif
}

/* Private class to check to see if MTail is already running - So we don't open multiple copies during debug */
BOOL Logger::MTailRunning()
{
	bool exists = false;
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshot, &entry))
		while (Process32Next(snapshot, &entry))
			if (!_wcsicmp(entry.szExeFile, L"mTAIL.exe"))
				exists = true;

	CloseHandle(snapshot);
	return exists;
}

/* Start MTail from Project or Build Directory - Depends on where ran from */
VOID Logger::StartMTail()
{
	if (MTailRunning()) {
		Logger::PrintLog(L"--MTail failed to start - Already Running\n");
		return;
	}

	Logger::PrintLog(L"--Starting MTail\n");
	WCHAR path[MAX_PATH] = { 0 };
	GetCurrentDirectoryW(MAX_PATH, path);
	std::wstring url = path + std::wstring(L"/mTAIL.exe");
	std::wstring params = L" \"" + LogDirectory() + L"/" + LogFile() + L"\" /start";
	ShellExecute(0, NULL, url.c_str(), params.c_str(), NULL, SW_SHOWDEFAULT);
}