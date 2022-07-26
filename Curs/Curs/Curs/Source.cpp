#define _CRT_SECURE_NO_WARNINGS
#include <windows.h> // ���������� �������� � ��������� API
//#include "time.h"
#include "resource.h"

// �������� ����:
PAINTSTRUCT ps;
MSG msg;
HDC hdc;
LOGFONT font;
HFONT fonts;
HINSTANCE hInst; 	//���������� ��������	
LPCTSTR szWindowClass = "QWERTY";
LPCTSTR szTitle = "��������i ���i";
HWND hWnd;
int T1[8] = { 8,7,6,5,4,3,2,1 };
int T2[8] = { 0,0,0,0,0,0,0,0 };
int T3[8] = { 0,0,0,0,0,0,0,0 };
int  i = 0, k, j;
//time_t c = clock();
// ��������� ���� �������

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine,
	int nCmdShow)
{
	MSG msg;

	// ��������� ����� ���� 
	MyRegisterClass(hInstance);

	// ��������� ���� ��������
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}
	// ���� ������� ����������
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW; 		//����� ����
	wcex.lpfnWndProc = (WNDPROC)WndProc; 		//������ ���������
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 			//���������� ��������
	wcex.hIcon = LoadIcon(NULL, IDI_HAND); 		//���������� ������
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW); 	//���������� �������
	wcex.hbrBackground = GetSysColorBrush(COLOR_WINDOW + 1); //��������� ����
	wcex.lpszMenuName = NULL; 				//���������� ����
	wcex.lpszClassName = szWindowClass; 		//��� �����
	wcex.hIconSm = NULL;

	return RegisterClassEx(&wcex); 			//��������� ����� ����
}

// FUNCTION: InitInstance (HANDLE, int)
// ������� ���� �������� � ������ ���������� �������� � ����� hInst

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	hInst = hInstance; //������ ���������� ������� � ����� hInst
	hWnd = CreateWindow(szWindowClass, 	// ��� ����� ����
		szTitle, 				// ����� ��������
		WS_OVERLAPPEDWINDOW,			// ����� ����
		300, 			// ��������� �� �	
		100,			// ��������� �� Y	
		400, 			// ����� �� �
		350, 			// ����� �� Y
		NULL, 					// ���������� ������������ ����	
		NULL, 					// ���������� ���� ����
		hInstance, 				// ���������� ��������
		NULL); 				// ��������� ���������.

	if (!hWnd) 	//���� ���� �� ���������, ������� ������� FALSE
	{
		return FALSE;
	}
	HWND b12 = CreateWindow(
      "BUTTON",  // Predefined class; Unicode assumed 
      "1>>2",      // Button text 
      WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
      65,         // x position 
      255,         // y position 
      70,        // Button width
      20,        // Button height
      hWnd,     // Parent window
      (HMENU)1001,       // No menu.
      hInstance,
      NULL);
	HWND b13 = CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed 
		"1>>3",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
		65,         // x position 
		280,         // y position 
		70,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		(HMENU)1002,       // No menu.
		hInstance,
		NULL);
	HWND b21 = CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed 
		"2>>1",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
		165,         // x position 
		255,         // y position 
		70,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		(HMENU)1003,       // No menu.
		hInstance,
		NULL);
	HWND b23 = CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed 
		"2>>3",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
		165,         // x position 
		280,         // y position 
		70,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		(HMENU)1004,       // No menu.
		hInstance,
		NULL);
	HWND b31 = CreateWindow(
      "BUTTON",  // Predefined class; Unicode assumed 
      "3>>1",      // Button text 
      WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
      265,         // x position 
      255,         // y position 
      70,        // Button width
      20,        // Button height
      hWnd,     // Parent window
      (HMENU)1005,       // No menu.
      hInstance,
      NULL);
	HWND b32 = CreateWindow(
		"BUTTON",  // Predefined class; Unicode assumed 
		"3>>2",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,  // Styles 
		265,         // x position 
		280,         // y position 
		70,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		(HMENU)1006,       // No menu.
		hInstance,
		NULL);
	ShowWindow(hWnd, nCmdShow); 		//�������� ����
	UpdateWindow(hWnd); 				//������� ����
	
	return true;
	
}



