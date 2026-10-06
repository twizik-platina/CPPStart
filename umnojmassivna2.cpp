#include <iostream>
using namespace std;

void mas_x2(int* mas, int n) {
    for (int i = 0; i < n; i++) {
        mas[i] *= 2;   
    }
}

int main() {
    int mas[5] = {1, 2, 3, 4, 5};

    mas_x2(mas, 5);

    for (int i = 0; i < 5; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;  

    return 0;
}
