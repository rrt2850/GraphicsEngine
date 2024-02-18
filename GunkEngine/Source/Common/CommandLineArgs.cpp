#include "GunkEngine.h"
#include "CommandLineArgs.h"
#include <algorithm>

VOID CmdLineArgs::ReadArguments()
{
	int argc = 0; // The amount of arguments
	LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc); // Get the arguments and count

	for (int i = 1; i < argc; ++i) {
		std::wstring key = argv[i];
		if (key[0] == '-') {
			key.erase(0, 1);
			std::transform(key.begin(), key.end(), key.begin(), ::tolower); // Convert the string to lowercase
			ReadArgument(key.c_str());

		}
	}
}

VOID CmdLineArgs::ReadArgument(const WCHAR* argument)
{
	if (wcscmp(argument, L"mtail") == 0) {
		Logger::StartMTail();
	}
	if (wcscmp(argument, L"debug") == 0) {
		Engine::SetMode(Engine::EngineMode::DEBUG);
	}
	if (wcscmp(argument, L"editor") == 0) {
		Engine::SetMode(Engine::EngineMode::EDITOR);
	}
	if (wcscmp(argument, L"server") == 0) {
		Engine::SetMode(Engine::EngineMode::SERVER);
	}
}
