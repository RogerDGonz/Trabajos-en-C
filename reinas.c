#include <stdio.h>

#define N 8
#define REINA 'Q'


// Retorna 1 si es seguro colocar la reina en la posicion (f,c)
// 0 sino.
int esSeguro(char tab[N][N], int f, int c)
{
	int i, j;

	for (i = 0; i < f; i++)
		for (j = 0; j < N; j++)
			if (tab[i][j] == REINA)
				if ((c == j) || (f-c == i-j) || (f+c == i+j))
					return 0;
	return 1;
}

int reinas(char tab[N][N], int fila)
{
	// Fin de la recursion porque salimos de las filas del tablero
	if (fila == N)
		return 1;

	int c;

	// Recorre las columnas de la fila
	for (c = 0; c < N; c++) {
		// Pregunta si es seguro colocar a la reina en esta posicion
		if (esSeguro(tab, fila, c)) {

			// Si lo es, marcamos esta posicion
			tab[fila][c] = REINA;
		
			// Pregunta si podemos hacer lo mismo en la fila siguiente
			if (reinas(tab, fila+1) == 1)
				return 1;
			else
				// Si resulta que no, desmarcamos la posicion - backtracking
				tab[fila][c] = '.';
		}
	}
	return 0;
}

void mostrar(char tab[N][N])
{
	register int i, j;
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%c ", tab[i][j]);
		putchar('\n');
	}
}

int main(void)
{
	char tablero[N][N];
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			tablero[i][j] = '.';

	if (reinas(tablero, 0))
		mostrar(tablero);
	return 0;
}
