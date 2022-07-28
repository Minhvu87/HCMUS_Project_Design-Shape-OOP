// BaiTap_Lon.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include<math.h>
#include<iostream>
#include"Point.h"
#include"CShape.h"
#include"DaGiac.h"
#include"Ellipse.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Square.h"
#include"Triangle.h"
#include "BaiTap_Lon.h"

#define MAX_LOADSTRING 100
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
enum BUTTON_ID { H_Ellipse, H_Circle, H_Rectangle, H_Square, H_Triangle, H_Polygon,
    H1_Ellipse, H1_Circle, H1_Rectangle, H1_Square, H1_Triangle, H1_Polygon
};
struct ButtonMap
{
    BUTTON_ID id;
    const TCHAR *name;
};
static ButtonMap aMapTab[] =
{
    H_Ellipse, L"Ellipse",
    H_Circle, L"Circle",
    H_Rectangle, L"Rectangle",
    H_Square, L"Square",
    H_Triangle,L"Triangle",
    H_Polygon,L"Polygon",
    H1_Ellipse, L"Ellipse",
    H1_Circle, L"Circle",
    H1_Rectangle, L"Rectangle",
    H1_Square, L"Square",
    H1_Triangle,L"Triangle",
    H1_Polygon,L"Polygon"
};
#define dim(a)(sizeof(a)/size(a[0]))
// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    
    // TODO: Place code here.
    
    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BAITAPLON, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAITAPLON));

    MSG msg;
    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAITAPLON));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_BAITAPLON);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Store instance handle in our global variable
    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
    

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId;
    PAINTSTRUCT ps;
    HDC hdc;
    static CShape* aS[] = {
        new CEllipse(400,250,200,100),
        new CCircle(300, 300, 150),
        new CRectangle(200,200,300,200),
        new CSquare(100,100,200),
        new CTriangle(100,200,200,400,300,200),
        new CDaGiac(5),
    };
    static int h = 0;
    static int h1 = 0;
    static int temp = h;
    const int n = sizeof(aS) / sizeof(aS[0]);
    int g = 5;
    static CShape* pS = aS[h];
    static CShape* pS1 = aS[h1];
    static BUTTON_ID iFigureRadio = H_Ellipse,iFigureRadio1=H1_Ellipse;
    RECT rt;
    switch (message)
    {

    case WM_CREATE:
        //CreateWindow(TEXT("button"), TEXT("Choose Object 1"), WS_VISIBLE|WS_CHILD, 10, 10, 10, 180,hWnd,(HMENU)0,hInst,NULL);
        CreateWindow(TEXT("button"), TEXT("Ellipse"),WS_VISIBLE|WS_CHILD|BS_AUTORADIOBUTTON, 20, 10, 100, 30,hWnd, (HMENU)aMapTab[0].id,hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Circle"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 20, 35, 100, 30, hWnd, (HMENU)aMapTab[1].id,hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Rectangle"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 20, 60, 100, 30, hWnd, (HMENU)aMapTab[2].id,hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Square"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 20, 85, 100, 30, hWnd, (HMENU)aMapTab[3].id,hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Triangle"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 20, 110, 100, 30, hWnd, (HMENU)aMapTab[4].id,hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Polygon"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 20, 135, 100, 30, hWnd, (HMENU)aMapTab[5].id,hInst, NULL);

        CreateWindow(TEXT("button"), TEXT("Ellipse"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 120, 10, 100, 30, hWnd, (HMENU)aMapTab[6].id, hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Circle"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 120, 35, 100, 30, hWnd, (HMENU)aMapTab[7].id, hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Rectangle"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 120, 60, 100, 30, hWnd, (HMENU)aMapTab[8].id, hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Square"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 120, 85, 100, 30, hWnd, (HMENU)aMapTab[9].id, hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Triangle"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 120, 110, 100, 30, hWnd, (HMENU)aMapTab[10].id, hInst, NULL);
        CreateWindow(TEXT("button"), TEXT("Polygon"), WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON, 120, 135, 100, 30, hWnd, (HMENU)aMapTab[11].id, hInst, NULL);
        GetClientRect(hWnd, &rt);
        {
            Point A(100, 200);
            Point B(300, 200);
            Point C(400, 300);
            Point D(50, 300);
            Point E(60, 250);
            dynamic_cast<CDaGiac*>(aS[g])->addPoint(A);
            dynamic_cast<CDaGiac*>(aS[g])->addPoint(B);
            dynamic_cast<CDaGiac*>(aS[g])->addPoint(C);
            dynamic_cast<CDaGiac*>(aS[g])->addPoint(D);
            dynamic_cast<CDaGiac*>(aS[g])->addPoint(E);
        }
        
        break;

    case WM_COMMAND:
    {
        wmId = LOWORD(wParam);
        // Parse the menu selections:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        
        case H_Ellipse:case H_Circle:case H_Rectangle:case H_Square:case H_Triangle:case H_Polygon:
            if (iFigureRadio != wmId)
            {
                iFigureRadio = (BUTTON_ID)wmId;
                InvalidateRect(hWnd, NULL, TRUE);
                CheckRadioButton(hWnd, H_Circle, H_Polygon, iFigureRadio);
                h = iFigureRadio - H_Ellipse;
                pS = aS[h];
                InvalidateRect(hWnd, NULL, TRUE);
            }
            
            break;
        case H1_Ellipse:case H1_Circle:case H1_Rectangle:case H1_Square:case H1_Triangle:case H1_Polygon:
            if (iFigureRadio1 != wmId)
            {
                iFigureRadio1 = (BUTTON_ID)wmId;
                InvalidateRect(hWnd, NULL, TRUE);
                CheckRadioButton(hWnd, H1_Circle, H1_Polygon, iFigureRadio1);
                h1 = iFigureRadio1 - H1_Ellipse;
                pS1 = aS[h1];
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }

    }
    break;

    case WM_CHAR:
        switch (TCHAR(wParam))
        {
        case '+':
            pS->Scale(1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '-':
            pS->Scale(1 / 1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case'*':
            pS1->Scale(1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case'/':
            pS1->Scale(1 / 1.2);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '4':
            pS1->move(-10, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '6':
            pS1->move(10, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '8':
            pS1->move(0, -10);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case '2':
            pS1->move(0, 10);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_LEFT:
            pS->move(-10, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_RIGHT:
            pS->move(10, 0);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_UP:
            pS->move(0, -10);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        case VK_DOWN:
            pS->move(0, 10);
            InvalidateRect(hWnd, NULL, TRUE);
            break;
        }
        break;
    case WM_PAINT:
    {
        hdc = BeginPaint(hWnd, &ps);
        HBRUSH hbr,hbr1;
        HPEN hpen;
        hbr = CreateSolidBrush(RGB(0, 255, 255));
        hbr1 = CreateSolidBrush(RGB(255, 0, 0));
        hpen = CreatePen(PS_DOT, 4, RGB(255, 255, 0));
        SelectObject(hdc, hpen);
        SetROP2(hdc, R2_NOTXORPEN);
        SelectObject(hdc, hbr);
        pS->draw(hdc);
        SelectObject(hdc, hbr1);
        pS1->draw(hdc);
        

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
