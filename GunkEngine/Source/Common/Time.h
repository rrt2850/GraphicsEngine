#pragma once
#include <string>

namespace Time {
	// Get current time in string format
	std::wstring GUNK_API GetTime(BOOL stripped = FALSE);

	// Get current date in string format
	std::wstring GUNK_API GetDate(BOOL stripped = FALSE);

	// Get current date and time in string format
	std::wstring GUNK_API GetDateTimeString(BOOL stripped = FALSE);
}