#include<stdio.h>

float mediana(float *arreglo, int longitud);

void bubble_sort(float arreglo[], int longitud) {
  for (int iter = 0 ; iter < longitud - 1 ; iter++) {
    for (int i = 0 ; i < longitud - iter - 1; i++) {
      if (arreglo[i] > arreglo[i + 1]) {
        float aux = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = aux;
      }
    }
  }
}
float mediana( float *arreglo, int longitud){
  int l=longitud;
  float temp[longitud];
  for (int i=0;i<longitud;i++){
    temp[i]=arreglo[i];
  }
  bubble_sort(temp,longitud);
  if(longitud%2==0){
    return (temp[(l/2)-1]+temp[l/2])/2;
  }
  else{
    return temp[l/2];
  }
}
int main(){
  float a[]={1,2,3,4,5};
  float b[]={1,1,2,6,10,10};
  printf("mediana de [1,2,3,4,5] = %f \n",mediana(a,5));
  printf("mediana de [1,1,2,6,10,10] = %f \n",mediana(b,6));
  return 0;
}
