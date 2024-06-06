#include "GameLayer.h"


namespace SceptreEngine
{
	GameLayer::GameLayer()
		: Layer("Game")
	{
	}

	void GameLayer::OnAttach()
	{
	}

	void GameLayer::OnDetach()
	{
	}

	void GameLayer::OnUpdate()
	{
		SC_INFO("GameLayer::Update");

	}
	void GameLayer::OnImGuiRender()
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}
	void GameLayer::OnEvent(SceptreEngine::Event& event)
	{
		SC_TRACE("{0}", event);
	}

};
