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