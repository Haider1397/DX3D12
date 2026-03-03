#pragma once

#include<DX3D12/Graphics/GraphicsResources.h>
#include<DX3D12/Core/Common.h>

namespace dx3d 
{
	class CommandList : public GraphicsResources
	{
	public:
		explicit CommandList(const GraphicsResourcesDesc& gDesc);
		~CommandList();

	private:
		Microsoft::WRL::ComPtr<ID3D12CommandAllocator> m_allocator{};
		Microsoft::WRL::ComPtr<ID3D12CommandQueue> m_query{};

	protected:
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> m_list{};
	};
}

