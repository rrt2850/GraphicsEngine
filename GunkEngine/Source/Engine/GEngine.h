#pragma once

class GUNK_API GEngine;

namespace Engine {
	enum EngineMode: INT {
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	// extern means that the variable is defined externally in the GEngine.cpp file
	extern GEngine g_GunkEngine;

	VOID GUNK_API SetMode(EngineMode mode);
	EngineMode GUNK_API GetMode();
	std::wstring GUNK_API ModeToString();
}

using namespace Engine;
class GUNK_API GEngine {

public:
	GEngine();
	~GEngine();

private:
	EngineMode m_EngineMode;

public:
	EngineMode GetEngineMode();
	VOID SetEngineMode(EngineMode mode);
};