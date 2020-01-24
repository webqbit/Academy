#include<stdio.h>
#include<malloc.h>
#include<string.h>

#define MAX_HEAP 20

typedef struct{
  int prioridad;
  char nombre[20];
}Dato;

typedef struct _BHeap{
  Dato* arreglo[MAX_HEAP];
  int nelems;
}BHeap;

typedef BHeap* Heap;


int padre(int i){
  return (i-1)/2;
}
Heap heap_crear(){
  Heap nh=malloc(sizeof(BHeap));
  nh->nelems=0;
  return nh;
}

void intercambiar(Heap h,int index1,int index2){
  Dato* aux=h->arreglo[index1];
  h->arreglo[index1]=h->arreglo[index2];
  h->arreglo[index2]=aux;
}
void flotar(Heap h,int index){
  if(index!= 0 && h->arreglo[padre(index)]->prioridad > h->arreglo[index]->prioridad ){
    intercambiar(h,index,padre(index));
    flotar(h,padre(index));
  }
}

void heap_insertar(Heap h,Dato* d){
  if(h->nelems!=MAX_HEAP){
    h->arreglo[h->nelems]=d;
    flotar(h,h->nelems);
    h->nelems++;
  }
}

int hijoIzq(int a){
  return a*2 +1;
}
int hijoDer(int a){
  return a*2+2;
}
int min(Heap h,int a,int b){
  if(b>h->nelems-1){
    return a;
  }
  else if(h->arreglo[a]->prioridad<h->arreglo[b]->prioridad){
    return a;
  }else{
    return b;
  }
}


void hundir(Heap h,int index){
  if(index<h->nelems-1 && h->arreglo[index]->prioridad>h->arreglo[min(h,hijoIzq(index),hijoDer(index))]->prioridad){
    intercambiar(h,index,min(h,hijoIzq(index),hijoDer(index)));
    hundir(h,min(h,hijoIzq(index),hijoDer(index)));
  }
}

void heap_eliminar_minimo(Heap h){
  if(h->nelems!=0){
    intercambiar(h,0,h->nelems-1);
    h->nelems--;
    hundir(h,0);
  }

}
Dato* dato_crear(int prioridad,char texto[]){
  Dato* nuevo=malloc(sizeof(Dato));
  nuevo->prioridad=prioridad;
  strcpy(nuevo->nombre,texto);
  return nuevo;
}
void mostrar_dato(Dato* d) {
  printf("[%d %s]\n",d->prioridad,d->nombre);
}
void heap_mostrar(Heap h){
  for(int i=0;i<h->nelems;i++){
    mostrar_dato(h->arreglo[i]);
  }
  printf("\n");
}

int main(){
  //mostrar_dato(dato_crear(123,"hola"));
  Heap miheap=heap_crear();
  heap_insertar(miheap,dato_crear(2,"Lucas"));
  heap_insertar(miheap,dato_crear(12,"Chon"));
  heap_insertar(miheap,dato_crear(8,"Ura"));
  heap_insertar(miheap,dato_crear(4,"Leonid"));
  heap_insertar(miheap,dato_crear(45,"Alexis"));
  heap_insertar(miheap,dato_crear(10,"Ariel"));
  heap_insertar(miheap,dato_crear(1,"Nico"));


  heap_mostrar(miheap);
  printf("%d",miheap->nelems);
  printf("\n");
  heap_eliminar_minimo(miheap);
  heap_mostrar(miheap);
  printf("%d",miheap->nelems);
  printf("\n");
}
