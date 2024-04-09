#pragma once
#include "Layer.h"
namespace SceptreEngine
{
	class SCEPTRE_API ImguiLayer : public Layer
	{
	public:
		ImguiLayer();
		~ImguiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}