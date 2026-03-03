#pragma once

#include<memory>
#include<stdexcept>

namespace dx3d
{
	class Base;
	class Window;
	class Game;
	class GraphicsEngine;
	class GraphicsDevice;
	class Logger;
	class Fence;
	class Msaa;
	class CommandList;
	class SwapChain;


	using GraphicsDevicePtr = std::shared_ptr <GraphicsDevice>;
	using FencePtr = std::shared_ptr <Fence>;
	using MsaaPtr = std::shared_ptr <Msaa>;
	using CommandListPtr = std::shared_ptr <CommandList>;
	using SwapChainPtr = std::shared_ptr <SwapChain>;


	using ui32 = unsigned int;

}