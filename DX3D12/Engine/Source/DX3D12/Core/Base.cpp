#include <DX3D12/Core/Base.h>

dx3d::Base::Base(const BaseDesc& desc):
	m_logger(desc.logger)
{
}

dx3d::Base::~Base()
{
}

dx3d::Logger& dx3d::Base::getLogger()
{
	return m_logger;
}
