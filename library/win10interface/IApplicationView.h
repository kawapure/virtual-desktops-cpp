#pragma once

#include "../base.h"

namespace KappaBarVirtualDesktopWin10
{
	enum class ApplicationViewCloakType
	{
		AVCT_NONE = 0,
		AVCT_DEFAULT = 1,
		AVCT_VIRTUAL_DESKTOP = 2
	};

	enum class ApplicationViewCompatibilityPolicy
	{
		AVCP_NONE = 0,
		AVCP_SMALL_SCREEN = 1,
		AVCP_TABLET_SMALL_SCREEN = 2,
		AVCP_VERY_SMALL_SCREEN = 3,
		AVCP_HIGH_SCALE_FACTOR = 4
	};

	struct IApplicationView : IUnknown
	{
		// Dummy entries for alignment as this is a WinRT IInspectable:
		virtual void dummy1() = 0;
		virtual void dummy2() = 0;
		virtual void dummy3() = 0;

		virtual void SetFocus() = 0;
		virtual void SwitchTo() = 0;
		virtual void TryInvokeBack(void *callback) = 0;
		virtual void *GetThumbnailWindow() = 0;
		virtual void *GetMonitor() = 0;
		virtual int GetVisibility() = 0;
		virtual void SetCloak(ApplicationViewCloakType cloakType, int unknown) = 0;
		virtual void *GetPosition(GUID *guid, void *position) = 0;
		virtual void SetPosition(void *position) = 0;
		virtual void InsertAfterWindow(HWND hWnd) = 0;
		virtual RECT *GetExtendedFramePosition() = 0;
		virtual LPWSTR GetAppUserModelId() = 0;
		virtual bool IsEqualByAppUserModelId(WCHAR *id) = 0;
		virtual DWORD GetViewState() = 0;
		virtual void SetViewState(DWORD state) = 0;
		virtual int GetNeediness() = 0;
		virtual unsigned long long GetLastActivationTimestamp() = 0;
		virtual void SetLastActivationTimestamp(unsigned long long timestamp) = 0;
		virtual GUID *GetVirtualDesktopId() = 0;
		virtual void SetVirtualDesktopId(GUID *guid) = 0;
		virtual int GetShowInSwitchers() = 0;
		virtual void SetShowInSwitchers(int flag) = 0;
		virtual int GetScaleFactor() = 0;
		virtual bool CanReceiveInput() = 0;
		virtual ApplicationViewCompatibilityPolicy GetCompatibilityPolicyType() = 0;
		virtual void SetCompatibilityPolicyType(ApplicationViewCompatibilityPolicy flags) = 0;
		virtual void *GetPositionPriority() = 0;
		virtual void SetPositionPriority(void *priority) = 0;
		virtual void GetSizeConstraints(void *monitor, SIZE *size1, SIZE *size2) = 0;
		virtual void GetSizeConstraintsForDpi(DWORD uint1, SIZE *size1, SIZE *size2) = 0;
		virtual void SetSizeConstraintsForDpi(DWORD *uint1, SIZE *size1, SIZE *size2) = 0;
		virtual int QuerySizeConstraintsFromApp() = 0;
		virtual void OnMinSizePreferencesUpdated(HWND hWnd) = 0;
		virtual void ApplyOperation(void *operation) = 0;
		virtual bool IsTray() = 0;
		virtual bool IsInHighZOrderBand() = 0;
		virtual bool IsSplashScreenPresented() = 0;
		virtual void Flash() = 0;
		virtual IApplicationView GetRootSwitchableOwner() = 0;
		virtual /* IObjectArray */ void *EnumerateOwnershipTree() = 0;
		virtual LPWSTR GetEnterpriseId() = 0;
		virtual bool IsMirrored() = 0;
	};
}