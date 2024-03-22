#include "../enginepch.h"
#include "Engine.h"

#include "../Events/ApplicationEvent.h"
#include "Log.h"
namespace SceptreEngine
{
	SceptreGame::SceptreGame()
	{
	}

	SceptreGame::~SceptreGame()
	{

	};

	void SceptreGame::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			SC_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			SC_TRACE(e);
		}
		while (true);
	};
}