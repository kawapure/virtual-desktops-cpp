#pragma once

#include "../base.h"
#include "IVirtualDesktopNotification.h"

namespace Kawapure
{
namespace VirtualDesktops
{
namespace Interfaces10240
{
	struct IVirtualDesktopNotificationService : IUnknown
	{
		virtual HRESULT Register(IVirtualDesktopNotification *pNotification) = 0;
		virtual void Unregister(DWORD dwCookie) = 0;
	};
} // namespace Interfaces10240
} // namespace VirtualDesktops
} // namespace Kawapure