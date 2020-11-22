#include <stdio.h>
#include <stdlib.h>
#include "LIB_TDA_COLA_EST_CIR.h"
#include "LIB_TDA_PILA_EST_COR.h"
//#include "LIB_TDA_LISTA_DIN_SE.h"
/*#include "LIB_TDA_PILA_LSE.h"*/
#include "LIB_TDA_LISTA_DIN_DE_CIR.h"



 main()
{
    int x;
    int hay;
    hay = 1;
    tPila p;
    tLista l;
    tDatos dato;


    lCrear(&l);
    pCrear(&p);

    while(!pLlena(&p) && hay != 0){
        printf("Ingrese un numero: \n");
        scanf("%i", &x);
        pPoner(&p, x);
        do{
        printf("Seguir 1, Parar 0: \n");
        scanf("%i", &hay);
        } while (hay != 1 && hay != 0);
    }
    printf("Ingreso en la lista de los datos \n");
    while(!lLlena(&l) && !pVacia(&p)) {
        pSacar(&p, &x);
        dato.clave = x;
        lInsertarOrden(&l, dato, 'A');
    }

    RecorrerLista(&l);
    //MostrarPila(&p);
}


void RecorrerLista(tLista* l){

    tDatos x;

    lPpio(l);
    lInfo(l, &x);
    printf("%i ", x.clave);
    lSig(l);
    while(!lFin(l)){
        lInfo(l, &x);
        printf("%i ", x.clave);
        lSig(l);
    }
}

void MostrarPila(tPila* p){

tDato x;

    while(!pVacia(p)){
        pSacar(p, &x);
        printf("%i ", x);
    }
    printf("La pila ha quedado vacia");
}
