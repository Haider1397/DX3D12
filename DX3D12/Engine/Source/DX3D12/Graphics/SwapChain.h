#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>
//#include<DX3D12/Graphics/CommandList.h>

namespace dx3d 
{
	class SwapChain final : public GraphicsResources
	{
	public:
		explicit SwapChain(const GraphicsResourcesDesc& gDesc , const SwapChainDesc& desc);
		~SwapChain();

	private:
		Rect m_size{};
		bool m_4xmsaaState{false};
		UINT m_4xmsaaQuality{};
		UINT m_bufferCount;

		DXGI_FORMAT m_backBufferFormat = DXGI_FORMAT_R32G32B32A32_SINT;


		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain{};

	};
}

