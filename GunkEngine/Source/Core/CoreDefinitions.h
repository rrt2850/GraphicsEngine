#pragma once


// If the build dll definition isn't detected we must be importing an
// application instead of exporting
#ifdef BUILD_DLL
	#define GUNK_API __declspec(dllexport)
#else
	#define GUNK_API __declspec(dllimport)
#endif

#define MAX_NAME_STRING 256
#define hInstance() GetModuleHandle(NULL)	// Get an instance of the entire WinMain program