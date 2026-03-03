#include <DX3D12/Game/Display.h>

dx3d::Display::Display(const DisplayDesc desc):
	Window(desc.window)
{
	m_swapChain = desc.graphicDevice.createSwapChain({ m_size,m_hwnd , DXGI_FORMAT_R16G16B16A16_SNORM  });
}

dx3d::Display::~Display()
{
}

dx3d::SwapChain& dx3d::Display::getSwapChain() noexcept
{
	return *m_swapChain;
}