#include <Sceptre.h>
#include <Sceptre/Log.h>
#include <Sceptre/Engine.h>
#include <Windows.h>

class MapEditor : public SceptreEngine::SceptreGame
{
public:
	MapEditor()
	{
		PushLayer(new SceptreEngine::Layer());
		PushOverlay(new SceptreEngine::ImguiLayer());
	}

	~MapEditor()
	{

	}
};

SceptreEngine::SceptreGame* SceptreEngine::InitMapEditor()
{
	return new MapEditor();
}