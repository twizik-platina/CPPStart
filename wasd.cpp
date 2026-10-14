#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "Переключись на нужное окно.\n";
    cout << "У тебя есть 3 секунды...\n";
    Sleep(3000);

    HWND activeWindow = GetForegroundWindow();

    RECT rect;
    GetWindowRect(activeWindow, &rect);

    int x = rect.left;
    int y = rect.top;

    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        if (GetAsyncKeyState('W') & 0x8000)
            y -= 5;

        if (GetAsyncKeyState('A') & 0x8000)
            x -= 5;

        if (GetAsyncKeyState('S') & 0x8000)
            y += 5;

        if (GetAsyncKeyState('D') & 0x8000)
            x += 5;

        SetWindowPos(activeWindow, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        Sleep(10);
    }

    return 0;
}
