#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define MAX_PILA 100

typedef struct _Pila {
	int *datos;
	int ultimo;
	int tam;
} *Pila;


Pila pila_crear(){
	Pila nuevaPila=malloc(sizeof(struct _Pila));
	nuevaPila->tam = MAX_PILA;
	nuevaPila->ultimo = -1;
	nuevaPila->datos = malloc(sizeof(int) * nuevaPila->tam);
	return nuevaPila;
}

int pila_es_vacia(Pila pila){
	return pila->ultimo < 0;
}

int pila_top(Pila pila){
	assert(!pila_es_vacia(pila));
	return pila->datos[pila->ultimo];
}

void pila_push(Pila pila, int dato){
	if (pila->tam <= pila->ultimo){
		pila->tam = pila->tam * 2;
		pila->datos = realloc(pila->datos, sizeof(int) * pila->tam);
	}
	pila->ultimo++;
	pila->datos[pila->ultimo] = dato;
}

void pila_pop(Pila pila){
	assert(!pila_es_vacia(pila));
	pila->ultimo--;
}

void pila_imprimir(Pila pila){
	int i;

	for (i=0 ;i <= (pila->ultimo); i++) printf ("\n[%d]\t=\t%d", i, pila->datos[i]);
}

int main(){
	Pila pila;
	pila = pila_crear();
	int i=0;

	for (; i<300; i++) pila_push(pila, i);

	pila_imprimir(pila);
	printf("\nTOP: %d\n", pila_top(pila));
	return 0;
}
