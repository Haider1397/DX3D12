#include <DX3D12/Graphics/CommandList.h>
#include <DX3D12/Graphics/GraphicsLogUtils.h>

dx3d::CommandList::CommandList(const GraphicsResourcesDesc& gDesc) :
	GraphicsResources(gDesc)
{
	D3D12_COMMAND_QUEUE_DESC queryDesc{};
	queryDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	queryDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;

	DX3DGraphicsLogThrowOnFail(m_device.CreateCommandQueue(&queryDesc, IID_PPV_ARGS(&m_query)),
		"CreateCommandQueue failed.");
	DX3DGraphicsLogThrowOnFail(m_device.CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&m_allocator)),
		"CreateCommandAllocator failed.");

	DX3DGraphicsLogThrowOnFail(m_device.CreateCommandList(NULL, D3D12_COMMAND_LIST_TYPE_DIRECT,m_allocator.Get(),

		NULL,                                             //Proper Pipline State Will be Added Later
		IID_PPV_ARGS(m_list.GetAddressOf())),
		"CreateCommandList failed");


		m_list->Close();
}

dx3d::CommandList::~CommandList()
{
}
