#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int price;
    int total = 0;
    int expensiveCount = 0;

    for (int i = 1; i <= 5; i++) {
        printf("Введите стоимость товара: ");
        scanf("%d", &price);

        total = total + price;

        if (price > 1000) {
            expensiveCount = expensiveCount + 1;
        }
    }

    printf("Общая стоимость: %d рублей\n", total);
    printf("Товаров дороже 1000 рублей: %d\n", expensiveCount);

    return 0;
}
