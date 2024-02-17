#include "GunkEngine.h"
#include <ctime>
#include <sstream>
#include <iomanip>

/// <summary>
/// Gets time in the format '00:00:00'
/// stripped = 000000
/// </summary>
/// <param name="stripped">Should we remove formatting?</param>
/// <returns>A string representing the time</returns>
std::wstring GUNK_API Time::GetTime(BOOL stripped)
{
	time_t now = time(0);
	tm localTime;
	localtime_s(&localTime, &now);
	std::wstringstream wss;
	wss << std::put_time(&localTime, L"%T");

	std::wstring timeString = wss.str();

	if (stripped) {
		std::wstring chars = L":";	// the characters to remove

		// For each character we want to remove, go through the time string and remove it
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}

/// <summary>
/// Gets the date in format '00/00/00'
/// </summary>
/// <param name="stripped">Should we remove the formatting?</param>
/// <returns>A string representing the date</returns>
std::wstring GUNK_API Time::GetDate(BOOL stripped)
{
	time_t now = time(0);
	tm localTime;
	localtime_s(&localTime, &now);
	std::wstringstream wss;
	wss << std::put_time(&localTime, L"%d/%m/%y");

	std::wstring timeString = wss.str();

	if (stripped) {
		std::wstring chars = L"/";	// the characters to remove

		// For each character we want to remove, go through the string and remove it
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}

std::wstring GUNK_API Time::GetDateTimeString(BOOL stripped)
{
	std::wstring timeString = GetDate(stripped) + L" " + GetTime(stripped);

	if (stripped) {
		std::wstring chars = L" ";	// the characters to remove

		// For each character we want to remove, go through the string and remove it
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}
