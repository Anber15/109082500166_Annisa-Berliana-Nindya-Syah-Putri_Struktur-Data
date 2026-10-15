# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">Annisa Berliana Nindya Syah Putri - 109082500166</p>

## Dasar Teori
### A. Konsep Dasar dan Definisi Abstract Data Type (ADT)<br/> 
Abstract Data Type (ADT) didefinisikan sebagai sebuah TYPE beserta sekumpulan PRIMITIF (operasi dasar) yang beroperasi terhadap TYPE tersebut. Dalam sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku, di mana ADT merupakan sebuah definisi yang bersifat statis (STATIK). Definisi tipe dari sebuah ADT juga dapat mengandung definisi ADT lain (komposisi), misalnya ADT Waktu yang terdiri dari ADT Jam dan ADT Tanggal, atau ADT Garis yang terdiri dari dua buah ADT Titik (Point).

### B. Implementasi TYPE dan PRIMITIF dalam C++
Dalam implementasinya pada bahasa C++, komponen TYPE diterjemahkan menjadi tipe data terdefinisi, yang umumnya menggunakan struct. Sementara itu, komponen PRIMITIF dalam konteks pemrograman prosedural diterjemahkan menjadi fungsi atau prosedur.

### C. Klasifikasi Operasi Primitif
Waktu ngoding, konsep ADT ini biasanya dipisah jadi beberapa file biar kodenya lebih rapi dan terstruktur (modular). Pertama ada file header (.h) yang isinya deklarasi struct dan prototype fungsi (spesifikasi tipe dan primitif). Kedua, ada file body (.cpp) yang isinya realisasi atau codingan lengkap dari fungsi-fungsi tersebut. Terakhir, ada file main (.cpp) buat program utamanya yang bakal manggil dan menguji fungsi-fungsi dari ADT yang udah dibuat.
1. Konstruktor/Kreator: Berfungsi untuk membentuk nilai tipe. Semua objek atau variabel bertipe tersebut harus melalui konstruktor (biasanya diawali dengan kata Make).
2. Selector: Digunakan untuk mengakses nilai komponen (biasanya diawali dengan kata Get).
3. Mutator (Pengubah Nilai): Prosedur untuk mengubah nilai komponen (secara akademis dan praktik umum biasanya diawali dengan kata Set).
4. Validator: Digunakan untuk menguji atau memvalidasi apakah suatu tipe dapat dibentuk sesuai dengan batasan yang ditetapkan.
5. Destruktor/Dealokator: Berfungsi untuk "menghancurkan" nilai objek atau variabel sekaligus membebaskan memori penyimpanannya.
6. Baca/Tulis: Digunakan sebagai antarmuka (interface) dengan perangkat masukan dan keluaran (I/O device).
7. Operator Relasional: Mendefinisikan operasi perbandingan terhadap tipe tersebut, seperti lebih besar, lebih kecil, atau sama dengan.
8. Operator Aritmatika: Mendefinisikan operasi matematika terhadap tipe tersebut, karena operasi aritmatika bawaan bahasa C/C++ umumnya hanya terdefinisi untuk tipe numerik dasar.
9. Konversi: Berfungsi untuk mengonversi tipe tersebut ke tipe data dasar dan sebaliknya

### D. Struktur Implementasi Modular ADT
Penerapan konsep ADT dalam bahasa C++ dilakukan secara modular untuk menjaga kerapihan kode dan prinsip enkapsulasi. Implementasi ini umumnya dipisahkan menjadi berkas-berkas utama berikut:
1. Berkas Header (.h): Berisi definisi dan spesifikasi TYPE serta PRIMITIF. Spesifikasi tipe disesuaikan dengan kaidah bahasa yang dipakai, sedangkan spesifikasi primitif mencakup nama, domain, range, dan prasyarat (precondition) untuk fungsi, serta initial state, final state, dan proses yang dilakukan untuk prosedur.
2. Berkas Body/Realisasi (.cpp): Berisi implementasi kode program dari primitif yang telah didefinisikan di header. Realisasi fungsi dan prosedur di dalam berkas ini harus sedapat mungkin memanfaatkan selector dan konstruktor yang telah dibuat.
3. Berkas Utama/Driver (main.cpp): Berisi program utama yang berfungsi sebagai antarmuka untuk menguji dan menggunakan ADT yang telah dibuat dengan menyertakan berkas header yang bersangkutan.

