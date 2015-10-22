#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef int Mat_Tri_Inf[((N*N+N)/2)];

void EntradaManual_Tri_Inf(Mat_Tri_Inf X){
	int i, j, k=0;
	for (i=1;i<=N;i++)
		for(j=1;j<=i;j++){
			printf("Entre com o valor da Matriz na posicao Mti[%d][%d] :\n",i,j);
			scanf("%d",&X[k]);
			k++;
		}
 }
 
 void EntradaRandTri(Mat_Tri_Inf X){
	int k=(N*N+N)/2;
	while (k>=0){
		X[k] = (rand() % 40 -20);
		k--;
	}
}

 int Map_Mat_tri_inf (int i, int j){
	 if (i<j)
		return (-1); //valor nÃ£o existe no vetor
     else
		return(((i*i-i)/2) +j -1); 
}

void Exibir_Matriz_tri(Mat_Tri_Inf X){
	int i, j, k, nulo =0;
	printf(" MATRIZ TRIANGULAR INFERIOR \n");
	printf("=========================== \n \n");
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			
			k = Map_Mat_tri_inf(i,j);
			if (k!=-1)
				printf("%5d",X[k]);
				
			else printf("%5d",0);
		}
		printf ("\n");
	}
	printf ("\n");
}
 
 
 void Consultar_Elemento_Tri (Mat_Tri_Inf X){
	int i, j, k;
	printf("Entre com a linha e coluna que deseja consultar na matriz:\n ");
	printf("linha :");
	scanf("%d",&i);
	printf("\nColuna: ");
	scanf("%d",&j);
	printf("\n");
	if(((i>0)&&(i<N+1)) && ((j>0)&&(j<N+1))){
		k = Map_Mat_tri_inf(i,j);
		if (k==-1)
			printf("O Valor procurado Ã© 0\n");
		else
			printf("O Valor procurado Ã© %5d\n",X[k]);
	}
	else printf(" Os valores da linha ou coluna estÃ£o fora da Matriz de dimensÃ£o %d x %d\n",N,N);
}

int main() {
	int preench, consult, flag;
	Mat_Tri_Inf a;
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
			case 1:	EntradaManual_Tri_Inf(a);
					break;
			case 2: EntradaRandTri(a);
					break;
		}
		
		if(preench!=3){
			do{
				printf ("Escolha a opção de visualização:\n\t1. Matriz inteira;\n\t2. Pesquisa componente;\n\t3. Voltar;\n");
				scanf ("%d", &consult);
				
				switch (consult){
					case 1: Exibir_Matriz_tri(a);
							break;
					case 2: Consultar_Elemento_Tri(a);
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

//set number si ts = 4 sw = 4;

