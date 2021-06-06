#include <stdio.h>
#include <stdlib.h>

#define FALSE 0 //define se usa para establecer al False como un cero en todo el programa
#define TRUE 1
int main ()
{
	int done = FALSE; // El valor de done sera cero.
	int j = 0; // El contador j en la salida sera cero

	while (!done) // Usamos el loop de while para imprimir todas las iteraciones para la memoria de asignación (alloc memory).
			// Este bucle while no está definido, ya que de  hecho no va a llegar a 1 en el bucle.
	{
	int n = 10000000;
	int* a = (int*)malloc(n * sizeof(int)); // usando malloc para establecer el tamaño de la matriz (array) "a" y
						// establecer el tamaño 10000000 * 4 (considerando el tamaño de int como 4)

	int i;
	for (i=0; i < n; i++) // El bucle for, establece el valor i en el puntero "a" asignado dinámicamente.
		a[i] = i;

	j++;
	printf(" %d\n", j); // Imprime los valores, mientras corre el loop de while.
	}


	return 0;
}

	
	//item if (!a){
	//	perror(NULL);
	//	exit (1);
//}







