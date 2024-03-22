#pragma once

#ifdef SC_PLATFORM_WINDOWS

extern SceptreEngine::SceptreGame* SceptreEngine::CreateGame();

int main(int argc, char** argv)
{
	SceptreEngine::Log::Init();
	SC_CORE_WARN("SCEPTRE INITIALIZED");
	SC_INFO("Hand me the Sceptre!");
	auto game = SceptreEngine::CreateGame();
	game->Run();
	delete game;
}
#endif