#include "DX11Renderer.h"
#include "../Assert.h"

namespace SceptreEngine
{
	DX11Renderer::DX11Renderer()
	{
		m_Direct3D = 0;
		m_Camera = 0;
		m_Model = 0;
		m_Shader = 0;
	}
	DX11Renderer::DX11Renderer(const DX11Renderer& other)
	{
	}
	DX11Renderer::~DX11Renderer()
	{
	}

	bool DX11Renderer::Initialize(int screenWidth, int screenHeight, HWND hwnd)
	{
		bool result;


		// Create and initialize the Direct3D object.
		Direct3D* m_Direct3D = new Direct3D;

		result = m_Direct3D->Initialize(screenWidth, screenHeight, VSYNC_ENABLED, hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
		SC_CORE_ASSERT(result, "Initializing Direct3D Failed");


		Camera* m_Camera = new Camera;
		m_Camera->SetPosition(0.0f, 0.0f, -5.0f);

		Model* m_Model = new Model;
		result = m_Model->Initialize(m_Direct3D->GetDevice());
		SC_CORE_ASSERT(result, "Initializing Model Object Failed");

		Shader* m_Shader = new Shader;
		result = m_Shader->Initialize(m_Direct3D->GetDevice(), hwnd);
		SC_CORE_ASSERT(result, "Initializing Shader Object Failed");

		return true;
	}

	void DX11Renderer::Shutdown()
	{
		// Release the color shader object.
		if (m_Shader)
		{
			m_Shader->Shutdown();
			delete m_Shader;
			m_Shader = 0;
		}

		// Release the model object.
		if (m_Model)
		{
			m_Model->Shutdown();
			delete m_Model;
			m_Model = 0;
		}

		// Release the camera object.
		if (m_Camera)
		{
			delete m_Camera;
			m_Camera = 0;
		}

		// Release the D3D object.
		if (m_Direct3D)
		{
			m_Direct3D->Shutdown();
			delete m_Direct3D;
			m_Direct3D = 0;
		}

		return;
	}

	bool DX11Renderer::Frame()
	{
		bool result;


		// Render the graphics scene.
		result = Render();
		if (!result)
		{
			return false;
		}

		return true;
	}

	bool DX11Renderer::Render()
	{
		DirectX::XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
		bool result;


		// Clear the buffers to begin the scene.
		m_Direct3D->BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

		// Generate the view matrix based on the camera's position.
		m_Camera->Render();

		// Get the world, view, and projection matrices from the camera and d3d objects.
		m_Direct3D->GetWorldMatrix(worldMatrix);
		m_Camera->GetViewMatrix(viewMatrix);
		m_Direct3D->GetProjectionMatrix(projectionMatrix);

		// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
		m_Model->Render(m_Direct3D->GetDeviceContext());

		// Render the model using the shader.
		result = m_Shader->Render(m_Direct3D->GetDeviceContext(), m_Model->GetIndexCount(), worldMatrix, viewMatrix, projectionMatrix);
		if (!result)
		{
			return false;
		}

		// Present the rendered scene to the screen.
		m_Direct3D->EndScene();

		return true;
	}
}