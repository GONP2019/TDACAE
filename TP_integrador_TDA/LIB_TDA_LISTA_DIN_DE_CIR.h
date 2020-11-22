#ifndef LIB_TDA_LISTA_DIN_DE_CIR_H_INCLUDED
#define LIB_TDA_LISTA_DIN_DE_CIR_H_INCLUDED



#endif // LIB_TDA_LISTA_DIN_DE_CIR_H_INCLUDED

typedef int tClave;

typedef struct tDatos
{
    int clave;
}tDatos;


typedef struct Nodo
{
    tDatos* info;
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
    x->clave = l->actual->info;
}

void lModificar(tLista* l, tDatos x)
{
    l->actual->info = &x;
}

void lSig(tLista* l)
{
    l->actual = l->actual->sig;
}

void lInsertarPpio(tLista* l, tDatos* x)
{
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if (l->cab == NULL){
        l->cab = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        nuevo->sig = l->cab;
        nuevo->ant = l->cab->ant;
        l->cab->ant->sig = nuevo;
        l->cab->ant = nuevo;

    }
}

void lInsertarFin(tLista* l, tDatos x)
{
    Nodo* aux;
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->sig = NULL;
    nuevo->ant = NULL;

    if(l->cab == NULL) {
        l->cab = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        aux = l->cab;
        while(aux->sig != l->cab)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->ant = aux;
        nuevo->sig = l->cab;
        l->cab->ant = nuevo;
    }
}

void lInsertarOrden(tLista* l, tDatos* dato, char orden)
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
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {

        if(((dato->clave > l->cab->info->clave)&& (orden = 'D'))|| ((dato->clave < l->cab->info->clave)&& (orden = 'A')))
        {
            nuevo->sig = l->cab;
            l->cab->ant->sig = nuevo;
            nuevo->ant = l->cab->ant;
            l->cab->ant = nuevo;
        } else {
            aux = l->cab;
            while((aux->sig != l->cab) && (((dato->clave > aux->sig->info->clave) && (orden = 'A')) || ((dato->clave < aux->sig->info->clave) && (orden = 'D'))))
            {
                aux = aux->sig;
            }
            nuevo->sig = aux->sig;
            aux->sig->ant = nuevo;
            aux->sig = nuevo;
            nuevo->ant = aux;

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
        l->actual = NULL;
    }else{
    l->cab->ant->sig = l->cab->sig;
    l->cab->sig->ant = l->cab->ant;
    l->cab = l->cab->sig;
    free(aux);
    }
}

void lBorrarActual(tLista* l)
{
    Nodo* aux;
    Nodo* t;
    aux = l->actual;
    if(l->actual == l->cab)
    {
        if(l->cab->sig == l->cab)
        {
            l->cab = NULL;
            l->actual = NULL;
        }else{
            l->actual = l->cab->sig;
            l->cab->ant->sig = l->actual;
            l->actual->ant = l->cab->ant;
            l->cab = l->actual;
        }
    }else{
        t = l->cab;
        while(t->sig != l->actual)
        {
            t = t->sig;
        }
        t->sig = l->actual->sig;
        l->actual->sig->ant = t;
        l->actual = l->actual->sig;
    }
    free(aux);
}

void lBorrarFin(tLista* l)
{
    Nodo* aux;
    Nodo* aux2;
    if(l->cab->sig = l->cab){
        aux = l->cab;
        l->cab = NULL;
        l->actual = NULL;
    }else{
        aux = l->cab->ant;
        aux2 = aux->ant;
        aux2->sig = l->cab;
        l->cab->ant = aux2;
        l->actual = l->cab;
    }
    free(aux);
}

void lBuscarOrdenado(tLista* l, tClave x, int existe)
{
    Nodo* pr;
    Nodo* ult;

    if(l->cab == NULL){
        existe = 1;
    }else{
        if(l->cab->info->clave == x){
            existe = 1;
            l->actual = l->cab;
        } else{
            pr = l->cab;
            ult = l->cab->ant;
            if(pr->info->clave < ult->info->clave){
                while((pr->info->clave < ult->info->clave) && (pr->info->clave < x) && (ult->info->clave > x)){
                    pr = pr->sig;
                    ult = ult->ant;
                }
            } else {
                while((pr->info->clave > ult->info->clave) && (pr->info->clave > x) && (ult->info->clave < x)){
                    pr = pr->sig;
                    ult = ult->ant;
                }
            }
            if(pr->info->clave == x){
                existe = 1;
                l->actual = pr;
            } else {
                if(ult->info->clave == x){
                    existe = 1;
                    l->actual = ult;
                } else {
                    existe = 0;
                }
            }
        }
    }
}

