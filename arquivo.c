#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct ag{ char nome[40];
                   char rua[30];
                   int numero;
                   int apartamento;
               }Agenda;
int main()
 { Agenda endereco;
	 FILE *arquivo;
	
    arquivo = fopen("arquivo.dat", "rb");
    if (arquivo!=NULL)
      { fread(&endereco,sizeof(Agenda),1,arquivo);
		printf(" Valor encontrado %s  -  %d \n",endereco.nome,endereco.apartamento);
	  }
	 
    arquivo = fopen("arquivo.dat", "a"); 
    if(arquivo!=NULL) { 
            strcpy(endereco.nome, "JOSE CARLOS");
            strcpy(endereco.rua, "Av. Brasil");
             endereco. numero = 2012;
             endereco.apartamento = 201;
             fwrite(&endereco, sizeof(endereco),1,arquivo);
            }
            

fclose(arquivo); 
 return 0;
 }
