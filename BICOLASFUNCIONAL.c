/*


	Esta estructura de bicola está doblemente encadenada. Salud2
		a. creaVacia: Crea una bicola vacía.
		b. agnadeIzq: Añade un elemento a la bicola por la izquierda.
		c. agnadeDer: Añade un elemento a la bicola por la derecha.
		d. eliminaIzq: Elimina un elemento de la bicola por la izquierda.
		e. eliminaDer: Elimina un elemento de la bicola por la derecha.
		f. observaIzq: Devuelve el elemento que hay más a la izquierda.
		g. observaDer: Devuelve el elemento que hay más a la derecha.
		h. esVacia: Indica si la bicola está o no vacía.
		i. long: Devuelve la longitud de la bicola.
		j. asigna: copia una bicola en otra.
		k. libera: Destruye una bicola liberando toda la memoria que ocupaba.
		l. iguales: Indica si dos bicolas son iguales o no, en cuanto a los elementos que contienen ambas exactamente en el mismo orden.
*/


#include <stdio.h>
#include <stdlib.h>


struct INFO
{
	int num;
};

struct NODO
{
	struct INFO elemento;
	struct NODO *p_anterior;
	struct NODO *p_siguiente;
};

struct BICOLA
{
	int nodos;
	struct NODO *primero;
	struct NODO *ultimo;
};



/* FUNCIONES ******************************************************************/

// Pone los punteros de una bicola a NULL
void inicializarBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola sin inicializar..
	Poscondición:
					Se inicializa la Bicola poniéndola a NULL o 0 según el parámetro a inicializar.
	*/

	// Se solicita memoria al sistema para la nueva Bicola:
	struct BICOLA *temp = (struct BICOLA *) malloc(sizeof(struct BICOLA));

	temp->nodos		= 0;
	temp->primero	= NULL;
	temp->ultimo	= NULL;

	(*bicola) 		= temp;

};



// Inserta nodos por la izquierda:
void insertIzqBicola( struct BICOLA **bicola, int dato )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola y un parámetro de tipo entero con el dato a introducir.
	Poscondición:
					Se inserta al principio un nuevo Nodo en la Bicola.
	*/

	// Se solicita memoria al sistema para el nuevo Nodo:
	struct NODO *temp = (struct NODO *) malloc(sizeof(struct NODO));


	// Si la Bicola no tiene Nodos se inserta sin mas
	if( (*bicola)->primero == NULL )
	{
		temp->elemento.num	= dato;					// Se guarda el nuevo dato en el nuevo Nodo.
		temp->p_anterior	= NULL;					// Como es el primer Nodo de la Bicola, tanto el puntero anterior como el siguiente apuntan a NULL.
		temp->p_siguiente	= NULL;

		(*bicola)->primero	= temp;					// Como es el primer Nodo de la Bicola, se hace que primero y ultimo apunten ambos al mismo Nodo.
		(*bicola)->ultimo	= temp;
	}
	else
	{
		temp->elemento.num	= dato;					// Se guarda el dato nuevo en el nuevo Nodo.
		temp->p_anterior	= NULL;					// Como el nuevo Nodo va a ser el primero de la Bicola no apuntara a ningún Nodo anterior.
		temp->p_siguiente	= (*bicola)->primero;	// El nuevo Nodo apuntara al siguiente Nodo (donde ahora apunta "primero".

		(*bicola)->primero->p_anterior	= temp;		// El puntero anterior del primer Nodo se hace que apunte al nuevo Nodo.
		(*bicola)->primero				= temp;		// El puntero del primero se hace que apunte al nuevo Nodo que ahora es el primero.
	};


	(*bicola)->nodos += 1;							// Se suma 1 a la variable que guarda el numero de Nodos de la Bicola.

};



