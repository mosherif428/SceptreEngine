
#include <Sceptre.h>
#include <Sceptre/Log.h>
#include <Sceptre/Engine.h>

#include <Windows.h>


class Game : public SceptreEngine::SceptreGame
{
public:
	Game()
	{
		PushLayer(new SceptreEngine::Layer());
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