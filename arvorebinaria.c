#include <stdlib.h>
#include <stdio.h>

typedef struct { int codigo;
                 char Nome[40];
                 char Data_Nasc[11]; //  dd/mm/yyyy
                 char Tel_Res[14]; // 99 - 9999-9999
                 char Tel_Cel[14]; // 99 - 9999-9999
                 char email[40];
                 }Tipo_Agenda;
                 
typedef struct nd { Tipo_Agenda Elem;
                    struct nd *Esq, *Dir;
                    }Nodo;
                    
typedef Nodo *Arvore;

void Criar_Arvore_Vazia(Arvore *T)
   {
      (*T)=NULL;
   }
void Menu()
   { printf("1 - Inserir Elemento \n");
     printf("2 - Remover Elemento \n");
     printf("3 - Percorrer Arvore em Ordem \n"); 
     printf("7 - Sair \n");  
     printf("Opcao: ");
   }
   
void Insere_Elemento_Arvore(Arvore *T, Tipo_Agenda X)
  {
    Arvore A;
    if((*T)==NULL)
      { A = (Arvore) malloc (sizeof (Nodo));
        A->Elem = X;
        A->Esq = NULL;
        A->Dir =NULL;
        (*T)=A; }
        else if (X.codigo<((*T)->Elem.codigo))
                   Insere_Elemento_Arvore(&(*T)->Esq, X);
                else if (X.codigo>((*T)->Elem.codigo))
                         Insere_Elemento_Arvore(&(*T)->Dir, X);
                      else printf("Elemento ja existe na árvore %d \n",X.codigo);
  }
  
//Árvores Binárias de Busca
Tipo_Agenda Sucessor_Maior (Arvore *Q, Tipo_Agenda *R)
{
while ((*Q)->Dir != NULL)
(*Q)=(*Q)->Dir;
*R=(*Q)->Elem;
return((*Q)->Elem);
}
/*Tipo_Agenda Maior (Apontador *Q, Registro *R)
{
while ((*Q)->Dir != NULL)
(*Q)=(*Q)->Dir;
*R=(*Q)->Elem;
return((*Q)->Elem);
} */

void Remover_Elemento_Arvore(Arvore *T,Tipo_Agenda *X)
 { Arvore A;
   if ((*T)==NULL)
	 printf("Arvore vazia - Elemento não encontrado \n");
	 else { if ((X->codigo < (*T)->Elem.codigo))
	            Remover_Elemento_Arvore (&(*T)->Esq,&(*X));
	           else  if ((X->codigo > (*T)->Elem.codigo))
	                    Remover_Elemento_Arvore (&(*T)->Dir,&(*X));
	                    else { A = (*T);
	                            *X = A->Elem;
	                            if ((*T)->Esq == NULL)
	                                { *X=(*T)->Elem;
                                      A=*T;
                                      (*T) = (*T)->Dir;;
                                      free(A);
								    }
	                              else if ((*T)->Dir == NULL)
	                                      {
	                                       (*X)=(*T)->Elem;
                                           A=(*T);
                                           (*T) = (*T)->Esq;;
                                           free(A);
									      }
	                                      else 
	                                         {
											   (*T)->Elem=Sucessor_Maior(&(*T)->Esq,&(*X));
                                               Remover_Elemento_Arvore (&(*T)->Esq,&(*X));
											 }
							
						  }
                 }
}
void Exibir_Elemento(Tipo_Agenda X)
  { printf("\n***********************************************************\n ");
	printf("\n ELEMENTO NUMERO: %d", X.codigo);
    printf(" \n \n *  Nome: %s   \n",X.Nome);
    printf(" *  Data_Nasc: %s   \n",X.Data_Nasc);
    // printf(" *  Endereco: %s   \n",X.Endereco);
    printf(" *  Telefone Cel: %s   \n",X.Tel_Cel);
    printf(" *  Telefone Res: %s   \n",X.Tel_Res);
    printf(" *  E-mail: %s   \n",X.email);
    printf("\n***********************************************************\n ");
}
void pre_ordem(Arvore T)
  { if (T!=NULL)
      { Exibir_Elemento(T->Elem);
        pre_ordem(T->Esq);
        pre_ordem(T->Dir);
       }
 }
void in_ordem(Arvore T)
  { if (T!=NULL)
      { in_ordem(T->Esq);
        Exibir_Elemento(T->Elem);
        in_ordem(T->Dir);
       }
 }
 void pos_ordem(Arvore T)
  { if (T!=NULL)
      { pos_ordem(T->Esq);
        pos_ordem(T->Dir);
        Exibir_Elemento(T->Elem);
       }
 }
void Ler_Agenda(Tipo_Agenda *X)
  {  printf("\n CADASTRO DE UM AMIGO \n ");
     printf("\n Entre com o Código de Um amigo: ");
     scanf("%d",&(X->codigo));
     getchar();
     printf("\n Entre com o Nome de Um amigo: ");
     //scanf("%s", X -> Nome);
     gets(X -> Nome);
    /* printf("\n Entre com o Endereço de Um amigo: ");
     //scanf("%s", X -> Endereco);
     gets(X -> Endereco); */
     printf("\n Entre com a Data de Nascimento de Um amigo: ");
     //scanf("%s", X -> Data_Nasc);
     gets(X -> Data_Nasc);
     printf("\n Entre com o Telefone Celular de Um amigo: ");
     //scanf("%s", X -> Tel_Cel);
     gets(X -> Tel_Cel);
     printf("\n Entre com o Telefone Residencial de Um amigo: ");
     //scanf("%s", X -> Tel_Res);
     gets(X -> Tel_Res);
     printf("\n Entre com o Endereço de E - mail de Um amigo: ");
     //scanf("%s", X -> email);
     gets(X -> email);
  }

int main()
 {  Arvore T;
    Tipo_Agenda X;
    int op;
    
	Criar_Arvore_Vazia(&T); 
	do { Menu();
	     scanf("%d",&op);
		switch (op) { 
			case 1: Ler_Agenda(&X);
			         Insere_Elemento_Arvore(&T,X);
			      break;
			case 2: printf("\n Entre com o Código que deseja remover: ");
			         scanf("%d",&(X.codigo));
			         Remover_Elemento_Arvore(&T,&X);
			         Exibir_Elemento(X);
			
			      break;
			case 3:  in_ordem(T);
			      break;
			default : printf("Nao existe esta opção no Menu \n");
			}
	}while (op==7);
	return(0);
 }
