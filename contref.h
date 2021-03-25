#ifndef CONTREF_H_INCLUDED
#define CONTREF_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int cont;
    void *address;
    struct heap *prox;
}heap;


heap *RemoveElemento(heap *l, void *address, int flag);

void MudaContador(void *end1,int x);

void *malloc2(int t);

void atrib2(void **end1, void *end2);

void dump();


#endif // CONTREF_H_INCLUDED
