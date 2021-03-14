#include <windows.h>

LRESULT CALLBACK WindowsProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam);

int WINAPI WinMain(HINSTANCE hCurrentInstance, HINSTANCE hPreviousInstance, PSTR cmdLine, int cmdCount) {
	//register the window calss
	const char* CLASS_NAME = "mywin32Class";
	
	WNDCLASS wc{};


	wc.hInstance = hCurrentInstance;
	wc.lpszClassName = CLASS_NAME;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowsProcessMessages;
	RegisterClass(&wc);

	CreateWindow(CLASS_NAME, "Win32 ttt",
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

LRESULT CALLBACK WindowsProcessMessages(HWND hwnd, UINT msg, WPARAM param, LPARAM lparam) {
	switch (msg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hwnd, msg, param, lparam);
	}
}