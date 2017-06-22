#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { int cod;
                 char Nome[40];
                }T_Pessoa;
                
typedef struct cx{ T_Pessoa Item;
                   struct cx *Prox, *Ant;
                  }Caixa;
                  
typedef Caixa *Ponteiro;

typedef struct {Ponteiro Prim;
	            Ponteiro Ult;
                int Tam;
                }Lista_dup_enc;

void Criar_Lista_Vazia(Lista_dup_enc *L)
  { L->Prim = NULL;
    L->Ult = NULL;
    L->Tam = 0;
  }
  
int Verifica_Lista_Vazia(Lista_dup_enc L)
  {
    return(L.Prim==NULL);   
 }
 
void Insere_Elemento_Lista(Lista_dup_enc *L, T_Pessoa X)
  { Ponteiro P,A;
	P=(Ponteiro) malloc(sizeof(Caixa));
	P->Item = X;
	if(L->Prim==NULL)  //lista vazia ainda
	  {L->Prim = P;
	   L->Ult = P;
	   L->Prim->Prox=NULL;
	   L->Prim->Ant=NULL;
	  }else{A=L->Prim;
		    while((A!=NULL)&&(X.cod>A->Item.cod))
		       A=A->Prox;
		    if(A==NULL) //Entra após o último elemento
		       {P->Prox=L->Ult->Prox;
				L->Ult->Prox=P;
				P->Ant=L->Ult;				
				L->Ult=P;
			 }else if(A==L->Prim)
			         {P->Prox=A;
					  P->Ant=A->Ant;
			          A->Ant=P;
			          L->Prim=P;
			         }else {P->Prox=A;
						    P->Ant=A->Ant;
						    A->Ant->Prox = P;
						    A->Ant=P;
						   }
		      L->Tam++;
		     }	  
}

void Exibir_Elemento(T_Pessoa X)
  {  printf("  %5d - %s \n",X.cod, X.Nome);
	  
   }

void Remove_Elemento_Lista(Lista_dup_enc *L, T_Pessoa *X)
 { Ponteiro P;
   if(Verifica_Lista_Vazia(*L))
      printf("A lista está Vazia - Remove\n");
     else {P=L->Prim;
		   while((P!=NULL)&&(X->cod > P->Item.cod))
		       P=P->Prox;
		   if((P==NULL)||(X->cod!=P->Item.cod))
		       printf("Elemento não Encontrado na Lista - Remove\n");
		      else { *X=P->Item;
				     if((P==L->Prim)&&(P==L->Ult)) //so tem um elemento na lista
		               { L->Ult = NULL;
						 L->Prim = NULL;
						}else if(P==L->Prim)  //vou remover o primeiro elemento da lista
						        {P->Prox->Ant=P->Ant;
								 L->Prim = P->Prox;
							 }else if (P==L->Ult)  //vou remover o ultimo elemento da lista
							         {P->Ant->Prox = P->Prox;
									  L->Ult=P->Ant;
								  }else {P->Ant->Prox = P->Prox;
									     P->Prox->Ant = P->Ant;
									    }
						L->Tam--;
						free(P);
						printf("\n Elemento removido : \n");
	                    Exibir_Elemento(*X);
					}
			}
	 
	}


 void Exibir_Lista(Lista_dup_enc L)
  { Ponteiro P;
	
	if(Verifica_Lista_Vazia(L))
	   printf("Lista Vazia - nada para exibir \n\n");
	  else { P = L.Prim;
		     while(P!=NULL)
		       { Exibir_Elemento(P->Item);
				 P=P->Prox;
			    }
			 }
  }
	  
   
void Ler(T_Pessoa *X)
  {
	  printf("\nEntre com o Código: ");
	  scanf("%d",&(X->cod));
	  printf("\nEntre com o Nome : ");
	  scanf("%s",X->Nome);
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
{ int op;
  Lista_dup_enc L;
  T_Pessoa X;
  Ponteiro P;
  FILE *arq;
  Criar_Lista_Vazia(&L);
  do { Menu();
	   scanf("%d",&op);
	   switch (op) {
		  case 1:Ler(&X);
	             Insere_Elemento_Lista(&L,X);
	             break;
		  case 2:printf("Entre com o codigo : \n");
		         scanf("%d",&X.cod);
		         Remove_Elemento_Lista(&L,&X);
		         break;
		  case 3:
		         break;
		  case 4: Exibir_Lista(L);
		         break;
		  case 5:  
		            arq = fopen("arquivo.dat", "wb"); 
                    if(arq!=NULL) 
                      { 
		                P=L.Prim;
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
 return(0);

}

