#include <DX3D12/Game/Game.h>


dx3d::Game::Game(const GameDesc& desc):
	Base({*std::make_unique<Logger>(dx3d::Logger::Error).release()}),
	m_loggerPtr(&m_logger)
{
	m_display = std::make_unique<Window>(WindowDesc{m_logger,desc.wndsize});
}

dx3d::Game::~Game()
{
	DX3D12LogInfo("Game ended.");
}


