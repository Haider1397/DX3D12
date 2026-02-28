#pragma once
#include<DX3D12/Graphics/GraphicsUtils.h>
#include<DX3D12/Core/Common.h>
#include<DX3D12/Graphics/GraphicsResources.h>
#include<DX3D12/Core/Core.h>



namespace dx3d 
{
	class GraphicsDevice final : public Base
	{
	public:
		explicit GraphicsDevice(const GraphicsDeviceDesc& desc);
		virtual ~GraphicsDevice() final;

		GraphicsDeviceDesc getGraphicsResourceDesc();
		FencePtr createFence();
		MsaaPtr createMsaa();
		CommandListPtr createCommadList();
		 

	private:
		Microsoft::WRL::ComPtr<ID3D12Device> m_device{};
		Microsoft::WRL::ComPtr<IDXGIFactory4> m_factory{};
	};
}

