#pragma once
#include<DX3D12/Core/Base.h>
#include<DX3D12/Core/Comman.h>


namespace dx3d 
{
	class GraphicsEngine : public Base
	{
	public:
		explicit GraphicsEngine(const GraphicsEngineDesc& gDesc);
		virtual ~GraphicsEngine();
	};
}

