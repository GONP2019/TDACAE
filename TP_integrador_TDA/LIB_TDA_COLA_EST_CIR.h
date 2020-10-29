#ifndef LIB_TDA_COLA_EST_CIR
#define LIB_TDA_COLA_EST_CIR
#define MAX 5
typedef int tDato;

typedef struct tCola
{
    tDato frente;
    tDato finc;
    int arrCC[MAX];
}tCola;

void ccCrear (tCola* k)
{
    k->frente = 1 ;
    k->finc = 1;
}

int ccLlena (tCola* k)
{
    /* Si devuelve 1 significa que está llena */
    int res;
    if ((k->finc + 1 == k->frente)||(k->frente == 1 && k->finc == MAX))
    {
        res = 1;
    }else
    {
        res = 0;
    }
    return res;
}

int ccVacia (tCola* k)
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

void ccPoner (tCola* k,tDato dato)
{
    if (k->finc == MAX)
    {
        k->finc = 1;
    }else
    {
        k->finc = k->finc + 1;
    }
    k->arrCC[k->finc] = dato;
}

void ccSacar (tCola* k, tDato dato)
{
    if (k->frente == MAX)
    {
        k->frente = 1;
    }else
    {
        k->frente = k->frente + 1;
    }
    dato = k->arrCC[k->frente];
}

     /*   int res;
        if (k.finc + 1 == k.frente) || (k.frente == 1 && k.finc == MAX)
        {
            res = 1;
        }else
        {
            res = 0;
        }
        return res;*/

#endif // LIB_TDA_COLA_EST_CIR
