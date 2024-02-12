#include "pch.h"

/* --------------------------------------------------------------------------- */
/*	Filename: WinMain.cpp													   */
/*  Author: Robert Tetreault (guided by OlympusMonsTutorials for this part)    */
/* --------------------------------------------------------------------------- */


/* --------------------------------------------------------------------------- */
/*	Global Variables                                                           */
/* --------------------------------------------------------------------------- */
#pragma region GlobalVariables

WCHAR	WindowClass[MAX_NAME_STRING]; // Make an array of 256 wide characters to hold the class name
WCHAR	WindowTitle[MAX_NAME_STRING]; // Window title array

int		WindowWidth;
int		WindowHeight;

HICON	hIcon;

#pragma endregion
/* --------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------- */
/*	Pre-Declarations                                                           */
/* --------------------------------------------------------------------------- */
#pragma region Pre-Declarations

VOID InitializeVariables();
VOID CreateWindowClass();
VOID InitializeWindow();
VOID MessageLoop();

#pragma endregion
/* --------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------- */
/*	Operations															       */
/* --------------------------------------------------------------------------- */
#pragma region Operations

/// <summary>
/// A function to handle window processes
/// </summary>
/// <param name="hwnd">An instance of the window that's running</param>
/// <param name="message">The message type parameter (windows close or windows resize) rn</param>
/// <param name="wparam">An argument for the message parameter</param>
/// <param name="lparam">An argument for the message parameter</param>
/// <returns>A modified default window process with the new message and parameters</returns>
LRESULT CALLBACK WindowProcess(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
	switch (message) {
	case WM_DESTROY:
		// If the window gets a message to destroy itself, quit.
		PostQuitMessage(0);
		break;
	}

	return DefWindowProc(hwnd, message, wparam, lparam);
}


/// <summary>
/// The main function for the window
/// </summary>
/// <param name="">An instance of the window</param>
/// <param name="">A past instance of the window? defunct?</param>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	InitializeVariables();
	CreateWindowClass();
	InitializeWindow();
	MessageLoop();

	return 0;
}

#pragma endregion
/* --------------------------------------------------------------------------- */


/* --------------------------------------------------------------------------- */
/*	Functions		                                                           */
/* --------------------------------------------------------------------------- */
#pragma region Functions

/// <summary>
/// Initializes all the global variables
/// </summary>
VOID InitializeVariables() {
	/* Initialize Global Variables */
	LoadString(hInstance(), IDS_PERGAMENAME, WindowTitle, MAX_NAME_STRING);	// Get the title from the lookup table
	LoadString(hInstance(), IDS_WINDOWCLASS, WindowClass, MAX_NAME_STRING);	// Get the class from the lookup table
	WindowWidth = 500;
	WindowHeight = 500;
	hIcon = LoadIcon(hInstance(), MAKEINTRESOURCE(IDI_MAINICON));
}

/// <summary>
/// Creates and Displays the window
/// </summary>
/// <returns></returns>
VOID InitializeWindow() {
	// Get a representation of the entire window (var 3 is window style, look into this later)
	HWND hwnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
		WindowWidth, WindowHeight, nullptr, nullptr, hInstance(), nullptr);
	// Last variable is uber important. it's for giving the window instructions during runtime ig.

	if (!hwnd) {
		MessageBox(0, L"Failed to create window. Good luck dude", 0, 0);
		PostQuitMessage(0);
	}

	if (hwnd != 0) ShowWindow(hwnd, SW_SHOW);
}

/// <summary>
/// Creates the window class for us to use
/// </summary>
/// <returns></returns>
VOID CreateWindowClass() {
	WNDCLASSEX wcex;

	// Will probably never change
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance();		// Pass the window class an instance of WinMain as a whole

	// Could change later
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);				// Cursor = basic default cursor
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);	// Background = null = white (overridden by directx)

	// Will change later
	wcex.hIcon = hIcon;									// top left of window icon
	wcex.hIconSm = hIcon;								// task bar icon
	wcex.lpszClassName = WindowClass;			 		// Class name
	wcex.lpszMenuName = nullptr;						// Change when we have a use for menus
	wcex.lpfnWndProc = WindowProcess;					// Function for processing the window


	// Register the class after setting all the variables
	RegisterClassEx(&wcex);
}

/// <summary>
/// Loops until it recieves exit message so the page doesn't immediately quit
/// </summary>
/// <returns></returns>
VOID MessageLoop() {
	MSG msg = { 0 };

	// While we don't receive a quit signal
	while (msg.message != WM_QUIT) {
		// If there are window messages, process them
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}

#pragma endregion
/* --------------------------------------------------------------------------- */