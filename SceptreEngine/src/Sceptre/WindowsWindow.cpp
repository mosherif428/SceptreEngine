#include "WindowsWindow.h"
#include "../enginepch.h"
#include "Log.h"

namespace SceptreEngine {


	//Window* Window::Create(const WindowProps& props)
	//{
	//	return new WindowsWindow(props);
	//}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		WindowsWindow::Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
	}

	bool WindowsWindow::IsVSync() const
	{
		return false;
	}

	void* WindowsWindow::GetNativeWindow() const
	{
		return nullptr;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		SC_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

	}
	void WindowsWindow::Shutdown()
	{
	}
}