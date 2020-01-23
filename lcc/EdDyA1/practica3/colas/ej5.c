#include <stdio.h>
#include <malloc.h>


#define MAX_COLA 5

typedef struct _Cola {
  int datos[MAX_COLA];
  int primero, ultimo;
} *Cola;

// crea e inicializa una nueva cola vac´ıa.
Cola cola_crear();

// determina si la cola est´a vac´ıa
int cola_es_vacia(Cola);

// toma una cola y devuelve el elemento en la primera posici´on.
int cola_primero(Cola);

// toma una cola y un elemento y agrega el elemento al fin de la cola.
void cola_encolar(Cola, int);

// toma una cola y elimina su primer elemento.
void cola_desencolar(Cola);

// toma una cola y la imprime en orden.
void cola_imprimir(Cola);

// libera la memoria requerida para la cola
void cola_destruir(Cola);


Cola cola_crear(){
  Cola new=malloc(sizeof(Cola));
  new->primero = -1;
  new->ultimo = -1;
  return new;
}

int cola_es_vacia(Cola cola){
  return cola->primero == -1;
}

int cola_primero(Cola cola){
  return cola->datos[cola->primero];
}

void cola_encolar(Cola cola,int dato){
  if(cola_es_vacia(cola)){
    cola->primero++;
    cola->ultimo++;
    cola->datos[cola->ultimo]=dato;
    return;
  }
  if((cola->ultimo+1)%MAX_COLA==cola->primero){
    printf("cola llena\n");
    return;
  }
  cola->ultimo = (cola->ultimo+1)%MAX_COLA;
  cola->datos[cola->ultimo]=dato;
}
void cola_desencolar(Cola cola){
  if(cola_es_vacia(cola)){
    return;
  }
  if(cola->primero==cola->ultimo){
    cola->primero = -1;
    cola->ultimo = -1;
    return;
  }
  cola->primero = (cola->primero+1)%MAX_COLA;
}

void recorrer_arreglo(int *arreglo,int ii,int f){
  if (ii==-1) {
    printf("cola_es_vacia\n");
    return;
  }
  for(int i=0;i<MAX_COLA;i++){
    printf(" %d ",arreglo[i] );
  }
  printf("\n");
  for(int i=0;i<MAX_COLA;i++){
    if(ii==i)printf(" i ");
    else if(f==i)printf(" f ");
    else{
      printf("   ");
    }
  }
  printf("\n");
}

int main(){

  Cola c1=cola_crear();
  recorrer_arreglo(c1->datos,c1->primero,c1->ultimo);
  cola_encolar(c1,1);
  cola_encolar(c1,2);
  cola_encolar(c1,3);
  cola_encolar(c1,3);
  cola_desencolar(c1);
  cola_encolar(c1,4);
  cola_encolar(c1,4);
  cola_desencolar(c1);
  cola_encolar(c1,9);
  cola_desencolar(c1);
  cola_desencolar(c1);
  cola_desencolar(c1);
  cola_desencolar(c1);
  cola_desencolar(c1);

  recorrer_arreglo(c1->datos,c1->primero,c1->ultimo);

  return 0;
}