// FUNCTION: WndProc (HWND, unsigned, WORD, LONG)
// ³����� ���������. ������ � �������� �� �����������, �� ��������� � �������


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	
	static int count = 0;
	switch (message)
	{
	case WM_CREATE: 				//����������� ��������� ��� �������� ����
		break;
	case WM_PAINT:{ 				//������������ ����
		HDC hdc = BeginPaint(hWnd, &ps);
		HDC hdc_x = CreateCompatibleDC(NULL);
		HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, "bitmap1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap1 = (HBITMAP)LoadImage(NULL, "bitmap01.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap2 = (HBITMAP)LoadImage(NULL, "bitmap02.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap3 = (HBITMAP)LoadImage(NULL, "bitmap03.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap4 = (HBITMAP)LoadImage(NULL, "bitmap04.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap5 = (HBITMAP)LoadImage(NULL, "bitmap05.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap6 = (HBITMAP)LoadImage(NULL, "bitmap06.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap7 = (HBITMAP)LoadImage(NULL, "bitmap07.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		HBITMAP hBitmap8 = (HBITMAP)LoadImage(NULL, "bitmap08.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		SelectObject(hdc_x, hBitmap);
		RECT rect;
		GetWindowRect(hWnd, &rect);
		BitBlt(hdc, 0, 0, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
		//time_t t = clock() - c;
		RECT rt;
		GetClientRect(hWnd, &rt);
		char text[50] = { '\0' };
		_itoa(i, text, 10);//��������� ����� � ������
		TextOutA(hdc, 55, 0, text, strlen(text));
		/*switch (T2[0]) {
		case 0:strcpy(text, "0");//�
			break;
		case 1:strcpy(text, "1");//�
			break;
		case 2:strcpy(text, "2");//�
			break;
		case 3:strcpy(text, "3");//�
			break;
		case 4:strcpy(text, "4");//�
			break;
		case 5:strcpy(text, "5");//�
			break;
		case 6:strcpy(text, "6");//�
			break;
		case 7:strcpy(text, "7");//�
			break;
		case 8:strcpy(text, "8");//�
			break;
		} */
		DrawText(hdc, "����:", -1, &rt, DT_SINGLELINE | DT_TOP | DT_LEFT);
		j = 0;
		for (k = 7; k >= 0; k--)
		{
			switch (T1[k])
			{
			case 1: {
				SelectObject(hdc_x, hBitmap1);
				BitBlt(hdc, 85, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 2: {
				SelectObject(hdc_x, hBitmap2);
				BitBlt(hdc, 80, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 3: {
				SelectObject(hdc_x, hBitmap3);
				BitBlt(hdc, 75, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 4: {
				SelectObject(hdc_x, hBitmap4);
				BitBlt(hdc, 70, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 5: {
				SelectObject(hdc_x, hBitmap5);
				BitBlt(hdc, 65, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 6: {
				SelectObject(hdc_x, hBitmap6);
				BitBlt(hdc, 60, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 7: {
				SelectObject(hdc_x, hBitmap7);
				BitBlt(hdc, 55, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 8: {
				SelectObject(hdc_x, hBitmap8);
				BitBlt(hdc, 50, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
					break;
			}
			j++;
		}
		j = 0;
		for (k = 7; k >= 0; k--)
		{
			switch (T2[k])
			{
			case 1: {
				SelectObject(hdc_x, hBitmap1);
				BitBlt(hdc, 185, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 2: {
				SelectObject(hdc_x, hBitmap2);
				BitBlt(hdc, 180, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 3: {
				SelectObject(hdc_x, hBitmap3);
				BitBlt(hdc, 175, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 4: {
				SelectObject(hdc_x, hBitmap4);
				BitBlt(hdc, 170, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 5: {
				SelectObject(hdc_x, hBitmap5);
				BitBlt(hdc, 165, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 6: {
				SelectObject(hdc_x, hBitmap6);
				BitBlt(hdc, 160, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 7: {
				SelectObject(hdc_x, hBitmap7);
				BitBlt(hdc, 155, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 8: {
				SelectObject(hdc_x, hBitmap8);
				BitBlt(hdc, 150, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
					break;
			}
			j++;
		}
		j = 0;
		for (k = 7; k >= 0; k--)
		{
			switch (T3[k])
			{
			case 1: {
				SelectObject(hdc_x, hBitmap1);
				BitBlt(hdc, 285, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 2: {
				SelectObject(hdc_x, hBitmap2);
				BitBlt(hdc, 280, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 3: {
				SelectObject(hdc_x, hBitmap3);
				BitBlt(hdc, 275, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 4: {
				SelectObject(hdc_x, hBitmap4);
				BitBlt(hdc, 270, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 5: {
				SelectObject(hdc_x, hBitmap5);
				BitBlt(hdc, 265, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 6: {
				SelectObject(hdc_x, hBitmap6);
				BitBlt(hdc, 260, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 7: {
				SelectObject(hdc_x, hBitmap7);
				BitBlt(hdc, 255, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
			case 8: {
				SelectObject(hdc_x, hBitmap8);
				BitBlt(hdc, 250, 90 + 20 * j, rect.right - rect.left, 400, hdc_x, 0, 0, SRCCOPY);
				break;
			}
					break;
			}
			j++;
		}
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_COMMAND:
	
		switch (LOWORD(wParam))
		{
		case 1001://1-2
			for (k = 7; k >= 0; k--)
			{
				if (T1[k] != 0)
				{
					for (j = 0; j <= 7; j++)
					{
						if (T2[j] == 0)
						{
							if ((j == 0) || (T2[j - 1]>T1[k]))
							{
								T2[j] = T1[k];
								T1[k] = 0;
								i++;
								break;
							}
						}
					}
				}
			}
			InvalidateRect(hWnd, 0, NULL);
			UpdateWindow(hWnd); 				//������� ����
			break;
		case 1002://1-3
			for (k = 7; k >= 0; k--)
			{
				if (T1[k] != 0)
				{
					for (j = 0; j <= 7; j++)
					{
						if (T3[j] == 0)
						{
							if ((j == 0) || (T3[j - 1]>T1[k]))
							{
								T3[j] = T1[k];
								T1[k] = 0;
								i++;
								break;
							}
						}
					}
				}
			}
			InvalidateRect(hWnd, 0, NULL);
			UpdateWindow(hWnd); 				//������� ����
			break;
		case 1003://2-1
			for (k = 7; k >= 0; k--)
			{
				if (T2[k] != 0)
				{
					for (j = 0; j <= 7; j++)
					{
						if (T1[j] == 0)
						{
							if ((j == 0) || (T1[j - 1]>T2[k]))
							{
								T1[j] = T2[k];
								T2[k] = 0;
								i++;
								break;
							}
						}
					}
				}
			}
			InvalidateRect(hWnd, 0, NULL);
			UpdateWindow(hWnd); 				//������� ����
			break;
		case 1004://2-3
			for (k = 7; k >= 0; k--)
			{
				if (T2[k] != 0)
				{
					for (j = 0; j <= 7; j++)
					{
						if (T3[j] == 0)
						{
							if ((j == 0) || (T3[j - 1]>T2[k]))
							{
								T3[j] = T2[k];
								T2[k] = 0;
								i++;
								break;
							}
						}
					}
				}
			}
			InvalidateRect(hWnd, 0, NULL);
			UpdateWindow(hWnd); 				//������� ����
			break;
		case 1005://3-1
			for (k = 7; k >= 0; k--)
			{
				if (T3[k] != 0)
				{
					for (j = 0; j <= 7; j++)
					{
						if (T1[j] == 0)
						{
							if ((j == 0) || (T1[j - 1]>T3[k]))
							{
								T1[j] = T3[k];
								T3[k] = 0;
								i++;
								break;
							}
						}
					}
				}
			}
			InvalidateRect(hWnd, 0, NULL);
			UpdateWindow(hWnd); 				//������� ����
			break;
		case 1006://3-2
			for (k = 7; k >= 0; k--)
			{
				if (T3[k] != 0)
				{
					for (j = 0; j <= 7; j++)
					{
						if (T2[j] == 0)
						{
							if ((j == 0) || (T2[j - 1]>T3[k]))
							{
								T2[j] = T3[k];
								T3[k] = 0;
								i++;
								break;
							}
						}
					}
				}
			}
			InvalidateRect(hWnd, 0, NULL);
			UpdateWindow(hWnd); 				//������� ����
			break;
		}
		break;
	case WM_DESTROY: 				//���������� ������
		PostQuitMessage(0);
		break;
	default:
		//������� ����������, �� �� �������� ������������
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
