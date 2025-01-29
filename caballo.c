#include <stdio.h>

#define N 8

int tablero[N][N];
int pasos = 1;	// Pasos del caballo para escribirlos en el tablero.

void init(int tab[N][N])
{
	register int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			tablero[i][j] = 0;
}

void mostrar(int tab[N][N])
{
	register int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf(" %d ", tab[i][j]);
		putchar('\n');
	}
}

int mov_valido(int f, int c)
{
	if (f >= 0 && c >= 0 && f < N && c < N)
		return 1;
	return 0;
}

int caballo(int f, int c, int ind)
{
	// Pregunta si la posicion ya esta ocupada.
	if (tablero[f][c] != 0)
		return 0;
	// La marca por si acaso la posicion actual es una posilble solucion.
	tablero[f][c] = pasos++;

	// Pregunta si se cumple el caso base, que ind sea igual al numero de casillas
	// del tablero.
	if (ind == (N * N) - 1)
		return 1;

	// abajo-derecha
	if (mov_valido(f+2, c+1) && caballo(f+2, c+1, ind+1))
		return 1;

	// derecha-abajo
	if (mov_valido(f+1, c+2) && caballo(f+1, c+2, ind+1))
		return 1;

	// derecha-arriba
	if (mov_valido(f-1, c+2) && caballo(f-1, c+2, ind+1))
		return 1;

	// arriba-derecha
	if (mov_valido(f-2, c+1) && caballo(f-2, c+1, ind+1))
		return 1;

	// arriba-izquierda
	if (mov_valido(f-2, c-1) && caballo(f-2, c-1, ind+1))
		return 1;

	// izquierda-arriba
	if (mov_valido(f-1, c-2) && caballo(f-1, c-2, ind+1))
		return 1;

	// izquierda-abajo
	if (mov_valido(f+1, c-2) && caballo(f+1, c-2, ind+1))
		return 1;

	// abajo-izquieda
	if (mov_valido(f+2, c-1) && caballo(f+2, c-1, ind+1))
		return 1;

	// Desmarca la posicion.
	tablero[f][c] = 0;
	pasos--;
	return 0;
}

int main(void)
{
	init(tablero);
	mostrar(tablero);
	if (caballo(0, 0, 0))
		printf("Solucion encontrada.\n");
	else
		printf("No se encontro una solucion.\n");
	mostrar(tablero);
	return 0;
}
