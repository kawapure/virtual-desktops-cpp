#pragma once

#include "../base.h"
#include "IVirtualDesktop.h"
#include "IApplicationView.h"
#include <ObjectArray.h>

namespace KappaBarVirtualDesktopWin11
{
	struct IVirtualDesktopNotification : IUnknown
	{
		virtual void VirtualDesktopCreated(IObjectArray *pArr, IVirtualDesktop *pDesktop) = 0;
		virtual void VirtualDesktopDestroyBegin(IObjectArray *pArr, IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) = 0;
		virtual void VirtualDesktopDestroyFailed(IObjectArray *pArr, IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) = 0;
		virtual void VirtualDesktopDestroyed(IObjectArray *pArr, IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) = 0;
		virtual void unk7(int a1) = 0;
		virtual void VirtualDesktopMoved(IObjectArray *pArr, IVirtualDesktop *pDesktop, int nIndexFrom, int nIndexTo) = 0;
		// chName in these contexts are WinRT HSTRING types. Since we don't have WinRT, we ignore them.
		virtual void VirtualDesktopRenamed(IVirtualDesktop *pDesktop, void *chName) = 0;
		virtual void ViewVirtualDesktopChanged(IApplicationView *pView) = 0;
		virtual void CurrentVirtualDesktopChanged(IObjectArray *pArr, IVirtualDesktop *pDesktopOld, IVirtualDesktop *pDesktopNew) = 0;
		virtual void VirtualDesktopWallpaperChanged(IVirtualDesktop *pDesktop, void *chPath) = 0;
	};
}