#include "GameCore.h"

namespace SceptreEngine
{
	SceptreEngine::GameCore::CGameState GameCore::Run()
	{
		CGameState gamestate;
		gamestate.StartDate = {12, 06, 1123};
		gamestate.CurrentDate = gamestate.StartDate;
		gamestate.InMainMenu;

		// initialize other stuff

		return gamestate;
	}
	void GameCore::Tick(CGameState gamestate)
	{
		//add update functions
		gamestate.CurrentDate.day += 1;
	}

	std::string GameCore::CCountry::getCountryNamefromTag(const std::unordered_map<const char*, std::string, CharPtrHash, CharPtrEqual>& map, const char* key)
	{
		auto it = map.find(key);
		return it->second;
	}
}