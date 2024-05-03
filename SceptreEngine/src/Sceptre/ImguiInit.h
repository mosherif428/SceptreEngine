#pragma once

#include "../enginepch.h"
#include "Core.h"
#include "Engine.h"
#include "../vendor/imgui/backends/imgui_impl_win32.h"
#include "../vendor/imgui/backends/imgui_impl_dx11.h"

namespace SceptreEngine
{
	// Data
	static ID3D11Device* g_pd3dDevice = nullptr;
	static ID3D11DeviceContext* g_pd3dDeviceContext = nullptr;
	static IDXGISwapChain* g_pSwapChain = nullptr;
	static UINT                     g_ResizeWidth = 0, g_ResizeHeight = 0;
	static ID3D11RenderTargetView* g_mainRenderTargetView = nullptr;

	// Forward declarations of helper functions
	bool SC_EXPORT_API CreateDeviceD3D(HWND hWnd);
	void SC_EXPORT_API CleanupDeviceD3D();
	void SC_EXPORT_API CreateRenderTarget();
	void SC_EXPORT_API CleanupRenderTarget();
	LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	class SCEPTRE_API ImguiInit
	{
	public:
		static int ImguiMain(HWND hwnd, WNDCLASSEXW wc);
		static void ImguiClean(HWND hwnd, WNDCLASSEXW wc);
	};
}