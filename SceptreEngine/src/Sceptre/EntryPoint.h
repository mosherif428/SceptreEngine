#pragma once

#include "Core.h"
#include "ImguiInit.h"
#include "DX11Renderer.h"
#include "../enginepch.h"
#include "../vendor/imgui/imgui.h"
#include "../vendor/imgui/backends/imgui_impl_dx11.h"
#include "../vendor/imgui/backends/imgui_impl_win32.h"
#include "../vendor/imgui/backends/imgui_impl_win32.cpp"

#ifdef SC_PLATFORM_WINDOWS

extern SceptreEngine::SceptreGame* SceptreEngine::CreateGame();


int main(int, char**)
{
    HWND hwnd = nullptr;
    WNDCLASSEXW wc{};
    SceptreEngine::ImguiInit::ImguiMain(hwnd, wc);
    SceptreEngine::DX11Renderer::Initialize(1280, 720, hwnd);

    SceptreEngine::ImguiInit::ImguiClean(hwnd, wc);
    return 0;
}
#endif
