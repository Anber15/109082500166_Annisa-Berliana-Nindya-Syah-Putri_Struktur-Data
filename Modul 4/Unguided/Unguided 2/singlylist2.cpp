#include "SinglyList2.h"

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

void deleteFirst(LinkedList &daftar, pointer &hapus) {
    hapus = daftar.head;
    daftar.head = hapus->next;
    hapus->next = Nil;
}

void deleteLast(LinkedList &daftar, pointer &hapus) {
    if (daftar.head->next == Nil) {
        hapus = daftar.head;
        daftar.head = Nil;
    } else {
        pointer bantu = daftar.head;

        while (bantu->next->next != Nil) {
            bantu = bantu->next;
        }

        hapus = bantu->next;
        bantu->next = Nil;
    }
}

void deleteAfter(LinkedList &daftar, pointer sebelumnya, pointer &hapus) {
    hapus = sebelumnya->next;
    sebelumnya->next = hapus->next;
    hapus->next = Nil;
}

int nbList(LinkedList daftar) {
    int jumlah = 0;
    pointer bantu = daftar.head;

    while (bantu != Nil) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

void deleteList(LinkedList &daftar) {
    pointer hapus;

    while (daftar.head != Nil) {
        deleteFirst(daftar, hapus);
        dealokasi(hapus);
    }
}