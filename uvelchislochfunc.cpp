#include <iostream>
using namespace std;

void plus_one(int* a) {
    (*a)++;   
}

int main() {
    int a = 5;
    plus_one(&a);   
    cout << a << endl;  
    return 0;
}
