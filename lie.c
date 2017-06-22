/* Alunos: Breno de Melo, Filipe Barros;
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXL 100

typedef struct { int cod;
    char nome[40];
    char data_nasc[11];
    char email[40];
    char tel[14];
}T_Pessoa;

typedef struct { T_Pessoa Elem[MAXL];
    int Prim, Ult;
}Lista_e;

void Criar_Lista_Vazia(Lista_e *L)
{  L->Prim = 0;
    L->Ult = L->Prim;
}

void Criar_Lista_vazia_Coracao(Lista_e *LCoracao)
{  LCoracao->Prim = 0;
   LCoracao->Ult = LCoracao->Prim;
 }
 
void Criar_Lista_vazia_Rim(Lista_e *LRim)
{  LRim->Prim = 0;
   LRim->Ult = LRim->Prim;
}

void Criar_Lista_vazia_Figado(Lista_e *LFigado) 
{  LFigado->Prim = 0;
   LFigado->Ult = LFigado->Prim;
}

void Criar_Lista_vazia_Pancreas(Lista_e *LPancreas)
{  LPancreas->Prim = 0;
   LPancreas->Ult = LPancreas->Prim;
}

void Criar_Lista_vazia_Cornea(Lista_e *LCornea)
{ LCornea->Prim = 0;
  LCornea->Ult = LCornea->Prim;
}		

void Criar_Lista_vazia__Pulmao(Lista_e *LPulmao)
{ LPulmao->Prim = 0;
  LPulmao->Ult = LPulmao->Prim;
}

int Verifica_Lista_Vazia(Lista_e L)
{
    return(L.Prim==L.Ult);
}

int Verifica_Lista_Cheia(Lista_e L)
{
    return(L.Ult==MAXL);
}

void Insere_Elemento_Lista(Lista_e *L, T_Pessoa X)
{ int P, A;
    if(Verifica_Lista_Cheia(*L))
        printf("Lista Cheia - Insere \n");
    else
    { P = L->Prim;
        while((P!=L->Ult)&&(X.cod>L->Elem[P].cod))
            P++;
        if ((P<L->Ult)&&(X.cod!=L->Elem[P].cod)) //insere no meio da lista
        { for(A=L->Ult; A>P; A--)
            L->Elem[A] = L->Elem[A-1];
            L->Elem[P] = X;
            L->Ult++;
        }else if(P==L->Ult)
        { L->Elem[P]=X;
            L->Ult++;
        }
        else {printf("Código já existe - Substituindo\n");
            L->Elem[P] = X;
        }
    }
}

void Exibe_Elemento(T_Pessoa X)
{ printf("\n*******  Pessoa de Codigo: %d ********\n",X.cod);
    printf("*Nome: %s \t \t*\n",X.nome);
    printf("*Data de Nascimento: %s \t \t*\n",X.data_nasc);
    printf("*E_Mail: %s \t \t*\n",X.email);
    printf("*Telefone: %s \t \t*\n",X.tel);
    printf("*******    Final do registro   ********\n");
}

void Exibe_Lista(Lista_e L)
{ int P;
    if(Verifica_Lista_Vazia(L))
        printf("Lista Vazia - Exibe\n");
    else { system("clear");
		      printf("*************  RELATORIO DOS ELEMENTOS DA LISTA **************\n");
		      for(P=L.Prim; P<L.Ult;P++)
                  Exibe_Elemento(L.Elem[P]);
		      printf("*************     FINAL DO RELATORIO DA LISTA    **************\n");
		      
    }
}

int Consultar_Elemento(Lista_e L, T_Pessoa X)
{ int P;
    if(Verifica_Lista_Vazia(L))
        return(-1);
    else { P = L.Prim;
        while((P!=L.Ult)&&(X.cod>L.Elem[P].cod))
            P++;
        if((P<L.Ult) && (X.cod == L.Elem[P].cod))
            return(P);
        else return(-1);
    }
}

void Remove_Elemento_Lista(Lista_e *L, T_Pessoa *X)
{ int P,A;
    if(Verifica_Lista_Vazia(*L))
        printf("Lista Vazia - Remove \n");
    else
    { P = L->Prim;
        while((P!=L->Ult)&&(X->cod>L->Elem[P].cod))
            P++;
        if ((P<L->Ult-1)&&(X->cod==L->Elem[P].cod)) //remover no meio da lista
        { *X = L->Elem[P];
            for(A=P; A<L->Ult; A++)
                L->Elem[A] = L->Elem[A+1];
            L->Ult--;
        }else if(P==L->Ult-1)
        { *X = L->Elem[P];
            L->Ult--;
        } else printf("Elemento não encontrado na Lista - Remover\n");
    }
}

void Ler_Elemento(T_Pessoa *X)
{   printf("***** Modulo de Leitura do Registro Pessoa *****\n");
    printf("\n* Entre com o codigo: ");
    scanf("%d",&X->cod);
    getchar();
    printf("\n* Entre com o Nome: ");
    gets(X->nome);
    printf("\n* Entre com o email: ");
    scanf("%s",X->email);
    printf("\n* Entre com o Telefone: ");
    scanf("%s", X->tel);
    printf("\n* Entre com  Data de Nascimento: ");
    scanf("%s", X->data_nasc);
}

void Menu()
{
    system("clear");
    printf("\n********* MENU ***********\n");
    printf("* 1 - Coração\n");
    printf("* 2 - Rim\n");
    printf("* 3 - Figado\n");
    printf("* 4 - Pâncreas\n");
    printf("* 5 - Cornea\n");
    printf("* 6 - Pulmão\n");
    printf("* 7 - Sair\n");
    printf("* Opcao: ");
}

void Menu_2()
{
    system("clear");
    printf("\n********* MENU ***********\n");
    printf("* 1 - Insere Elemento na lista\n");
    printf("* 2 - Remover Elemento da lista\n");
    printf("* 3 - Consultar Elemento na lista\n");
    printf("* 4 - Exibir Elementos da lista\n");
    printf("* 5 - Alterar Elemento na lista\n");
    printf("* 6 - Sair\n");
    printf("* Opcao: ");
}

int main()
{
    T_Pessoa X;
    Lista_e LCoracao, LRim, LFigado, LPancreas, LCornea, LPulmao;
    int op,op2, p;
    Criar_Lista_vazia_Coracao(&LCoracao);
    Criar_Lista_vazia_Rim(&LRim);
    Criar_Lista_vazia_Figado(&LFigado);
    Criar_Lista_vazia_Pancreas(&LPancreas);
    Criar_Lista_vazia_Cornea(&LCornea);
    Criar_Lista_vazia__Pulmao(&LPulmao);
    do { Menu();
        scanf("%d",&op);
        if(op == 7)
          break;
        Menu_2();
        scanf("%d", &op2);
        switch(op){
           case 1: switch(op2) {
                     case 1: Ler_Elemento(&X);
                             getchar();                    
                             Insere_Elemento_Lista(&LCoracao, X);
                             break;
                     case 2: printf("Entre com o Código que deseja Remover: ");
                         scanf("%d",&X.cod);
                         Remove_Elemento_Lista(&LCoracao, &X);
                         printf("\n Removendo o elemento: \n");
                         Exibe_Elemento(X);
                          break;
                     case 3: printf("Entre com o Código que deseja Consultar: ");
                         scanf("%d",&X.cod);
                         p = Consultar_Elemento(LCoracao,X);
                         if (p!=-1)
                            Exibe_Elemento(LCoracao.Elem[p]);
                         else printf("Elemento não encontrado na lista - consulta");
                         break;
                    case 4: Exibe_Lista(LCoracao);
                         break;
                    case 5: printf("Estamos em construção \n");
                        break;
                    case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                        break;
                    default: printf("Digite uma opção de 1 a 6 por favor \n");
                        break;
                  }    
                  break;    
         
         case 2 : switch(op2) {
            case 1: Ler_Elemento(&X);
                Insere_Elemento_Lista(&LRim, X);
                break;
            case 2: printf("Entre com o Código que deseja Remover: ");
                scanf("%d",&X.cod);
                Remove_Elemento_Lista(&LRim, &X);
                printf("\n Removendo o elemento: \n");
                Exibe_Elemento(X);
                break;
            case 3: printf("Entre com o Código que deseja Consultar: ");
                scanf("%d",&X.cod);
                p = Consultar_Elemento(LRim,X);
                if (p!=-1)
                    Exibe_Elemento(LRim.Elem[p]);
                else printf("Elemento não encontrado na lista - consulta");
                break;
            case 4: Exibe_Lista(LRim);
                break;
            case 5: printf("Estamos em construção \n");
                break;
            case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                break;
            default: printf("Digite uma opção de 1 a 6 por favor \n");
                break;
         }
         break;
         case 3 : switch(op2) {
            case 1: Ler_Elemento(&X);
                Insere_Elemento_Lista(&LFigado, X);
                break;
            case 2: printf("Entre com o Código que deseja Remover: ");
                scanf("%d",&X.cod);
                Remove_Elemento_Lista(&LFigado, &X);
                printf("\n Removendo o elemento: \n");
                Exibe_Elemento(X);
                break;
            case 3: printf("Entre com o Código que deseja Consultar: ");
                scanf("%d",&X.cod);
                p = Consultar_Elemento(LFigado,X);
                if (p!=-1)
                    Exibe_Elemento(LFigado.Elem[p]);
                else printf("Elemento não encontrado na lista - consulta");
                break;
            case 4: Exibe_Lista(LFigado);
                break;
            case 5: printf("Estamos em construção \n");
                break;
            case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                break;
            default: printf("Digite uma opção de 1 a 6 por favor \n");
                break;
         }
         break;
         case 4 : switch(op2) {
            case 1: Ler_Elemento(&X);
                Insere_Elemento_Lista(&LPancreas, X);
                break;
            case 2: printf("Entre com o Código que deseja Remover: ");
                scanf("%d",&X.cod);
                Remove_Elemento_Lista(&LPancreas, &X);
                printf("\n Removendo o elemento: \n");
                Exibe_Elemento(X);
                break;
            case 3: printf("Entre com o Código que deseja Consultar: ");
                scanf("%d",&X.cod);
                p = Consultar_Elemento(LPancreas,X);
                if (p!=-1)
                    Exibe_Elemento(LPancreas.Elem[p]);
                else printf("Elemento não encontrado na lista - consulta");
                break;
            case 4: Exibe_Lista(LPancreas);
                break;
            case 5: printf("Estamos em construção \n");
                break;
            case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                break;
            default: printf("Digite uma opção de 1 a 6 por favor \n");
                break;
         }
         break;
         case 5 : switch(op2) {
            case 1: Ler_Elemento(&X);
                Insere_Elemento_Lista(&LCornea, X);
                break;
            case 2: printf("Entre com o Código que deseja Remover: ");
                scanf("%d",&X.cod);
                Remove_Elemento_Lista(&LCornea, &X);
                printf("\n Removendo o elemento: \n");
                Exibe_Elemento(X);
                break;
            case 3: printf("Entre com o Código que deseja Consultar: ");
                scanf("%d",&X.cod);
                p = Consultar_Elemento(LCornea,X);
                if (p!=-1)
                    Exibe_Elemento(LCornea.Elem[p]);
                else printf("Elemento não encontrado na lista - consulta");
                break;
            case 4: Exibe_Lista(LCornea);
                break;
            case 5: printf("Estamos em construção \n");
                break;
            case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                break;
            default: printf("Digite uma opção de 1 a 6 por favor \n");
                break;
         }
         break;
         case 6 : switch(op2) {
            case 1: Ler_Elemento(&X);
                Insere_Elemento_Lista(&LPulmao, X);
                break;
            case 2: printf("Entre com o Código que deseja Remover: ");
                scanf("%d",&X.cod);
                Remove_Elemento_Lista(&LPulmao, &X);
                printf("\n Removendo o elemento: \n");
                Exibe_Elemento(X);
                break;
            case 3: printf("Entre com o Código que deseja Consultar: ");
                scanf("%d",&X.cod);
                p = Consultar_Elemento(LPulmao,X);
                if (p!=-1)
                    Exibe_Elemento(LPulmao.Elem[p]);
                else printf("Elemento não encontrado na lista - consulta");
                break;
            case 4: Exibe_Lista(LPulmao);
                break;
            case 5: printf("Estamos em construção \n");
                break;
            case 6: printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                break;
            default: printf("Digite uma opção de 1 a 6 por favor \n");
                break;
         }
         break;
         case 7 : printf("Obrigado Por Usar nosso Progrma - ESS(R)\n");
                break;
         
         default: printf("Digite uma opção de 1 a 6 por favor \n");
                break;        
     }
        printf("\nDigite algo pra continuar.....\n");
        char t[2];
        scanf("%s",t);
        
    } while(op!=6);
    printf("Obrigado por utilizar o software :)\n");
    return(0);
}
