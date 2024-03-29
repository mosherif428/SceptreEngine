#include "../enginepch.h"
#include "Engine.h"

#include "../Events/ApplicationEvent.h"
#include "Log.h"
#include "Assert.h"
namespace SceptreEngine
{

#define BIND_EVENT_FN(x) std::bind(&SceptreGame::x, this, std::placeholders::_1)

	SceptreGame* SceptreGame::s_Instance = nullptr;
	
	SceptreGame::SceptreGame()
	{
		SC_CORE_ASSERT(!s_Instance, "SceptreGame already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	SceptreGame::~SceptreGame()
	{

	};

	void SceptreGame::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void SceptreGame::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	bool SceptreGame::OnWindowClose(WindowCloseEvent& e)
	{
		return false;
	}

	void SceptreGame::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void SceptreGame::Run()
	{
		while (m_Running)
		{
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	};
}