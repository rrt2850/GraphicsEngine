#include "GunkEngine.h"
#include "SplashScreen.h"

#include "Platform/Windows32/Win32Utils.h"

namespace SplashScreen {
#define WM_OUTPUTMESSAGE (WM_USER + 0x0001) // Set the user to user + 1 to avoid conflicts

	SplashWindow* m_SplashWindow;	// Declare pointer to hold the SplashWindow

	VOID Open()
	{
		// Check if the window exists, if it does, just leave.
		if (m_SplashWindow != nullptr) return;
		m_SplashWindow = new SplashWindow();
	}

	VOID Close()
	{
		return VOID GUNK_API();
	}

	VOID AddMessage(const WCHAR* message)
	{
		// Send a message with id WM_OUTPUTMESSAGE to the splash window with message as it's contents
		PostMessage(m_SplashWindow->GetHandle(), WM_OUTPUTMESSAGE, (WPARAM)message, 0);
	}

}

// SplashWindow Constructor
SplashWindow::SplashWindow()
	: Win32::Window(L"SplashScreen", L"SplashScreen", NULL, 500, 600)
{
	wcscpy_s(m_outputMessage, L"SplashScreen Created...");
	Win32::Window::RegisterNewClass();	// Create a window class to hold the splashscreen
	Win32::Window::Initialize();		// Initialize the window
}

SplashWindow::~SplashWindow()
{
}

LRESULT SplashWindow::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
		case WM_PAINT:{
			HBITMAP hbitmap;
			HDC hdc, hmemdc;
			PAINTSTRUCT ps;

			hdc = BeginPaint(hwnd, &ps); // Start painting

			Win32::Utils::AddBitmap(PerGameSettings::SplashPath(), hdc);

			SetBkMode(hdc, TRANSPARENT);				// Set background to transparent
			SetTextColor(hdc, RGB(255, 255, 255));		// Set the text color to white

			// If our engine mode isn't in release mode, display the mode
			if (Engine::GetMode() != Engine::EngineMode::RELEASE) {

				std::wstring engineModeText = Engine::ModeToString() + L" Mode"; // Create the string holding the mode
				SetTextAlign(hdc, TA_RIGHT);	// Align the text to the right
				TextOut(hdc, m_Width - 15, 15, engineModeText.c_str(), wcslen(engineModeText.c_str())); // Put the text on the window 15 pixels from its edge
			}

			SetTextAlign(hdc, TA_CENTER); // Align the remaining text to the center

			TextOut(hdc, m_Width / 2, m_Height - 30, m_outputMessage, wcslen(m_outputMessage)); // display m_outputMessage in the center, 30 pixels above the bottom
			EndPaint(hwnd, &ps); // Stop painting
		}
		break;
		case WM_OUTPUTMESSAGE:{
			// if there is an output message take whatever is in wParam and convert it to our outputMessage
			WCHAR* msg = (WCHAR*)wParam;
			wcscpy_s(m_outputMessage, msg);
			RedrawWindow(GetHandle(), NULL, NULL, RDW_INVALIDATE);
			return 0;
		}
	}

	return CommonMessageHandler(hwnd, message, wParam, lParam);
}
