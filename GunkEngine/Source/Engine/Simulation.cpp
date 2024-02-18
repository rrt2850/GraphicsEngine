#include "GunkEngine.h"
#include "Simulation.h"
#include "Engine/SplashScreen.h"

GunkEngine::Simulation::Simulation()
{
}

GunkEngine::Simulation::~Simulation()
{
}

VOID GunkEngine::Simulation::PreInitialize()
{
	Logger::PrintDebugSeparator();
	Logger::PrintLog(L"Application starting...\n");
	Logger::PrintLog(L"Game Name: %s\n", PerGameSettings::GameName());
	Logger::PrintLog(L"Boot Time: %s\n", Time::GetDateTimeString().c_str());
	Logger::PrintLog(L"Engine Mode: %s\n", Engine::ModeToString().c_str());
	Logger::PrintDebugSeparator();

	Logger::PrintLog(L"bruhhh %s", L"Yo mama\n");

    SplashScreen::Open();
}
