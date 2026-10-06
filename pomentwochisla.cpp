#include <iostream>
using namespace std;

void swap_values(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10, b = 20;

    cout << "До: a = " << a << ", b = " << b << endl;
    swap_values(&a, &b);
    cout << "После: a = " << a << ", b = " << b << endl;

    return 0;
}
