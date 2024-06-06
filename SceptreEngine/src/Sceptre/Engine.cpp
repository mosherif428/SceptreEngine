#include "../enginepch.h"
#include "Engine.h"

#include "../Events/ApplicationEvent.h"
#include "Log.h"
#include "Assert.h"
#include "Core/GameCore.h"
namespace SceptreEngine
{

#define BIND_EVENT_FN(x) std::bind(&SceptreGame::x, this, std::placeholders::_1)

	SceptreGame* SceptreGame::s_Instance = nullptr;
	
	SceptreGame::SceptreGame()
	{
		SC_CORE_ASSERT(!s_Instance, "SceptreGame already exists!");
		s_Instance = this;

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

	void SceptreGame::Build()
	{
		using clock = std::chrono::steady_clock;
		auto lastUpdateTime = clock::now();

		GameCore game;
		SceptreEngine::GameCore::CGameState gamestate = game.Run();

		while (m_Running)
		{
			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			auto now = clock::now();
			std::chrono::duration<double> deltaTime = now - lastUpdateTime;
			lastUpdateTime = now;
			
			if (!game.IsPaused)
			{
				game.Tick(gamestate);

			}

		}
	};

	void SceptreGame::Close()
	{
		m_Running = false;
	};
}