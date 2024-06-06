#pragma once

//#include <Sceptre.h>
#include <Sceptre/Log.h>
#include <Sceptre/Engine.h>

namespace SceptreEngine
{
	class GameLayer : public Layer
	{
	public:
		GameLayer();
		virtual ~GameLayer() = default;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		void OnUpdate();
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;

	private:
		// renderer stuff
	};
}
