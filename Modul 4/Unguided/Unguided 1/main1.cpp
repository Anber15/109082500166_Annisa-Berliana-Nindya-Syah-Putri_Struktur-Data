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