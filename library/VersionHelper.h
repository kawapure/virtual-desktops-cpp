#pragma once

#include "base.h"

class CVersionHelper
{
public:
	// Data structure returned by GetVersionInfo().
	struct VersionStruct
	{
		bool isInitialized = false;
		DWORD dwMajorVersion = 0;
		DWORD dwMinorVersion = 0;
		DWORD dwBuildNumber = 0;
		DWORD dwPlatformId = 0;
	};

	// Gets the precise OS version.
	static const VersionStruct *GetVersionInfo();

	// Specific version helpers.
	static const bool IsCurrentWindowsBetaSeries();
	static const bool IsWindows10();
	static const bool IsWindowsServer2022();
	static const bool IsWindows11_22000();
	static const bool IsWindows11_22621();
	static const bool IsWindows11_22631();

private:
	// Caches the version information so we don't have to load the library every
	// time we need to access it.
	static VersionStruct s_versionStruct;
};