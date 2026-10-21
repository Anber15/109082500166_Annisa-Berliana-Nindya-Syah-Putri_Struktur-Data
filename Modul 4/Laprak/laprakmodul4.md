# <h1 align="center">Laporan Praktikum Modul 4 -  SINGLY LINKED LIST </h1>
<p align="center">Annisa Berliana Nindya Syah Putri - 109082500166</p>

## Dasar Teori
### A. Konsep Linked List dan Pointer<br/> 
Linked list adalah struktur data yang merepresentasikan serangkaian elemen yang saling terhubung secara berurutan. Berbeda dengan array yang bersifat statis (ukurannya tetap sejak deklarasi), linked list bersifat dinamis sehingga dapat tumbuh atau menyusut sesuai kebutuhan selama program berjalan. Implementasi linked list umumnya menggunakan pointer karena sifatnya yang fleksibel dalam mengelola alokasi memori, di mana setiap elemen tidak harus disimpan di alamat memori yang berurutan secara fisik.

### B. Struktur Singly Linked List
Singly Linked List adalah jenis linked list yang hanya memiliki satu arah pointer. Setiap elemen atau node di dalamnya terdiri dari dua bagian utama, yaitu info (data yang disimpan) dan next (pointer yang menunjuk ke alamat node berikutnya). Node pertama dalam list ditunjuk oleh pointer head atau first, sedangkan node terakhir akan menunjuk ke nilai Nil atau NULL yang menandakan akhir dari list. Karena hanya satu arah, penelusuran data hanya bisa dilakukan dari depan ke belakang.

### C. Manajemen Memori (Alokasi dan Dealokasi)
Karena linked list bersifat dinamis, pengelolaan memori dilakukan secara manual saat program berjalan. Proses alokasi adalah pembentukan node baru di memori menggunakan perintah new pada C++ (atau malloc pada C). Sebaliknya, proses dealokasi dilakukan untuk menghapus node yang tidak terpakai dan membebaskan kembali memorinya ke sistem menggunakan perintah delete (atau free pada C). Tanpa dealokasi, program akan mengalami kebocoran memori (memory leak).

### D. Operasi Insert
Operasi insert digunakan untuk menambahkan node baru ke dalam list. Terdapat tiga metode utama: Insert First (menyisipkan node di paling depan/head), Insert Last (menyisipkan node di paling belakang), dan Insert After (menyisipkan node tepat setelah node tertentu). Setiap metode memerlukan pengaturan ulang pointer next agar rantai antar node tidak terputus. Pada Insert First, pointer next node baru diarahkan ke head lama, lalu head diperbarui ke node baru.

### E. Operasi Delete
Operasi delete berfungsi untuk menghapus node dari list sekaligus membebaskan memorinya. Sama seperti penyisipan, penghapusan juga dibagi menjadi Delete First (menghapus node paling depan), Delete Last (menghapus node paling belakang), dan Delete After (menghapus node setelah node tertentu). Untuk Delete Last dan Delete After, program perlu menelusuri list terlebih dahulu untuk menemukan node target dan node sebelum target (predecessor) agar pointer next bisa diarahkan dengan benar sebelum node di-dealokasi.

### E. Operasi View dan Update
Operasi view (atau printInfo) dilakukan dengan cara menelusuri list dari node head hingga Nil menggunakan perulangan (biasanya while), untuk menampilkan isi data pada setiap node. Sementara itu, operasi update digunakan untuk mengubah nilai info pada node tertentu. Proses update ini biasanya diawali dengan operasi pencarian (searching) untuk menemukan alamat node yang ingin diubah datanya.

