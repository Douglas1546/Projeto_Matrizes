#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

struct matrix create_matrix(int *data, int n_rows, int n_cols)
{
  struct matrix a_matrix;
  a_matrix.data = data;
  a_matrix.n_rows = n_rows;
  a_matrix.n_cols = n_cols;
  a_matrix.stride_rows = n_cols;
  a_matrix.stride_cols = 1;
  a_matrix.offset = 0;

  return a_matrix;
}
 

struct matrix zeros_matrix(int n_rows, int n_cols)
{
  printf("**********************************************************\n");
  struct matrix a_matrix;
  int size = n_rows*n_cols;
  printf("Matriz com zeros: \n");
  int* arr = (int*)malloc(size * sizeof(int));
  for (int i=0; i<size; i++){
    arr[i] = 0;
  }

  a_matrix.data = arr;
  a_matrix.n_rows = n_rows;
  a_matrix.n_cols = n_cols;
  a_matrix.stride_rows = n_cols;
  a_matrix.stride_cols = 1;
  a_matrix.offset = 0;

  return a_matrix;
}


struct matrix random_matrix(int n_rows, int n_cols, int b, int e){
printf("**********************************************************\n");
struct matrix a_matrix;
int intervalo;

printf("Matriz com valores aleatorios e com intervalos escolhidos \n");
// caso seja colocado um valor menor que o primeiro valor, o programa pedirá para digitar outro valor
while (e < b){
    printf("Intervalo invalido. Digite novos valores: ");
    scanf("%d %d", &b, &e);
}
intervalo = e - b;
printf("Intervalo de: %d a %d \n", b, e);
printf("\n");
int size = n_rows*n_cols;
int* arr = (int*)malloc(size * sizeof(int));
for(int i=0; i < size; i++){
        arr[i] = rand()%intervalo + b;
    }

  a_matrix.data = arr;
  a_matrix.n_rows = n_rows;
  a_matrix.n_cols = n_cols;
  a_matrix.stride_rows = n_cols;
  a_matrix.stride_cols = 1;
  a_matrix.offset = 0;

  return a_matrix;
}


struct matrix i_matrix(int n){
    printf("**********************************************************\n");
    struct matrix a_matrix;

    int size = n*n;
    int* arr = (int*) malloc(size * sizeof(int));

    printf("Matriz identidade: \n\n");
    for(int i = 0; i < size; i++) {
        if(i % (n+1) == 0){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }

    a_matrix.data = arr;
    a_matrix.n_rows = n;
    a_matrix.n_cols = n;
    a_matrix.stride_rows = n;
    a_matrix.stride_cols = 1;
    a_matrix.offset = 0;

    return a_matrix;
}


int get_element(struct matrix a_matrix, int ri, int ci){

  printf("\n\n**********************************************************\n");
  int i, j, elemento;
  printf("\nPegar o elemento de uma determinada posição:");
  printf("\n\n------------------- Elementos ------------------- \n\n");
  
  for ( i=0; i<a_matrix.n_rows; i++ )
    for ( j=0; j<a_matrix.n_cols; j++ )
    {
      printf ("\nElemento[%d][%d] = %d \n", i, j,a_matrix.data[i*a_matrix.n_cols + j]);
    }

  printf("\n\n------------------- Elemento selecionado ------------------- \n\n");

  printf("O elemento selecionado foi [%d][%d] = ", ri, ci);
  elemento = a_matrix.data[ri*a_matrix.n_cols + ci];

  return elemento;
}


void put_element(struct matrix a_matrix, int ri, int ci, int elem){

  printf("\n\n**********************************************************\n");
  int i, j;
  printf("\nColoca um elemento na matriz de acordo com sua posição:");
  printf("\n\n------------------- Elementos ------------------- \n\n");
  
  for ( i=0; i<a_matrix.n_rows; i++ )
    for ( j=0; j<a_matrix.n_cols; j++ )
    {
      printf ("\nElemento[%d][%d] = %d \n", i, j,a_matrix.data[i*a_matrix.n_cols + j]);
    }

  printf("\n\n------------------- alterar ------------------- \n\n");

  printf("A posição escolhida foi: [%d][%d], e o elemento inserido nessa posição foi: %d \n", ri, ci,elem);
  a_matrix.data[ri*a_matrix.n_cols + ci] = elem;
    
    for ( i=0; i<a_matrix.n_rows; i++ )
      for ( j=0; j<a_matrix.n_cols; j++ )
    {
      printf ("\nElemento[%d][%d] = %d \n", i, j,a_matrix.data[i*a_matrix.n_cols + j]);
    }
  printf("\n");

  return elem;
}


void print_matrix(struct matrix a_matrix){

  int i, j=0;
  int cols = a_matrix.n_cols;
  printf("\n");
  for (i = 0; i < a_matrix.n_rows; i++){
    for (; j < cols; j++){
      printf("%d ", a_matrix.data[j]);
    }
    cols += a_matrix.n_cols;
    printf("\n");
  }
  printf("\n");
}


struct matrix transpose(struct matrix a_matrix){
printf("\n\n**********************************************************\n");

