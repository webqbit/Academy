#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <stdlib.h>

typedef struct Matriz_ Matriz;

/*
** Crea una nueva matriz
*/
Matriz* matriz_crear(int filas, int columnas);

/*
** Destruye una matriz
*/

void matriz_destruir(Matriz* matriz);

/*
** Obtiene el dato guardado en la posición dada de la matriz
*/

float matriz_leer(Matriz* matriz, int fila, int columna);

/*
**Imprime los elementos de la matriz
*/

void matriz_imprimir(Matriz* matriz);

/*
** Modifica el dato guardado en la posición dada de la matriz
*/

void matriz_escribir(Matriz* matriz, int fila, int columna, int dato);
/*

** Obtiene número de filas de la matriz
*/
int matriz_num_filas(Matriz* matriz);

/*
** Obtiene número de columnas de la matriz
*/
int matriz_num_columnas(Matriz* matriz);

/*
** Intercambia dos filas de una matriz
*/
void matriz_intercambiar_filas(Matriz* matriz, int fila1, int fila2);

/*
** Dada la matriz A y la matriz B, retorna A+B
*/
Matriz* matriz_suma(Matriz* A, Matriz* B);

/*
** Dada la matriz A y la matriz B, retorna A*B
*/
Matriz* matriz_producto(Matriz* A, Matriz* B);

#endif /* __MATRIZ_H__ */
