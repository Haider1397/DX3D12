#pragma once
#include<DX3D12/Core/Base.h>
#include<DX3D12/Core/Common.h>
#include<DX3D12/Window/Window.h>
#include<DX3D12/Core/Logger.h>
#include<memory>

namespace dx3d
{
	class Game: public Base
	{
	public:
		explicit Game(const GameDesc& desc);
		virtual ~Game();

		void run();

	private:
		bool m_isRunning{true};
		std::unique_ptr<Logger> m_loggerPtr;
		std::unique_ptr<Window> m_display;
	};
}