  int i, j, valor;
  int size = a_matrix.n_rows*a_matrix.n_cols;

  printf("Transposta: \n\nMatriz utilizada:\n\n");

  int* arr = (int*) malloc(size * sizeof(int));

    for (i = 0; i < a_matrix.n_rows; i++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
      for(j = 0; j < a_matrix.n_cols; j++){ //
        printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
      }
      printf("\n");
    }
  printf("\nTransposta feita:\n");
  int cont = 0;
  for (i = 0; i < a_matrix.n_cols; i++){ // A partir daqui é feita a transposta
    for( j = 0; j < a_matrix.n_rows; j++){
      valor = a_matrix.data[j*a_matrix.n_cols + i];
      arr[cont++] = valor;
    }
  }

  return create_matrix(arr, a_matrix.n_cols, a_matrix.n_rows);
}


struct matrix reshape(struct matrix a_matrix, int new_n_rows, int new_n_cols){

  printf("**********************************************************\n");
  struct matrix b_matrix;

  printf("Reshape: \n\nMatriz utilizada:\n\n");
  int i, j;

  for (i = 0; i < a_matrix.n_rows; i++){  // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
    for(j = 0; j < a_matrix.n_cols; j++){  //
      printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
    }
    printf("\n");
  }  
  printf("\nReshape feito:\n"); // A partir daqui é feito o reshape
  b_matrix.data = a_matrix.data;
  b_matrix.n_rows = new_n_rows;
  b_matrix.n_cols = new_n_cols;
  b_matrix.stride_rows = new_n_cols;
  b_matrix.stride_cols = 1;
  b_matrix.offset = 0;
  return b_matrix;
}


struct matrix flatten(struct matrix a_matrix){

  printf("**********************************************************\n");
  struct matrix b_matrix;

  printf("Flatten: \n\nMatriz utilizada:\n\n");
  int i, j;

  for (i = 0; i < a_matrix.n_rows; i++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
    for(j = 0; j < a_matrix.n_cols; j++){ //
      printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
    }
    printf("\n");
  }
  printf("\nRedmensionada em 1 linha:\n"); // A partir daqui é feito o flatten
  b_matrix.data = a_matrix.data;
  b_matrix.n_rows = 1;
  b_matrix.n_cols = a_matrix.n_rows*a_matrix.n_cols;
  b_matrix.stride_rows = a_matrix.n_rows*a_matrix.n_cols;
  b_matrix.stride_cols = 1;
  b_matrix.offset = 0;
  return b_matrix;
}


struct matrix slice(struct matrix a_matrix, int rs, int re, int cs, int ce){

  printf("**********************************************************\n");
  struct matrix b_matrix;

  printf("Slice: \n\nMatriz utilizada:\n\n");
  int size = (re-rs)*(ce-cs);
  int* arr = (int*) malloc(size * sizeof(int));
  int l, c;
  int i;
  int j = cs + (rs*a_matrix.stride_rows);
  int j_end = ce + (rs*a_matrix.stride_rows);
  int k=0;

  for (l = 0; l < a_matrix.n_rows; l++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
    for(c = 0; c < a_matrix.n_cols; c++){ //
      printf("%d ", a_matrix.data[l*a_matrix.n_cols + c]); //
    }
    printf("\n");
  }  
  printf("\nSlice feito:\n");
  for (i = rs; i < re; ){ // A partir daqui é feito o slice
    for ( ; j < j_end; j++){
      arr[k] = a_matrix.data[j];
      k++;
    }
    i++;
    j = cs + (i*a_matrix.stride_rows);
    j_end = ce + (i*a_matrix.stride_rows);
  }

