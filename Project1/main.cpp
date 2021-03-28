#include <iostream>  
#include <Windows.h>  
#include <conio.h>
using namespace std;

LRESULT CALLBACK WindowsProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hCurrentInstance, _In_opt_ HINSTANCE hPreviousInstance, PSTR cmdLine, int cmdCount) {
	//register the window calss
	const char* CLASS_NAME = "mywin32Class";

	WNDCLASS wc{};


	wc.hInstance = hCurrentInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowsProcessMessages;
	RegisterClass(&wc);

	CreateWindow(CLASS_NAME, "Win32 Titleeeeeee",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600,
		nullptr, nullptr, nullptr, nullptr
		);




	MSG msg{};

	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return 0;
}
#define _L LPCSTR
LRESULT CALLBACK WindowsProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam) {
	switch (msg) {
	case WM_CLOSE:
		if (MessageBox(hwnd, (_L)("真的要關嗎?"), (_L)(""), MB_OKCANCEL | MB_ICONEXCLAMATION) == IDOK) {
			MessageBox(hwnd, (_L)("Fuck Q"), (_L)(""), NULL);
			DestroyWindow(hwnd);
		}
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_LBUTTONDOWN:
		int msgbox = MessageBox(hwnd, (LPCSTR)("Context"), (LPCSTR)("This is title"), MB_OKCANCEL | MB_ICONEXCLAMATION);
		if (msgbox == IDOK) {
			MessageBox(hwnd, (LPCSTR)("OK三小"), "", MB_ICONQUESTION);
		}
	}
	return DefWindowProc(hwnd, msg, param, lparam);
}
