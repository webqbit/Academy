#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main(){
	Matriz* matriz = matriz_crear(4,1);
	matriz_escribir(matriz, 0,0,3);
	matriz_escribir(matriz, 1,0,4);
	matriz_escribir(matriz, 2,0,1);
	matriz_escribir(matriz, 3,0,0);
	matriz_imprimir(matriz);
	puts("---------------");

	Matriz* matriz1 = matriz_crear(1,4);
	matriz_escribir(matriz1, 0,0,0);
	matriz_escribir(matriz1, 0,1,4);
	matriz_escribir(matriz1, 0,3,1);
	matriz_escribir(matriz1, 0,2,7);
	matriz_imprimir(matriz1);
	puts("---------------");

	Matriz* producto = matriz_producto(matriz, matriz1);
	matriz_imprimir(producto);


	matriz_destruir(matriz);
	return 0;
}