#pragma once

#include "Core.h"
#include "../enginepch.h"
#include "../Events/Event.h"
#include "LayerStack.h"
#include "../Events/ApplicationEvent.h"
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/imgui_internal.h"

namespace SceptreEngine {
	class SCEPTRE_API SceptreGame
	{
	public:
		SceptreGame();
		virtual ~SceptreGame();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);


		inline static SceptreGame& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		bool m_Running = true;
		LayerStack m_LayerStack;
		static SceptreGame* s_Instance;
	};

	//To be defined in CLIENT
	SceptreGame* CreateGame();
}