// Inserta nodos por la derecha:
void insertDerBicola( struct BICOLA **bicola, int dato )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola y un parámetro de tipo entero con el dato a introducir.
	Poscondición:
					Se inserta al final un nuevo Nodo en la Bicola.
	*/


	struct NODO *temp = (struct NODO *) malloc(sizeof(struct NODO));


	// Si la bicola esta vacía se introduce sin mas:
	if( (*bicola)->primero == NULL )
	{
		temp->elemento.num	= dato;
		temp->p_anterior	= NULL;
		temp->p_siguiente	= NULL;

		(*bicola)->primero	= temp;
		(*bicola)->ultimo	= temp;
	}
	  // Si contiene nodos, se introduce al final de todos ellos:
	else
	{
		temp->elemento.num	= dato;
		temp->p_anterior	= (*bicola)->ultimo;
		temp->p_siguiente	= NULL;

		(*bicola)->ultimo->p_siguiente	= temp;
		(*bicola)->ultimo				= temp;
	};


	(*bicola)->nodos += 1;

};



// Elimina el primer Nodo:
void eliminaIzqBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola.
	Poscondición:
					Se elimina el primer Nodo de la Bicola.
	*/


	struct NODO *aBorrar;


	// Si la Bicola esta vacía...
	if( (*bicola)->primero == NULL )
	{
		printf( "No puede eliminar Nodos de una Bicola vacía." );
	}
	  // Si solo hay un Nodo en la Bicola, al liberar la RAM del Nodo se inicializa la Bicola a los valores por defecto:
	else if( (*bicola)->nodos == 1 )
	{
		free(*bicola);
		inicializarBicola( bicola );
	}
	  // En caso contrario se elimina solo el primer Nodo:
	else if( (*bicola)->nodos > 1 )
	{
		aBorrar = (*bicola)->primero;

		(*bicola)->primero->p_siguiente->p_anterior	= NULL;
		(*bicola)->primero							= (*bicola)->primero->p_siguiente;
		free(aBorrar);

		(*bicola)->nodos -= 1;
	};

};



// Elimina el ultimo Nodo:
void eliminaDerBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola.
	Poscondición:
					Se elimina el ultimo Nodo de la Bicola.
	*/


	struct NODO *aBorrar;


	// Si la Bicola esta vacia...
	if( (*bicola)->primero == NULL )
	{
		printf( "No puede eliminar Nodos de una Bicola vacía." );
	}
	  // Si solo hay un Nodo en la Bicola, al liberar la RAM del Nodo se inicializa la Bicola a los valores por defecto:
	else if( (*bicola)->nodos == 1 )
	{
		free(*bicola);
		inicializarBicola( bicola );
	}
	else if( (*bicola)->nodos > 1 )
	{
		aBorrar = (*bicola)->ultimo;

		(*bicola)->ultimo->p_anterior->p_siguiente	= NULL;
		(*bicola)->ultimo							= (*bicola)->ultimo->p_anterior;
		free(aBorrar);

		(*bicola)->nodos -= 1;
	};

};



// Devuelve un true o un false si la Bicola contiene o no Nodos:
int tieneNodosLaBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola.
	Poscondición:
					Se devuelve un parámetro de tipo entero con valores true 1 o false 0 dependiendo de si la Bicola contiene Nodos o no.
	*/


	int resp = 0;

	if( (*bicola)->nodos != 0 )
		resp = 1;

	return resp;
};



// Libera la memoria RAM usada por la Bicola:
void borraLaBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola.
	Poscondición:
					Se libera la RAM usada por los Nodos contenidos en la Bicola.
	*/


	struct NODO *actual, *siguiente;
	actual = (*bicola)->primero;

	while( actual != NULL )
	{
		siguiente = actual->p_siguiente;
		free(actual);
		actual = siguiente;
	};

	*bicola = NULL;
};



// Devuelve el número de Nodos que contiene la Bicola:
int cuantosNodosTieneLaBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola.
	Poscondición:
					Se devuelve un parámetro de tipo entero que indica el número de Nodos que contiene la Bicola.
	*/

	return (*bicola)->nodos;
};



