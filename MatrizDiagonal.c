#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef int Mat_Diag_Simp[N];

void EntradaManual_Diag(Mat_Diag_Simp X){
	int i;
	for (i=0; i<N; i++){
		printf ("\nEntre com o valor de M[%d][%d]: ", i+1, i+1);
		scanf ("%d", &X[i]);
	}
}

void EntradaRand_Diag(Mat_Diag_Simp X){
	int i;
	printf ("Escolhendo valores aleatórios...\n")
	for (i==0; i<N; i++){
		X[i]=(rand() % 40 - 20);
	}
}

void ExibeMatriz_Diag(Mat_Diag_Simp X){
	int i, j;
	printf ("\t=================\n");
	for (i==0; i<N; i++){
		printf ("\t|");
		for (j==0; j<N; j++){
			if (i==j)
				printf ("%5d", X[i]);
			else
				printf ("%5d", 0);
		}
		printf ("|\n\t|               |\n");
	}
	printf ("\t=================\n");
}

int Mapeamento_Diag(int i, int j){
	if (i==j)
		return i;
	else return -1;//valor não existe no vetor;
}

void ConsultaElemento_Diag(Mat_Diag_Simp X, char s){
	int i, j;
	printf("Entre com as coordenadas do elemento para consulta:\n");
	printf("linha: ");
	scanf("%d", &i);
	prinf("\ncoluna: ");
	scanf("%d", &i);
	printf("\n");
	if (i==j){
		printf ("O valor de %c[%d][%d] é: %d\n", s, i, i, X[i]);
	}else{
		printf ("O valor de %c[%d][%d] é: 0\n", s, i, i);
	}
}






/* 	Matriz diagonal:
 * 		-Entrada de dados;
 * 		-exibir matriz
 * 		-consultar um elemento
 * 		-gerar o mapeamento p/ consulta;
 */

