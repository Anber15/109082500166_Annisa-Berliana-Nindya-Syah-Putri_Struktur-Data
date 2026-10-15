// pelajaran.h
#ifndef PELAJARAN_H_INCLUDED
#define PELAJARAN_H_INCLUDED

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string nMapel, string kMapel);
void tampil_pelajaran(pelajaran dataPel);

#endif 

// pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string nMapel, string kMapel) {
    pelajaran hasilPel;
    hasilPel.namaMapel = nMapel;
    hasilPel.kodeMapel = kMapel;
    
    return hasilPel;
}

void tampil_pelajaran(pelajaran dataPel) {
    cout << "nama pelajaran : " << dataPel.namaMapel << endl;
    cout << "nilai : " << dataPel.kodeMapel << endl;
}

// main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaMatkul = "Struktur Data";
    string kodeMatkul = "STD";
    
    pelajaran dataPelajaran = create_pelajaran(namaMatkul, kodeMatkul);
    
    tampil_pelajaran(dataPelajaran);

    return 0;
}
