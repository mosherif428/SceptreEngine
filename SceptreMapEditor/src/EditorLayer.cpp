#include "EditorLayer.h"

namespace SceptreEngine
{
		EditorLayer::EditorLayer()
			: Layer("Editor")
		{
		}

		void EditorLayer::OnAttach()
		{
		}

		void EditorLayer::OnDetach()
		{
		}

		void EditorLayer::OnUpdate()
		{
			SC_INFO("EditorLayer::Update");

		}
		void EditorLayer::OnImGuiRender()
		{
			
		}
		void EditorLayer::OnEvent(SceptreEngine::Event& event)
		{
			SC_TRACE("{0}", event);
		}

}