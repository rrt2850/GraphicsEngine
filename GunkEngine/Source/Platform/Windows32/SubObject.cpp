#include "GunkEngine.h"
#include "SubObject.h"

namespace Win32 {

	// run constructor and initialize class member variables
	SubObject::SubObject(std::wstring className, std::wstring classTitle, HICON icon)
		: m_Class(className), m_Title(classTitle), m_hIcon(icon)
	{
	}

	SubObject::~SubObject(){
	}

	
	VOID SubObject::Initialize()
	{
		return VOID();
	}


	/// <summary>
	/// Creates the window class for us to use
	/// </summary>
	/// <returns></returns>
	VOID SubObject::RegisterNewClass() {
		WNDCLASSEX wcex;

		// Will probably never change
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = hInstance();		// Pass the window class an instance of WinMain as a whole

		// Could change later
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);				// Cursor = basic default cursor
		wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(46, 46, 46)));

		// Will change later
		wcex.hIcon = m_hIcon;									// top left of window icon
		wcex.hIconSm = m_hIcon;									// task bar icon
		wcex.lpszClassName = m_Class.c_str();			 		// Class name
		wcex.lpszMenuName = nullptr;							// Change when we have a use for menus
		wcex.lpfnWndProc = SetupMessageHandler;					// Function for processing the window


		// Register the class after setting all the variables
		RegisterClassEx(&wcex);
	}

	LRESULT SubObject::SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Win32::SubObject* const pWnd = static_cast<Win32::SubObject*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32::SubObject::AssignMessageHandler));
			return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	LRESULT SubObject::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32::SubObject* const pWnd = reinterpret_cast<Win32::SubObject*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
	}

	LRESULT SubObject::CommonMessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
}