## Guided
### Guided 1
#### 1. Mahasiswa
##### Code Program
###### a. list.h
```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam 1 program
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node { //node untuk isi dari linked listnya, isis setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address Prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```
###### b. list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList list) {
    if(list.first == Nil){
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedList &list) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    list.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &list, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(list)) {
        list.first = nodeBaru;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &list){
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(list) == false) {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &list){
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if(isEmpty(list) == false){
        nodeHapus = list.first;
        if(nodeHapus->next == Nil){
            list.first = Nil;
            dealokasi(nodeHapus);
        } else {
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev){
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedList list) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(list)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = list.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama 
                 << ", NIM : " << nodeBantu->isidata.nim 
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedList list) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &list){
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```
###### c. main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main() {
    linkedList list;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(list);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(list, nodeA);
    insertLast(list, nodeB);
    insertAfter(list, nodeC, nodeA);
    insertAfter(list, nodeD, nodeC);
    insertLast(list, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(list);
    cout << "jumlah node : " << nbList(list) << endl;
    cout << endl;

    delFirst(list);
    delLast(list);
    delAfter(list, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(list);
    cout << "jumlah node : " << nbList(list) << endl;
    cout << endl;

     return 0;
} 
```
##### Penjelasan Program
Program ini menggunakan struktur data linked list untuk menyimpan data mahasiswa berupa nama, NIM, dan umur. File `list.h` berisi deklarasi struktur data dan fungsi yang digunakan, sedangkan `list.cpp` berisi implementasi fungsi untuk membuat list kosong, menambahkan node, menghapus node, menampilkan data, dan menghitung jumlah node. Pada `main.cpp`, program membuat list kosong, kemudian menambahkan lima data mahasiswa menggunakan `insertFirst()`, `insertAfter()`, dan `insertLast()`. Setelah itu, program menampilkan seluruh data beserta jumlah nodenya. Selanjutnya, program menghapus node pertama, node terakhir, dan node setelah Rizal. Terakhir, program menampilkan kembali data yang tersisa dan jumlah node setelah penghapusan.

## Unguided
### Unguided 1
#### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
Type infotype : int
Type address  : pointer to ElmList

Type ElmList <
    info  : infotype
    next  : address
>

Type List : < First : address >

procedure CreateList ( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi ( input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P : address)
```
Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file 
“Singlylist.cpp”

Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai 
berikut :
```C++
int main(){
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

Output yang diharapkan :
9 12 8 0 2
process returned 0 (0x0) execution time : 0.019s
press any key to continue

##### a. singlylist1.h
###### Code Program
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int dataType;
typedef struct Node* pointer;

struct Node {
    dataType data;
    pointer next;
};

struct LinkedList {
    pointer head;
};

void createList(LinkedList &daftar);
pointer alokasi(dataType nilai);
void dealokasi(pointer &hapus);
void insertFirst(LinkedList &daftar, pointer baru);
void printInfo(LinkedList daftar);

#endif
```
###### b. singlylist1.cpp
```C++
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
```
###### c. main1.cpp
```C++
#include <iostream>
#include <chrono>
#include "SinglyList1.h"
using namespace std;
using namespace chrono;

int main() {
    auto mulai = high_resolution_clock::now();

    LinkedList daftar;
    pointer nodeA, nodeB, nodeC, nodeD, nodeE;

    createList(daftar);

    nodeA = alokasi(2);
    insertFirst(daftar, nodeA);

    nodeB = alokasi(0);
    insertFirst(daftar, nodeB);

    nodeC = alokasi(8);
    insertFirst(daftar, nodeC);

    nodeD = alokasi(12);
    insertFirst(daftar, nodeD);

    nodeE = alokasi(9);
    insertFirst(daftar, nodeE);

    printInfo(daftar);

    auto selesai = high_resolution_clock::now();
    duration<double> waktu = selesai - mulai;

    cout << "\nProcess returned 0 (0x0) execution time : "
         << waktu.count() << "s" << endl;
    cout << "Press any key to continue...";

    cin.get();

    return 0;
}
```
##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%204/Unguided/Unguided%201/Screenshot%202026-10-21%20183819.png)

##### Penjelasan Program
Program ini digunakan untuk membuat dan menampilkan data menggunakan struktur data Singly Linked List. File `singlylist1.h` berisi deklarasi struktur data dan fungsi yang digunakan, sedangkan `singlylist1.cpp` berisi implementasi fungsi untuk membuat list kosong, mengalokasikan memori, menambahkan node di awal list, menampilkan data, dan menghapus node dari memori. Pada `main1.cpp`, program membuat list kosong, kemudian menambahkan lima node dengan nilai 2, 0, 8, 12, dan 9 menggunakan fungsi `insertFirst()`. Karena setiap node dimasukkan di awal list, urutan data yang ditampilkan menjadi 9, 12, 8, 0, dan 2. Program juga menghitung waktu eksekusi menggunakan `chrono` dan menampilkan hasilnya setelah seluruh proses selesai.

### Unguided 2
#### Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().
Output yang diharapkan : 
12 0
Jumlah node: 2

-List berhasil terhapus -
Jumlah node: 0

##### a. singlylist2.h
###### Code Program
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int dataType;
typedef struct Node* pointer;

struct Node {
    dataType data;
    pointer next;
};

struct LinkedList {
    pointer head;
};

void createList(LinkedList &daftar);
pointer alokasi(dataType nilai);
void dealokasi(pointer &hapus);
void insertFirst(LinkedList &daftar, pointer baru);
void printInfo(LinkedList daftar);

void deleteFirst(LinkedList &daftar, pointer &hapus);
void deleteLast(LinkedList &daftar, pointer &hapus);
void deleteAfter(LinkedList &daftar, pointer sebelumnya, pointer &hapus);
int nbList(LinkedList daftar);
void deleteList(LinkedList &daftar);

#endif
```
###### b. singlylist2.cpp
```C++
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
```
###### c. main2.cpp
```C++
#include <iostream>
#include "singlylist2.h"
using namespace std;

int main() {
    LinkedList daftar;
    pointer nodeA, nodeB, nodeC, nodeD, nodeE;
    pointer nodeHapus, nodeSebelum;

    createList(daftar);

    nodeA = alokasi(2);
    insertFirst(daftar, nodeA);

    nodeB = alokasi(0);
    insertFirst(daftar, nodeB);

    nodeC = alokasi(8);
    insertFirst(daftar, nodeC);

    nodeD = alokasi(12);
    insertFirst(daftar, nodeD);

    nodeE = alokasi(9);
    insertFirst(daftar, nodeE);

    deleteFirst(daftar, nodeHapus);
    dealokasi(nodeHapus);

    deleteLast(daftar, nodeHapus);
    dealokasi(nodeHapus);

    nodeSebelum = daftar.head;
    deleteAfter(daftar, nodeSebelum, nodeHapus);
    dealokasi(nodeHapus);

    printInfo(daftar);
    cout << "Jumlah node: " << nbList(daftar) << endl;

    deleteList(daftar);
    cout << "\n-List berhasil terhapus -" << endl;
    cout << "Jumlah node: " << nbList(daftar) << endl;

    return 0;
}
```
##### Output Unguided 2
![Screenshot Output Unguided 2](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%204/Unguided/Unguided%202/Screenshot%202026-10-21%20192104.png)

##### Penjelasan Program
Program ini menggunakan struktur data Single Linked List untuk menyimpan dan mengelola data. Fungsi `createList()` digunakan untuk membuat list kosong, `alokasi()` untuk membuat node baru, dan `insertFirst()` untuk menambahkan node di awal list. Fungsi `printInfo()` digunakan untuk menampilkan isi list, sedangkan `deleteFirst()`, `deleteLast()`, dan `deleteAfter()` digunakan untuk menghapus node berdasarkan posisinya. Fungsi `dealokasi()` membebaskan memori node yang dihapus, `nbList()` menghitung jumlah node, dan `deleteList()` menghapus seluruh node hingga list kosong.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa Single Linked List merupakan struktur data yang dapat digunakan untuk menyimpan dan mengelola data dalam bentuk node yang saling terhubung. Operasi yang dipelajari meliputi pembuatan list, penambahan node di awal, penampilan data, penghapusan node berdasarkan posisi, penghitungan jumlah node, dan penghapusan seluruh isi list. Dengan menggunakan fungsi-fungsi tersebut, pengelolaan data dalam linked list dapat dilakukan secara terstruktur.

## Referensi
[1] Informatics Lab, Fakultas Informatika, Telkom University, “Modul 4: Singly Linked List (Bagian Pertama),” Modul Praktikum Struktur Data, Telkom University, hlm. 36–46.