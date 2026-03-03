#include <DX3D12/Graphics/SwapChain.h>
#include<DX3D12/Graphics/GraphicsLogUtils.h>
#include <algorithm>
#undef max

dx3d::SwapChain::SwapChain(const GraphicsResourcesDesc& gDesc, const SwapChainDesc& desc):
	GraphicsResources(gDesc),
	m_size(desc.wndsize),
	m_backBufferFormat(desc.backBufferFormat)
{

	DXGI_SWAP_CHAIN_DESC swapChainDesc{};
	swapChainDesc.BufferDesc.Width = std::max(1,desc.wndsize.x );
	swapChainDesc.BufferDesc.Height = std::max(1, desc.wndsize.y);
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.Format = m_backBufferFormat;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

	//swapChainDesc.SampleDesc.Count = m_MsaaQualityState ? 4 : 1;
	//swapChainDesc.SampleDesc.Quality = m_MsaaQualityState ? (m_MsaaQualityLvl - 1) : 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = m_bufferCount;
	swapChainDesc.OutputWindow = static_cast<HWND>(desc.hwnd);
	swapChainDesc.Windowed = true;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;


	DX3DGraphicsLogThrowOnFail(m_factory.CreateSwapChain(&m_device, &swapChainDesc, &swapChain),
		"CreateSwapChain failed.");
}

dx3d::SwapChain::~SwapChain()
{
}
