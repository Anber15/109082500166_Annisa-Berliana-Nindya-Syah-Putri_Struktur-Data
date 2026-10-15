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