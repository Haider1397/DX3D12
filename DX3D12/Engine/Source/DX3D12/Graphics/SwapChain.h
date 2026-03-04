#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>
#include<DX3D12/Core/Core.h>

namespace dx3d 
{
	class SwapChain final : public GraphicsResources
	{
	public:
		explicit SwapChain(const GraphicsResourcesDesc& gDesc , const SwapChainDesc& desc);
		~SwapChain();

	private:

		Rect m_size{};
		bool m_4xMsaaState{false};
		UINT m_4xMsaaQuality{};
		UINT m_bufferCount{2};

		DXGI_FORMAT m_backBufferFormat{};


		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_commandQurey{};

	};
}

