#pragma once

#include "../Core.h"
#include "../../enginepch.h"
#include "Camera.h"
#include "Shader.h"

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")


namespace SceptreEngine
{
	class SCEPTRE_API Direct3D
	{
    public:
        Direct3D();
        Direct3D(const Direct3D&);
        ~Direct3D();

        bool Initialize(int, int, bool, HWND, bool, float, float);
        void Shutdown();

        void BeginScene(float, float, float, float);
        void EndScene();

        ID3D11Device* GetDevice();
        ID3D11DeviceContext* GetDeviceContext();

        void GetProjectionMatrix(DirectX::XMMATRIX&);
        void GetWorldMatrix(DirectX::XMMATRIX&);
        void GetOrthoMatrix(DirectX::XMMATRIX&);

        void GetVideoCardInfo(char*, int&);

        void SetBackBufferRenderTarget();
        void ResetViewport();

    private:
        bool m_vsync_enabled;
        int m_videoCardMemory;
        char m_videoCardDescription[128];
        IDXGISwapChain* m_swapChain;
        ID3D11Device* m_device;
        ID3D11DeviceContext* m_deviceContext;
        ID3D11RenderTargetView* m_renderTargetView;
        ID3D11Texture2D* m_depthStencilBuffer;
        ID3D11DepthStencilState* m_depthStencilState;
        ID3D11DepthStencilView* m_depthStencilView;
        ID3D11RasterizerState* m_rasterState;
        DirectX::XMMATRIX m_projectionMatrix;
        DirectX::XMMATRIX m_worldMatrix;
        DirectX::XMMATRIX m_orthoMatrix;
        D3D11_VIEWPORT m_viewport;
	};
}



