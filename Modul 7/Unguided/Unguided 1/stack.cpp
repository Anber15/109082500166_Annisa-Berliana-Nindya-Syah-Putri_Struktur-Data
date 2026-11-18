#include "stack.h"

int isEmpty(Stack S) {
    return (S.Top == 0) ? 0 : 1;
}

void createStack(Stack &S) {
    S.Top = 0;
}

void push(Stack &S, infotype X) {
    if (S.Top == BATAS) {
        cout << "Stack penuh, data tidak dapat ditambahkan" << endl;
        return;
    }
    S.Top++;
    S.info[S.Top - 1] = X;
}

void pop(Stack &S, infotype &X) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong, tidak ada data yang dapat diambil" << endl;
        return;
    }
    X = S.info[S.Top - 1];
    S.Top--;
}

void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "Isi stack (dari TOP):" << endl;
    for (int i = S.Top; i > 0; i--) {
        cout << i << ". " << S.info[i - 1].nim << " - "
             << S.info[i - 1].nama << endl;
    }
}