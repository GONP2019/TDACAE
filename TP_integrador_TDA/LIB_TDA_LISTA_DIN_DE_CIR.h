#ifndef LIB_TDA_LISTA_DIN_DE_CIR_H_INCLUDED
#define LIB_TDA_LISTA_DIN_DE_CIR_H_INCLUDED



#endif // LIB_TDA_LISTA_DIN_DE_CIR_H_INCLUDED

/*typedef int tClave;*/

typedef struct tDatos
{
    int clave;
}tDatos;


typedef struct Nodo
{
    tDatos info;
    struct Nodo* sig;
    struct Nodo* ant;
}Nodo;

typedef struct tLista
{
    struct Nodo* cab;
    struct Nodo* actual;
}tLista;

void lCrear(tLista *l)
{
    l->cab = NULL;
}


int lLlena(tLista* l)
{
    Nodo* t;
    return (t = (Nodo*)malloc(sizeof(t))) == NULL;
}

int lVacia(tLista* l)
{
    return l->cab == NULL;
}

int lFin(tLista* l)
{
    return l->actual == l->cab;
}

void lPpio(tLista* l)
{
    l->cab = l->cab;
}

void lInfo(tLista* l, tDatos* x)
{
    *x = l->actual->info;
}

void lModificar(tLista* l, tDatos x)
{
    l->actual->info = x;
}

void lSig(tLista* l)
{
    l->actual = l->actual->sig;
}

void lInsertarPpio(tLista* l, tDatos x)
{
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = x;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if (l->cab == NULL){
        l->cab = nuevo;
        l->cab->sig = l->cab;
        l->cab->ant = l->cab;
    } else {
        nuevo->sig = l->cab;
        nuevo->ant = l->cab->ant;
        l->cab->ant->sig = nuevo;
        l->cab->ant = nuevo;
        l->cab = nuevo;

    }
}

void lInsertarFin(tLista* l, tDatos x)
{
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->info = x;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if(l->cab == NULL) {
        l->cab = nuevo;
        nuevo->sig = l->cab;
        nuevo->ant = l->cab;
    } else {
        nuevo->sig = l->cab;
        nuevo->ant = l->cab->ant;
        l->cab->ant->sig = nuevo;
        l->cab->ant = nuevo;
    }
}

void lInsertarOrden(tLista* l, tDatos dato, char orden)
{
    Nodo* aux;
    Nodo* nuevo;
    nuevo =(Nodo*)malloc(sizeof(Nodo));
    nuevo->info = dato;
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if(l->cab == NULL)
    {
        l->cab = nuevo;
        l->cab->sig = nuevo;
        l->cab->ant = nuevo;
    } else {

        if(((dato.clave > l->cab->info.clave)&& (orden = 'D'))|| ((dato.clave < l->cab->info.clave)&& (orden = 'A')))
        {
            nuevo->sig = l->cab;
            nuevo->ant = l->cab->ant;
            l->cab->ant->sig = nuevo;
            l->cab->ant = nuevo;
            l->cab = nuevo;
        } else {
            Nodo* pr = l->cab;
            Nodo* ult = l->cab->ant;
            if (orden = 'A'){
                while ((pr->info.clave < ult->info.clave) && (pr->info.clave < dato.clave) && (ult->info.clave > dato.clave))
                {
                    pr = pr->sig;
                    ult = ult->ant;
                }
            }else {

                    while ((pr->info.clave > ult->info.clave) && (pr->info.clave > dato.clave) && (ult->info.clave > dato.clave))
                    {
                            pr = pr->sig;
                            ult = ult->ant;
                    }

            }
            if ((pr->info.clave >= dato.clave && orden = 'A') || (pr->info.clave <= dato.clave && orden = 'D'))
            {
                nuevo->sig = pr;
                nuevo->ant = pr->ant;
                pr->ant->sig = nuevo;
                pr->ant = nuevo;

            }else {
                if ((ult->info.clave >= dato.clave && orden = 'A') || (ult->info.clave <= dato.clave && orden = 'D')){

                    nuevo->sig = ult->sig;
                    nuevo->ant = ult;
                    ult->sig->ant = nuevo;
                    ult->sig = nuevo;
                }



            }

        }

    }
}

void lBorrarPpio(tLista* l)
{
    Nodo* aux;
    aux = l->cab;
    if (l->cab->sig = l->cab)
    {
        l->cab = NULL;
    }else{
        l->cab->sig->ant = l->cab->ant;
        l->cab->ant->sig = l->cab->sig;
        l->cab = l->cab->sig;

    }
    free(aux);
}

void lBorrarActual(tLista* l)
{
    Nodo* t;
    t = l->actual;
    if(l->cab == l->actual)
    {
        if(l->cab->sig == l->cab)
        {
            l->cab = NULL;
            l->actual = NULL;
        }else{
            t = l->cab;
            l->cab->sig->ant = l->cab->ant;
            l->cab->ant->sig = l->cab->sig;
            l->cab = l->cab->sig;
            l->actual = l->cab;
        }
    }else{
        l->actual->sig->ant = l->actual->ant;
        l->actual->ant->sig = l->actual->sig;
        l->actual = l->actual->sig;
    }
    free(aux);
}

void lBorrarFin(tLista* l)
{
    Nodo* aux;

    if(l->cab->sig = l->cab){
        aux = l->cab;
        l->cab = NULL;
    }else{
        aux = l->cab->ant;
        aux->ant->sig = l->cab;
        l->cab->ant = aux->ant;
    }
    free(aux);
}

void lBuscarOrdenado(tLista* l, tDatos x, int* existe)
{
    Nodo* pr;
    Nodo* ult;

    if(l->cab == NULL){
        *existe = 1;
    }else{
        if(l->cab->info.clave == x.clave){
            *existe = 1;
            l->actual = l->cab;
        } else{
            pr = l->cab;
            ult = l->cab->ant;
            if(pr->info.clave < ult->info.clave){
                while((pr->info.clave < ult->info.clave) && (pr->info.clave < x.clave) && (ult->info.clave > x.clave)){
                    pr = pr->sig;
                    ult = ult->ant;
                }
            } else {
                while((pr->info.clave > ult->info.clave) && (pr->info.clave > x.clave) && (ult->info.clave < x.clave)){
                    pr = pr->sig;
                    ult = ult->ant;
                }
            }
            if(pr->info.clave == x.clave){
                *existe = 1;
                l->actual = pr;
            } else {
                if(ult->info.clave == x.clave){
                    *existe = 1;
                    l->actual = ult;
                } else {
                    *existe = 0;
                }
            }
        }
    }
}

