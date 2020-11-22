#include <stdio.h>
#include <stdlib.h>
#include "LIB_TDA_COLA_EST_CIR.h"
#include "LIB_TDA_PILA_EST_COR.h"
#include "LIB_TDA_LISTA_DIN_SE.h"
/*#include "LIB_TDA_PILA_LSE.h"*/
/*#include "LIB_TDA_LISTA_DIN_DE_CIR.h"*/


/*//////////////////////////////////////*/
/* Inicializo el array de tCola en ceros*/
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
/*//////////////////////////////////////*/
/* Recorro  la pila y muestro sus valores por pantalla*/
void MostrarPil(tPila* p)
{
    int x;
    if (!pVacia(p)){
        printf("------------------\n");
        printf("Comienzo de impresi%cn pila de pares \n",162);

        while (!pVacia(p))
        {
            pSacar(p,&x);
            printf("El n%cmero de la pila par es: %i \n",163,x);
        }
    }
}

void MostrarLisp (tLista* I)
{
    tDatos x;

    if (lVacia(I))
    {
        printf("------------------\n");
        printf("Comienzo de impresi%cn lista impares \n",162);
        lPpio(I);
        printf("El dato es: %i \n",x.clave);
        lInfo(&I,&x);
        printf("El n%cmero impar es:%i",163,x.clave);
        lSig(I);
        while(!lFin(I))
        {
            lInfo(I,&x);
            printf("El n%cmero impar es:%i",163,x.clave);
            lSig(I);
        }
    }
}

void MostrarLisprimo (tLista* PM)
{
    tDatos datPRIM;

    if (lVacia(PM))
    {
        printf("------------------\n");
        printf("Comienzo de impresi%cn lista primos \n",162);
        lPpio(PM);
        lInfo(PM,&datPRIM);
        printf("El número primo es:%i \n",datPRIM);
        lSig(PM);
        while(!lFin(PM))
        {
            lInfo(PM,&datPRIM);
            printf("El n%cmero primo es:%i",163,datPRIM);
            lSig(PM);
        }
    }
}



/*//////////////////////////////////////*/
/* Inicializo la pila */
void inipil(tPila* p)
{
    for(int f=0;f<=MAX-1;f++)
    {
      p->elem[f] = 0;
    }
}

/*//////////////////////////////////////*/
/* Función si es primo o no*/

int esprimo (tDato dato)
{
    int rest;
    int cantdiv = 0;
    int numdiv = 1;
    while (numdiv <= dato)
    {
        if (dato % numdiv == 0)
        {
            cantdiv += 1;
        }
        numdiv += 1;
    }
    if (cantdiv == 2)
    {
        return 1;
    }else
    {
        return 0;
    }
}

/*//////////////////////////////////////*/
/* Código principal*/
 main()
{
    tDato dato;
    tPila p;
    tCola k;
    tLista I;
    tLista PM;
    char rt;
    int error = 0;
    cCrear(&k);
    pCrear(&p);
    lCrear(&I);
    lCrear(&PM);
    inicol(&k);
    inipil(&p);
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
       procesar(&k,&p,&I,&PM,&error);
           if (error != 1){
                MostrarPil(&p);
                MostrarLisp(&I);
                MostrarLisprimo (&PM);
                printf("Finalizado");
          }else{
                printf("No ha sido posible continuar con el proceso.\n");
                printf("Finalizando sistema....\n");
          }
    }
}


void procesar(tCola k,tPila p,tLista I,tLista PM,int *error,tDato dato)
{

    tDatos datlis;
    while(cVacia(&k)!=1 && error != 1)
    {
        cSacar(&k,&dato);
        if(dato % 2 == 0)
        {
            if(!pLlena(&p))
            {
                pPoner(&p,dato);
            } else {
                *error = 1;
            }
        }else{
                if(!lLlena(&I))
               {
                   datlis.clave = dato;
                   lInsertarOrden(&I,datlis,'D');
               } else {
                    *error = 1;
               }

        }

        if(esprimo(dato) == 1)
        {
            if(!lLlena(&PM))
            {
                datlis.clave = dato;
                lInsertarOrden(&PM,datlis,'A');

            } else {
                *error = 1;
            }
        }

    }

}




