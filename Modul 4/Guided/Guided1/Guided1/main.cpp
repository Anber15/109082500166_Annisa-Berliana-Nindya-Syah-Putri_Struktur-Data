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