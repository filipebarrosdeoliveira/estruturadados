#include <stdio.h>
#define MAXF 100
#define MAXP 100

typedef struct { int cod;
                 char Nome[40];
                 char Tel[15]; //(xx) 9xxxx-xxxx
                 char data_nasc[10]; // dd/mm/yyyy
                 }T_Agenda;
                 
typedef struct { T_Agenda Item[MAXF];
                 int Inicio, Fim, Total;
                }Fila_est;

typedef struct { T_Agenda Item[MAXP];
                 int Topo;
                }Pilha_est;

void Criar_Fila_Vazia(Fila_est *F)
  { F-> Inicio = 0;
    F-> Fim = 0;
    F-> Total = 0;
  }

void Criar_Pilha_Vazia(Pilha_est *P)
  { P-> Topo = 0;
  }
int Verifica_Fila_Vazia(Fila_est F)
  {
    return(F.Inicio == F.Fim);
  }
  
int Verifica_Pilha_Vazia(Pilha_est P)
  {
    return(P.Topo == 0);
  }
  
 int Verifica_Fila_Cheia(Fila_est F)
  {
    return((F.Fim+1)%MAXF == F.Fim);
  }
  
int Verifica_Pilha_Cheia(Pilha_est P)
  {
    return(P.Topo == MAXP);
  }

void Enfileirar (Fila_est *F, T_Agenda X)
{  if(Verifica_Fila_Cheia(*F))
      printf("A Fila está cheia - Enfileirar\n");
     else { F->Item[F->Fim] = X;
            F->Fim = (F->Fim + 1)% MAXF;
            F->Total++;
           }
}

void Empilhar (Pilha_est *P, T_Agenda X)
{  if(Verifica_Pilha_Cheia(*P))
      printf("A Pilha está cheia - Empilhar\n");
      else { P->Item[P->Topo] = X;
            P->Topo++;
           }
}

void Desenfileirar(Fila_est *F, T_Agenda *X)
{ if(Verifica_Fila_Vazia(*F))
	  printf("A Fila esta Vazia - Desenfileirar\n ");
	 else { *X = F->Item[F->Inicio];
		    F->Inicio = (F->Inicio + 1)%MAXF;
		    F->Total--;
		   }
	 }

void Desempilhar(Pilha_est *P, T_Agenda *X)
  { if(Verifica_Pilha_Vazia(*P))
	  printf("A Pilha esta Vazia - Desempilhar\n ");
	 else { P->Topo --;
		    *X = P->Item[P->Topo];
		   }
	 }

void Exibir_Elemento (T_Agenda X)
 { printf("\nELEMENTO DE COD = %4d \n",X.cod);
   printf(" ===================== \n");
   printf(" NOME: %s \n",X.Nome);
   printf(" TELEFONE: %s \n",X.Tel);
   printf(" DATA DE NASCIMENTO: %s \n",X.data_nasc);
   printf(" ================= \n");
}

void Ler_Elemento (T_Agenda *X)
    { printf("\n Entre com o Codigo : ");
	  scanf("%d",&X->cod);
	  printf("\n Entre com o Nome : ");
	  scanf("%s",X->Nome);
	  printf("\n Entre com o Telefone : ");
	  scanf("%s",X->Tel);
	  printf("\n Entre com o Data de Nascimento : ");
	  scanf("%s",X->data_nasc);
	 }

void MENU()
   { printf("\n M E N U   F U N C I O N A L\n ");
	 printf(" = = = = = = = = = = = = = =\n"); 
	 printf("1 - Enfileirar Elemento \n");
	 printf("7 - Consultar elemento no Inicio da Fila \n");
	 
	 printf("9 - Sair do Programa \n");
	 printf(" = = = = = = = = = = = = = =\n "); 
	 printf("Opcao: ");  
   }

void Inverter_Pilha (Pilha_est *P){
Pilha_est Aux; 
T_Agenda X;
Criar_Pilha_Vazia(&Aux); // para usar para inverter a outra pilha
while( !Verifica_Pilha_Vazia(*P)) // enquanto não for vazia, estar desimpilhando para por na aux
{
Desempilhar(&(*P),&X); 
Empilhar(&Aux,X);
}
*P = Aux;
}

void Inverter_Fila (Fila_est *F)
{
  Pilha_est Aux; 
  T_Agenda X;
  Criar_Pilha_Vazia(&Aux); // para usar para inverter a outra pilha
  while( !Verifica_Fila_Vazia(*F)) {
      Desenfileirar(&(*F),&X); // tira da fila e tras pro x
      Exibir_Elemento(X);
      Empilhar(&Aux,X);
     }
while(!Verifica_Pilha_Vazia(Aux))
    {
      Desempilhar(&Aux,&X);
      Exibir_Elemento(X);
      Enfileirar(&(*F),X);
    }
}

int main()
  { int op;
	T_Agenda X;
	Fila_est F;
	Pilha_est P;
	Criar_Fila_Vazia(&F);
	Criar_Pilha_Vazia(&P);
	do {
		MENU();
		scanf("%d",&op);
		getchar();
		switch (op) {
		  case 1:printf("\n Entre com o Elemento a ser Enfileirado \n");
		         Ler_Elemento(&X);
		         Enfileirar(&F, X);
		         break;
		  case 2:printf("\n Entre com o Elemento a ser Empilhar \n");
		         Ler_Elemento(&X);
		         Empilhar(&P, X);
		         break;
		   case 3: Desenfileirar(&F, &X);
		         printf("\n Elemento a ser Desenfileirado:\n");
		         Exibir_Elemento(X);
		         break;
		  case 4: Desempilhar(&P, &X);
		         printf("\n Elemento a ser Desempilhado: \n");
		         Exibir_Elemento(X);
		         break;
		  case 5 : Inverter_Fila(&F);
		         break;
		   case 6 : Inverter_Pilha(&P);
		         break;
		   case 7 :printf("O Elemento que esta no Inicio da Fila: \n "); 
		         if(Verifica_Fila_Vazia(F))
		               printf("A Fila Está Vazia - Consulta\n");
		              else  Exibir_Elemento(F.Item[F.Inicio]);
		         break; 
		   case 8 :printf("O Elemento que esta no Topo da Pilha: \n "); 
		           if(Verifica_Pilha_Vazia(P))
		               printf("A Pilha Está Vazia - Consulta\n");
		              else  Exibir_Elemento(P.Item[P.Topo-1]);
		         break; 
		   case 9: printf(" FIM...OBRIGADO POR USAR NOSSO SOFTWARE \n");
		         break;
		    default : printf("\n Opcao nao existe escolha outra correta \n");
		         break;
		}
	}while (op !=9);  
	return 0;
}
  
