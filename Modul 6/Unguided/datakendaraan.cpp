#include <iostream>
#include "datakendaraan.h"
using namespace std;

void createList(List &L) {
    L.First = nullptr;
    L.Last = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    P->prev = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void insertLast(List &L, address P) {
    if (P == nullptr) return;

    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;

    if (L.First == nullptr) {
        L.First = P;
        L.Last = P;
    } else {
        P->next = L.First;
        L.First->prev = P;
        L.First = P;
    }
}

void printInfo(List L) {
    address P = L.First;

    while (P != nullptr) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;

        P = P->next;
    }
}

address findElm(List L, string nopol) {
    address P = L.First;

    while (P != nullptr) {
        if (P->info.nopol == nopol) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

void deleteFirst(List &L, address &P) {
    P = nullptr;

    if (L.First == nullptr) return;

    P = L.First;
    L.First = P->next;

    if (L.First != nullptr) {
        L.First->prev = nullptr;
    } else {
        L.Last = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteLast(List &L, address &P) {
    P = nullptr;

    if (L.Last == nullptr) return;

    P = L.Last;
    L.Last = P->prev;

    if (L.Last != nullptr) {
        L.Last->next = nullptr;
    } else {
        L.First = nullptr;
    }

    P->next = nullptr;
    P->prev = nullptr;
}

void deleteAfter(List &L, address Prec, address &P) {
    P = nullptr;

    if (Prec == nullptr || Prec->next == nullptr) return;

    P = Prec->next;
    Prec->next = P->next;

    if (P->next != nullptr) {
        P->next->prev = Prec;
    } else {
        L.Last = Prec;
    }

    P->next = nullptr;
    P->prev = nullptr;
}