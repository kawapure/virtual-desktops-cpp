/*
 * IVirtualDesktopNotification interface proxy implementation.
 * 
 * This implementation uses a bottom-up proxy model, so this class which implements the strict
 * child ABI forwards its calls to the parent proxy class.
 * 
 * Note: Windows 11 expands the method definitions, and that's what the parent class implements.
 *       Windows 10 just passes nullptr for these because no such argument exists here.
 *
 * Target OS build: 10240 (Windows 10)
 */

#include "../base.h"
#include "../clsids.h"
#include "../InterfaceProxyBase.h"

#include "ProxyVirtualDesktopNotification.h"

// Proxied interface:
#include "../win10interface/IVirtualDesktopNotification.h"
using namespace Kawapure::VirtualDesktops::Interfaces10240;

namespace Kawapure
{
namespace VirtualDesktops
{
	struct CProxy10240_IVirtualDesktopNotification
		: public IVirtualDesktopNotification
	{
		void VirtualDesktopCreated(IVirtualDesktop *pDesktop) override
		{
			m_ownerProxy->VirtualDesktopCreated(nullptr, pDesktop);
		}

		void VirtualDesktopDestroyBegin(IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) override
		{
			m_ownerProxy->VirtualDesktopCreated(pDesktopDestroyed, pDesktopFallback);
		}

		void VirtualDesktopDestroyFailed(IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) override
		{
			m_ownerProxy->VirtualDesktopDestroyFailed(nullptr, pDesktopDestroyed, pDesktopFallback);
		}

		void VirtualDesktopDestroyed(IVirtualDesktop *pDesktopDestroyed, IVirtualDesktop *pDesktopFallback) override
		{
			m_ownerProxy->VirtualDesktopDestroyed(nullptr, pDesktopDestroyed, pDesktopFallback);
		}

		void ViewVirtualDesktopChanged(IApplicationView *pView) override
		{
			m_ownerProxy->ViewVirtualDesktopChanged(nullptr, pView);
		}

		void CurrentVirtualDesktopChanged(IVirtualDesktop *pDesktopOld, IVirtualDesktop *pDesktopNew) override
		{
			m_ownerProxy->CurrentVirtualDesktopChanged(nullptr, pDesktopOld, pDesktopNew);
		}

		// Constructor
		CProxy10240_IVirtualDesktopNotification(IProxyVirtualDesktopNotification *owner)
		{
			m_ownerProxy = owner;
		}

	private:
		IProxyVirtualDesktopNotification *m_ownerProxy;
	};
} // namespace VirtualDesktops
} // namespace Kawapure