#include "../base.h"

namespace Kawapure
{
namespace VirtualDesktops
{
	// Pure interface
	class IProxyVirtualDesktopNotificationService
	{
		virtual HRESULT Register(void *pNotification) = 0;
		virtual void Unregister(DWORD dwCookie) = 0;
	};
} // namespace VirtualDesktops
} // namespace Kawapure