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