#include "GunkEngine.h"

namespace Engine {
	GEngine g_GunkEngine;

	VOID SetMode(EngineMode mode) {
		g_GunkEngine.SetEngineMode(mode);
	}

	EngineMode GetMode() {
		return g_GunkEngine.GetEngineMode();
	}

	std::wstring GUNK_API ModeToString() {
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG: return L"Debug";
		case EngineMode::RELEASE: return L"Release";
		case EngineMode::SERVER: return L"Server";
		case EngineMode::EDITOR: return L"Editor";
		default: return L"None";
		}
	}
}

GEngine::GEngine()
{

#ifdef _DEBUG
	m_EngineMode = EngineMode::DEBUG;
#else
	m_EngineMode = EngineMode::RELEASE;
#endif

}

GEngine::~GEngine()
{
}

EngineMode GEngine::GetEngineMode() {
	return m_EngineMode;
}

VOID GEngine::SetEngineMode(EngineMode mode) {
	m_EngineMode = mode;
}