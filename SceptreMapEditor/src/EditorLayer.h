#pragma once

//#include <Sceptre.h>
#include <Sceptre/Log.h>
#include <Sceptre/Engine.h>

namespace SceptreEngine
{
	class EditorLayer : public Layer
	{
	public:
		EditorLayer();
		virtual ~EditorLayer() = default;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnImGuiRender() override;
		void OnEvent(Event& e) override;

	private:
		// renderer stuff
	};
}