#pragma once

#include "base.h"
#include "clsids.h"
#include "InterfaceProxyBase.h"
#include <stdexcept>

template <GUID const *pGuid, class TargetInterface>
class CComProxyBase : public CInterfaceProxyBase<TargetInterface>
{
protected:
	IServiceProvider *m_pServiceProvider = nullptr;

	// Implemented by CInterfaceProxyBase:
	//TargetInterface *m_pProxiedInterface = nullptr;

public:
	CComProxyBase()
	{
		HRESULT hr = CoCreateInstance(
			CLSID_ImmersiveShell,
			NULL,
			CLSCTX_LOCAL_SERVER,
			__uuidof(IServiceProvider),
			(void **)&m_pServiceProvider
		);

		if (SUCCEEDED(hr))
		{
			hr = m_pServiceProvider->QueryService(
				pGuid,
				&this->m_pProxiedInterface
			);
		}

		if (FAILED(hr))
		{
			throw std::runtime_error("Failed to create interface.");
		}
	}

	CComProxyBase(IUnknown *pFromInterface)
	{
		this->m_pProxiedInterface = pFromInterface;
	}

	~CComProxyBase()
	{
		this->m_pProxiedInterface->Release();

		if (m_pServiceProvider)
			m_pServiceProvider->Release();
	}
};
