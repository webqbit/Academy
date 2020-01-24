#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

struct Matriz_{
	float* matriz;
	int filas;
	int columnas;
};


Matriz* matriz_crear(int filas, int columnas){
	Matriz* matriz = malloc(sizeof(Matriz));
	matriz->matriz = malloc(sizeof(float) * filas * columnas);
	matriz->filas = filas;
	matriz->columnas = columnas;
	return matriz;
}

void matriz_destruir(Matriz* matriz){
	free(matriz->matriz);
	free(matriz);
	return;
}

void matriz_escribir(Matriz* matriz, int fila, int columna, int dato){
	if(matriz->filas < fila || matriz->columnas < columna)
		return;
	matriz->matriz[(fila * matriz->columnas) + columna] = dato;
	return;
}

float matriz_leer(Matriz* matriz, int fila, int columna){
	 return matriz->matriz[(fila*matriz->columnas) + columna];
}

void matriz_imprimir(Matriz* matriz){
	int i = 0;
	int j = 0;
	for(; i < matriz->filas ; i++){
		for(; j < matriz->columnas ; j++){
			printf("%.2f\t",matriz->matriz[(i*matriz->columnas) + j]);
		}
		j = 0;
		puts("");
	}
}

int matriz_num_filas(Matriz* matriz) {
	return matriz->filas;
}

int matriz_num_columnas(Matriz* matriz) {
	return matriz->columnas;
}

void matriz_intercambiar_filas(Matriz* matriz, int fila1, int fila2){
	int i = 0;
	for(; i < matriz->columnas ; i++){
		float temp = matriz->matriz[(fila1*matriz->columnas)+i];
		matriz->matriz[(fila1*matriz->columnas)+i] = matriz->matriz[(fila2*matriz->columnas)+i];
		matriz->matriz[(fila2*matriz->columnas)+i] = temp;
	}
	return;
}

Matriz* matriz_suma(Matriz* A, Matriz* B){
	Matriz* suma = matriz_crear(A->filas, A->columnas);
	int i = 0;
	for(; i < A->filas * A->columnas ; i++)
		suma->matriz[i] = A->matriz[i] + B->matriz[i];
	return suma;
}

Matriz* matriz_producto(Matriz* A, Matriz* B){
	Matriz* producto = matriz_crear(A->filas, B->columnas);
	int i = 0, j = 0, k = 0;
	for(; i < A->filas ; i++){
		for(; j < A->columnas ; j++){
			for(; k < producto->columnas ; k++){
				producto->matriz[(i*producto->columnas)+j] += A->matriz[(i*producto->columnas)+k]*B->matriz[(k*producto->columnas)+j];

			}
			k = 0;
		}
		j = 0;
	}
	return producto;
}
