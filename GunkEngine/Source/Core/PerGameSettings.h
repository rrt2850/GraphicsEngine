class GUNK_API PerGameSettings {
private:
	// Singleton reference to static class

	static PerGameSettings* inst;

	static PerGameSettings* Instance() { return inst; }

public:
	// Constructor with static assignment and predefined variables
	PerGameSettings();
	~PerGameSettings();

private:
	// Holders for the variables
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];
	WCHAR m_SplashPath[MAX_NAME_STRING];

public:
	// Getters and setters

	// GameName
	static WCHAR* GameName() { return inst->m_GameName; }
	static VOID SetGameName(UINT id) { LoadString(hInstance(), id, inst->m_GameName, MAX_NAME_STRING); }

	// ShortName
	static WCHAR* ShortName() { return inst->m_ShortName; }
	static VOID SetShortName(UINT id) { LoadString(hInstance(), id, inst->m_ShortName, MAX_NAME_STRING); }

	// SplashPath
	static WCHAR* SplashPath() { return inst->m_SplashPath; }
	static VOID SetSplashPath(UINT id) { LoadString(hInstance(), id, inst->m_SplashPath, MAX_NAME_STRING); }

	// MainIcon
	static HICON MainIcon() { return inst->m_MainIcon; }
	static VOID SetMainIcon(UINT id) { LoadIcon(hInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return inst->m_BootTime;  }
};