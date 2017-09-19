
#include <string>
#include "Initialiaztion.h"

int main()
{
	INT WINAPI GameCode4

	(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		LPWSTR lpCmdLine,
		int nCmdShow
	)

		{
			int tmpDbgFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
			tmpDbgFlag j = _CRTDBG_LEAK_CHECK_DF;
			_CrtSetDbgFlag(tmpDbgFlag);


			g_pApp->m_Options.Init("PlayerOptions.xml", lpCmdLine);

			if (g_pApp->m_Options.m_Renderer == "Direct3D 11")
			{
				DXUTSetCallbackD3D11DeviceAcceptable(GameCodeApp::IsD3D11DeviceAcceptable);
				DXUTSetCallbackD3D11DeviceCreated(GameCodeApp::OnD3D11CreateDevice);
				DXUTSetCallbackD3D11DeviceReset(GameCodeApp::OnD3D11ResetDevice);
				DXUTSetCallbackD3D11DeviceLost(GameCodeApp::OnD3D11LostDevice);
				DXUTSetCallbackD3D11DeviceDestroyed(GameCodeApp::OnD3D11DestroyDevice);
				DXUTSetCallbackD3D11FrameRender(GameCodeApp::OnD3D11FrameRender);
			}
			else if (g_pApp->m_Options.m_Renderer == "Direct3D 12")
			{
				DXUTSetCallbackD3D12DeviceAcceptable(GameCodeApp::IsD3D12DeviceAcceptable);
				DXUTSetCallbackD3D12DeviceCreated(GameCodeApp::OnD3D12CreateDevice);
				DXUTSetCallbackD3D12SwapChainResized(GameCodeApp::OnD3D12ResizedSwapChain);
				DXUTSetCallbackD3D12SwapChainReleasing(GameCodeApp::OnD3D12ReleasingSwapChain);
				DXUTSetCallbackD3D12DeviceDestroyed(GameCodeApp::OnD3D12DestroyDevice);
				DXUTSetCallbackD3D12FrameRender(GameCodeApp::OnD3D12FrameRender);
			}
			else
			{
				GCC_ASSERT(0 && "Unknown renderer specified in game options.");
				return false;
			}

			if (!g_pApp->InitInstance(hInstance, lpCmdLine, 0,
				g_pApp->m_Options.m_ScreenSize.x, g_pApp->m_Options.m_ScreenSize.y))
			{
				return FALSE;
			}

		}
}


