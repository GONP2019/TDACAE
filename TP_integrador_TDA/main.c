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
    for (int f=0;f<=p->cima;f++)
    {
        printf("Elemento de la pila: %i \n",p->elem[f]);
    }
}

/*//////////////////////////////////////*/
/* Inicializo la pila */
void inipil(tPila* p)
{
    for(int f=-1;f<=MAX-1;f++)
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
    int error;
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
                if(pVacia(&p)!= 1){  //Pregunto si no estan vacías antes de mostrar su contenido
                    MostrarPil(&p);
                }
                if(lVacia(&I) != 1){
                    RecorrerLista(&I);
                }
                if(lVacia(&PM) != 1){
                    RecorrerLista(&PM);
                }
                /*MostrarLisp ();
                MostrarLisi ();*/
          }else{
                printf("No ha sido posible continuar con el proceso.\n");
                printf("Finalizando sistema....\n");
          }
    }
}

void procesar(tCola* k,tPila* p,tLista* I,tLista* PM,int* error)
{
    tDato dato;
    tDatos datlis;
    tDatos datlis2;
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
        }else{
                if(!lLlena(&I))
               {
                   datlis.clave = dato;
                   lInsertarOrden(&I,&datlis,'D');
               } else {
                    error = 1;
               }

        }
        if(esprimo(dato) == 1)
        {
            if(!lLlena(&PM))
            {
                datlis2.clave = dato;
                lInsertarOrden(&PM,&datlis2,'A');

            } else {
                error = 1;
            }
        }

    }
}

void RecorrerLista(tLista* I){

tDatos x;
if(lVacia(&I) != 1){
    lPpio(&I);
    lInfo(&I, &x);
    printf(x.clave);
    lSig(&I);
    while(lFin(&I) != 1) {
        lInfo(&I, &x);
        printf(x.clave);
        lSig(&I);
    }
}

}


/*
void procesar(tCola k,tPila p,tLista I,tLista PM,int error,tDato dato)
{
    tDatos datlis;
    tDatos datlis2;
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
        }else{
                if(!lLlena(&I))
               {
                   datlis.clave = dato;
                   lInsertarOrden(&I,&datlis,'D');
               } else {
                    error = 1;
               }

        }
        if(esprimo(dato) == 1)
        {
            if(!lLlena(&PM))
            {
                datlis2.clave = dato;
                lInsertarOrden(&PM,&datlis2,'A');

            } else {
                error = 1;
            }
        }

    }
        printf("Comienzo de la impresion \n");
        tLista *aux ;
        aux = &PM;
        while (aux->cab != NULL)
        {
            printf("El numero primo es: %i \n",aux->cab->info->clave);
            aux->cab = aux->cab->sig;

        }

}



*/






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

