#include "pch.h"
#include "Application.h"
#include "Platform/Windows32/WinEntry.h"

// Feed this application into the engine so that it becomes the entry point
ENTRYAPP(Application)

/// <summary>
/// 
/// </summary>
Application::Application()
{

}
/// <summary>
/// 
/// </summary>
Application::~Application()
{
}
VOID Application::SetupPerGameSettings()
{
	/* Set the Per Game Settings, getting them from the application, not the engine */
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
VOID Application::Initialize()
{
	Logger::StartMTail();
	Logger::PrintLog(L"Application starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintDebugSeparator();

	Logger::PrintLog(L"bruhhh %s", L"Yo mama");
	return;
}
/// <summary>
/// 
/// </summary>
/// <returns></returns>
VOID Application::Update()
{
}
