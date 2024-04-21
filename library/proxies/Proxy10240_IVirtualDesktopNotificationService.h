/*
 * IVirtualDesktopNotificationService interface proxy implementation.
 *
 * This implementation uses a top-down proxy model, so this class which implements the
 * proxy forwards its calls to the child.
 * 
 * Target OS build: 10240 (Windows 10)
 */

#include "../base.h"
#include "../clsids.h"
#include "../ComProxyBase.h"

#include "ProxyVirtualDesktopNotificationService.h"

// Proxied interface:
#include "../win10interface/IVirtualDesktopNotificationService.h"
using namespace Kawapure::VirtualDesktops::Interfaces10240;

namespace Kawapure
{
namespace VirtualDesktops
{
	struct CProxy10240_IVirtualDesktopNotificationService
		: public IProxyVirtualDesktopNotificationService
		, protected CComProxyBase<
			&IID_IVirtualDesktopNotificationService,
			IVirtualDesktopNotificationService
		  >
	{
		HRESULT Register(void *pNotification) override
		{
			return m_pProxiedInterface->Register(pNotification);
		}

		void Unregister(DWORD dwCookie) override
		{
			return m_pProxiedInterface->Unregister(dwCookie);
		}
	};
} // namespace VirtualDesktops
} // namespace Kawapure