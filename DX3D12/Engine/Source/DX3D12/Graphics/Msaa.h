#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>

namespace dx3d
{
	class Msaa final : public GraphicsResources
	{
	public:

		explicit Msaa(const GraphicsResourcesDesc& gdesc);
		~Msaa();

		DXGI_FORMAT& getBackBufferFormet();
		UINT& GetMsaaQualityLvl();

	private:
		DXGI_FORMAT m_backBufferFormet{ DXGI_FORMAT_R8G8B8A8_UNORM };

		UINT m_4xMsaaQualityLvl{};
	};
}
