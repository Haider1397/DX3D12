#pragma once
#include<DX3D12/Graphics/GraphicsUtils.h>
#include<DX3D12/Graphics/GraphicsResources.h>
#include<DX3D12/Core/Comman.h>

namespace dx3d
{
	class Fence final: public GraphicsResources
	{
	public:
		explicit Fence(const GraphicsResourcesDesc& gDesc);
		~Fence();

	private:

		Microsoft::WRL::ComPtr<ID3D12Fence> m_fence{};

		UINT m_rtvDescSize{};
		UINT m_dsvDescSize{};
		UINT m_sbvSrvDescSize{};
	};
}