### E. Keuntungan Penggunaan ADT
Keuntungan utama pakai ADT adalah kita bisa menyembunyikan detail implementasi atau yang sering disebut enkapsulasi. Programmer yang pakai ADT cuma perlu tahu cara pakai fungsinya aja, nggak perlu pusing mikirin gimana codingan di dalamnya. Ini bikin program jadi lebih gampang di-debug dan dikembangkan. Kalau misalnya ada perubahan logika di dalam fungsi, kita cuma perlu ubah di file body-nya aja tanpa harus ngutak-atik program utama.

## Guided
### Guided 1
#### 1. Mahasiswa
##### Code Program
###### a. mahasiswa.h
```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs (mahasiswa &m) ;
float rata2 (mahasiswa m) ;
#endif //MAHASISWA_H_INCLUDED
```
###### b. mahasiswa.cpp
```C++
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
```
###### c. main.cpp
```C++
#include <iostream>
using namespace std;

int main() 
{
    mahasiswa mhs;
    inputMhs (mhs) ;
    cout << "rata-rata = " << rata2 (mhs) ;
    return 0;
}
```
##### Penjelasan Program
Program ini digunakan untuk memasukkan data mahasiswa berupa NIM, nilai 1, dan nilai 2, kemudian menghitung nilai rata-ratanya. File `mahasiswa.h` berisi deklarasi struct `mahasiswa` dan fungsi yang akan digunakan. File `mahasiswa.cpp` berisi fungsi `inputMhs()` untuk memasukkan data mahasiswa dan `rata2()` untuk menghitung rata-rata dari dua nilai. Pada fungsi `main()`, program memanggil kedua fungsi tersebut, lalu menampilkan hasil rata-rata nilai mahasiswa.

## Unguided
### Unguided 1
#### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 * uts + 0.4 * uas + 0.3 * tugas.
##### a. mahasiswa.h
###### Code Program
```C++
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
```
###### b. mahasiswa.cpp
```C++
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
```
###### c. main.cpp
```C++
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
```
##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%203/Unguided/Unguided%201/Screenshot%202026-10-15%20080119.png)

##### Penjelasan Program
Program ini digunakan untuk memasukkan dan menampilkan data beberapa mahasiswa beserta nilai akhirnya. File `mahasiswa.h` berisi struct untuk menyimpan nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir. File `mahasiswa.cpp` berisi fungsi `inputMhs()` untuk memasukkan data, `hitungNilaiAkhir()` untuk menghitung nilai akhir berdasarkan bobot UTS 30%, UAS 40%, dan tugas 30%, serta `tampilMhs()` untuk menampilkan data mahasiswa. Pada `main.cpp`, pengguna menentukan jumlah mahasiswa yang akan dimasukkan, dengan batas maksimal 10 orang. Setelah semua data diinput, program menampilkan data setiap mahasiswa beserta nilai akhirnya.

### Unguided 2
#### Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”: 
```C++
Type pelajaran <
namaMapel : string
kodeMapel : string
>
function create_pelajaran( namapel : string,
 kodepel : string ) → pelajaran
procedure tampil_pelajaran( input pel : pelajaran )
```
#### Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp”
#### Cobalah hasil implementasi ADT pada file “main.cpp”
```C++
using namespace std;
int main(){
string namapel = "Struktur Data";
string kodepel = "STD";
pelajaran pel = create_pelajaran(namapel,kodepel);
tampil_pelajaran(pel);
return 0;
}
```
### Contoh output hasil:
```C++
nama pelajaran : Struktur Data
nilai : STD
```
##### Code Program
#### a. pelajaran.h
```C++
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
```
#### b. pelajaran.cpp
```C++
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
```
#### c. main.cpp
```C++
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
```

###### Output Unguided 2:
![Screenshot Output Unguided 2](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%203/Unguided/Unguided%202/Screenshot%202026-10-15%20080238.png)

###### Penjelasan Program
Program ini digunakan untuk menyimpan dan menampilkan data pelajaran menggunakan ADT. File `pelajaran.h` berisi struct `pelajaran` yang memiliki variabel `namaMapel` dan `kodeMapel`, serta deklarasi fungsi yang digunakan. File `pelajaran.cpp` berisi fungsi `create_pelajaran()` untuk menyimpan nama dan kode pelajaran ke dalam struct, sedangkan `tampil_pelajaran()` digunakan untuk menampilkan data tersebut. Pada file `main.cpp`, program mengisi nama mata kuliah dengan Struktur Data dan kodenya STD, kemudian memanggil fungsi untuk menyimpan dan menampilkan data ke layar.

