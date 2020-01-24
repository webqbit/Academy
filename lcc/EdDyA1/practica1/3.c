#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int* direccion;
	int capacidad;
}ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(size_t capacidad){
	ArregloEnteros* arr = malloc(sizeof(ArregloEnteros));
	arr->direccion = malloc(sizeof(int)*capacidad);
	arr->capacidad = capacidad;
	return arr;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
	free(arreglo->direccion);
	free(arreglo);
	return;
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, size_t pos){
	return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, size_t pos, int dato){
	arreglo->direccion[pos] = dato;
	return;
}

int  arreglo_enteros_capacidad(ArregloEnteros* arreglo){
	return arreglo->capacidad;
}

void arreglo_enteros_imprimir_en_pantalla(ArregloEnteros* arreglo){
	int i = 0;
	for(; i < arreglo->capacidad ; i++)
		printf("%d\t",arreglo->direccion[i]);
	return;
}

void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad){
	arreglo->direccion = realloc(arreglo->direccion, sizeof(int)*capacidad);
	arreglo->capacidad = capacidad;
}

void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato){
	arreglo_enteros_ajustar(arreglo, arreglo->capacidad + 1);
	int i = arreglo->capacidad - 1;
	for(; i > pos ; i--)
		arreglo->direccion[i] = arreglo->direccion[i-1];
	arreglo->direccion[i] = dato;
	return;
}

void imprimir(ArregloEnteros* arreglo){
	int i = 0;
	for(; i < arreglo->capacidad ; i++)
		printf("%d\t",arreglo->direccion[i]);
	puts("");
}

void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos){
	if(pos >= arreglo->capacidad || pos < 0)
		return;
	for(; pos < arreglo->capacidad - 1 ; pos++)
		arreglo->direccion[pos] = arreglo->direccion[pos+1]
;	arreglo_enteros_ajustar(arreglo, arreglo->capacidad -1);
}

int main(){
	ArregloEnteros* arreglo = arreglo_enteros_crear(10);
	arreglo_enteros_escribir(arreglo, 5, 5);
	arreglo_enteros_escribir(arreglo, 6, 6);
	arreglo_enteros_escribir(arreglo, 7, 7);
	arreglo_enteros_escribir(arreglo, 9, 9);
	arreglo_enteros_escribir(arreglo, 2, 2);
	imprimir(arreglo);
	arreglo_enteros_insertar(arreglo, 4, 4);
	imprimir(arreglo);
	printf("%d\n",arreglo->capacidad);
	arreglo_enteros_destruir(arreglo);
	return 0;
}
