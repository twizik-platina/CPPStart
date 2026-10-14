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

    while (true)
    {
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        if (GetAsyncKeyState('1') & 0x8000)
            SetWindowTextW(activeWindow, L"Player");

        if (GetAsyncKeyState('2') & 0x8000)
            SetWindowTextW(activeWindow, L"Boss");

        if (GetAsyncKeyState('3') & 0x8000)
            SetWindowTextW(activeWindow, L"IT-PARK");

        Sleep(10);
    }

    return 0;
}
