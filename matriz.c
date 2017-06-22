#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef int MATRIZ[N][N];

void Entrada_de_Dados_Matriz(MATRIZ X)
 {
   int linha, coluna;
   for (linha=0;linha<N;linha++)
      for(coluna=0;coluna<N;coluna++)
        {
          printf("Entre com o valor de X[%d][%d] :  ",linha,coluna);
          scanf("%d",&X[linha][coluna]);
          }
   }
   
   void Produto_Matrizes(MATRIZ X, MATRIZ Y, MATRIZ Z)
    {int linha, coluna, inner;
	  printf("Resultado do Produto das Matrizes \n\n");
      for (linha = 0; linha<N; linha++) {
        for ( coluna = 0; coluna<N; coluna++) {
			 Z[linha][coluna] = 0;
            for ( inner = 0; inner<N; inner++) {
                Z[linha][coluna] += X[linha][inner] * Y[inner][coluna];
              }
           }
	    }
        for(linha=0;linha<N;linha++) 
        { 
          for(coluna=0;coluna<N;coluna++) 
              printf("%5d",Z[linha][coluna]); 
              printf ("\n\n"); 
} 	
     }
   void Soma_Matrizes(MATRIZ X, MATRIZ Y, MATRIZ Z)
     { int linha, coluna;
	  printf("Resultado da Soma das Matrizes \n\n");
      for (linha=0;linha<N;linha++) 
        { 
          for(coluna=0;coluna<N;coluna++) 
               Z[linha][coluna]=(X[linha][coluna]+Y[linha][coluna]);
         } 
        for(linha=0;linha<N;linha++) 
        { 
          for(coluna=0;coluna<N;coluna++) 
              printf("%5d",Z[linha][coluna]); 
              printf ("\n\n"); 
         }
     }
    
     void Subtracao_Matrizes(MATRIZ X, MATRIZ Y, MATRIZ Z)
     { int linha, coluna;
	  printf("Resultado da Subtracao das Matrizes \n\n");
      for (linha=0;linha<N;linha++) 
        { 
          for(coluna=0;coluna<N;coluna++) 
               Z[linha][coluna]=(X[linha][coluna]-Y[linha][coluna]);
         } 
        for(linha=0;linha<N;linha++) 
        { 
          for(coluna=0;coluna<N;coluna++) 
              printf("%5d",Z[linha][coluna]); 
              printf ("\n\n"); 
         }
     }
     
    
   int main()
    { MATRIZ A, B, C;
	  Entrada_de_Dados_Matriz(A);
	  Entrada_de_Dados_Matriz(B);
	  Produto_Matrizes(A,B,C);
	  Soma_Matrizes(A,B,C);
	  Subtracao_Matrizes(A,B,C);
	  
      return(0);
	}
	
