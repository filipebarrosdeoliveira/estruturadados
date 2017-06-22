#include <stdio.h>
#include <stdlib.h>
#define MAXL 360

typedef struct { int cod;
    char data[8];
    int numeros_sorteadas[6];
}sorteio;

typedef struct { sorteio item[MAXL];
    int Prim, Ult;
}Lista_e;


typedef struct Cx{ sorteio Item;
    struct Cx *Prox;
}Caixa;

typedef Caixa *Ponteiro;



void Criar_Lista_Vazia(Lista_e *L)
{  L->Prim = 0;
    L->Ult = L->Prim;
}
int Verifica_Lista_Vazia(Lista_e L)
{
    return(L.Prim==L.Ult);
}

int Verifica_Lista_Cheia(Lista_e L)
{
    return(L.Ult==MAXL);
}
void Insere_Elemento_Lista(Lista_e *L, sorteio X)
{ int P, A;
    if(Verifica_Lista_Cheia(*L))
        printf("Lista Cheia - Insere \n");
    else
    { P = L->Prim;
        while((P!=L->Ult)&&(X.cod>L->item[P].cod))
            P++;
        if ((P<L->Ult)&&(X.cod!=L->item[P].cod)) //insere no meio da lista
        { for(A=L->Ult; A>P; A--)
            L->item[A] = L->item[A-1];
            L->item[P] = X;
            L->Ult++;
        }else if(P==L->Ult)
        { L->item[P]=X;
            L->Ult++;
        }
        else {printf("Código já existe - Substituindo\n");
            L->item[P] = X;
        }
    }
}

void Exibe_Elemento(sorteio X)
{ int i;
    printf("\n*******  Número do Sorteio: %d ********\n",X.cod);
    printf("*data: %s \t \t*\n",X.data);
    for( i=0;i<6;i++){
        printf("*Dezena %d: %d \t \t*",(i+1),X.numeros_sorteadas[i]);
    }
    printf("\n");
    printf("*******    Final do registro   ********\n");
}

void Exibe_Lista(Lista_e L)
{ int P;
    if(Verifica_Lista_Vazia(L))
        printf("Lista Vazia - Exibe\n");
    else   { system("clear");
        
		      printf("*************  RELATORIO DOS ELEMENTOS DA LISTA **************\n");
		      for(P=L.Prim; P<L.Ult;P++)
                  Exibe_Elemento(L.item[P]);
		      printf("*************     FINAL DO RELATORIO DA LISTA    **************\n");
    
    }
}
int Consultar_Elemento(Lista_e L, sorteio X)
{ int P;
    if(Verifica_Lista_Vazia(L))
        return(-1);
    else { P = L.Prim;
        while((P!=L.Ult)&&(X.cod>L.item[P].cod))
            P++;
        if((P<L.Ult) && (X.cod == L.item[P].cod))
            return(P);
        else return(-1);
    }
}

void Remove_Elemento_Lista(Lista_e *L, sorteio *X)
{ int P,A;
    if(Verifica_Lista_Vazia(*L))
        printf("Lista Vazia - Remove \n");
    else
    { P = L->Prim;
        while((P!=L->Ult)&&(X->cod>L->item[P].cod))
            P++;
        if ((P<L->Ult-1)&&(X->cod==L->item[P].cod)) //remover no meio da lista
        { *X = L->item[P];
            for(A=P; A<L->Ult; A++)
                L->item[A] = L->item[A+1];
            L->Ult--;
        }else if(P==L->Ult-1)
        { *X = L->item[P];
            L->Ult--;
        } else printf("Elemento não encontrado na Lista - Remover\n");
    }
}
void Ler_Elemento(sorteio *X)
{ int i;
	   printf("***** Cadastrar Sorteio *****\n");
    printf("\n* Entre com o codigo: ");
    scanf("%d",&X->cod);
    printf("\n* Entre com a data: ");
    scanf("%s",X->data);
    for( i=0;i<6;i++){
        printf("digite a dezena número %d: ",i+1);
        scanf("%d", &X->numeros_sorteadas[i]);
	   }
}



void contador_Dezena(int N,int *vet_ocorrencias){
    int i;
    for( i=0;i<60;i++){
        if(N==(i+1)){
            vet_ocorrencias[i]++;
            break;
        }
    }
    
}

void inicializar_vet_cont(int *vet_ocorrencias){
    int i;
    for( i=0;i<60;i++)
        vet_ocorrencias[i]=0;
    
}





void Menu()
{
    system("clear");
    printf("\n********* MENU ***********\n");
    printf("* 1 - Inserir pessoas\n");
    printf("* 2 - Consultar Pessoas na lista\n");
    printf("* 3 - Exibir Pessoas da lista\n");
    printf("* 4 - Gravar em Arquivo\n");
    printf("* 5 - Carregar Lista de Arquivo\n");
    printf("* 6 - Exibir ocorrencias de cada numero do sorteio\n");
    printf("* 7 - Exibie os seis números mais sorteados\n ");
    printf("* 8 - Sair\n");
    printf("* Opcao: ");
}

int main()
{
    int vet_ocorrencias[60];
    int indice[6];
    sorteio X;
    Lista_e L;
    int op, p,i;
    FILE *arq;
    Ponteiro P;
    inicializar_vet_cont(vet_ocorrencias);
    Criar_Lista_Vazia(&L);
    do { Menu();
        scanf("%d",&op);
        switch(op) {
            case 1: Ler_Elemento(&X);
                Insere_Elemento_Lista(&L, X);
                for(i=0;i<6;i++){
                    contador_Dezena(X.numeros_sorteadas[i],vet_ocorrencias);
                }
                maiores_ocorrencias(vet_ocorrencias,indice);
                break;
                
            case 2: printf("Entre com o Código que deseja Consultar: ");
                scanf("%d",&X.cod);
                p = Consultar_Elemento(L,X);
                if (p!=-1)
                    Exibe_Elemento(L.item[p]);
                else printf("Elemento não encontrado na lista - consulta");
                break;
            case 3: Exibe_Lista(L);
                break;
                
                
            case 4:
                arq = fopen("arquivo.dat", "wb");
                if(arq!=NULL)
                {
                    
                    while(P!=NULL)
                    { fwrite(&(P->Item), sizeof(sorteio),1,arq);   //fechamento
                        P=P->Prox;
                    }
                    fclose(arq);
                }
                break;
            case 5:  arq = fopen("arquivo.dat", "rb");
                if (arq!=NULL)
                {Criar_Lista_Vazia(&L);
                    X.cod=0;
                    while (!feof(arq))
                    { if(X.cod!=0)
                        Insere_Elemento_Lista(&L,X);
                        fread(&X, sizeof(sorteio), 1, arq);   //fechamento
                    }
                    fclose(arq);
                }
                break;
            case 6: for( i=0;i<60;i++){
                printf("ocorencias do número %d: %d vezes", i+1,vet_ocorrencias[i]);
            }
                break;
            case 7: printf("Ordem decrescente\n");
                for(i=0;i<6;i++){
                    printf("%d\n", vet_ocorrencias[indice[0]]);
                    break;
                }
            case 8:printf("Obrigado por utilizar o software\n");
                break;
            default : printf("Opção não existente\n");
                break;
        }
        
    }while(op!=8);
    
    return(0);
}


