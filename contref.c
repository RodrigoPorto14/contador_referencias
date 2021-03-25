#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int cont;
    void *address;
    struct heap *prox;
}heap;

heap *lista = NULL;

heap *RemoveElemento(heap *l, void *address, int flag)
{
    heap *aux;
    {
        if(l==NULL){return l;}
        if(l->address==address && flag==0)
        {
            aux=l;
            l=l->prox;
            free(aux->address);
            free(aux);
            return l;
        }
        else
        {
            aux = l->prox;
            if(aux->address==address)
            {
                l->prox=aux->prox;
                free(aux->address);
                free(aux);
                return l;
            }
            else l = RemoveElemento(l->prox,address,1);
        }
    }
}

void MudaContador(void *end1,int x)
{
    heap *aux = lista;
    while(aux!=NULL)
    {
        if(aux->address==end1)
        {
            aux->cont = aux->cont + x;
            if(aux->cont==0){lista=RemoveElemento(lista,aux->address,0);}
            break;
        }
        aux=aux->prox;
    }
}

void *malloc2(int t)
{
    heap *aux;
    aux = malloc(sizeof(heap));
    aux->address = malloc(t);
    aux->cont = 1;
    aux->prox = NULL;
    if(lista!=NULL)aux->prox=lista;
    lista = aux;
    return lista->address;
}

void atrib2(void **end1, void *end2)
{
    if((*end1)!=NULL)
    {
        MudaContador((*end1),-1);
        if(end2!=NULL)MudaContador((end2),1);
        (*end1) = end2;
    }
}

void dump()
{
    heap *aux=lista;
    while(aux!=NULL)
    {
        printf("Endereco: %p    Contador: %d\n",aux->address,aux->cont);
        aux=aux->prox;
    }
    printf("\n");
}
