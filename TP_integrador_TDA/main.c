#include <stdio.h>
#include <stdlib.h>
#include "LIB_TDA_COLA_EST_CIR.h"
#include "LIB_TDA_PILA_EST_COR.h"
/*#include "LIB_TDA_PILA_LSE.h"*/

void inicol (tCola* k)
{
    for(int h=0;h<=MAX;h++)
    {
        k->arrCC[h] = 0;
    }
}

int RevFinDat (int rt)
{
    do
    {
        printf ("Ingrese 1 si desea ingresar datos o ingrese 0 para terminar el proceso \n");
        fflush (stdin);
        scanf("%i",&rt);
    }while (rt != 0 && rt != 1);

    return rt;
}


 main()
{
    tDato dato;
    tPila p;
    tCola k;
    int rt;
    int error;
    ccCrear(&k);
    pCrear(&p);
    inicol (&k);
    RevFinDat (&rt);
    while ( rt != 0 && ccLlena(&k)!= 1)
    {
        printf("Ingrese numero entero positivo: \n");
        scanf ("%i",&dato);
        ccPoner(&k,dato);
        RevFinDat (&rt);
    }

    if (rt != 0){
        printf ("Error, la estructura de datos se ha llenado. \n");
        error = 1;
    }else
    {
       error = 0;
    }

    if (error != 1){
      /*  Procesar    ();
        MostrarPil  ();
        MostrarLisp ();
        MostrarLisi ();*/
    }else
    {
        printf("No ha sido posible continuar con el proceso. \n");
    }
}

/*void procesar(tLista* lImpares, tLista* lPrimos,tPila* p, tCola* q: tCola, _Bool *error)
{
    tDato num;
    _Bool primo;
    while(!cVacia(&q) && !error)
    {
        cSacar(&q, &num)
        if(num.clave % 2 = 0)
        {
            if(!pLlena(&p))
            {
                pPoner(&num, &num)
            } else {
                error = 1;
            }
        } else {
            if(!lLlena(&lImpares)
               {
                   lInsertarOrdenado(&lImpares, num, 'D');
               } else {
                    error = 1;
               }
        }
        primo = esPrimo(num);
        if(primo)
        {
            if(!lLlena(&lPrimos))
            {
                lInsertarOrdenado(&lPrimos, num, 'A'));
            } else {
                error = 1;
            }
        }
    }
}*/

