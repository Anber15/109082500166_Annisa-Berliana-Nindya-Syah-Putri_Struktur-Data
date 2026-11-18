#ifndef STACK_H
#define STACK_H

typedef int infotype;

const int KAPASITAS = 20;

struct Stack {
    infotype info[KAPASITAS];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif