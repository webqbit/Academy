#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

/*
** Implementacion utilizando un arreglo bidimensional (arreglo de punteros a arreglo)
*/

struct Matriz_ {
	int filas;
	int columnas;
	float** matriz;
};


Matriz* matriz_crear(int filas, int columnas) {
	Matriz* matriz = malloc(sizeof(Matriz));
	matriz->matriz = malloc(sizeof(float*)*filas);
	int i = 0;
	for(; i < filas ; i++)
		matriz->matriz[i] = malloc(sizeof(float)*columnas);
	matriz->filas = filas;
	matriz->columnas = columnas;
	return matriz;
}

void matriz_destruir(Matriz* matriz) {
	int i = 0;
	for(; i < matriz->filas ; i++)
		free(matriz->matriz[i]);
	free(matriz->matriz);
}

float matriz_leer(Matriz* matriz, int fila, int columna) {
	return matriz->matriz[fila][columna];
}

void matriz_escribir(Matriz* matriz, int fila, int columna, int dato) {
	matriz->matriz[fila][columna] = dato;
	return;
}

void matriz_imprimir(Matriz* matriz){
	int i = 0, j = 0;
	for(; i < matriz->filas; i++){
		for(; j < matriz->columnas ; j++)
			printf("%.2f\t",matriz->matriz[i][j]);	
		puts("");
		j = 0;
	}
	return;
}

int matriz_num_filas(Matriz* matriz) {
	return matriz->filas;
}

int matriz_num_columnas(Matriz* matriz) {
	return matriz->columnas;
}

void matriz_intercambiar_filas(Matriz* matriz, int fila1, int fila2){
	float* temp = matriz->matriz[fila1];
	matriz->matriz[fila1] = matriz->matriz[fila2];
	matriz->matriz[fila2] = temp;
	return;
}

Matriz* matriz_suma(Matriz* A, Matriz* B){
	Matriz* suma = matriz_crear(A->filas, A->columnas);
	int i = 0, j = 0;
	for(; i < A->filas ; i++)
		for(; j < A->columnas ; j++)
			suma->matriz[i][j] = A->matriz[i][j] + B->matriz[i][j];
	return suma;
}

Matriz* matriz_producto(Matriz* A, Matriz* B){
	Matriz* producto = matriz_crear(A->filas, B->columnas);
	int i = 0, j = 0, k = 0;
	for(; i < producto->filas ; i++){
		for(; j < producto->columnas ; j++){
			for(; k < A->columnas ; k++)
				producto->matriz[i][j] += A->matriz[i][k] * B->matriz[k][j];
			k = 0;
		}
		j = 0;
	}
	return producto;
}
