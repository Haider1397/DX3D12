#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>
#include<DX3D12/Core/Common.h>
#include<DX3D12/Math/Rect.h>
#include<DX3D12/Core/Core.h>
#include<DX3D12/Graphics/Msaa.h>

namespace dx3d
{
	class SwapChain: public GraphicsResources
	{
	public:
		explicit SwapChain(const GraphicsResourcesDesc& gDesc , const SwapChainDesc& desc);
		~SwapChain();

	private:
		Rect m_size{};
		DXGI_FORMAT m_backBufferFormat{};
		UINT m_MsaaQualityLvl{NULL}; // not used;
		bool m_MsaaQualityState{};
		UINT m_bufferCount{2};

		Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;
	};
}
