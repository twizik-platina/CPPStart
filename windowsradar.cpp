#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

int eventCount = 0;
std::wstring lastWindowTitle = L"";

std::string getCurrentTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
    return buf;
}

void CALLBACK WinEventProc(
    HWINEVENTHOOK hWinEventHook,
    DWORD event,
    HWND hwnd,
    LONG idObject,
    LONG idChild,
    DWORD dwEventThread,
    DWORD dwmsEventTime)
{
    if (idObject != OBJID_WINDOW || hwnd == NULL) return;

    wchar_t windowTitle[256];
    GetWindowTextW(hwnd, windowTitle, 256);

    std::wstring currentTitle(windowTitle);

    if (currentTitle.empty()) return;

    if (currentTitle == lastWindowTitle) {
        return;
    }
    lastWindowTitle = currentTitle;

    eventCount++;

    std::string titleStr(currentTitle.begin(), currentTitle.end());
    std::string timeStr = getCurrentTime();

    std::cout << "Событие №" << eventCount << "\n";
    std::cout << "Время: " << timeStr << "\n";
    std::cout << "Активное окно: " << titleStr << "\n\n";

    std::ofstream logFile("events.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << timeStr << " | " << titleStr << "\n";
        logFile.close();
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    std::cout << "== WINDOWS EVENT MONITOR ==\n";
    std::cout << "Программа запущена. Ожидание событий...\n\n";

    HWINEVENTHOOK hook = SetWinEventHook(
        EVENT_SYSTEM_FOREGROUND,
        EVENT_SYSTEM_FOREGROUND,
        NULL,
        WinEventProc,
        0, 0,
        WINEVENT_OUTOFCONTEXT
    );

    if (hook == NULL) {
        std::cout << "Ошибка установки хука!\n";
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWinEvent(hook);
    return 0;
}
