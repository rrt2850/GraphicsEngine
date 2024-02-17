#pragma once
#include "Platform/Windows32/IApplication.h"

class Application: public IApplication {
public:
	/* Application Constructor */
	Application();

	/* Application Destructor */
	~Application();

public:
	/* Setup the settings */
	VOID SetupPerGameSettings();

	/* Initialize Application */
	VOID Initialize();

	/* Game loop - Called repeatedly when application is running*/
	VOID Update();
};