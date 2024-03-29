#include "Game.h"
#include <Windows.h>

class ExampleLayer : public SceptreEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SC_INFO("ExampleLayer::Update");

	}

	void OnEvent(SceptreEngine::Event& event) override
	{
		SC_TRACE("{0}", event);
	}

};

class Game : public SceptreEngine::SceptreGame
{
public:
	Game()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new SceptreEngine::ImguiLayer());
	}

	~Game()
	{

	}
};

SceptreEngine::SceptreGame* SceptreEngine::CreateGame()
{
	return new Game();
}