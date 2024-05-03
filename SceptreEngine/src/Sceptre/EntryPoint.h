#pragma once

#include "Core.h"
#include "ImguiInit.h"
//#include "DX11Renderer.h"
#include "../enginepch.h"
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/backends/imgui_impl_dx11.h"
#include "../vendor/imgui/backends/imgui_impl_win32.h"
#include "../vendor/imgui/backends/imgui_impl_win32.cpp"

#ifdef SC_PLATFORM_WINDOWS

extern SceptreEngine::SceptreGame* SceptreEngine::CreateGame();


int main(int, char**)
{
    // Create application window
    ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_CLASSDC, SceptreEngine::ImguiInit::WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"Sceptre Engine", nullptr };
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"Sceptre Engine", WS_OVERLAPPEDWINDOW, 100, 100, 1280, 720, nullptr, nullptr, wc.hInstance, nullptr);

    SceptreEngine::ImguiInit::ImguiMain(hwnd, wc);
    //SceptreEngine::DX11Renderer::Initialize(1280, 720, hwnd);

    SceptreEngine::ImguiInit::ImguiClean(hwnd, wc);
    return 0;
}
#endif
