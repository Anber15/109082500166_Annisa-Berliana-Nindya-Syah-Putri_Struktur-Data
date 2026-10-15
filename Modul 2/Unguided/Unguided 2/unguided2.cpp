#include <iostream>
using namespace std;

void pointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void reference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 10, b = 20, c = 30;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    pointer(&a, &b, &c);

    cout << "\nPointer:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    a = 10;
    b = 20;
    c = 30;

    reference(a, b, c);

    cout << "\nReference:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}