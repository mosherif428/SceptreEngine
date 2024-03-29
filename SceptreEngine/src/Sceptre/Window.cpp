#include "../enginepch.h"
#include "Window.h"

#ifdef SC_PLATFORM_WINDOWS
#include "WindowsWindow.h"
#endif

namespace SceptreEngine
{
	Window* Window::Create(const WindowProps& props)
	{
#ifdef SC_PLATFORM_WINDOWS
		return nullptr;
#else
		SC_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}