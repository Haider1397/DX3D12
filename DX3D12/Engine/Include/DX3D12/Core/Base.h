#pragma once
#include<DX3D12/Core/Common.h>
#include<DX3D12/Core/Logger.h>

namespace dx3d 
{
	class Base
	{
	public:
		explicit Base(const BaseDesc& desc);
		virtual ~Base();

		Logger& getLogger();

	protected:
		Base(const Base&) = delete;
		Base operator= (const Base&) = delete;

		Base(Base&&) = delete;
		Base operator= (Base&&) = delete;

	protected:
		Logger& m_logger;
	};
}


#define DX3D12LogInfo(message)\
	DX3D12Log(getLogger(), Logger::LogLevel::Info, message)

#define DX3D12LogWarning(message)\
	DX3D12Log(getLogger(), Logger::LogLevel::Warning, message)

#define DX3D12LogError(message)\
	DX3D12Log(getLogger(), Logger::LogLevel::Error, message)

#define DX3D12LogThrowError(message)\
	DX3D12LogThrow(getLogger(), std::runtime_error, Logger::LogLevel::Error, message)

#define DX3D12LogThrowInvalidArg(message)\
	DX3D12LogThrow(getLogger(), std::invalid_argument, Logger::LogLevel::Error, message)