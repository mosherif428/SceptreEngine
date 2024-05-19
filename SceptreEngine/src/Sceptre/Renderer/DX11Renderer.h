#pragma once

#include "../../enginepch.h"
#include "../Core.h"
#include "Direct3D.h"
#include "Camera.h"
#include "Shader.h"
#include "Model.h"

namespace SceptreEngine
{
	class SCEPTRE_API DX11Renderer
	{
		static const bool FULL_SCREEN = false;
		static const bool VSYNC_ENABLED = true;
		static const float SCREEN_DEPTH;
		static const float SCREEN_NEAR;

	public:
		DX11Renderer();
		DX11Renderer(const DX11Renderer&);
		~DX11Renderer();

		static bool Initialize(int screenWidth, int screenHeight, HWND hwnd);

		void Shutdown();
		bool Frame();

	private:
		bool Render();

	private:
		Direct3D* m_Direct3D;
		Camera* m_Camera;
		Model* m_Model;
		Shader* m_Shader;

	};
	#ifdef SC_BUILD_DLL
	const float DX11Renderer::SCREEN_DEPTH = 1000.0f;
	const float DX11Renderer::SCREEN_NEAR = 0.3f;
	#endif
}