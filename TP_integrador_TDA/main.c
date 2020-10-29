#include <stdio.h>
#include <stdlib.h>
#include "LIB_TDA_COLA_EST_CIR.h"


 main()
{
    tDato dato;
    tCola k;
    int rt;
    ccCrear(&k);

    /*printf("Desea ingresar datos ? S/N \n");
    scanf ("%c",rt);*/

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
        printf("Cola llena");

        for (int j=1;j<=MAX;j++){
            printf("El numero es %i \n",k.arrCC[j]);
        }
    }
    else{
        printf("Todavia hay espacio");
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

