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
/*/////////////////////////////////////////////////////////////*/
/* Proceso que valida el ingreso de un numero entero positivo */
void ingnum (tDato *dato)
{
    int num;
    do
    {
        printf("Ingrese n%cmero entero positivo: \n",163);
        fflush (stdin);
        scanf ("%i",&num);
    }while (num < 0);

    *dato = &num;

}

void MostrarPil(tPila* p)
{
    int x;
    for (int f=0;f<=p->cima;f++)
    {
        printf("Elemento de la pila: %i \n",p->elem[f]);
    }
}


/*//////////////////////////////////////*/
/* Código principal*/
 main()
{
    tDato dato;
    tPila p;
    tCola k;
    char rt;
    int error;
    cCrear(&k);
    pCrear(&p);
    inicol(&k);
    RevFinDat(&rt);
    while ( rt == 'S' && cLlena(&k)!= 1)
    {
        ingnum(&dato);
        cPoner(&k,dato);
        RevFinDat(&rt);
    }

    if (rt == 'S'){
        printf ("Error,no ha respetado el m%cximo de datos a ingresar. Estructura de datos llena.\n",160);
        printf("Desea comenzar nuevamente ? S\N \n");
        RevFinDat(&rt);
        if (rt =='S')
        {
           system("main.exe");
        }else{
           exit(-1);
        }

    }else
    {
       printf("Comienzo del proceso. \n");
       procesar(&k,&error,&p,&dato);
           if (error != 1){
                MostrarPil(&p);
                /*MostrarLisp ();
                MostrarLisi ();*/
          }else{
                printf("No ha sido posible continuar con el proceso.\n");
                printf("Finalizando sistema....\n");
          }
    }
}


void procesar(tCola k,tPila p,int error,tDato dato)
{
    printf ("El contenido de la variable dato es: %i \n",dato);
    error = 0;
    while(cVacia(&k)!=1 && error != 1)
    {
        cSacar(&k,&dato);
        if(dato % 2 == 0)
        {
            if(!pLlena(&p))
            {
                pPoner(&p,dato);
            } else {
                error = 1;
            }
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

