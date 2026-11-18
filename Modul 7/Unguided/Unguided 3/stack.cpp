#include "stack.h"
#include <iostream>
#include <cctype>
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top >= KAPASITAS) {
        cout << "Stack penuh" << endl;
        return;
    }
    S.info[S.top++] = x;
}

infotype pop(Stack &S) {
    if (S.top <= 0) {
        cout << "Stack kosong" << endl;
        return -1;
    }
    return S.info[--S.top];
}

void printInfo(Stack S) {
    if (S.top == 0) {
        cout << "Stack kosong" << endl;
        return;
    }
    cout << "[TOP]";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << " " << S.info[i];
    }
    cout << endl;
}

void balikStack(Stack &S) {
    infotype sementara[KAPASITAS];
    int n = S.top;
    for (int i = 0; i < n; i++) {
        sementara[i] = pop(S);
    }
    for (int i = 0; i < n; i++) {
        push(S, sementara[i]);
    }
}

void getInputStream(Stack &S) {
    int c = cin.get();
    while (c != '\n' && c != EOF) {
        if (isdigit(c)) {
            push(S, c - '0');
        }
        c = cin.get();
    }
}