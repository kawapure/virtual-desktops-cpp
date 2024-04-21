#include "VersionHelper.h"

// Private implementation

typedef void (WINAPI *RtlGetVersion_t)(OSVERSIONINFOEXW *);

const CVersionHelper::VersionStruct *CVersionHelper::GetVersionInfo()
{
	// Skip if cached.
	if (!s_versionStruct.isInitialized)
	{
		HMODULE hMod = LoadLibraryW(L"ntdll.dll");

		if (hMod)
		{
			RtlGetVersion_t func = (RtlGetVersion_t)GetProcAddress(hMod, "RtlGetVersion");

			if (!func)
			{
				FreeLibrary(hMod);

				// TODO: error handling.
				return &s_versionStruct;
			}

			OSVERSIONINFOEXW osVersionInfo = { 0 };
			osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);

			func(&osVersionInfo);

			s_versionStruct.dwBuildNumber = osVersionInfo.dwBuildNumber;
			s_versionStruct.dwMajorVersion = osVersionInfo.dwMajorVersion;
			s_versionStruct.dwMinorVersion = osVersionInfo.dwMinorVersion;
			s_versionStruct.dwPlatformId = osVersionInfo.dwPlatformId;

			s_versionStruct.isInitialized = true;

			FreeLibrary(hMod);
		}
	}

	return &s_versionStruct;
}

const bool CVersionHelper::IsCurrentWindowsBetaSeries()
{
	// Current beta series: Windows 11 2024 Update (25000+)
	return s_versionStruct.dwBuildNumber >= 25000;
}

const bool CVersionHelper::IsWindows10()
{
	return s_versionStruct.dwBuildNumber >= 10240 && s_versionStruct.dwBuildNumber < 21000;
}

const bool CVersionHelper::IsWindowsServer2022()
{
	// Windows Server 2022 is Iron 20348, but the interface works for all of the
	// builds in the range.
	return s_versionStruct.dwBuildNumber >= 20231 && s_versionStruct.dwBuildNumber < 21313;
}

const bool CVersionHelper::IsWindows11_22000()
{
	return s_versionStruct.dwBuildNumber >= 21000 && s_versionStruct.dwBuildNumber < 22600;
}

const bool CVersionHelper::IsWindows11_22621()
{
	return s_versionStruct.dwBuildNumber >= 22600 && s_versionStruct.dwBuildNumber < 22630;
}

const bool CVersionHelper::IsWindows11_22631()
{
	return s_versionStruct.dwBuildNumber >= 22630 && s_versionStruct.dwBuildNumber < 25000;
}