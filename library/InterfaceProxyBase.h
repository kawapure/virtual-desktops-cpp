#pragma once

#include "base.h"
#include "clsids.h"

template <class TargetInterface>
class CInterfaceProxyBase
{
protected:
	TargetInterface *m_pProxiedInterface = nullptr;

public:
	CInterfaceProxyBase(IUnknown *pFromInterface)
	{
		m_pProxiedInterface = pFromInterface;
	}

	TargetInterface *_UnwrapInterfaceProxy()
	{
		return m_pProxiedInterface;
	}
};
