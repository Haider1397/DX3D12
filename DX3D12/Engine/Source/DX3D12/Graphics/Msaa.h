#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>

namespace dx3d
{
	class Msaa final : public GraphicsResources
	{
	public:

		explicit Msaa(const GraphicsResourcesDesc& gdesc, const MsaaDesc& desc);
		~Msaa();

	private:
		DXGI_FORMAT m_backBufferFormet{};
		UINT m_4xMsaaQualityLvl{};
	};
}
