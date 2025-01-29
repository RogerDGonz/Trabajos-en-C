#include <stdio.h>
#include <stdlib.h>

//estructura del nodo
typedef struct nodo{
        int dato;
        struct nodo *sig;
        int longitud;
}* Nodo;

//Mostrar la lista
void mostrar_lista(Nodo lista){

	Nodo temporal = lista;
	while (temporal != NULL){
		printf("%d   ",temporal->dato);
		temporal = temporal->sig;
	}
	puts("NULL");

}

//crear nodo
Nodo crear_nodo(int valor){
     Nodo nuevo =(Nodo)malloc(sizeof(struct nodo));

     if (nuevo == NULL){
        fprintf(stderr,"crear nodo error en malloc");
        exit(-1);
     }
     nuevo->dato = valor;
     nuevo->sig = NULL;

    return nuevo;
}



//primer elemento de la lista.
Nodo primero(Nodo lista){


    if (lista == NULL){
        printf("La lista esta vacia\n");
    }
    else
    {
        lista->sig= NULL;
    }
    return lista;
}

//la lista sin el primer elemento
Nodo cola(Nodo lista){

    if (lista == NULL){
        printf("La lista esta vacia\n");
        return NULL;
    }
    else
        return lista->sig;
}
//Anadir al frente
Nodo add_front(Nodo lista, int valor){
	Nodo newp = crear_nodo(valor);

	if (lista == NULL){
		return newp;
	}

	newp->sig = lista;
	lista = newp;
	return lista;
}

//Anadir al final
Nodo add_end(Nodo lista, int valor){
	Nodo nuevo = crear_nodo(valor);
	Nodo temp = lista;

	if (lista == NULL){
		return nuevo;
	}

	while (temp->sig != NULL){
		temp = temp->sig;
	}

	temp->sig = nuevo;

	return lista;
}

//Crear lista
Nodo crear_lista(Nodo lista){
    int valor = 1;
    printf("\nIngrese los elementos de la lista\n");
    printf("ingrese el \"0 para finalizar\n");

    while (valor != 0){
        printf("Ingrese el nuevo elemento de la lista\n");
        scanf("%d",&valor);
        if (valor != 0)
        lista = add_end(lista,valor);
    }
    mostrar_lista(lista);
    printf("\n");

    return lista;
}

//contar los elementos de la lista
int contar(Nodo lista){
    Nodo temp = lista;
    int cont=0;
    for(;temp != NULL; temp = cola(temp)){
       cont++;
    }
    return cont;
}



//comparar dos listas si son iguales o no, retorna -1 si las dos listas estan vacias, 1 si las listas son iguales y 0 si las listas son diferentes
int iguales(Nodo lista1, Nodo lista2){
    if (lista1 == NULL || lista2 == NULL){
        printf("Una o las dos listas estan vacias.\n");
        return -1;
    }

    while (lista1 != NULL && lista2 !=NULL){
        if (lista1->dato == lista2->dato){
            lista1 = lista1->sig;
            lista2 = lista2->sig;
            if (lista1 == NULL && lista2 ==NULL){
                return 1; // las listas son iguales
            }
            if (lista1 == NULL || lista2 == NULL){
                return 0; // las listas no son iguales
            }
        }
        else
            return 0; // las listas no son iguales
    }
}


//Concatenar dos listas, devuelve la lista nueva, pero modifica la prjmera lista.
Nodo concatenar(Nodo lista1, Nodo lista2){
    Nodo temp = lista1;
    if (temp == NULL){
        return lista2; //cuando la lista 1 esta vacia devuelve la lista 2
    }

    while (temp->sig != NULL){
            temp = temp->sig;
    }
    temp->sig = lista2;

    return lista1; //lista 1 ahora es la union de lista 1 y lista 2
}
int main(void){
    Nodo lista1 = NULL, lista2 = NULL;

    int valor;
    //Crear las listas
    lista1 = crear_lista(lista1);
    lista2 = crear_lista(lista2);

/*
    //Calcular la longitud de la lista
    printf("La lista 1 tiene %d elementos\n",contar(lista1));


    //Cola de las listas
    printf("\ncola de la lista 1:\n");
    lista1 = cola(lista1);
    mostrar_lista(lista1);

    printf("cola de la lista 2:\n\n");
    lista2 = cola(lista2);
    mostrar_lista(lista2);
*/
   if (iguales(lista1,lista2) == 1){
        printf("Las listas son iguales\n");
   }
   else
        printf("Las listas no son iguales\n");

    printf("Union de las dos listas ingresadas:\n");
    mostrar_lista(concatenar(lista1,lista2));

    return 0;
}

