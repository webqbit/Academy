
#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionVisitante2) (int dato, int dato2);


typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

//longitud de la lista
int slist_longitud(SList lista);

//concatena dos listas
SList slist_concatenar(SList l1,SList l2);

//inserta un dato en un indice arbitrario
SList slist_insertar(SList lista,int indice, int dato);

//elimina dado un indice a un nodo
SList slist_eliminar(SList lista, int indice);

//
int slist_contiene(SList lista,int dato);

//
int slist_indice(SList lista,int dato);

//slist intersecar que devuelve una nueva lista
// con los elementos comunes (independiente-mente de la posición)
// de dos listas dadas por parámetro. Las listas originales no se modifican.
SList slist_intersecar(SList l1,SList l2);

//que trabaja como la anterior pero recibe un par ́ametro extra que
//es un puntero a una funci ́on de comparaci ́on que permite definir la noci ́on de igualdad a ser
//usada al comparar elementos por igualdad.

SList slist_intersecar_custom(SList l1,SList l2,FuncionVisitante2 compare);

//que ordena una lista de acuerdo al criterio dado por una funci ́on de compa-
//raci ́on (que usa los mismos valores de retorno questrcmp()) pasada por par ́ametro
SList slist_ordenar(SList l1,FuncionVisitante2 criterio);

//slist reverso que obtenga el reverso de una lista.
SList slist_reverso(SList l1);

#endif /* __SLIST_H__ */
