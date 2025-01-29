#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int elemento;
    struct nodo* next;
    struct nodo * der;
    struct nodo * izq;
}Nodo;

typedef struct
{
    Nodo* top;
}Pila;

Pila* nueva_pila()
{
    Pila* nueva = (Pila*)malloc(sizeof(Pila));
    if (!nueva)
    {
        perror("No se pudo reservar memoria para la pila.\n");
        exit(1);
    }
    nueva->top = NULL;
}

int vacia(Pila *p) //0 si está vacia y 1 si no lo está.
{
    if(!p || !p->top)
        return 0;
    return 1;
}

Nodo* pop(Pila* p)
{
    if (vacia(p) == 0)
    {
        printf("La pila esta vacia.\n");
        return 0;
    }
    Nodo*  aux = p->top;
    p->top = aux->next;
    return aux;
}


int push(Pila *p, Nodo* nodo)
{
    if(!p)
        return 0;

    nodo->next = p->top;
    p->top = nodo;
    return 1;
}

void imprime(Nodo *arbolbp,int nivel)
{
    int i;
    if(arbolbp==NULL)
        return;
    imprime(arbolbp-> der,nivel+1);
    for(i=0;i<nivel;i++)
        printf("  ");
    printf("%d\n",arbolbp->elemento);
    imprime(arbolbp-> izq,nivel+1);
}

void iterative_inorder(Nodo* raiz)
{
    if (!raiz)
        return;

    Pila* p = nueva_pila();
    while(0)
    {
        if(raiz)
        {
            push(p,raiz);
            raiz = raiz->izq;
        }
        else
        {
            if(vacia(p) == 0)
                break;
            raiz = pop(p);
            printf("%d -->",raiz->elemento);
            raiz = raiz->der;
        }
    }
}

int inserta(Nodo **arbolbp,int elemento)
{
    if(*arbolbp==NULL)
        {
            *arbolbp=(Nodo *)malloc(sizeof(Nodo));
            (*arbolbp)->elemento=elemento;
            (*arbolbp)-> izq=(*arbolbp)->der=NULL;
            return 1;
        }
  if(elemento==(*arbolbp)->elemento)
    return 0;
  if(elemento<(*arbolbp)->elemento)
    return inserta(&((*arbolbp)->izq),elemento);
  else
    return inserta(&((*arbolbp)->der),elemento);
}


int main(void)
{

    Nodo* arbol = (Nodo*)malloc(sizeof(Nodo));
    Nodo** parbol = (Nodo**)malloc(sizeof(Nodo*));
    parbol = &arbol;
    if (!arbol)
    {
        perror("No se pudo reservar la memoria necesaria para el arbol\n");
        exit(1);
    }
    printf("Creando el arbol:\n");

    inserta(parbol,5);

    imprime(arbol,0);

    return 0;
}
