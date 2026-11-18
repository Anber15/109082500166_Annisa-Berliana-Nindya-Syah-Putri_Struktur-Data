#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    const char *daftarNim[]  = {"103112400011", "103112400012", "103112400013"};
    const char *daftarNama[] = {"Dina", "Raka", "Salsa"};

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    for (int i = 0; i < 3; i++) {
        strcpy(data.nim, daftarNim[i]);
        strcpy(data.nama, daftarNama[i]);
        push(S, data);
    }
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    while (isEmpty(S) != 0) {
        pop(S, hasil);
    }
    viewStack(S);

    return 0;
}