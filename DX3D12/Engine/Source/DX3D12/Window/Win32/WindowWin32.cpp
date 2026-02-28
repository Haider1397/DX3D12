#include <DX3D12/Window/Window.h>
#include <functional>

static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return 0;
}


dx3d::Window::Window(const WindowDesc& desc):
	Base({ {m_logger} }),
	m_size(desc.size)
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindow";
			wc.lpfnWndProc = WindowProcedure;
			return RegisterClassEx(&wc);
		};


	static const auto windowClassId = std::invoke(registerWindowClassFunction);

	if (!windowClassId)
		DX3D12LogThrowError("RegisterClassEx failed.");

	RECT size{};

	size.left = 0;
	size.top = 0;
	size.right = m_size.x - size.left;
	size.bottom = m_size.y - size.top;

	AdjustWindowRect(&size, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, NULL);

	m_hwnd = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), m_name,
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, m_size.x, m_size.y,
		NULL, NULL, NULL, NULL);

	if (!m_hwnd)
		DX3D12LogThrowError("CreateWindowEx failed.");

	ShowWindow(m_hwnd, SW_SHOW);
	DX3D12LogThrowError("ShowWindow completed.");
}

dx3d::Window::~Window()
{
	DestroyWindow(m_hwnd);
	DX3D12LogInfo("Window destoryed.");
}
