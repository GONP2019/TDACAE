#include <stdio.h>
#include <stdlib.h>
#include "LIB_TDA_COLA_EST_CIR.h"

void inicol (tCola* k)
{
    for(int h=0;h<=MAX;h++)
    {
        k->arrCC[h] = 0;
    }
}

 main()
{
    tDato dato;
    tCola k;
    int rt;
    ccCrear(&k);

    /*printf("Desea ingresar datos ? S/N \n");
    scanf ("%c",rt);*/

    inicol(&k);

    printf("Desea ingresar datos ? 1/0 \n");
    scanf ("%i",&rt);


    while (rt == 1 && ccLlena(&k)!= 1)
        {
            printf("Ingrese numero entero positivo\n");
            scanf ("%i",&dato);
            ccPoner(&k,dato);
            printf("Desea ingresar datos ? 1/0 \n");
            scanf ("%i",&rt);
        }

    if (ccLlena(&k)== 1)
    {
        printf("Cola llena \n");

        for (int j=1;j<=MAX;j++){
            printf("%i \t",k.arrCC[j]);
        }
    }
    else{
        printf("Todavia hay espacio \n");
    }

    int rt2;
    printf("Desea sacar todos los datos ? 1/0 \n");
    scanf ("%i",&rt2);

    if (rt2 == 1)
    {
        while (ccVacia(&k)!=1)
        {
            ccSacar(&k,&dato);
            printf("Numero: %i \n",dato);
        }
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

