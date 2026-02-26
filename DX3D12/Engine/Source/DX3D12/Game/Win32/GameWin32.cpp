#include<DX3D12/Game/Game.h>

void dx3d::Game::run()
{
	MSG msg{};
	while (m_isRunning)
	{
		while (PeekMessage(&msg, NULL , NULL ,NULL, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				m_isRunning = false;
				break;
			}
			DispatchMessage(&msg);
			TranslateMessage(&msg);
		}
		Sleep(1);
	}
}