#pragma once
#include "Platform/Windows32/Window.h"

namespace SplashScreen {
	VOID GUNK_API Open();
	VOID GUNK_API Close();
	VOID GUNK_API AddMessage(CONST WCHAR* message);
}

class GUNK_API SplashWindow : public Win32::Window {
public:
	SplashWindow();
	~SplashWindow();

	virtual			LRESULT				MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};