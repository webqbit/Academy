#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define MAX_PILA 100

typedef struct _Pila{
	int datos[MAX_PILA];
	int ultimo;
} *Pila;

/*Crea e inicializa una nueva pila vacía*/
Pila pila_crear();

/* determina si la pila est´a vac´ıa.*/
int pila_es_vacia(Pila);

/* toma una pila y devuelve el elemento en la cima.*/
int pila_top(Pila);

/* toma una pila y un elemento y agrega el elemento a la pila.*/
void pila_push(Pila, int);

/* toma una pila y elimina el elemento de la cima.*/
void pila_pop(Pila);

/* toma una pila y la imprime en orden*/
void pila_imprimir(Pila);

Pila pila_crear(){
	Pila nuevaPila=malloc(sizeof(struct _Pila));
	nuevaPila->ultimo = -1;
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
	assert(pila->ultimo < MAX_PILA);
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
	int i=0;
	Pila pila;
	pila = pila_crear();


	for (; i<20; i++) pila_push(pila, i);

	pila_imprimir(pila);

	printf("\nTOP: %d\n", pila_top(pila));
	return 0;
}
