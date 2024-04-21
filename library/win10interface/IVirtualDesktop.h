#pragma once

#include "../base.h"
#include "IApplicationView.h"

namespace KappaBarVirtualDesktopWin10
{
	struct IVirtualDesktop : IUnknown
	{
		virtual bool IsViewVisible(IApplicationView *view) = 0;
		virtual _GUID *GetID() = 0;
	};
}