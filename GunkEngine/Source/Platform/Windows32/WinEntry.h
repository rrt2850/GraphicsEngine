#include "GunkEngine.h"
#include "IApplication.h"
#include "Common/CommandLineArgs.h"
#include "Engine/SplashScreen.h"

extern Win32::IApplication* EntryApplication();


/// <summary>
/// The main function for the window
/// </summary>
/// <param name="">An instance of the window</param>
/// <param name="">A past instance of the window? defunct?</param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
INT CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	auto EntryApp = EntryApplication();	// Entry point for the application to access GunkEngine

	
	PerGameSettings GameSettings;		// Initialize settings and create instance
	EntryApp->SetupPerGameSettings();	// Set up the settings

	CmdLineArgs::ReadArguments();		// Before we initialie the game, what arguments are we sending in?

	Logger logger;						// Initialize a logger for the application so we can communicate

	EntryApp->PreInitialize();

	Logger::PrintLog(L"Logger made, opening splashscreen\n");
	SplashScreen::Open();				// Open the splash screen while everything loads

	EntryApp->Initialize();				// Initialize the app
	
	MSG msg = { 0 };

	// While we don't receive a quit signal
	while (msg.message != WM_QUIT) {
		// If there are window messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// otherwise update the application using the specific application's update function
			EntryApp->Update();
		}
	}
	
	return 0;
}