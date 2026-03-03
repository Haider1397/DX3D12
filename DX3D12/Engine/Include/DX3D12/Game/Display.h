#pragma once

#include<DX3D12/Window/Window.h>
#include<DX3D12/Core/Common.h>
#include<DX3D12/Graphics/SwapChain.h>

namespace dx3d 
{
	class Display final : public Window
	{
	public:
		explicit Display(const DisplayDesc desc);
		virtual ~Display();

	private:
		SwapChainPtr m_swapChain;
	};
}