// Copia la bicola original a la bicola copia:
void copiarLaBicola( struct BICOLA **bicolaA, struct BICOLA **bicolaB )
{
	/*
	Precondición:
					Se han de recibir dos dobles punteros de tipo struct BICOLA a dos Bicolas.
	Poscondición:
					Se copia íntegramente la BicolaA en la BicolaB
	*/


	struct NODO *temp = (*bicolaA)->primero;


	// Si la BicolaB no esta vacia, se libera la RAM antes de copiar la BicolaA en BicolaB.
	if( (*bicolaB)->primero != NULL )
	{
		borraLaBicola( bicolaB );		// Se borra y se inicializa.
		inicializarBicola( bicolaB );
	};



	if( temp == NULL )
		printf( "La Bicola A no contiene Nodos, no se puede copiar nada." );
	else
	{
		while( temp != NULL )
		{
			// Se inserta al final:
			insertDerBicola( bicolaB, temp->elemento.num );

			// Se avanza un Nodo hacia delante:
			temp = temp->p_siguiente;
		};

	};

};



// Compara dos bicolas, devuelve true o false
int sonIgualesLasBicolas( struct BICOLA **bicolaA, struct BICOLA **bicolaB )
{
	/*
	Precondición:
					Se han de recibir dos dobles punteros de tipo struct BICOLA a dos Bicolas.
	Poscondición:
					Se devuelve un true 1 si las dos Bicolas son idénticas. En caso de que haya alguna diferencia entre ellas, ya sea en el contenido de sus Nodos o en la longitud de las Bicolas se devolverá un false 0.
	*/


	struct NODO *bicA = (*bicolaA)->primero;
	struct NODO *bicB = (*bicolaB)->primero;
	int salirBucle=0, resp=1;


	if( bicA == NULL ||  bicB == NULL )
	{
		resp = 0;

		if( bicA == NULL )
			printf( "Debe de insertar antes algún Nodo en la Bicola A\n" );

		if( bicB == NULL )
			printf( "Debe de insertar antes algún Nodo en la Bicola B\n" );
	}
	else
	{
		while( !salirBucle )
		{
			// Si alguno de los datos (num en este caso) del elemento de cada Nodo de la Bicola es diferente de la copia, devuelve false:
			if( bicA->elemento.num != bicB->elemento.num )
			{
				resp = 0;
				salirBucle = 1;
			}
			 // Si todo es igual...
			else
			{
				// Si los dos punteros siguen a puntando a algo diferente de NULL se avanza una posición:
				bicA = bicA->p_siguiente;
				bicB = bicB->p_siguiente;


				// Si alguno de los dos punteros ha llegado a NULL antes que el otro, las Bicolas están mal copiadas:
				if( (bicA != NULL  &&  bicB == NULL)  ||  (bicA == NULL  &&  bicB != NULL) )
				{
					resp = 0;
					salirBucle = 1;
				}
				  // Si por el contrario, las dos están a NULL a la vez, se termina la iteración y se devuelve true;
				else if( (bicA == NULL  &&  bicB == NULL) )
				{
					salirBucle = 1;
				};

			};

		};

	};

	return resp;

};



// imprime por pantalla el contenido de todos los Nodos de la Bicola:
void imprimeBicola( struct BICOLA **bicola )
{
	/*
	Precondición:
					Se recibe un doble puntero de tipo struct BICOLA a una Bicola.
	Poscondición:
					Se imprime por pantalla el contenido de todos los Nodos.
	*/


	struct NODO *bic = (*bicola)->primero;



	if( bic == NULL )
		printf( "La Bicola no contiene Nodos." );
	else
	{

		printf( "Su Bicola contiene: " );

		while( bic != NULL )
		{
			printf( "%i, ", bic->elemento.num );
			bic = bic->p_siguiente;
		};

		printf( "\n\n" );

	};

};

/****************************************************************** FUNCIONES */





