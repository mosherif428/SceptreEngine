#pragma once

#include "../Core.h"
#include "../../enginepch.h"

namespace SceptreEngine
{
	class SCEPTRE_API Camera
	{
	public:
		Camera();
		Camera(const Camera&);
		~Camera();

		void SetPosition(float x, float y, float z);
		void SetRotation(float x, float y, float z);

		DirectX::XMFLOAT3 GetPosition();
		DirectX::XMFLOAT3 GetRotation();

		void Render();
		void GetViewMatrix(DirectX::XMMATRIX& viewMatrix);

	private:

		float m_positionX, m_positionY, m_positionZ;
		float m_rotationX, m_rotationY, m_rotationZ;
		DirectX::XMMATRIX m_viewMatrix;
	};

}

