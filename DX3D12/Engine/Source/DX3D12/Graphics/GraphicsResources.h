#pragma once

#include<DX3D12/Core/Base.h>
#include<DX3D12/Graphics/GraphicsUtils.h>

namespace dx3d
{
	struct GraphicsResourcesDesc
	{
		BaseDesc base;
		std::shared_ptr<const GraphicsDevice> graphicsDevice;
		ID3D12Device& device;
		IDXGIFactory4& factory;
	};


	class GraphicsResources: public Base
	{
	public:
		explicit GraphicsResources(const GraphicsResourcesDesc& gDesc):
			Base(gDesc.base),
			m_graphicsDevice(gDesc.graphicsDevice),
			m_device(gDesc.device),
			m_factory(gDesc.factory)

		{

		}

		std::shared_ptr<const GraphicsDevice> m_graphicsDevice;
		ID3D12Device& m_device;
		IDXGIFactory4& m_factory;
	
		virtual ~GraphicsResources() {};
	};


}