#include <iostream>
using namespace std;

// By Pointer
void tukarPointer(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// By Reference
void tukarReference(int &x, int &y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

// By Value
void tukarValue(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;

    // By Pointer
    a = 4;
    b = 6;

    cout << "=== By Pointer ===" << endl;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukarPointer(&a, &b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    // By Reference
    a = 4;
    b = 6;

    cout << "\n=== By Reference ===" << endl;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukarReference(a, b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    // By Value
    a = 4;
    b = 6;

    cout << "\n=== By Value ===" << endl;
    cout << "Sebelum ditukar: a = " << a << ", b = " << b << endl;

    tukarValue(a, b);

    cout << "Setelah ditukar: a = " << a << ", b = " << b << endl;

    return 0;
}
