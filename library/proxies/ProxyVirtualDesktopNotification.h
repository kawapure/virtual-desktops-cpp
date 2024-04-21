#include "../base.h"
#include <ObjectArray.h>

typedef void IVirtualDesktopPlaceholder;
typedef void IApplicationViewPlaceholder;
typedef void * HSTRINGPLACEHOLDER;

namespace Kawapure
{
namespace VirtualDesktops
{
	// Pure interface
	struct IProxyVirtualDesktopNotification
	{
		virtual void VirtualDesktopCreated(IObjectArray *pArr, IVirtualDesktopPlaceholder *pDesktop) = 0;
		virtual void VirtualDesktopDestroyBegin(IObjectArray *pArr, IVirtualDesktopPlaceholder *pDesktopDestroyed, IVirtualDesktopPlaceholder *pDesktopFallback) = 0;
		virtual void VirtualDesktopDestroyFailed(IObjectArray *pArr, IVirtualDesktopPlaceholder *pDesktopDestroyed, IVirtualDesktopPlaceholder *pDesktopFallback) = 0;
		virtual void VirtualDesktopDestroyed(IObjectArray *pArr, IVirtualDesktopPlaceholder *pDesktopDestroyed, IVirtualDesktopPlaceholder *pDesktopFallback) = 0;
		virtual void ViewVirtualDesktopChanged(IObjectArray *pArr, IApplicationViewPlaceholder *pView) = 0;
		virtual void CurrentVirtualDesktopChanged(IObjectArray *pArr, IVirtualDesktopPlaceholder *pDesktopOld, IVirtualDesktopPlaceholder *pDesktopNew) = 0;
		virtual void VirtualDesktopMoved(IObjectArray *pArr, IVirtualDesktopPlaceholder *pDesktop, int nIndexFrom, int nIndexTo) = 0;
		virtual void VirtualDesktopRenamed(IVirtualDesktopPlaceholder *pDesktop, HSTRINGPLACEHOLDER chName) = 0;
		virtual void VirtualDesktopWallpaperChanged(IVirtualDesktopPlaceholder *pDesktop, HSTRINGPLACEHOLDER chName) = 0;
	};
} // namespace VirtualDesktops
} // namespace Kawapure