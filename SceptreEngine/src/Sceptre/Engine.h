#pragma once

#include "Core.h"
#include "../Events/Event.h"

namespace SceptreEngine {
	class SCEPTRE_API SceptreGame
	{
	public:
		SceptreGame();
		virtual ~SceptreGame();

		void Run();
	};

	//To be defined in CLIENT
	SceptreGame* CreateGame();
}