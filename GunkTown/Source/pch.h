#pragma once

// pch means pre-compiled headers btw, it's just a pain to type


#include <Windows.h>

#include "../resource.h"
#include "GunkEngine.h"
#include "Common/Logger.h"

#define MAX_NAME_STRING 256					// Set the max length for a name string
#define hInstance() GetModuleHandle(NULL)	// Get an instance of the entire WinMain program

