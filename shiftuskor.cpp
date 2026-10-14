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

        int speed = 5;

        if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
            speed = 20;

        if (GetAsyncKeyState(VK_LEFT) & 0x8000)
            x -= speed;

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
            x += speed;

        if (GetAsyncKeyState(VK_UP) & 0x8000)
            y -= speed;

        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
            y += speed;

        SetWindowPos(activeWindow, NULL, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        Sleep(10);
    }

    return 0;
}
