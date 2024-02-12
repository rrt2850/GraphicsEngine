#pragma once

#include <windows.h>

#include "../resource.h"

#define MAX_NAME_STRING 256					// Set the max length for a name string
#define hInstance() GetModuleHandle(NULL)	// Get an instance of the entire WinMain program