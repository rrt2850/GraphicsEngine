#include "GunkEngine.h"

PerGameSettings* PerGameSettings::inst;

PerGameSettings::PerGameSettings()
{
	inst = this;

	// Set the default per-game settings before the application overrides them
	wcscpy_s(inst->m_GameName, L"undefined");
	wcscpy_s(inst->m_ShortName, L"undefined");
	wcscpy_s(inst->m_BootTime, Time::GetDateTimeString(TRUE).c_str());
	wcscpy_s(inst->m_SplashPath, L"..\\GunkEngine\\Assets\\Images\\SplashScreen.bmp");
}

PerGameSettings::~PerGameSettings()
{
}
