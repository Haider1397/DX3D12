#pragma once
#include<DX3D12/Core/Core.h>
#include<DX3D12/Core/Base.h>

namespace dx3d 
{
	class GraphicsEngine final: public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& gDesc);
		virtual ~GraphicsEngine();

	private:
		GraphicsDevicePtr m_graphicsDevice;
		FencePtr m_fence;
		MsaaPtr m_msaa;
	};
}

