#include <iostream>
#include <Windows.h>
#include <cstdlib>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    srand(GetTickCount());

    cout << "Переключись на нужное окно.\n";
    cout << "У тебя есть 3 секунды...\n";
    Sleep(3000);

    HWND activeWindow = GetForegroundWindow();

    RECT rect;
    GetWindowRect(activeWindow, &rect);

    int x = rect.left;
    int y = rect.top;

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            x = rand() % (screenWidth - windowWidth);
            y = rand() % (screenHeight - windowHeight);

            SetWindowPos(activeWindow, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
            Sleep(200);
        }

        Sleep(10);
    }

    return 0;
}
