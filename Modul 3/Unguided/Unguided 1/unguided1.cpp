//a.mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nama[50];
    char nim[16];
    int nilaiUTS, nilaiUAS, nilaiTugas;
    float nilaiAkhir;
};

void inputMhs(mahasiswa &data);
float hitungNilaiAkhir(mahasiswa data);
void tampilMhs(mahasiswa data);

#endif 

//mahasiswa.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &data) {
    cout << "Input nama = ";
    cin >> data.nama;

    cout << "Input NIM = ";
    cin >> data.nim;

    cout << "Input nilai UTS = ";
    cin >> data.nilaiUTS;

    cout << "Input nilai UAS = ";
    cin >> data.nilaiUAS;

    cout << "Input nilai tugas = ";
    cin >> data.nilaiTugas;

    data.nilaiAkhir = hitungNilaiAkhir(data);
}

float hitungNilaiAkhir(mahasiswa data) {
    return 0.3 * data.nilaiUTS + 0.4 * data.nilaiUAS
           + 0.3 * data.nilaiTugas;
}

void tampilMhs(mahasiswa data) {
    cout << "Nama = " << data.nama << endl;
    cout << "NIM = " << data.nim << endl;
    cout << "UTS = " << data.nilaiUTS << endl;
    cout << "UAS = " << data.nilaiUAS << endl;
    cout << "Tugas = " << data.nilaiTugas << endl;
    cout << "Nilai akhir = " << data.nilaiAkhir << endl;
}

//main.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa daftarMhs[10];
    int jumlah;

    do {
        cout << "Jumlah mahasiswa (max 10) = ";
        cin >> jumlah;
    } while (jumlah < 1 || jumlah > 10);

    for (int i = 0; i < jumlah; i++) {
        cout << endl << "Data mahasiswa ke-" << i + 1 << endl;
        inputMhs(daftarMhs[i]);
    }

    cout << endl << "=== DATA MAHASISWA ===" << endl;

    for (int i = 0; i < jumlah; i++) {
        cout << endl << "Mahasiswa ke-" << i + 1 << endl;
        tampilMhs(daftarMhs[i]);
    }

    return 0;
}