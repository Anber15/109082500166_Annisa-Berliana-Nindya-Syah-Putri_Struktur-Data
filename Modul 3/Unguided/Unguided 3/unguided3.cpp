// array2d.h
#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

void tampilArray(int matriks[3][3]);
void tukarArray(int matriksA[3][3], int matriksB[3][3], int brs, int kol);
void tukarPointer(int *ptrA, int *ptrB);

#endif

// array2d.cpp
#include <iostream>
#include "array2d.h"
using namespace std;

void tampilArray(int matriks[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(int matriksA[3][3], int matriksB[3][3], int brs, int kol) {
    int temp = matriksA[brs][kol];
    matriksA[brs][kol] = matriksB[brs][kol];
    matriksB[brs][kol] = temp;
}

void tukarPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

// c. main.cpp
#include <iostream>
#include "array2d.h"
using namespace std;

int main() {
    int matriksA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriksB[3][3] = {
        {9, 8, 7},
        {6, 0, 4},
        {3, 2, 1}
    };

    int angka1 = 10, angka2 = 20;
    int *ptrA = &angka1;
    int *ptrB = &angka2;

    int brs, kol;

    cout << "Array A" << endl;
    tampilArray(matriksA);

    cout << "\nArray B" << endl;
    tampilArray(matriksB);

    cout << "\nMasukkan posisi yang ingin ditukar (baris kolom, 0-2): ";
    cin >> brs >> kol;

    if (brs >= 0 && brs < 3 && kol >= 0 && kol < 3) {
        tukarArray(matriksA, matriksB, brs, kol);

        cout << "\nSetelah ditukar:" << endl;

        cout << "Array A" << endl;
        tampilArray(matriksA);

        cout << "\nArray B" << endl;
        tampilArray(matriksB);
    } else {
        cout << "Posisi tidak valid" << endl;
    }

    cout << "\nSebelum tukar pointer: angka1 = " << *ptrA
         << ", angka2 = " << *ptrB << endl;

    tukarPointer(ptrA, ptrB);

    cout << "Sesudah tukar pointer: angka1 = " << *ptrA
         << ", angka2 = " << *ptrB << endl;

    return 0;
}