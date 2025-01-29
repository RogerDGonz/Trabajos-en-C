#include <stdio.h>
#include <stdlib.h>

#define MAX_FILAS 20
#define MAX_COLUMNAS 40

// Se definen las estructuras para el laberinto

char laberinto[MAX_FILAS][MAX_COLUMNAS];

int buscar(int f, int c)
{
	// Guarda el caracter actual, para poder desmarcar el camino en caso de que este no sirva.
	char ch = laberinto[f][c];
	
	// Como la posicion inicial al inicio del algoritmo esta marcada con 'R', se marca
	// como un espacio disponible para poder continuar. Sino, siempre va a retornar falso.
	if (laberinto[f][c] == 'R')
		laberinto[f][c] = ' ';

	// Si se sale de los limites del laberinto, el camino no sirve.
	if (f < 0 || f >= MAX_FILAS || c < 0 || c >= MAX_COLUMNAS)
		return 0;

	// Si encuentra el queso, entonces termina el algoritmo.
	if (laberinto[f][c] == 'Q')
		return 1;

	// Si encuentra un obstaculo, entonces el camino no sirve.
	if (laberinto[f][c] != ' ')
		return 0;

	// Si no pasa nada de lo anterior, entonces marca la posicion como un posible camino a seguir.
	laberinto[f][c] = 'r';

	// Se puede mover al norte.
	if (buscar(f-1, c))
		return 1;

	// Se puede mover al sur.
	if (buscar(f+1, c))
		return 1;

	// Se puede mover al este.
	if (buscar(f, c+1))
		return 1;

	// Se puede mover al oeste.
	if (buscar(f, c-1))
		return 1;

	// Si nada de lo anterior pasa, entonces el camino no sirve, se desmarca,
	// luego se retrocede y se evalua la siguiente opcion. Esto es el "back" en "backtracking".
	laberinto[f][c] = ch;
	return 0;
}
