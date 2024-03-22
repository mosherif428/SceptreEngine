#include "Game.h"

class Game : public SceptreEngine::SceptreGame
{
public:
	Game()
	{

	}

	~Game()
	{

	}
};

SceptreEngine::SceptreGame* SceptreEngine::CreateGame()
{
	return new Game();
}