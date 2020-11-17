#ifndef LIB_TDA_LISTA_DIN_SE


typedef struct tDatos
{
    int clave;
}tDatos;


typedef struct Nodo
{
    tDatos* info;
    struct Nodo* sig;
}Nodo;

typedef struct tLista
{
    struct Nodo *cab;
    struct Nodo *actual;
}tLista;

void lCrear(tLista* l)
{
    (*l).cab = NULL;
}

int lLlena(tLista* l)
{
    Nodo* t;
    return (t = (Nodo*)malloc(sizeof(t))) == NULL;
}

int lVacia(tLista* l)
{
    return (*l).cab == NULL;
}

int lFin(tLista* l)
{
    return (*l).actual == NULL;
}

void lPpio(tLista* l)
{
    (*l).actual = (*l).cab;
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
    nuevo->info = x;
    nuevo->sig = l->cab;
    l->cab = nuevo;
    printf("El valor de sig es: %s\n",nuevo->sig);
}

void lInsertarFin(tLista* l, tDatos x)
{
    Nodo* aux;
    Nodo* nuevo;
    nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(l->cab == NULL) {
        l->cab = nuevo;
    } else {
        aux = l->cab;
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void lInsertarOrden(tLista* l, tDatos* datlist, char orden)
{
    Nodo *aux;
    Nodo *nuevo;
    nuevo = malloc(sizeof(Nodo));
    nuevo->info = datlist;
    nuevo->sig = NULL;

    if(l->cab == NULL)
    {
        l->cab = nuevo;
    } else {
        if(((datlist->clave > l->cab->info->clave)&& (orden == 'D'))|| ((datlist->clave < l->cab->info->clave)&& (orden == 'A')))
        {
            nuevo->sig = l->cab;
            l->cab = nuevo;
        } else {
            aux = l->cab;
            while((aux->sig != NULL) && (((datlist->clave > aux->sig->info->clave) && (orden == 'A')) || ((datlist->clave < aux->sig->info->clave) && (orden == 'D'))))
            {
                aux = aux->sig;
            }
           /* nuevo->sig = aux->sig;*/
            aux->sig = nuevo;
        }

    }
}

void lBorrarPpio(tLista* l)
{
    Nodo* aux;
    aux = l->cab;
    l->cab = l->cab->sig;
    free(aux);
}

void lBorrarActual(tLista* l)
{
    Nodo* aux;
    Nodo* t;
    aux = l->actual;
    if(l->actual == l->cab)
    {
        if(l->cab->sig == NULL)
        {
            l->cab = NULL;
            l->actual = NULL;
        }else{
            l->cab = l->cab->sig;
            l->actual = l->actual->sig;
        }
    }else{
        t = l->cab;
        while(t->sig != l->actual)
        {
            t = t->sig;
        }
        t->sig = l->actual->sig;
        l->actual = l->actual->sig;
    }
    free(aux);
}

void lBorrarFin(tLista* l)
{
    Nodo* aux;
    Nodo* h;
    aux = l->cab;
    if (l->cab->sig == NULL)
    {
        l->cab = NULL;
        free(aux);
    }else{
        while(aux->sig->sig != NULL)
        {
            aux = aux->sig;
        }
        h = aux->sig;
        aux->sig = NULL;
        free(h);
    }

}



void lBuscarOrdenado(tLista* l, tDatos x, int existe)
{
    Nodo* aux;
    existe = 0;
    if(l->cab != NULL)
    {
        if(l->cab->info->clave == x.clave)
        {
            existe = 1;
            l->actual = l->cab;
        }else{
            aux = l->cab;
            while((aux != NULL) && (l->cab->info->clave == aux->info->clave))
            {
                aux = aux->sig;
            }
            if(aux != NULL)
            {
                if(l->cab->info->clave < aux->info->clave)
                {
                    while((aux != NULL) && (aux->info->clave < x.clave))
                    {
                        aux = aux->sig;
                    }
                } else {
                    while (aux != NULL && aux->info->clave > x.clave)
                    {
                        aux = aux->sig;
                    }
                }
                if((aux != NULL) && (aux->info->clave = x.clave))
                {
                    existe = 1;
                    l->actual = aux;
                }
            }
        }
    }
}

#endif // LIB_TDA_LISTA_DIN_SE
