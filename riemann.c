#include <stdio.h>

/*
 * Calcula la suma de Riemann de una funcion f, en el intervalo [a, b].
 * La formula es:
 *
 *    n
 *   ---
 *   \    f(xi) * delta x;
 *   /
 *   ---
 *   i=1
 *	
 * Donde xi = a + i*delta x
 */


// Limite de la sumatoria. Mientras mas grande, mas preciso el resultado.
#define N 10000


// La funcion a aplicarle la suma de Riemann. Pueden cambiarla.
// Esta es una parabola.
float func(float x)
{
	return x*x;
}

/*
 * Lo que se hace es que en cada iteracion (o llamada recursiva)
 * se calcula el xi. Se evalua la funcion en ese valor y se multiplica
 * por el delta x. Ese resultado se le suma al acumulado, y se repite.
 */

/* Iterativa
 * deltax --> delta x
 * f --> funcion que le van a aplicar la suma
 * a --> limite inferior
 * b --> limite superior
 */

float integral1(float deltax, float (*f)(float), float a, float b)
{
	float acumulado = 0.0;
	float xi;
	int i;

	// i = 0 hasta N-1 se aproxima por la izquierda.
	// i = 1 hasta N se aproxima por la derecha.
	// Ustedes eligen.
	for (i = 1; i <= N; i++) {
		xi = a + (i * deltax);
		acumulado += (*f)(xi) * deltax;
	}
	return acumulado;
}

// Recursiva
// i --> contador de la sumatoria
// acumulado --> el resultado acumulado hasta ahora
float integral2(float deltax, float (*f)(float), float a, float b, int i, float acumulado)
{
	if (i == N)
		return 0.0;

	float xi = a + (i*deltax);
	float resultado_parcial = (*f)(xi) * deltax;

	acumulado += integral2(deltax, f, a, b, i+1, resultado_parcial);
	return acumulado;
}

// Recursiva de cola
float integral3(float deltax, float(*f)(float), float a, float b, int i, float acumulado)
{
	if (i == N)
		return acumulado;	// La condicion de parada devuelve el resultado final.

	float xi = a + (i*deltax);
	float resultado_parcial = acumulado + ((*f)(xi) * deltax);
	return integral3(deltax, f, a, b, i+1, acumulado + (*f)(xi)*deltax);
}


int main(void)
{
	float a = 0;
	float b = 2;
	float delta = (float) (b-a) / N;	// Formula del delta x.

	float resultado_iterativa = integral1(delta, func, a, b);
	float resultado_recursiva = integral2(delta, func, a, b, 1, 0.0);
	float resultado_recursiva_cola = integral3(delta, func, a, b, 1, 0.0);

	printf("Iterativa\t\t= %.2f\n", resultado_iterativa);
	printf("Con recursion\t\t= %.2f\n", resultado_recursiva);
	printf("Con recursion de cola\t= %.2f\n", resultado_recursiva_cola);

	return 0;
}
