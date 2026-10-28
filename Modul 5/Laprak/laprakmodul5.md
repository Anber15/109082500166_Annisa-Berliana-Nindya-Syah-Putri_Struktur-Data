# <h1 align="center">Laporan Praktikum Modul 5 -  SINGLY LINKED LIST (BAGIAN KEDUA) </h1>
<p align="center">Annisa Berliana Nindya Syah Putri - 109082500166</p>

## Dasar Teori
### A. Operasi Pencarian (Searching)<br/> 
Searching adalah operasi dasar untuk mencari node tertentu di dalam linked list. Proses ini dilakukan dengan menelusuri list dari node pertama (first) hingga node terakhir menggunakan perulangan. Pencarian akan berhenti ketika node yang dicari ditemukan atau ketika pointer sudah mencapai Nil. Fungsi yang umum digunakan adalah findElm (mengembalikan alamat node jika ditemukan, atau Nil jika tidak) dan fFindElm (mengembalikan nilai boolean true/false). Terdapat juga findBefore yang digunakan untuk mencari alamat node tepat sebelum node target.

### B. Penyisipan di Akhir (Insert Last)
Berbeda dengan insertFirst yang langsung menyisipkan di depan, insertLast menyisipkan node baru di posisi paling belakang list. Untuk melakukan ini, program harus menelusuri list terlebih dahulu hingga menemukan node terakhir (node yang next-nya bernilai Nil), kemudian mengarahkan next dari node terakhir tersebut ke node baru.

### C. Operasi Penghapusan (Delete)
Penghapusan node melibatkan pemutusan hubungan pointer dan pembebasan memori (dealokasi).
1. Delete First (delFirst): Menghapus node paling depan. Pointer first akan diarahkan ke node kedua, lalu node lama di-dealokasi.
2. Delete Last (delLast): Menghapus node paling belakang. Program harus mencari node kedua dari belakang, lalu mengarahkan next-nya ke Nil dan men-dealokasi node terakhir.
3. Delete After (delAfter): Menghapus node tepat setelah node tertentu (Prec).
4. Delete P (delP): Mencari node dengan nilai info tertentu, lalu menghapusnya dari list.

### D. Operasi Lain (nbList, delAll, dll)
Selain insert dan delete, terdapat operasi pendukung seperti nbList (menghitung jumlah elemen dalam list), delAll (menghapus seluruh elemen list dan mengosongkannya), invertList (membalikkan urutan elemen), serta operasi copy list untuk menduplikasi struktur data.

## Guided
### Guided 1
#### 1. List Buah
##### Code Program
###### a. listBuah.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
###### b. listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```
###### c. main.cpp
```C++
 #include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
##### Penjelasan Program
Program ini mengimplementasikan struktur data Singly Linked List untuk mengelola data buah (nama, jumlah, harga). Program ini menerapkan konsep Abstract Data Type (ADT) dengan memisahkan deklarasi (listBuah.h), implementasi fungsi (listBuah.cpp), dan program utama (main.cpp). Operasi yang dilakukan mencakup manajemen memori, penyisipan (insert), penghapusan (delete), pembaruan (update), dan pencarian (searching).

## Unguided
### Unguided 1
#### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”:
```
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
info : infotype
next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst(input/output L : List, input P :address)
```
#### Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”. Adapun data
![Screenshot Ilustrasi elemen](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%205/Laprak/Screenshot%202026-10-28%20081500.png)

#### Cobalah hasil implementasi ADT pada file “main.cpp"
```
int main()
{
List L;
address P1, P2, P3, P4, P5 = Nil;
createList(L);
P1 = alokasi(2);
insertFirst(L,P1);
P2 = alokasi(0);
insertFirst(L,P2);
P3 = alokasi(8);
insertFirst(L,P3);
P4 = alokasi(12);
insertFirst(L,P4);
P5 = alokasi(9);
insertFirst(L,P5);
printInfo(L)
return 0;
}
```
#### Ekspektasi Output:
```text
9 12 8 0 2
Process returned 0 (0x0)    execution time: 0.019 s
Press any key to continue
```

##### a. singlylist.h
###### Code Program
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList* address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void printInfo(List L);

address findElm(List L, infotype x);
int sumList(List L);

#endif
```
#### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru.
#### fungsi findElm( L : List, x : infotype ) : address
#### Ekspektasi Output:
```text
0 ditemukan dalam list
Process returned 0 (0x0)    execution time: 0.020 s
Press any key to continue
```

##### b. singlylist.cpp
###### Code Program
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

address findElm(List L, infotype x) {
    address P = L.first;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }

    return Nil;
}

int sumList(List L) {
    int total = 0;
    address P = L.first;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}
```
#### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31).
#### Ekspektasi Output:
```text
Total info dari kelima elemen adalah 31
Process returned 0 (0x0)    execution time: 0.019s
Press any  key to continue.
```

##### c. main.cpp
###### Code Program
```C++
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

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

    address found = findElm(L, 8);

    if (found != Nil) {
        cout << "Elemen 8 ditemukan di alamat: " << found << endl;
    } else {
        cout << "Elemen 8 tidak ditemukan" << endl;
    }

    cout << "Total info seluruh elemen: " << sumList(L) << endl;

    return 0;
}
```
##### Output Unguided 1
![Screenshot Output Unguided 1](https://github.com/Anber15/109082500166_Annisa-Berliana-Nindya-Syah-Putri_Struktur-Data/blob/main/Modul%205/Unguided/Screenshot%202026-10-28%20091046.png)

##### Penjelasan Program
Program ini menerapkan struktur data Singly Linked List yang setiap elemennya menyimpan nilai dan alamat elemen berikutnya. Elemen dibuat menggunakan alokasi() dan ditambahkan ke awal list menggunakan insertFirst(). Program kemudian menampilkan isi list, mencari elemen bernilai 8 menggunakan findElm(), serta menghitung jumlah seluruh nilai elemen menggunakan sumList(). Hasil akhirnya adalah list berisi 9, 12, 8, 0, 2, elemen 8 berhasil ditemukan, dan total seluruh nilai adalah 31.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa struktur data Singly Linked List berhasil diimplementasikan menggunakan bahasa C++ dengan memanfaatkan konsep pointer untuk manajemen memori dinamis. Berbeda dengan array yang bersifat statis, linked list memungkinkan penambahan dan penghapusan elemen secara fleksibel sesuai kebutuhan tanpa membatasi ukuran awal. Melalui praktikum ini, saya memahami cara kerja node yang terdiri dari data (info) dan penunjuk (next), serta pentingnya operasi alokasi (new) dan dealokasi (delete) memori untuk mencegah kebocoran memori (memory leak).

Selain itu, operasi-operasi primitif seperti penyisipan (insertFirst, insertLast, insertAfter) dan penghapusan (delFirst, delLast, delAfter) berhasil diterapkan dengan manipulasi pointer yang tepat. Pada modul lanjutan, operasi pencarian (searching menggunakan findElm), penghitungan elemen (nbList), dan pembaruan data juga berhasil diimplementasikan. Penerapan konsep Abstract Data Type (ADT) dengan memisahkan kode menjadi file header (.h) untuk spesifikasi dan file body (.cpp) untuk realisasi, terbukti sangat efektif dalam membuat program menjadi lebih terstruktur, modular, dan mudah untuk dikembangkan atau di-debug.

## Referensi
Tim Asisten Laboratorium Struktur Data. (2024). Modul 5: Singly Linked List (Bagian Kedua). Bandung: Fakultas Informatika, Telkom University.