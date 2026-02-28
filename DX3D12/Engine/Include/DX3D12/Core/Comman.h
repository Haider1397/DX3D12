#pragma once
#include<DX3D12/Core/Core.h>
#include<DX3D12/Core/Logger.h>
#include<DX3D12/Math/Rect.h>

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
		BaseDesc base;
	};
	struct GraphicsEngineDesc
	{
		BaseDesc base;
	};

	struct GameDesc 
	{
		Rect wndsize{ 1200 ,720 };
		Logger::LogLevel logLevel = Logger::LogLevel::Info;
	};
	struct GraphicsDeviceDesc
	{
		BaseDesc base;
	};
}