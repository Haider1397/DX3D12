#pragma once

namespace dx3d
{
	class Rect
	{
	public:

		Rect() {}
		Rect(int x ,int y): x(x) ,y(y){}

		int x{};
		int y{};
	};
}