#ifndef LIB_TDA_PILA_EST_COR_H_INCLUDED
#define LIB_TDA_PILA_EST_COR_H_INCLUDED
#define MAX 10

typedef unsigned int tDato;

typedef struct tPila
{
    int cima;
    tDato elem[MAX];
}tPila;

void pCrear(tPila* p)
{
    p->cima = -1;
}

int pVacia (tPila* p)
{
    return p->cima == -1;
}

int pLlena(tPila* p)
{
    return p->cima == MAX - 1;
}

void pPoner(tPila* p, tDato dato)
{
    p->cima++;
    p->elem[p->cima]=dato;
}

void pSacar(tPila* p, tDato* dato)
{
    *dato = p->elem[p->cima];
    p->cima--;
}

#endif // LIB_TDA_PILA_EST_COR_H_INCLUDED
