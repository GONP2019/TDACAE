#ifndef LIB_TDA_LISTA_DIN_SE
#endif // LIB_TDA_LISTA_DIN_SE

typedef struct tDato
{
    int clave;
}

typedef struct nodo
{
    tDato info;
    struct nodo* sig;
}Nodo;

typdef struct tLista
{
    struct nodo* cab;
    struct nodo* actual;
}tLista;

void lCrear(tLista* l)
{
    (*l)->cab = NULL;
}

int lLlena(tLista* l)
{
    return 0;
}

int lVacia(tLista* l)
{
    return (*l)->cab == NULL;
}

int lFin(tLista* l)
{
    return (*l)->actual == NULL;
}

void lPpio(tLista* l)
{
    (*l)->actual = (*l)->cab
}

void lInfo(tLista* l, int* x)
{
    *x = (*l)->actual
}

void Modificar(tLista* l, int x)
{
    (*l)->actual = x
}

void lSig(tLista* l)
{
    (*l)->actual = (*l)->actual->sig
}

void lInsertarPpio(tLista* l, tDato x)
{
    Nodo* nodo;
    nodo=(Nodo*)malloc(sizeof(Nodo));
    nodo->info = x;
    nodo->sig = (*l)->cab;
    (*l)->cab = nuevo;
}

void lInsertarFin(tLista* l, tDato x)
{
    Nodo* aux;
    Nodo* nodo;
    nodo=(Nodo*)malloc(sizeof(Nodo));
    if((*l)->cab == NULL) {
        (*l)->cab = nuevo;
    } else {
        aux = (*l)->cab
        while(aux->sig != NULL)
        {
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void lInsertarOrden(tLista* l, tDato x, char orden)
{
    Nodo* aux;
    Nodo* nodo;
    nodo=(Nodo*)malloc(sizeof(Nodo));
    if((*l)->cab == NULL)
    {
        (*l)->cab = nodo;
    }else{
        if((x->clave > (l*)->cab->info->clave && orden = 'D') || (x->clave < (l*)->cab->info->clave && orden = 'A'))
        {
            nuevo-sig = (*l)->cab;
            (*l)->cab = nodo;
        } else {
            aux = (*l)->cab;
            while(aux->sig != NULL && (x->clave > aux->sig->info->clave && orden = 'A') || (x->clave < aux->sig->info->clave && orden = 'D'))
            {
                aux = aux->sig;
            }
            nuevo->sig = aux->sig;
            aux->sig = nodo;
        }
    }
}

void lBorrarPpio(tLista* l)
{
    Nodo* aux;
    aux = (*l)->cab;
    (*l)->cab = (*l)->cab->sig;
    free(aux);
}

void lBorrarActual(tLista* l)
{
    Nodo* aux;
    Nodo* t;
    aux = (l*)->actual
    if((*l)->actual = (*l)->cab)
    {
        if((*l)->cab->sig = NULL)
        {
            (*l)->cab = NULL;
            (*l)->actual = NULL;
        }else{
            (*l)->cab = (*l)->cab->sig;
            (*l)->actual = (*l)->actual->sig;
        }
    }else{
        t = (*l)->cab;
        while(t->sig != (*l)->actual)
        {
            t = t->sig;
        }
        t->sig = (*l)->actual->sig;
        (*l)->actual = (*l)->actual->sig;
    }
    free(aux);
}

void lBuscarOrdenado(tLista* l, int x->clave, int existe)
{
    Nodo* aux;
    *existe = 0;
    if((*l)->cab != NULL)
    {
        if((*l)->info->clave = x)
        {
            existe = 1;
            (*l)->actual = (*l)->cab;
        }else{
            aux = (*l)->cab;
            while((aux != NULL) && (*l)->cab->info->clave = aux->info->clave)
            {
                aux = aux->sig;
            }
            if(aux != NULL)
            {
                if((*l)->cab->info->clave < aux->info->clave)
                {
                    while(aux != nil && aux->info->clave < x)
                    {
                        aux = aux->sig;
                    }
                } else {
                    while (aux != NULL && aux->info->clave > x)
                    {
                        aux = aux->sig;
                    }
                }
                if(aux != NULL && aux->info->clave = x)
                {
                    existe = 1;
                    (*l)->actual = aux;
                }
            }
        }
    }
}
#endif