/**************************************************************************************************************************/
main()
{
	enum opciones{ salir, insertIzq, insertDer, eliminaIzq, eliminaDer, impIzq, impDer, impTodos, quedanNodos, cuantosNodosHay, copiaBicola, sonBicolasIguales, borraBicola } opc;
	struct BICOLA *bicolaA;
	struct BICOLA *bicolaB;
	int eleccion, nuevoDato;


	// Se inicializan las dos Bicolas poniéndolas a NULL:
	inicializarBicola( &bicolaA );
	inicializarBicola( &bicolaB );



	// Menú de selección:
	do{
		printf( "\n\n" );
		printf( "Indique que desea hacer con los Nodos de la Bicola:\n\n" );
		printf( "   1. Añadir un Nodo por la izquierda\n" );
		printf( "   2. Añadir un Nodo por la derecha\n" );
		printf( "   3. Eliminar el primer Nodo\n" );
		printf( "   4. Eliminar el ultimo Nodo\n" );
		printf( "   5. Mostrar el primer Nodo\n" );
		printf( "   6. Mostrar el ultimo Nodo\n" );
		printf( "   7. Muestra todos los Nodos\n" );
		printf( "   8. Quedan Nodos?\n" );
		printf( "   9. Cuantos Nodos hay?\n" );
		printf( "  10. Copiar BicolaA a una nueva BicolaB\n" );
		printf( "  11. BicolaA es igual que BicolaB?\n" );
		printf( "  12. Borrar la BicolaA\n\n" );
		printf( "   0. Salir del programa.\n" );


		do{
			scanf( "%i", &eleccion );
		} while( eleccion < 0  &&  eleccion > 12 );
		opc = (enum opciones)(eleccion);


		printf( "\n\n" );


		switch( opc )
		{


			case insertIzq:
				printf( "Introduzca el número entero que contendrá el nuevo Nodo de la Bicola: " );
				scanf( "%i", &nuevoDato );
				insertIzqBicola( &bicolaA, nuevoDato );
			break;



			case insertDer:
				printf( "Introduzca el número entero que contendrá el nuevo Nodo de la Bicola: " );
				scanf( "%i", &nuevoDato );
				insertDerBicola( &bicolaA, nuevoDato);
			break;



			case eliminaIzq:
				eliminaIzqBicola( &bicolaA );
			break;



			case eliminaDer:
				eliminaDerBicola( &bicolaA );
			break;



			case impIzq:
				if( tieneNodosLaBicola( &bicolaA ) )
					printf( "El primer Nodo contiene un: %i\n", bicolaA->primero->elemento.num );
				else
					printf("La Bicola no contiene Nodos");
			break;



			case impDer:
				if( tieneNodosLaBicola( &bicolaA ) )
					printf( "El ultimo Nodo contiene un: %i\n", bicolaA->ultimo->elemento.num );
				else
					printf("La Bicola no contiene Nodos");
			break;



			case impTodos:
				imprimeBicola( &bicolaA );
			break;



			case quedanNodos:
				if( tieneNodosLaBicola( &bicolaA ) )
					printf( "La Bicola contiene Nodos." );
				else
					printf( "La Bicola esta vacía." );

			break;



			case cuantosNodosHay:
				printf( "La Bicola contiene %i Nodos.",  cuantosNodosTieneLaBicola( &bicolaA ) );
			break;



			case copiaBicola:
				copiarLaBicola( &bicolaA, &bicolaB );
			break;



			case sonBicolasIguales:
				if( sonIgualesLasBicolas( &bicolaA, &bicolaB ) )
					printf( "Las Bicolas son idénticas" );
				else
					printf( "Las Bicolas son diferentes" );
			break;



			case borraBicola:
				borraLaBicola( &bicolaA );		// Se borran todos los nodos...
				inicializarBicola( &bicolaA );	// ... y después se inicializa.
			break;



			case salir:
				system("clear");
			break;

		};


	} while( opc != salir );


	// Libera la RAM que pudiera quedar sin liberar:
	borraLaBicola( &bicolaA );
	borraLaBicola( &bicolaB );

};
