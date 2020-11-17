#ifndef LIB_TDA_COLA_EST_CIR
#define LIB_TDA_COLA_EST_CIR
#define MAX 5
typedef unsigned int tDato;

typedef struct tCola
{
    tDato frente;
    tDato finc;
    int arrCC[MAX];
}tCola;

void cCrear (tCola* k)
{
    k->frente = 0 ;
    k->finc = 0;
}

int cLlena (tCola* k)
{
    /* Si devuelve 1 significa que está llena */
    int res;
    if ((k->finc + 1 == k->frente)||(k->frente == 0 && k->finc == MAX-1))
    {
        res = 1;
    }else
    {
        res = 0;
    }
    return res;
}

int cVacia (tCola* k)
{
    int res;
    if (k->finc == k->frente)
    {
        res = 1;
    }else
    {
        res = 0;
    }
    return res;
}

void cPoner (tCola* k,tDato *dato)
{
    if (k->finc == MAX-1)
    {
        k->finc = 0;
    }else
    {
        /*if (k->finc =) {}*/
        k->finc = k->finc + 1;

    }
    k->arrCC[k->finc] = *dato;
}

void cSacar (tCola* k, tDato* dato)
{

    if (k->frente == MAX-1)
    {
        k->frente = 0;
    }else
    {
        k->frente = k->frente + 1;
    }
     &dato  = k->arrCC[k->frente];

}

#endif // LIB_TDA_COLA_EST_CIR
