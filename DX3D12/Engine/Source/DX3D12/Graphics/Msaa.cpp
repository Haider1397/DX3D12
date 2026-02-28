#include<DX3D12/Graphics/Msaa.h>
#include<DX3D12/Graphics/GraphicsLogUtils.h>


dx3d::Msaa::Msaa(const GraphicsResourcesDesc& gdesc) :
	GraphicsResources(gdesc)
{
	D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS qualityLvls{};

	qualityLvls.Format = m_backBufferFormet;
	qualityLvls.SampleCount = 4u;
	qualityLvls.NumQualityLevels = NULL;
	qualityLvls.Flags = D3D12_MULTISAMPLE_QUALITY_LEVELS_FLAG_NONE;

	DX3DGraphicsLogThrowOnFail(m_device.CheckFeatureSupport(D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS, &qualityLvls, sizeof(qualityLvls)),
		"CheckFeatureSupport D3D12_FEATURE_MULTISAMPLE_QUALITY_LEVELS failed.");

	m_4xMsaaQualityLvl = qualityLvls.SampleCount;
	assert(m_4xMsaaQualityLvl > 0 && "Unexpected MSAA quality level.");
}

dx3d::Msaa::~Msaa()
{
}
