//Header
#include<windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//WinMain()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
	//variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("MyApp");

	//code
	//initialization of WNDCLASSEX
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	//register above class
	RegisterClassEx(&wndclass);

	//create window
	hwnd = CreateWindow(szAppName,
		TEXT("My Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	//messageloop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	//code
	TCHAR str[255];
	switch (iMsg)
	{
	case WM_CREATE:
		wsprintf(str,TEXT("WM_CREATE HAS ARRIVED"));
		MessageBox(hwnd, str, TEXT("Message"), MB_OK);
		break;
	}
	switch (iMsg)
	{
	case WM_LBUTTONDOWN:
		wsprintf(str, TEXT("LBUTTON DOWN HAS ARRIVED"));
		MessageBox(hwnd, str, TEXT("message"), MB_OK);
		break;
	}
	switch (iMsg)
	{
	case WM_KEYDOWN:
		wsprintf(str, TEXT("key down"));
		MessageBox(hwnd, str, TEXT("message box"), MB_OK);
		break;
	}
	switch (iMsg)
	{
	case WM_CLOSE:
		wsprintf(str, TEXT("BAND KELAY RE"));
		MessageBox(hwnd, str, TEXT("bagh re"), MB_OK);
		break;
	}

	switch (iMsg)
	{
		case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}