#include <DX3D12/Graphics/SwapChain.h>
#include<DX3D12/Graphics/GraphicsLogUtils.h>
#undef max;
#undef min;

dx3d::SwapChain::SwapChain(const GraphicsResourcesDesc& gDesc, const SwapChainDesc& desc):
	GraphicsResources(gDesc),
	m_commandQurey(desc.commadList.getCommandQuery())
{
	m_swapChain.Reset();
	DXGI_SWAP_CHAIN_DESC swapChainDesc{};

	swapChainDesc.BufferDesc.Width = std::max(1, m_size.x);
	swapChainDesc.BufferDesc.Height = std::max(1, m_size.y);
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.Format = m_backBufferFormat;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.Windowed = true;
	swapChainDesc.SampleDesc.Count = m_4xmsaaState? 4:1;
	swapChainDesc.SampleDesc.Quality = m_4xmsaaState ? (m_4xmsaaQuality - 1):0 ;
	swapChainDesc.BufferCount = m_bufferCount;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	swapChainDesc.OutputWindow = static_cast<HWND>(desc.hwnd);
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;

	DX3DGraphicsLogThrowOnFail(m_factory.CreateSwapChain(m_commandQurey.Get(), &swapChainDesc, &m_swapChain),
		"CreateSwapChain failed.");

}

dx3d::SwapChain::~SwapChain()
{
}
