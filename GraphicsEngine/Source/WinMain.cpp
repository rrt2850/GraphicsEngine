#include "pch.h"

WCHAR WindowClass[MAX_NAME_STRING]; // Make an array of 256 wide characters to hold the class name
WCHAR WindowTitle[MAX_NAME_STRING]; // Window title array
int WindowWidth;
int WindowHeight;

HICON hIcon;

/**
 * WindowProcess: A function to handle window processes
 * 
 * @param hwnd: An instance of the window that's running
 * @param message: The message type parameter (windows close or windows resize) rn
 * @param wparam: An argument for the message parameter
 * @param lparam: An argument for the message parameter
 */
LRESULT CALLBACK WindowProcess(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {
	switch (message) {
		case WM_DESTROY:
			// If the window gets a message to destroy itself, quit.
			PostQuitMessage(0);
			break;
	}

	return DefWindowProc(hwnd, message, wparam, lparam);
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	/* Initialize Global Variables */
	
	wcscpy_s(WindowClass, TEXT("bruh")); // Copy the text into WindowClass as wide characters
	wcscpy_s(WindowTitle, TEXT("Super Dope Window. Property of Robert"));
	WindowWidth = 500;
	WindowHeight = 500;
	hIcon = LoadIcon(hInstance(), MAKEINTRESOURCE(IDI_MAINICON));

	/* Create Window Class */
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


	/* Create and Display the Window */
		// Get a representation of the entire window (var 3 is window style, look into this later)
		HWND hwnd = CreateWindow(WindowClass, WindowTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0,
			WindowWidth, WindowHeight, nullptr, nullptr, hInstance(), nullptr);
		// Last variable is uber important. it's for giving the window instructions during runtime ig.

		if (!hwnd) {
			MessageBox(0, L"Failed to create window. Good luck dude", 0, 0);
			return 0;
		}
		ShowWindow(hwnd, SW_SHOW);


	/* Listen for Message events */
		// Loop here so the page doesn't immediately quit

		MSG msg = { 0 };

		// While we don't receive a quit signal
		while (msg.message != WM_QUIT) {
			// If there are window messages, process them
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		
	return 0;
}