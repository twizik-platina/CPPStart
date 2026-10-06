#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int* mas = new int[n];   
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;

    delete[] mas;   
    return 0;
}
