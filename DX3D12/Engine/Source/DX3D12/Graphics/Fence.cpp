#include<DX3D12/Graphics/GraphicsLogUtils.h>
#include <DX3D12/Graphics/Fence.h>

dx3d::Fence::Fence(const GraphicsResourcesDesc& gDesc):
	GraphicsResources(gDesc)
{
	m_rtvDescSize = m_device.GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	m_dsvDescSize = m_device.GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);
	m_sbvSrvDescSize = m_device.GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

	DX3DGraphicsLogThrowOnFail(m_device.CreateFence(NULL, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&m_fence)),"createFence failed.");
}

dx3d::Fence::~Fence()
{
}