### Unguided 3
#### 3. Buatlah program dengan ketentuan :
##### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
##### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
##### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
##### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer
#### Code Program
##### a. array2d.h
```C++
#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

void tampilArray(int matriks[3][3]);
void tukarArray(int matriksA[3][3], int matriksB[3][3], int brs, int kol);
void tukarPointer(int *ptrA, int *ptrB);

#endif
```
##### b. array2d.cpp
```C++
#ifndef ARRAY2D_H_INCLUDED
#define ARRAY2D_H_INCLUDED

void tampilArray(int matriks[3][3]);
void tukarArray(int matriksA[3][3], int matriksB[3][3], int brs, int kol);
void tukarPointer(int *ptrA, int *ptrB);

#endif
```
##### c. main.cpp
```C++
#include <iostream>
#include "array2d.h"
using namespace std;

int main() {
    int matriksA[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matriksB[3][3] = {{9, 8, 7}, {6, 0, 4}, {3, 2, 1}};

    int angka1 = 10, angka2 = 20;
    int *ptrA = &angka1;
    int *ptrB = &angka2;

    int brs, kol;

    cout << "Array A" << endl;
    tampilArray(matriksA);

    cout << "Array B" << endl;
    tampilArray(matriksB);

    cout << "Masukkan posisi yang ingin ditukar (baris kolom, 0-2): ";
    cin >> brs >> kol;

    if (brs >= 0 && brs < 3 && kol >= 0 && kol < 3) {
        tukarArray(matriksA, matriksB, brs, kol);

        cout << "\nSetelah ditukar:" << endl;
        cout << "Array A" << endl;
        tampilArray(matriksA);

        cout << "Array B" << endl;
        tampilArray(matriksB);
    } else {
        cout << "Posisi tidak valid" << endl;
    }

    cout << "\nSebelum tukar pointer: angka1 = " << *ptrA
         << ", angka2 = " << *ptrB << endl;

    tukarPointer(ptrA, ptrB);

    cout << "Sesudah tukar pointer: angka1 = " << *ptrA
         << ", angka2 = " << *ptrB << endl;

    return 0;
}
```

##### Output Unguided 3
![Screenshot Output Unguided 3](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%203/Unguided/Unguided%202/Screenshot%202026-10-15%20080238.png)

##### Penjelasan Program
Program ini digunakan untuk menampilkan dan menukar elemen dari dua array dua dimensi serta menukar nilai menggunakan pointer. File array2d.h berisi deklarasi fungsi yang digunakan, sedangkan array2d.cpp berisi implementasi fungsi tersebut.

Fungsi tampilArray() digunakan untuk menampilkan isi matriks dengan perulangan. Fungsi tukarArray() menukar elemen pada posisi baris dan kolom yang dipilih dari matriks A dan B. Sementara itu, fungsi tukarPointer() menukar nilai dua variabel melalui pointer. Pada main.cpp, pengguna memasukkan posisi elemen yang ingin ditukar, kemudian program menampilkan hasil perubahan matriks dan pertukaran nilai pointer.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa penggunaan ADT, struct, array, function, dan pointer dapat membantu dalam membuat program C++ yang lebih terstruktur. ADT digunakan untuk mengatur data dan fungsi sesuai kebutuhan, sedangkan struct digunakan untuk menyimpan beberapa data dalam satu kelompok. Array dapat digunakan untuk menyimpan banyak nilai, baik dalam satu dimensi maupun dua dimensi. Selain itu, function membantu membagi program menjadi beberapa bagian agar lebih mudah dipahami, sementara pointer dapat digunakan untuk mengakses dan mengubah nilai melalui alamat memori. Melalui praktikum ini, pemahaman mengenai pengolahan data dan penggunaan fungsi dalam C++ menjadi lebih baik.

## Referensi
[1] Modul 3: ABSTRACT DATA TYPE (ADT). Modul Praktikum Struktur Data. (Referensi Modul). 
<br>[2] Triase, Diktat Struktur Data, Universitas Islam Negeri Sumatera Utara, 2020. Diakses melalui http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf
<br>[3] Indahyanti, Uce., Rahmawati, Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses melalui https://doi.org/10.21070/2020/978-623-6833-67-4.