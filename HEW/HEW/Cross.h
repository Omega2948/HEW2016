#pragma once

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HRESULT InitD3D(HWND);

void wcSet(WNDCLASSEX* wc, HINSTANCE hInstance);
void DestroyD3D(void);
