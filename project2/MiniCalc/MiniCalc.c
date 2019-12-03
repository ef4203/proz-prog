#include <Windows.h>

#include "Const.h"
#include "StringHelp.h"

/* Function prototypes. */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void HandleParam(WPARAM);

/* Globally acessable variables. */
HWND mainWindow;
HWND displayWindow;
WCHAR *displayText;

/* Entry point for the Windows API. */
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR args, _In_ int nCmdShow)
{
    /* Register the main window class. */
    WNDCLASSW window = {0};

    window.lpfnWndProc = WndProc;
    window.hInstance = hInstance;
    window.hCursor = LoadCursor(NULL, IDC_ARROW);
    window.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    window.lpszClassName = PROG_WINDOW_NAME;

    if (!RegisterClassW(&window))
        return EXIT_FAILURE;

    /* Create the components. */
    mainWindow =
        CreateWindowW(PROG_WINDOW_NAME, PROG_WINDOW_NAME, WS_OVERLAPPED | WS_MINIMIZEBOX | WS_SYSMENU | WS_VISIBLE, 0,
                      0, PROG_WINDOW_WIDTH, PROG_WINDOW_HEIGHT, NULL, NULL, hInstance, NULL);

    displayWindow =
        CreateWindowW(L"static", L"", WS_VISIBLE | WS_CHILD, CELL_GAP, CELL_GAP,
                      PROG_WINDOW_WIDTH + CELL_GAP - CELL_WIDTH, CELL_WIDTH, mainWindow, NULL, hInstance, NULL);

    CreateWindowW(L"button", L"7", WS_VISIBLE | WS_CHILD, CELL_GAP, CELL_GAP * 2 + CELL_WIDTH, CELL_WIDTH, CELL_WIDTH,
                  mainWindow, BTN_PRESS_SEVEN, hInstance, NULL);
    CreateWindowW(L"button", L"4", WS_VISIBLE | WS_CHILD, CELL_GAP, CELL_GAP * 3 + CELL_WIDTH * 2, CELL_WIDTH,
                  CELL_WIDTH, mainWindow, BTN_PRESS_FOUR, hInstance, NULL);
    CreateWindowW(L"button", L"1", WS_VISIBLE | WS_CHILD, CELL_GAP, CELL_GAP * 4 + CELL_WIDTH * 3, CELL_WIDTH,
                  CELL_WIDTH, mainWindow, BTN_PRESS_ONE, hInstance, NULL);
    CreateWindowW(L"button", L"=", WS_VISIBLE | WS_CHILD, CELL_GAP, CELL_GAP * 5 + CELL_WIDTH * 4, CELL_WIDTH,
                  CELL_WIDTH, mainWindow, BTN_PRESS_EQ, hInstance, NULL);

    CreateWindowW(L"button", L"8", WS_VISIBLE | WS_CHILD, CELL_GAP * 2 + CELL_WIDTH, CELL_GAP * 2 + CELL_WIDTH,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_EIGHT, hInstance, NULL);
    CreateWindowW(L"button", L"5", WS_VISIBLE | WS_CHILD, CELL_GAP * 2 + CELL_WIDTH, CELL_GAP * 3 + CELL_WIDTH * 2,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_FIVE, hInstance, NULL);
    CreateWindowW(L"button", L"2", WS_VISIBLE | WS_CHILD, CELL_GAP * 2 + CELL_WIDTH, CELL_GAP * 4 + CELL_WIDTH * 3,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_TWO, hInstance, NULL);
    CreateWindowW(L"button", L"0", WS_VISIBLE | WS_CHILD, CELL_GAP * 2 + CELL_WIDTH, CELL_GAP * 5 + CELL_WIDTH * 4,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_ZERO, hInstance, NULL);

    CreateWindowW(L"button", L"9", WS_VISIBLE | WS_CHILD, CELL_GAP * 3 + CELL_WIDTH * 2, CELL_GAP * 2 + CELL_WIDTH,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_NINE, hInstance, NULL);
    CreateWindowW(L"button", L"6", WS_VISIBLE | WS_CHILD, CELL_GAP * 3 + CELL_WIDTH * 2, CELL_GAP * 3 + CELL_WIDTH * 2,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_SIX, hInstance, NULL);
    CreateWindowW(L"button", L"3", WS_VISIBLE | WS_CHILD, CELL_GAP * 3 + CELL_WIDTH * 2, CELL_GAP * 4 + CELL_WIDTH * 3,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_THREE, hInstance, NULL);
    CreateWindowW(L"button", L".", WS_VISIBLE | WS_CHILD, CELL_GAP * 3 + CELL_WIDTH * 2, CELL_GAP * 5 + CELL_WIDTH * 4,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_ONE, hInstance, NULL);

    CreateWindowW(L"button", L"/", WS_VISIBLE | WS_CHILD, CELL_GAP * 4 + CELL_WIDTH * 3, CELL_GAP * 2 + CELL_WIDTH,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_DIV, hInstance, NULL);
    CreateWindowW(L"button", L"*", WS_VISIBLE | WS_CHILD, CELL_GAP * 4 + CELL_WIDTH * 3, CELL_GAP * 3 + CELL_WIDTH * 2,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_MUL, hInstance, NULL);
    CreateWindowW(L"button", L"-", WS_VISIBLE | WS_CHILD, CELL_GAP * 4 + CELL_WIDTH * 3, CELL_GAP * 4 + CELL_WIDTH * 3,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_MINUS, hInstance, NULL);
    CreateWindowW(L"button", L"+", WS_VISIBLE | WS_CHILD, CELL_GAP * 4 + CELL_WIDTH * 3, CELL_GAP * 5 + CELL_WIDTH * 4,
                  CELL_WIDTH, CELL_WIDTH, mainWindow, BTN_PRESS_PLUS, hInstance, NULL);

    /* Initialize calculator display. */
    displayText = wstrnew();
    SetWindowTextW(displayWindow, displayText);

    /* Start the message loop. */
    MSG message = {0};
    while (GetMessageW(&message, mainWindow, 0u, 0u))
    {
        TranslateMessage(&message);
        DispatchMessageW(&message);
    }

    free(displayText);
    return EXIT_SUCCESS;
}

/* The window procedure that acts on messages from the main window. */
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        HandleParam(wParam);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

/* Handles the window parameter. */
void HandleParam(WPARAM wParam)
{
    switch (wParam)
    {
    case BTN_PRESS_ONE:
        wstrapp(&displayText, L"1");
        SetWindowTextW(displayWindow, displayText);
        break;

    case BTN_PRESS_TWO:
        wstrapp(&displayText, L"2");
        SetWindowTextW(displayWindow, displayText);
        break;

    case BTN_PRESS_THREE:
        wstrapp(&displayText, L"3");
        SetWindowTextW(displayWindow, displayText);
        break;

    case BTN_PRESS_FOUR:
        wstrapp(&displayText, L"4");
        SetWindowTextW(displayWindow, displayText);
        break;

    default:
        break;
    }
}
