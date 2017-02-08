
#include"Main.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}

	return 0;

}

//DirectX‰Šú‰»ŠÖ”
HRESULT InitD3D(HWND hWnd)
{

	D3DPRESENT_PARAMETERS d3dpp;

	if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		return E_FAIL;
	}

	SecureZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pd3dDevice->LightEnable(0, FALSE);

	return S_OK;

}

//DirectXI—¹ˆ—ŠÖ”
void DestroyD3D(void)
{
	if (g_pd3dDevice != NULL){
		g_pd3dDevice->Release();
	}
	if (g_pD3D != NULL){
		g_pD3D->Release();
	}
}

void wcSet(WNDCLASSEX* wc, HINSTANCE hInstance)
{

	wc->cbSize = sizeof(WNDCLASSEX);
	wc->style = CS_HREDRAW | CS_VREDRAW;
	wc->hInstance = hInstance;
	wc->lpszClassName = "DX21";
	wc->lpfnWndProc = (WNDPROC)WndProc;
	wc->hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc->hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc->hCursor = LoadCursor(NULL, IDC_ARROW);
	wc->hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc->lpszMenuName = NULL;
	wc->cbClsExtra = 0;
	wc->cbWndExtra = 0;

}
