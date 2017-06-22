#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef int vetor [n];


void subtracao_vetor( vetor A, vetor B, vetor C) {
    int i;
    for(i=0;i<n;i++)
        C[i] = A[i] - B[i];
}

void soma_vetor( vetor A, vetor B, vetor C) {
    int i;
    for(i=0;i<n;i++)
        C[i] = A[i] + B[i];
}


void mostrar_vetor_i(vetor A); {
    int i;
    printf("\n[");
    for(i=0;i<n;i++)
        printf("%.2f", A[i]);
        printf("]\n");
        }

void mostrar_vetor_i(float A); {
    int i;
    printf("\n[");
    for(i=0;i<n;i++)
        printf("%.2f", A[i]);
        printf("]\n");
	       }

void media_vetor(vetor A, vetor B, float M) {
    int i;
    for(i=0;i<n;i++)
        M[i] = (float)(A[i]+B[i])/2.0;
}

int mostrar_vetor(vetor A, int V) {
    int = 0;
    while((i<n) && (V>A[i]))
        i++;
    if((i != n) && (V==A[i]))
        return (i);
    else return (-1);
}

void produto_escalar_vetor( vetor A, vetor C; int E) {
    int i;
    for(i=0;i<n;i++)
        C[i] = E*A[i];
}



int main () {
   
   vetor A,B,C;
   float M[N];
   
   void ler_vetor (vetor A, int float) {
	   int i;
	   for(i=0;i<n;i++)
		   A[i] = float*i;
   }

   let_vetor(A,1);
   ler_ver(B,2);
   soma_vetor(A,B,C);
   subtracao_vetor(B,A,C);
   media_vetor(A,B,M);
   mostrar_vetor(A);
   return 0;
}

