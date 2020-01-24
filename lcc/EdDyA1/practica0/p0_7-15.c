
#include <stdio.h>

struct pack3 {
  int a;
};
struct pack2 {
  int b;
  struct pack3 *next;
};
struct pack1 {
  int c;
  struct pack2 *next;
};
int main (){
  struct pack1 data1 , * dataPtr ;
  struct pack2 data2;
  struct pack3 data3;
  data1 .c = 30;
  data2 .b = 20;
  data3 .a = 10;
  dataPtr = &data1 ;
  data1 .next = & data2;
  data2 .next = & data3;
  return 1;
}

// Expresion
//correcta=======valor
                            // data1.c                        
                            // dataPtr->c
                            // dataPtr.c
                            // data1.next->b
                            // dataPtr->next->b
                            // dataPtr.next.b
                            // dataPtr->next.b
                            // (*(dataPtr->next)).b
                            // data1.next->next->a
                            // dataPtr->next->next.a
                            // dataPtr->next->next->a
                            // dataPtr->next->a
                            // dataPtr->next->next->b



//
// #include <stdio.h>
// int main (){
// char *ptr = "hola mundo";
// ptr [0] = 's';
// printf (" %s\n", ptr);
// }
// //segmentation fault , no se pidio memoria para el str



// #include <stdio.h>
// #include <malloc.h>
// void foo(int* a){
// a = NULL;
// }
// int main (){
// int a[67];
// a[0] = 123;
// printf (" %d\n", a[0]);
// printf (" %d\n", a[0]);
// }
// 123
// 123
// que le affecta a = NULL ya que a es estatico.??


// #include <stdio.h>
// #include <malloc.h>
// char* copiar_cadena (char* cad , int longitud ){
// char* a = malloc ( sizeof (char) * longitud );
// a = cad;
// return a;
// }
// int main (){
// char a[10] = "hola";
// char* b = copiar_cadena (a, 10);
// printf (" %s %s\n", a, b);
// b[0] = 's';
// printf (" %s %s\n", a, b);
// }
// hola hola
// sola sola
// bien

// #include <stdio.h>
// int main () {
// int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int* ptr;
// ptr = array;
// printf (" array[0]> %d;*ptr: %d\n", array [0], *ptr);
// printf (" array[1]> %d;*( ptr +1): %d\n", array [1], *( ptr +1));
// ptr ++;
// printf ("ptr ++; *ptr:%d\n", *ptr);
// return 1;
// }
// 1 1
// 2 2
// 2
// bien



// #include <stdio.h>
// int main () {
// char textoA [30] = " Agarrate Catalina ";
// char textoB [30] = "El Cuarteto de Nos";
// char* p= textoA ;
// char* q= textoB ;
// printf (" textoA : %s\ntextoB : %s\n", textoA , textoB );
// while (*p++ = *q++);
// printf (" while (*p++ = *q++) ;\n");
// printf (" textoA : %s\ntextoB : %s\n", textoA , textoB );
// return 1;
// }

//PREGUNTAR!!!!! tambien las condiciones del while si es 0 >0 etc

// # include <stdio.h>
// # include <string.h>
// int *fun0(int x) {
// return &x;
// }
// int main(int argc , char *argv [])
// {
// int *ptr = NULL;
// ptr = fun0 (2);
// printf (" %d\n", *ptr);
// printf (" %d\n", *ptr);
// return 0;
// }
//core generado
// porque, si solo se esta leyendo la pila no modificandola





// #include<stdio.h>
// #include <malloc.h>
// #include <stdlib.h>
// #include <string.h>
//
// void ingreseCadena (char* c){
// gets(c);
// }
// int main () {
// char* cadena = malloc ( sizeof (char)* 10);
// gets( cadena );
// printf (" %s\n", cadena );
// ingreseCadena ( cadena );
// printf (" %s", cadena );
// return 1;
// }
// bien, pero porque deja superar la cant esta. de char




// #include <stdio.h>
//
// void suma_dos (int* x, int* y, int z){
// *x = *x + 2;
// *y = *y + 5;
// z = z + 4;
// }
// int main () {
// int x, y, z;
// x = 3;
// y = 10;
// z = 15;
// suma_dos (&x, &y, z);
// printf (" %d %d %d", x, y, z);
// return 1;
// }//5 15 15 bien
