#pragma once

#include "Core.h"
#include "../Events/Event.h"

namespace SceptreEngine
{
	class SCEPTRE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_LayerName; }

	protected:
		std::string m_LayerName;

	};
}

