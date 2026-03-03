#pragma once
#include<DX3D12/Core/Base.h>
#include<DX3D12/Core/Common.h>
#include<DX3D12/Game/Display.h>
#include<DX3D12/Core/Logger.h>
#include<memory>
#include<DX3D12/Graphics/GraphicsEngine.h>

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
		std::unique_ptr<GraphicsEngine> m_graphicsEnginePtr;
		std::unique_ptr<Display> m_display;
	};
}
