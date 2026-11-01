#include <iostream>
#include "datakendaraan.h"
using namespace std;

int main() {
    List L;
    createList(L);

    string nopol, warna;
    int tahun;
    char inputLagi;

    do {
        cout << "masukkan nomor polisi: ";
        cin >> nopol;

        address cek = findElm(L, nopol);

        if (cek != nullptr) {
            cout << "nomor polisi sudah terdaftar" << endl;
            cout << endl;
            continue;
        }

        cout << "masukkan warna kendaraan: ";
        cin >> warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> tahun;
        cout << endl;

        infotype dataBaru;
        dataBaru.nopol = nopol;
        dataBaru.warna = warna;
        dataBaru.thnBuat = tahun;

        address P = alokasi(dataBaru);
        insertFirst(L, P);

        cout << "input lagi? (y/n): ";
        cin >> inputLagi;
        cout << endl;

    } while (inputLagi == 'y' || inputLagi == 'Y');

    cout << "DATA LIST 1" << endl;
    printInfo(L);
    cout << endl;

    string cariNopol;

    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cariNopol;

    address hasilCari = findElm(L, cariNopol);

    if (hasilCari != nullptr) {
        cout << endl;
        cout << "Nomor Polisi : " << hasilCari->info.nopol << endl;
        cout << "Warna        : " << hasilCari->info.warna << endl;
        cout << "Tahun        : " << hasilCari->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    cout << endl;

    string hapusNopol;

    cout << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapusNopol;

    address P = findElm(L, hapusNopol);

    if (P != nullptr) {
        address temp = nullptr;

        if (P == L.First) {
            deleteFirst(L, temp);
        } else if (P == L.Last) {
            deleteLast(L, temp);
        } else {
            deleteAfter(L, P->prev, temp);
        }

        dealokasi(temp);

        cout << "Data dengan nomor polisi " << hapusNopol
             << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }

    cout << endl;

    cout << "DATA LIST 1" << endl;

    address Q = L.First;

    while (Q != nullptr) {
        cout << "Nomor Polisi : " << Q->info.nopol << endl;
        cout << "Warna        : " << Q->info.warna << endl;
        cout << "Tahun        : " << Q->info.thnBuat << endl;

        Q = Q->next;
    }

    return 0;
}