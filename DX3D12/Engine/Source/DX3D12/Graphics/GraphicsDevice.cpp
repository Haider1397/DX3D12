#include<DX3D12/Graphics/GraphicsDevice.h>
#include<DX3D12/Graphics/GraphicsLogUtils.h>

#include<DX3D12/Graphics/Fence.h>
#include<DX3D12/Graphics/Msaa.h>


dx3d::GraphicsDevice::GraphicsDevice(const GraphicsDeviceDesc& desc):
	Base(desc.base)
{

#if defined(DEBUG) || defined(_DEBUG)
		Microsoft::WRL::ComPtr<ID3D12Debug> debugController;
		DX3DGraphicsLogThrowOnFail(D3D12GetDebugInterface(IID_PPV_ARGS(&debugController)),
			"D3D12GetDebugInterface failed.");
		debugController->EnableDebugLayer();
#endif


		DX3DGraphicsLogThrowOnFail(CreateDXGIFactory1(IID_PPV_ARGS(&m_factory)),
			"CreateDXGIFactory1 failed.");
		HRESULT hardwareResult = D3D12CreateDevice(NULL, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device));

		if (FAILED(hardwareResult))
		{
			Microsoft::WRL::ComPtr<IDXGIAdapter> warpAdapter;
			DX3DGraphicsLogThrowOnFail(m_factory->EnumWarpAdapter(IID_PPV_ARGS(&warpAdapter)),
				"EnumWarpAdapter failed.");
			DX3DGraphicsLogThrowOnFail(D3D12CreateDevice(warpAdapter.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&m_device)),
				"D3D12CreateDevice failed.");
		}
}

dx3d::GraphicsDevice::~GraphicsDevice()
{
}

dx3d::GraphicsDeviceDesc dx3d::GraphicsDevice::getGraphicsResourceDesc()
{
	return GraphicsDeviceDesc({m_logger});
}

dx3d::FencePtr dx3d::GraphicsDevice::createFence()
{
	return std::make_shared<Fence>(getGraphicsResourceDesc());
}

dx3d::MsaaPtr dx3d::GraphicsDevice::createMsaa()
{
	return std::make_shared<Msaa>(getGraphicsResourceDesc());
}

dx3d::CommandListPtr dx3d::GraphicsDevice::createCommadList()
{
	return std::make_shared<CommandList>(getGraphicsResourceDesc());
}
