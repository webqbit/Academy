#include<stdio.h>

int main(){
  // int* punt;
  // int x=7;
  // int y = 5;
  // punt =&x;
  // *punt = 4;
  // printf (" %d %d", x, y); //45 bien

  // int* punt;
  // int x=7;
  // int y = 5;
  // punt =&x;
  // x = 4;
  // punt =&y;
  // printf (" %d %d", *punt , x);//54 bien


  // int* punt , i;
  // int x[]={1 , 2, 3, 4, 5};
  // punt = x;
  // *punt = 9;
  // for(i=0; i <5; i++){
  // printf (" %d", x[i]);
  // }

//   int* punt , i;
//   int x[]={1 , 2, 3, 4, 5};
//   punt = x;
//   *( punt +2) = 9;
//   *(x+3) = 7;
//   punt [1]=11;
//   for(i=0; i <5; i++){
//   printf (" %d", *( punt+i));
// }//1 11 7 9 5 bien

// int *punt ,i;
// int x[5]={1 ,2 ,3 ,4 ,5};
// punt =&x [0]+3;
// *( punt -2) =9;
// punt --;
// *( punt)=7 ;
// punt [1]=11 ;
// punt=x;
// for(i=0;i <5;i++)
// printf (" %d,",punt[i]); //1 9,7 11, 5 bien


// int main () {
// int v[4] = { 2,4,5,7}, a, *p;
// p = v+2;
// p--;
// a = *p + *(p+1) + *(v+1) + p[2];
// printf (" %d", a);
// return 1;
// } //20 bien




  return 0;
}
