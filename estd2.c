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
	printf ("Escolhendo valores aleatórios...\n");
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
	else return -1;//valor nÃ£o existe no vetor;
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
		printf ("O valor de %c[%d][%d] Ã©: %d\n", s, i, i, X[i]);
	}else{
		printf ("O valor de %c[%d][%d] Ã©: 0\n", s, i, i);
	}
}
int main() {
	int preench, consult, flag;
	Mat_Diag_Simp a;
	do{
		do{
			printf ("Escolha a opção de preenchimento:\n\t1. Preenchimento manual;\n\t2. Preenchimento randomico;\n\t3. Sair\n");
			scanf ("%d",&preench);
			if (preench<1||preench>3){
				preench=0;
				printf("Entrada inválida!\n");
			}
		}while (preench==0);
		
		switch (preench) {
			case 1:	EntradaManual_Diag(a);
					break;
			case 2: EntradaRand_Diag(a);
					break;
		}
		
		if(preench!=3){
			do{
				printf ("Escolha a opção de visualização:\n\t1. Matriz inteira;\n\t2. Pesquisa componente;\n\t3. Voltar;\n");
				scanf ("%d", &consult);
				
				switch (consult){
					case 1: ExibeMatriz_Diag(a);
							break;
					case 2: ConsultaElemento_Diag(a,'A');
							break;
				}
				if (consult<1||consult>3){
					printf ("Entrada inválida!!\n");
				}
			}while (consult!=3);
		}	
	}while (preench!=3);
	return 0;
}
