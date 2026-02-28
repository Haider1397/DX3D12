#pragma once
#include<DX3D12/Core/Logger.h>
#include<stdexcept>
#include <d3d12.h>

namespace dx3d
{
	namespace GraphicsLogUtils
	{
		inline void CheckShaderCompile(Logger& logger, HRESULT hr, ID3DBlob* errorBlob)
		{
			auto errorMsg = errorBlob ? static_cast<const char*>(errorBlob->GetBufferPointer()) : nullptr;

			if (FAILED(hr))
				DX3D12LogThrow(logger, std::runtime_error, Logger::LogLevel::Error, errorMsg ? errorMsg :
					"Shader compilation failed.");
			if (errorMsg)
				DX3D12Log(logger, Logger::LogLevel::Warning, errorMsg);
		}

	}
}

#define DX3DGraphicsLogThrowOnFail(hr,message)\
	{\
	auto res = (hr);\
	if (FAILED(res))\
		DX3D12LogThrowError(message);\
	}


#define DX3D12GraphicsCheckShaderCompile(hr, errorBlob)\
{\
auto res = (hr);\
dx3d::GraphicsLogUtils::CheckShaderCompile(getLogger(), res, errorBlob);\
}