#include <stdio.h>
#include <stdlib.h>
#define N 5
typedef int Mat_Tri_Inf[((N*N+N)/2)];

void Entrada_Dados(Mat_Tri_Inf X)
{ int i, j, k=0;
    for (i=1;i<=N;i++)
        for(j=1;j<=i;j++)
        { printf("Entre com o valor da Matriz na posicao Mti[%d][%d] :\n",i,j);
            scanf("%d",&X[k]);
            k++;
        }
}

int Map_Mat_tri_inf (int i, int j)
{ if (i<j)
    return (-1); //valor não existe no vetor
else return(((i*i-i)/2) +j -1);
            }
            
            void Exibir_Matriz_ti(Mat_Tri_Inf X)
            { int i, j, k, nulo =0;
                printf(" MATRIZ TRIANGULAR INFERIOR \n");
                printf("=========================== \n \n");
                for(i=1;i<=N;i++)
                { for(j=1;j<=N;j++)
                { k = Map_Mat_tri_inf(i,j);
                    if (k!=-1)
                        printf("%5d",X[k]);
                    else printf("%5d",nulo);
                }
                    printf ("\n");
                }
            }

                
                void Consultar_Elemento (Mat_Tri_Inf X)
                { int i, j, k;
                    printf("Entre com a linha e coluna que deseja consultar na matriz:\n ");
                    printf("linha :");
                    scanf("%d",&i);
                    printf("\nColuna: ");
                    scanf("%d",&j);
                    if (((i>0)&&(i<N+1)) && ((j>0)&&(j<N+1)))
                    { k = Map_Mat_tri_inf(i,j);
                        if (k==-1)
                            printf("O Valor procurado é 0");
                        else printf("O Valor procurado é %5d",X[k]);
                    }
                    else printf(" Os valores da linha ou coluna estão fora da Matriz de dimensão %d x %d\n",N,N);
                }
            

int main()
{
    Mat_Tri_Inf X;
    Entrada_Dados(X);
    Exibir_Matriz_ti(X);
    Consultar_Elemento(X);
    
    return 0;
}
