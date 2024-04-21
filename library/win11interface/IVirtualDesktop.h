#pragma once

#include "../base.h"
#include "IApplicationView.h"

namespace KappaBarVirtualDesktopWin11
{
	struct IVirtualDesktop : IUnknown
	{
		virtual bool IsViewVisible(IApplicationView *view) = 0;
		virtual _GUID *GetID() = 0;
		virtual void *unk5() = 0;
		// WinRT HSTRINGs:
		virtual void *GetName() = 0;
		virtual void *GetWallpaperPath() = 0;
	};
}