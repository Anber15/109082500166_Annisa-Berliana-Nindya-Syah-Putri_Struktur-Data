#include <iostream>
using namespace std;

int main() {
    float x, y;
    
    cout << "Masukkan bilangan pertama: ";
    cin >> x;
    cout << "Masukkan bilangan kedua: ";
    cin >> y;
    
    cout << "\n--- Hasil Operasi ---" << endl;
    cout << "Penjumlahan: " << x << " + " << y << " = " << x + y << endl;
    cout << "Pengurangan: " << x << " - " << y << " = " << x - y << endl;
    cout << "Perkalian: " << x << " * " << y << " = " << x * y << endl;
    
    if (y != 0) {
        cout << "Pembagian: " << x << " / " << y << " = " << x / y << endl;
    } else {
        cout << "Pembagian dengan nol tidak terdefinisi." << endl;
    }

    return 0;
}