#include <stdio.h>
#include "matrix.c"

int main (void)
{
    struct matrix matrix, zeros, random, identidade, transposta, unidimensional, adc, subt, multi, divisao, recorte, resh, a, b;
    int soma, min, max, get;
    float media;

    int data[6] = {10,20,30,40,50,60};
    printf("\nMatriz criada: \n");

    matrix = create_matrix(data, 2, 3);
    print_matrix(matrix);
    
    zeros = zeros_matrix(2, 3);
    print_matrix(zeros);

    random = random_matrix(2, 3, 30, 100);
    print_matrix(random);
  
    identidade = i_matrix(5);
    print_matrix(identidade);

    get = get_element(random, 0, 2);
    printf("%d", get);

    put_element(matrix, 0, 1, 15);

    transposta = transpose(random);
    print_matrix(transposta);

    resh = reshape(random,3,2);
    print_matrix(resh);

    unidimensional = flatten(random);
    print_matrix(unidimensional);

    recorte = slice(random,0,2,1,3);
    print_matrix(recorte);

    soma = sum(random);
    printf("%d", soma);

    media = mean(random);
    printf("%.2f", media);

    min = minimo(random);
    printf("%d", min);

    max = maximo(random);
    printf("%d", max);
// -------------------------------------------------------------------------------------------- //
    a = create_matrix(data, 2, 3); // Os prints de A e B abaixo, foram colocados apenas para ficar de fácil visualização para o
    b = create_matrix(data, 2, 3); // usuário visualizar os valores das matrizes que estavam sendo utilizadas.

    printf("\n\n**********************************************************\n"); 
    printf("Soma de Matrizes: \n\nMatriz A:\n");
    print_matrix(a);
    printf("\nMatriz B:\n"); 
    print_matrix(b);
    
    adc = add(matrix, matrix);
    print_matrix(adc);

    printf("\n\n**********************************************************\n"); 
    printf("Subtração de Matrizes: \n\nMatriz A:\n");
    print_matrix(a);
    printf("\nMatriz B:\n"); 
    print_matrix(b);

    subt = sub(matrix, matrix);
    print_matrix(subt);

    printf("\n\n**********************************************************\n"); 
    printf("Divisão de Matrizes: \n\nMatriz A:\n");
    print_matrix(a);
    printf("\nMatriz B:\n"); 
    print_matrix(b);

    divisao = division(matrix, matrix);
    print_matrix(divisao);

    printf("\n\n**********************************************************\n"); 
    printf("Multiplicação de Matrizes: \n\nMatriz A:\n");
    print_matrix(a);
    printf("\nMatriz B:\n"); 
    print_matrix(b);

    multi = mul(matrix, matrix);
    print_matrix(multi); 
// -------------------------------------------------------------------------------------------- //
}