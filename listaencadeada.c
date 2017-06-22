#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
                 int codigo;
                 char Nome[40];
                 char Endereco[50];
                 char Data_nasc[12];
                 char Tel_res[11];
                 char Tel_cel[11];
                 int Prox;
                }Tipo_AgendaE;

typedef struct { Tipo_AgendaE Elem[MAX];
                 int Prim, Ult, Dispo, Tam;
               }Lista_Enc_Est;

void Criar_Lista_Vazia(Lista_Enc_Est *L)
  {  int P;
     L->Prim = -1;
     L->Ult=L->Prim;
     L->Dispo = 0;
     L->Tam = 0;
     for(P=0;P<MAX-1;P++)
       L->Elem[P].Prox = P+1;
     L->Elem[P].Prox= -1;
  }
int Verificar_Lista_Vazia(Lista_Enc_Est L)
   {
      return(L.Prim==-1);
    }
int Verificar_Lista_Cheia(Lista_Enc_Est L)
   {
      return(L.Dispo==-1);
    }
void Inserir_Elemento_Lista(Lista_Enc_Est *L,Tipo_AgendaE X)
    { int W, P, A;
      if (Verificar_Lista_Cheia(*L))
        printf("\n A Lista esta Cheia *** Impossivel Inserir \n");
      else { W = L->Dispo;
             L->Dispo= L->Elem[W].Prox;
             L->Elem[W] = X;
             if(Verificar_Lista_Vazia(*L))
               { L->Elem[W].Prox=L->Prim;
                 L->Prim = W;
                 L->Ult = L->Prim;
               //  L ->Tam++; 
               }else {
                       P = L->Prim;
                           while ((P!=-1) && (X.codigo > L->Elem[P].codigo))
                                { printf("\n P = %d \n",P);
                                  A = P;
                                  P = L->Elem[P].Prox;
                                 }
                           if(P==L->Prim)
                             { L->Elem[W].Prox=L->Prim;
                               L->Prim = W;
                              // L->Tam++;
                             } else if (P==-1)
                                      {  L->Elem[W].Prox= P;
                                         L->Elem[A].Prox=W;
                                         L->Ult=W;
                                        // L->Tam++;
                                      }else {
                                              L->Elem[W].Prox= P;
                                              L->Elem[A].Prox=W;
                                            //  L->Tam++;
                                            }
 
                     }
             L->Tam++;
         }

  }
  
  void Remover_Elemento_Lista(Lista_Enc_Est *L,Tipo_AgendaE *X)
    { int W, P, A=-1;
      if (Verificar_Lista_Vazia(*L))
        printf("\n A Lista esta Vazia *** Impossivel Remover \n");
      else { P = L->Prim;
             while ((P!=L->Ult) && (X->codigo > L->Elem[P].codigo))
                 { A = P;
                   P = L->Elem[P].Prox;
                 }
              if((X->codigo == L->Elem[P].codigo))
                  {W = P;
                   if(A==-1)
                     {L->Prim=L->Elem[P].Prox;
                      if(P==L->Ult)
                         L->Ult=L->Prim;
                     }else {L->Elem[A].Prox=L->Elem[P].Prox;
                             if(P==L->Ult)
                                L->Ult=A;
						     }
			       *X=L->Elem[W];
			        L->Elem[W].Prox=L->Dispo;
			        L->Dispo=W;
			        L->Tam--;
			       }else printf("\n Elemento Nao Existente *** Remove \n\n");
		}
  }
 void Exibir_Elemento(Tipo_AgendaE X,int P)
    {
		  printf("| %d | %d |->  ",P, X.codigo);
	}
 void Exibir_Lista(Lista_Enc_Est L)
   {  int P;
      
      if(Verificar_Lista_Vazia(L))
         printf("\n Lista vazia *** Exibir Lista");
        else {
			  P = L.Prim;
			  printf("********* Lista Encadeada - Estatica ********** \n\n");
			  while(P!= -1)
			    { Exibir_Elemento(L.Elem[P],P);
			      P = L.Elem[P].Prox;
		        }
	           printf("\n\n********* FIM da Lista ********** \n\n");
   }
}
void Ler_Agenda(Tipo_AgendaE *X)
   {
	   printf("\n Entre com o codigo: ");
	   scanf("%d",&X->codigo);
	   getchar(); 
   }

void Menu()
  {  printf("1 - Inserir Elemento\n");
     printf("2 - Remover Elemento\n");
     printf("3 - Exibir Lista\n");
     printf("4 - Tamanho da Lista\n");
     printf(">5 - Sair \n");
     printf("Opcao:  ");
	  
	 }

int main()
  {  int op=1;
     Lista_Enc_Est L;
     Tipo_AgendaE X;
     Criar_Lista_Vazia(&L);
     
     do {  switch (op) {
		     case 1: 
                     Ler_Agenda(&X);
                     printf("\n Tamanho da Lista: %d \n",L.Tam);
                     Inserir_Elemento_Lista(&L,X);
                     Exibir_Lista(L);
                     break;
              case 2: Ler_Agenda(&X);
                       Remover_Elemento_Lista(&L,&X);
                       Exibir_Lista(L);
                       break;
              case 3: Exibir_Lista(L);
                       break;
              default: printf("\n Tamanho da Lista: %d \n",L.Tam);
                        break;
                }
                Menu();       
                printf("\n Entre com op 5 para parar: ");
		        scanf("%d",&op);
                getchar();
         }while(op<5);
     system("pause");
     
     return(0);
}
