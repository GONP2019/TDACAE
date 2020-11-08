#include <stdio.h>
#include <stdlib.h>
#include "LIB_TDA_COLA_EST_CIR.h"
#include "LIB_TDA_PILA_EST_COR.h"
/*#include "LIB_TDA_LISTA_DIN_SE.h"*/
/*#include "LIB_TDA_PILA_LSE.h"*/

/*//////////////////////////////////////*/
/* Inicializa el array de tCola en ceros*/
void inicol (tCola* k)
{
    for(int h=0;h<=MAX;h++)
    {
        k->arrCC[h] = 0;
    }
}

/*////////////////////////////////////////////////*/
/* Funcion pregunta si hay mas datos que ingresar*/
void RevFinDat (char* rt)
{
    char rts;
    do
    {
        printf ("Desea ingresar datos ? \n");
        fflush (stdin);
        scanf("%c",&rts);
    }while (rts != 'S' && rts != 'N');
    *rt = rts;
}

void ingnum (tDato *dato)
{
    int num;
    do
    {
        printf("Ingrese numero entero positivo: \n");
        fflush (stdin);
        scanf ("%i",&num);
    }while (num < 0);

    *dato = &num;

}


/*//////////////////////////////////////*/
/* Código principal*/
 main()
{
    tDato *dato;
    tPila p;
    tCola k;
    char rt ='P';
    int error;
    cCrear(&k);
    pCrear(&p);
    inicol(&k);
    RevFinDat(&rt);
    printf("El dato ingresado es:%c \n",rt);

    while ( rt == 'S' && cLlena(&k)!= 1)
    {
        ingnum(&dato);
        cPoner(&k,dato);
        RevFinDat(&rt);
    }

    if (rt == 'S'){
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

