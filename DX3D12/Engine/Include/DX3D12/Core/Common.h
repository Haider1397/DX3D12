#pragma once
#include<DX3D12/Core/Core.h>
#include<DX3D12/Core/Logger.h>
#include<DX3D12/Math/Rect.h>
#include<DX3D12/Graphics/GraphicsDevice.h>

namespace dx3d
{
	struct BaseDesc 
	{
		Logger& logger;
	};
	struct WindowDesc 
	{
		BaseDesc base;
		Rect size{};
	};
	struct DisplayDesc
	{
		WindowDesc window;
		GraphicsDevice& graphicDevice;
	};
	struct GraphicsEngineDesc
	{
		BaseDesc base;
	};
	struct GraphicsDeviceDesc
	{
		BaseDesc base;
	};
	struct SwapChainDesc
	{
		Rect wndsize{};
		void* hwnd;
		ui32 backBufferFormat{ DXGI_FORMAT_R16G16B16A16_SNORM };
	};
	struct GameDesc 
	{
		Rect wndsize{ 1200 ,720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Info;
	};
}