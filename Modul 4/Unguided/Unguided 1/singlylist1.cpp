#include "SinglyList1.h"

void createList(LinkedList &daftar) {
    daftar.head = Nil;
}

pointer alokasi(dataType nilai) {
    pointer baru = new Node;
    baru->data = nilai;
    baru->next = Nil;
    return baru;
}

void dealokasi(pointer &hapus) {
    delete hapus;
    hapus = Nil;
}

void insertFirst(LinkedList &daftar, pointer baru) {
    baru->next = daftar.head;
    daftar.head = baru;
}

void printInfo(LinkedList daftar) {
    pointer bantu = daftar.head;
    while (bantu != Nil) {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }
    cout << endl;
}