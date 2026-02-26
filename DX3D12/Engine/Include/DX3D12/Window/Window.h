#pragma once
#include<DX3D12/Core/Base.h>
#include<DX3D12/Core/Comman.h>
#include<windows.h>

namespace dx3d
{
	class Window: public Base
	{
	public:
		explicit Window(const WindowDesc& desc);
		virtual ~Window();

	private:

		static constexpr const wchar_t* m_name = L"Window";
		Rect m_size{};
		HWND m_hwnd{};
	};
}
