#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>

namespace dx3d
{
	class Msaa final : public GraphicsResources
	{
	public:

		explicit Msaa(const GraphicsResourcesDesc& gdesc);
		~Msaa();

	private:
		DXGI_FORMAT m_backBufferFormet{}; //Must Be Later Changed Later To Swap Chain

		UINT m_4xMsaaQualityLvl{};
	};
}
