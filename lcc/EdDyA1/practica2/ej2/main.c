#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d->", dato);
}

int comparar_igualdad(int a, int b){
  return  a==b;
}
int comparar_mayor(int a, int b){
  return  a>b;
}
int comparar_menor(int a, int b){
  return  a<b;
}


int main(int argc, char *argv[]) {

  SList lista = slist_crear();
  SList lista1 = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 7);
  lista = slist_agregar_final(lista, 21);
  lista = slist_agregar_final(lista, 99);

  lista1 = slist_agregar_inicio(lista1, 23);
  lista1 = slist_agregar_inicio(lista1, 21);
  lista1= slist_agregar_inicio(lista1, 1);
  lista1= slist_agregar_inicio(lista1, 99);

  printf("============\n");
  puts("L1:");
  slist_recorrer(lista, imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(lista));

  puts("\n\nL2:");
  slist_recorrer(lista1, imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(lista1));


  puts("\n\nL1 + L2:");
  lista = slist_concatenar(lista,lista1);
  slist_recorrer(lista, imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(lista));

  puts("\n\nInserto elemento de la pos: 3:VER 1 y no 0??");
  lista = slist_insertar(lista,3,777);
  slist_recorrer(lista, imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(lista));


  puts("\n\nEliminar elemento de la pos: 3:");
  lista = slist_eliminar(lista,3);
  slist_recorrer(lista, imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(lista));

  puts("\n\nEsta el 99?:");
  slist_recorrer(lista, imprimir_entero);
  printf("\n: %d",slist_contiene(lista,99));

  puts("\n\nEsta el 44?:");
  slist_recorrer(lista, imprimir_entero);
  printf("\n: %d",slist_contiene(lista,44));

  puts("\n\nindice del 44?:");
  slist_recorrer(lista, imprimir_entero);
  printf("\n: %d",slist_indice(lista,44));

    puts("\n\nindice del 99?:");
  slist_recorrer(lista, imprimir_entero);
  printf("\n: %d",slist_indice(lista,99));

  puts("\n\n\n\n//VER ->sig??\nL1:");
  slist_recorrer(lista, imprimir_entero);
  puts("\nL2:");
  slist_recorrer(lista1, imprimir_entero);
  puts("\nInterseccion entre la lista 1 y 2");
  slist_recorrer(slist_intersecar(lista1,lista), imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(slist_intersecar(lista,lista1)));

  puts("\n\n\n\n//VER ->sig??\nL1:");
  slist_recorrer(lista, imprimir_entero);
  puts("\nL2:");
  slist_recorrer(lista1, imprimir_entero);
  puts("\nInterseccion Custom por = entre la lista 1 y 2");
  slist_recorrer(slist_intersecar_custom(lista,lista1,comparar_igualdad), imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(slist_intersecar(lista,lista1)));

  puts("\n\n\n\n//VER ->sig??\nL1:");
  slist_recorrer(lista, imprimir_entero);
  puts("\nL2:");
  slist_recorrer(lista1, imprimir_entero);
  puts("\nInterseccion Custom por > entre la lista 1 y 2");
  slist_recorrer(slist_intersecar_custom(lista,lista1,comparar_mayor), imprimir_entero);
  printf("\nlongitud: %d",slist_longitud(slist_intersecar(lista,lista1)));

  puts("\n\n\n\nlista \nL1:");
  slist_recorrer(lista, imprimir_entero);
  puts("\nL1 ordenada ver el codigo!!");
  slist_recorrer(slist_ordenar(lista,comparar_mayor), imprimir_entero);

  puts("\n\n\n\nlista \nL1:");
  slist_recorrer(lista, imprimir_entero);
  puts("\nreverso de L1");
  slist_recorrer(slist_reverso(lista), imprimir_entero);





  puts("");
  printf("============\n");

  slist_destruir(lista);

  return 0;
}
