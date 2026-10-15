// mahasiswa.h
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif //MAHASISWA_H_INCLUDED

// mahasiswa.cpp
#include <iostream>
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "input nim = ";
    cin >> (m).nim;
    cout << "input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "input nilai 2 = ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float(m.nilai1+m.nilai2)/2;
}

// main.cpp
#include <iostream>
using namespace std;

int main() 
{
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}