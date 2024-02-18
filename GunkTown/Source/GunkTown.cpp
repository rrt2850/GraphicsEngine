#include "GunkTown.h"
#include "Engine/Simulation.h"
#include "Platform/Windows32/WinEntry.h"

// GunkTown is the implementation to send to GunkEngine
class GunkTown : public GunkEngine::Simulation {
public:
	GunkTown() {};
	~GunkTown() {};

public:
	/* Setup the settings */
	VOID SetupPerGameSettings();

	/* Initialize GunkTown */
	VOID Initialize() {};

	/* Game loop - Called repeatedly when GunkTown is running*/
	VOID Update() {};
};



// Feed this GunkTown into the engine so that it becomes the entry point
ENTRYAPP(GunkTown)

VOID GunkTown::SetupPerGameSettings()
{
	/* Set the Per Game Settings, getting them from the GunkTown, not the engine */
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashPath(IDS_SPLASHPATH);
}
