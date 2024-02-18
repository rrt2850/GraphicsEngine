#pragma once

// If we declare this function in our application with a class it'll translate into our entry point
// This means it can be run from other places?
#define ENTRYAPP(x) Win32::IApplication* EntryApplication() {return new x;}

namespace Win32 {
	// declspec(dllexport) expands the scope so other projects can use the linker to include this.
	class GUNK_API IApplication {
	public:
		/* Application Constructor */
		IApplication();

		/* Application Destructor */
		virtual ~IApplication() {};

	public:
		/* Setup settings for the game */
		virtual VOID SetupPerGameSettings() = 0;

		/* Initialize Application */
		virtual VOID PreInitialize() = 0;

		/* Initialize Application */
		virtual VOID Initialize() = 0;

		/* Game loop - Called repeatedly when application is running*/
		virtual VOID Update() = 0;
	};


	IApplication* EntryApplication();
}

