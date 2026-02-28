#include <DX3D12/Graphics/GraphicsEngine.h>
#include<DX3D12/Graphics/GraphicsResources.h>
#include<DX3D12/Graphics/GraphicsDevice.h>


dx3d::GraphicsEngine::GraphicsEngine(const GraphicsEngineDesc& gDesc):
	Base(gDesc.base)
{
	m_graphicsDevice  = std::make_shared<GraphicsDevice>(GraphicsDeviceDesc{ m_logger });
	m_fence = m_graphicsDevice->CreateFence();
	m_msaa = m_graphicsDevice->CreateMsaa();
}

dx3d::GraphicsEngine::~GraphicsEngine()
{
}
