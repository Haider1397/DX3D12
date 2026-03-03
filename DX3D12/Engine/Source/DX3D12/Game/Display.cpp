#include<DX3D12/Game/Display.h>
#include<DX3D12/Graphics/GraphicsDevice.h>


dx3d::Display::Display(const DisplayDesc desc):Window(desc.window)
{
	m_swapChain = desc.graphicsDevice.createSwapChain(SwapChainDesc{ m_size,m_hwnd });
}

dx3d::Display::~Display()
{
}