  b_matrix.data = arr;
  b_matrix.n_rows = re-rs;
  b_matrix.n_cols = ce-cs;
  b_matrix.stride_rows = ce-cs;
  b_matrix.stride_cols = 1;
  b_matrix.offset = 0;
  return b_matrix;
}


int sum(struct matrix a_matrix){
  printf("**********************************************************\n");
  int i, j, soma = 0;
  int size = a_matrix.n_rows*a_matrix.n_cols;

  printf("Soma da Matriz:\n\n");
  printf("Matriz utilizada:\n\n");

  for (i = 0; i < a_matrix.n_rows; i++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
      for(j = 0; j < a_matrix.n_cols; j++){ //
        printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
      }
      printf("\n"); 
    }

  printf("\n");

  printf("A soma é: ");
  for(i = 0; i < size; i++){
    soma += a_matrix.data[i];
  }
  return soma;

}


float mean(struct matrix a_matrix){
printf("\n\n**********************************************************");
int i, j, soma = 0;
float cont = 0, media;
int size = a_matrix.n_rows*a_matrix.n_cols;

printf("\nMatriz da média: \n\n");
printf("Matriz utilizada:\n\n");
for (i = 0; i < a_matrix.n_rows; i++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
      for(j = 0; j < a_matrix.n_cols; j++){ //
        printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
      }
      printf("\n");
    }
  printf("\n");
  printf("A media é: ");
  for(i = 0; i < size; i++){
    soma += a_matrix.data[i];
    cont++;
    media = soma / cont;
  }
  return media;
}


int minimo(struct matrix a_matrix){ // Tive que alterar a função de "Min" que estava no PDF, para "minimo", porquê não reconhecia como função.
    printf("\n\n**********************************************************\n");
    int i, j, menor;
    int size = a_matrix.n_rows*a_matrix.n_cols;

    printf("Menor valor da Matriz\n\n");
    printf("Matriz utilizada:\n\n");
    for (i = 0; i < a_matrix.n_rows; i++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
      for(j = 0; j < a_matrix.n_cols; j++){ //
        printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
      }
      printf("\n");
    }
    printf("\n");
    menor = a_matrix.data;


    for (i = 0; i < size; i++) {
        if (a_matrix.data[i] < menor) menor = a_matrix.data[i];
    }
    printf("Menor valor da Matriz é: ");
        
    return menor;
}


int maximo(struct matrix a_matrix){ // Tive que alterar a função de "Max" que estava no PDF, para "maximo", porquê não reconhecia como função.

  printf("\n\n**********************************************************\n");

  int i, j, maior;
  int size = a_matrix.n_rows*a_matrix.n_cols;

  printf("Maior valor da Matriz\n\n");
  printf("Matriz utilizada:\n\n");
  for (i = 0; i < a_matrix.n_rows; i++){ // Os dois "For" e o "printf", coloquei apenas para mostrar qual era a matriz que estava sendo usada no processo
    for(j = 0; j < a_matrix.n_cols; j++){ //
      printf("%d ", a_matrix.data[i*a_matrix.n_cols + j]); //
    }
    printf("\n");
  }
  printf("\n");
  maior = a_matrix.data[0];

  for (i = 0; i < size; i++) {
    if (a_matrix.data[i] > maior) maior = a_matrix.data[i];
  }
  printf("Maior valor da Matriz é: ");
      
  return maior;
}


struct matrix add(struct matrix a_matrix, struct matrix b_matrix){

  struct matrix c_matrix;
  printf("Matriz Somada: \n");
  int size = a_matrix.n_rows*a_matrix.n_cols;
  int* arr = (int*) malloc(size * sizeof(int));

  for (int i=0; i<size; i++){
    arr[i] = a_matrix.data[i] + b_matrix.data[i];
  }

  c_matrix.data = arr;
  c_matrix.n_rows = a_matrix.n_rows;
  c_matrix.n_cols = a_matrix.n_cols;
  c_matrix.stride_rows = a_matrix.n_cols;
  c_matrix.stride_cols = 1;
  c_matrix.offset = 0;

  return c_matrix;
}


struct matrix sub(struct matrix a_matrix, struct matrix b_matrix){

  struct matrix c_matrix;
  printf("\nMatriz Subtraída: \n");
  int size = a_matrix.n_rows*a_matrix.n_cols;
  int* arr = (int*) malloc(size * sizeof(int));

  for (int i=0; i<size; i++){
    arr[i] = a_matrix.data[i] - b_matrix.data[i];
  }

  c_matrix.data = arr;
  c_matrix.n_rows = a_matrix.n_rows;
  c_matrix.n_cols = a_matrix.n_cols;
  c_matrix.stride_rows = a_matrix.n_cols;
  c_matrix.stride_cols = 1;
  c_matrix.offset = 0;

  return c_matrix;
}


struct matrix division(struct matrix a_matrix, struct matrix b_matrix){

  struct matrix c_matrix;
  printf("\nMatriz Dividida: \n");
  int size = a_matrix.n_rows*a_matrix.n_cols;
  int* arr = (int*) malloc(size * sizeof(int));

  for (int i=0; i<size; i++){
    arr[i] = a_matrix.data[i] / b_matrix.data[i];
  }

  c_matrix.data = arr;
  c_matrix.n_rows = a_matrix.n_rows;
  c_matrix.n_cols = a_matrix.n_cols;
  c_matrix.stride_rows = a_matrix.n_cols;
  c_matrix.stride_cols = 1;
  c_matrix.offset = 0;

  return c_matrix;
}


struct matrix mul(struct matrix a_matrix, struct matrix b_matrix){

  struct matrix c_matrix;
  printf("\nMatriz Multiplicada: \n");
  int size = a_matrix.n_rows*a_matrix.n_cols;
  int* arr = (int*) malloc(size * sizeof(int));

  for (int i=0; i<size; i++){
    arr[i] = a_matrix.data[i] * b_matrix.data[i];
  }

  c_matrix.data = arr;
  c_matrix.n_rows = a_matrix.n_rows;
  c_matrix.n_cols = a_matrix.n_cols;
  c_matrix.stride_rows = a_matrix.n_cols;
  c_matrix.stride_cols = 1;
  c_matrix.offset = 0;

  return c_matrix;
}