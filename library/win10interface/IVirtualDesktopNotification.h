#pragma once

#include "../base.h"
#include "IVirtualDesktop.h"
#include "IApplicationView.h"

namespace Kawapure
{
namespace VirtualDesktops
{
namespace Interfaces10240
{
	struct IVirtualDesktopNotification : IUnknown
	{
		virtual void VirtualDesktopCreated(IVirtualDesktop *pDesktop) = 0;
		virtual void VirtualDesktopDestroyBegin(IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) = 0;
		virtual void VirtualDesktopDestroyFailed(IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) = 0;
		virtual void VirtualDesktopDestroyed(IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) = 0;
		virtual void ViewVirtualDesktopChanged(IApplicationView *pView) = 0;
		virtual void CurrentVirtualDesktopChanged(IVirtualDesktop *pDesktopOld, IVirtualDesktop *pDesktopNew) = 0;
	};
} // namespace Interfaces10240
} // namespace VirtualDesktops
} // namespace Kawapure