#include "slist.h"
#include <stdlib.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista){
    int i;
    if(lista==NULL)return 0;
    SList nodo = lista;
    for (i=1;nodo->sig != NULL;nodo = nodo->sig,i++);
    return i;

}

SList slist_concatenar(SList l1,SList l2){
    if(l1==NULL)l1=l2;
    SList nodo = l1;
    for (;nodo->sig != NULL;nodo = nodo->sig);
    nodo->sig=l2;
    return l1;
}

SList slist_insertar(SList lista,int indice, int dato){
    SList temp=lista;
    int i=1;
    for(;temp->sig != NULL && i<indice;temp=temp->sig,i++);
    if(i==indice){
      temp->sig=slist_agregar_inicio(temp->sig,dato);
    }
    return lista;
}


SList slist_eliminar(SList lista,int indice){
    SList temp;
    SList nodo = lista;
    int i=1;
    for (;nodo->sig != NULL && i != indice ;nodo = nodo->sig,i++);
    if(i == indice){
        temp=nodo->sig;
        nodo->sig=nodo->sig->sig;
        free(temp);
    }
    return lista;
}

int slist_contiene(SList lista,int dato){
    SList temp;
    SList nodo = lista;
    for (;nodo->sig != NULL && nodo->dato != dato ;nodo = nodo->sig);
    if(nodo->dato == dato){
        return 1;
    }
    return 0;
}

int slist_indice(SList lista,int dato){
    if(lista==NULL){
        return -1;
    }
    SList temp;
    SList nodo = lista;
    int i=0;
    for (;nodo->sig != NULL && nodo->dato != dato ;nodo = nodo->sig,i++);
    if(nodo->sig == NULL){
        return -1;
    }
    return i;

}

SList slist_intersecar(SList l1,SList l2){
  SList intersecado=slist_crear();
  SList temp,temp2;
  for(temp=l1;temp!=NULL;temp=temp->sig){
    for(temp2=l2;temp2!=NULL;temp2=temp2->sig){
      if (temp->dato==temp2->dato){
        intersecado=slist_agregar_inicio(intersecado,temp->dato);
      }
    }
  }
  return intersecado;
}

SList slist_intersecar_custom(SList l1,SList l2,FuncionVisitante2 compare){
  SList intersecado=slist_crear();
  SList temp,temp2;
  for(temp=l1;temp!=NULL;temp=temp->sig){
    for(temp2=l2;temp2!=NULL;temp2=temp2->sig){
      if (compare(temp->dato,temp2->dato)){
        intersecado=slist_agregar_inicio(intersecado,temp->dato);
      }
    }
  }
  return intersecado;
}

SList slist_ordenar(SList l1,FuncionVisitante2 criterio){
  SList i,j;
  int temp=0;
  for(i=l1;i->sig != NULL;i=i->sig){
      for(j=i->sig;j!=NULL;j=j->sig){
        if(i->dato > j->dato){
          temp=i->dato;
          i->dato=j->dato;
          j->dato=temp;
        }
      }
  }
return l1;
}

SList slist_reverso(SList l1){
  SList n=NULL;
  SList temp;
  for(temp=l1;temp!=NULL;temp=temp->sig){
    n=slist_agregar_inicio(n,temp->dato);
  }
  return n;
}
