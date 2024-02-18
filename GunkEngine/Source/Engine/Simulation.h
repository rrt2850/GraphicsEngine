#pragma once

#include "Platform/Windows32/IApplication.h"

namespace GunkEngine {
	// This class is a windows 32 application that inherits functionalities from somewhere else
	class GUNK_API Simulation: public Win32::IApplication{

	public:
		Simulation();
		~Simulation();

		virtual VOID PreInitialize() override;
	};
}