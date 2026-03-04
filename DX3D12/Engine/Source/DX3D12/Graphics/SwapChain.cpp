#include <DX3D12/Graphics/SwapChain.h>
#include<DX3D12/Graphics/GraphicsLogUtils.h>
#include<DX3D12/Graphics/CommandList.h>
#include<DX3D12/Graphics/Msaa.h>
#undef max;
#undef min;

dx3d::SwapChain::SwapChain(const GraphicsResourcesDesc& gDesc, const SwapChainDesc& desc) :
	GraphicsResources(gDesc),
	m_size(desc.wndSize),
	m_backBufferFormat(desc.msaa.getBackBufferFormet()),
	m_4xMsaaQuality(desc.msaa.GetMsaaQualityLvl()),
	m_commandQurey(desc.commadList.getCommandQuery())
{
	m_swapChain.Reset();
	DXGI_SWAP_CHAIN_DESC swapChainDesc{};

	swapChainDesc.BufferDesc.Width = std::max(1, m_size.x);
	swapChainDesc.BufferDesc.Height = std::max(1, m_size.y);

	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferDesc.Format = m_backBufferFormat;
	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	swapChainDesc.SampleDesc.Count = m_4xMsaaState ? 4 : 1;
	swapChainDesc.SampleDesc.Quality = m_4xMsaaState ? (m_4xMsaaQuality - 1) : 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = m_bufferCount;
	swapChainDesc.OutputWindow = reinterpret_cast<HWND>(desc.hwnd);
	swapChainDesc.Windowed = true;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	DX3DGraphicsLogThrowOnFail(m_factory.CreateSwapChain(m_commandQurey.Get(), &swapChainDesc, m_swapChain.GetAddressOf()),
		"CreateSwapChain failed.");

}

dx3d::SwapChain::~SwapChain()
{
}
