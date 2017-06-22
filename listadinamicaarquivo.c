#include <stdio.h>
#include <stdlib.h>

typedef struct { int cod;
                 char nome[40];
                 char data_nasc[11];
                 char email[40];
                 char telcel[11];
                 }T_Pessoa;

typedef struct Cx{ T_Pessoa Item;
                   struct Cx *Prox;
                 }Caixa;
typedef Caixa *Ponteiro;
typedef struct { Ponteiro Prim, Ult;
	             int Tam;
	            }Lista_din_enc;

void Criar_Lista_Vazia(Lista_din_enc *L)
 { Ponteiro P;
   P = (Ponteiro) malloc(sizeof (Caixa));
   L->Prim = P;
   L->Ult = L->Prim;
   L->Tam = 0;
 }

int Verifica_Lista_Vazia(Lista_din_enc L)
   {  
	   return(L.Prim == L.Ult);
    }

 void Insere_Elemento_Lista(Lista_din_enc *L, T_Pessoa X)
   { Ponteiro P, A;
	 P = (Ponteiro) malloc(sizeof (Caixa));
	 P->Item = X;
	 A = L->Prim;
	 while((A!=L->Ult)&&(X.cod>A->Prox->Item.cod))
	    A = A->Prox;
	  P->Prox = A->Prox;
	  A->Prox = P;
	  if(A==L->Ult)
		 L->Ult = P;
	  L->Tam++;
	 }
	 
void Exibir_Elemento(T_Pessoa X)
  {  printf("  %5d - %s \n",X.cod, X.nome);
	  
   }
	 
 void Remove_Elemento_Lista(Lista_din_enc *L, T_Pessoa *X)
  { Ponteiro P, A;
    if(Verifica_Lista_Vazia (*L))
      printf("A Lista esta vazia - remove\n");
     else { P = L->Prim;
            while((P!=L->Ult)&&(X->cod > P->Prox->Item.cod))
                P=P->Prox;
            if ((P==L->Ult)||(X->cod!=P->Prox->Item.cod))
              printf("Elemento NAO EXISTE na lista - Remove\n");
             else { *X = P->Prox->Item;
				 	printf("\n Elemento removido : \n");
				    Exibir_Elemento(*X);
                    A = P->Prox;
                    if (A==L->Ult)
                      L->Ult = P;
					P->Prox=A->Prox;
					free(A);
					L->Tam--;
                 }
          }
   }
   
 void Exibir_Lista(Lista_din_enc L)
  { Ponteiro P;
	
	if(Verifica_Lista_Vazia(L))
	   printf("Lista Vazia - nada para exibir \n\n");
	  else { P = L.Prim;
		     while(P!=L.Ult)
		       { Exibir_Elemento(P->Prox->Item);
				 P=P->Prox;
			    }
			 }
  }
 
 void Consulta_Elemento(Lista_din_enc L, int cod)
  { Ponteiro P;
    if(Verifica_Lista_Vazia (L))
      printf("A Lista esta vazia - consulta\n");
     else { P = L.Prim->Prox;
            while((P!=NULL)&&(cod > P->Item.cod))
                P=P->Prox;
            if ((P==NULL)||(cod!=P->Item.cod))
              printf("Elemento NAO foi encontrado para consulta\n");
             else  Exibir_Elemento(P->Item);   
            }
    }
  
  void Ler(T_Pessoa *X)
  {
	  printf("\nEntre com o Código: ");
	  scanf("%d",&(X->cod));
	  printf("\nEntre com o Nome : ");
	  scanf("%s",X->nome);
  }


   void Menu()
   {
	   printf("M E N U - L I S T A   E S T A T I C A  E N C A D E A D A\n");
	   printf("1 - Inserir Novo Elemento na Lista\n");
	   printf("2 - Remover Elemento da Lista\n");
	   printf("3 - Consultar Elemento na Lista\n");
	   printf("4 - Exibir Lista\n");
	   printf("5 - Gravar em Arquivo\n");
	   printf("6 - Carregar Lista de Arquivo\n");
	   printf("7 - Sair\n");
	   printf("Opcao:  ");
	   
   }
   
  int main()
    {T_Pessoa X;
	 Lista_din_enc L;
	 Ponteiro P;
	 int op,cod;
	 FILE *arq;
	 Criar_Lista_Vazia(&L);
	  do { Menu();
	   scanf("%d",&op);
	   switch (op) {
		  case 1:Ler(&X);
	             Insere_Elemento_Lista(&L,X);
	             break;
		  case 2:printf("Entre com o código a consultar: \n");
		         scanf("%d",&X.cod);
		         Remove_Elemento_Lista(&L,&X);
		         break;
		  case 3:printf("Entre com o código a consultar: \n");
		         scanf("%d",&cod);
		         Consulta_Elemento(L,cod);
		         break;
		  case 4: Exibir_Lista(L);
		         break;
		  case 5:  
		            arq = fopen("arquivo.dat", "wb"); 
                    if(arq!=NULL) 
                      { 
		                P=L.Prim->Prox;
				        while(P!=NULL)
					      { fwrite(&(P->Item), sizeof(T_Pessoa),1,arq);   //fechamento
					        P=P->Prox;						
					       }  
					    fclose(arq);    
					   }       
                    break;
          case 6:  arq = fopen("arquivo.dat", "rb"); 
                   if (arq!=NULL)
                       {Criar_Lista_Vazia(&L);
						X.cod=0;
                        while (!feof(arq))
						  { if(X.cod!=0)
							  Insere_Elemento_Lista(&L,X);
							fread(&X, sizeof(T_Pessoa), 1, arq);   //fechamento
						   }      
					   fclose(arq);
					  }       
                  break;
		  case 7: printf("\nObrigado por usar nosso Software\n");
		         break;
		  default : printf("Opção não existente\n");
		         break;
		   }
	   	  
  }while(op!=7);
	 return 0;	
    }
	  
