#pragma once

#include<DX3D12/Window/Window.h>
#include<DX3D12/Core/Common.h>

namespace dx3d 
{
	class Display final : public Window
	{
	public:
		explicit Display(const DisplayDesc desc);
		virtual ~Display();

	private:

	};
}

