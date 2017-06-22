/*
ALUNOS: KARINE PIRES DE ARAÚJO MATRICULA: 20140267
         FILIPE BARROS OLIVEIRA MATRICULA: 201614840
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

typedef struct {
    int codProduto;
    char nomeProduto[100];
    char tipoProduto[100];
    double valorProduto;
    char uniProduto[10];
    int qtdEstoque;
    char dataVencimento[11];
    int codFornecedor;
}T_Item;

typedef struct{ 
    T_Item Elem[MAX];
    int Prim, Ult;
}Lista_Est;

typedef struct nd {
    int codProd;
    struct nd *Esq, *Dir;
}Nodo;

typedef Nodo *Arvore;

void Criar_Arvore_Vazia(Arvore *T){
    (*T) = NULL;
}

void Criar_Lista_Vazia(Lista_Est *L){ 
    L -> Prim = 0;
    L -> Ult = L -> Prim;	   
}
int verifica_lista_vazia (Lista_Est L){
    return(L.Prim == L.Ult); // Quando Prim for igual a Ult a lista está vazia
}

int verifica_lista_cheia (Lista_Est L){ 
    return(L.Ult == MAX); // Quando Ult apontar para a posição Max a lista está cheia
}

void Insere_Elemento_Lista(Lista_Est *L, T_Item X, Arvore *T){ 
    int A, P = L -> Prim;
    
    if (verifica_lista_cheia(*L))
        printf("\n A LISTA ESTÁ CHEIA ***** AUMENTE A CAPACIDADE DELA \n ");
    else {
	    while ((P < L -> Ult) && (X.codProduto > L -> Elem[P].codProduto))
            P++;
        if(P == L-> Ult){
            L -> Elem[P] = X;
            L -> Ult ++;
        }
        else {
			for(A=L -> Ult; A > P; A--)
			    L -> Elem[A] = L -> Elem[A-1];
			L -> Elem[P] = X;
			L -> Ult ++;
        }      
    }
    Insere_Elemento_Arvore(*T, X.codProduto);
}

void Exibir_Elemento(int codigo, Lista_Est *L){
    printf("\n------Exibindo Elemento------");
    printf("\nCODIGO DO PRODUTO: %i", L->Elem[codigo].codProduto);
    printf("\nNOME DO PRODUTO: %s", L->Elem[codigo].nomeProduto);
    printf("\nTIPO DO PRODUTO: %s", L->Elem[codigo].tipoProduto);
    printf("\nVALOR DO PRODUTO: %lf", L->Elem[codigo].valorProduto);
    printf("\nUNIDADE DO PRODUTO: %s", L->Elem[codigo].uniProduto);
    printf("\nQUANTIDADE DE ESTOQUE DO PRODUTO: %s", L->Elem[codigo].qtdEstoque);
    printf("\nDATA DE VENCIMENTO DO PRODUTO: %s", L->Elem[codigo].dataVencimento);
    printf("\nCODIGO DO FORNECEDOR DO PRODUTO: %s", L->Elem[codigo].codFornecedor);
}

void Insere_Elemento_Arvore(Arvore *T, int codProduto){
    Arvore A;
    if((*T)==NULL)
      { A = (Arvore) malloc (sizeof (Nodo));
        A->codProd = codProduto;
        A->Esq = NULL;
        A->Dir =NULL;
        (*T)=A; }
        else if (codProduto < ((*T)->codProd))
                   Insere_Elemento_Arvore(&(*T)->Esq, codProduto);
                else if (codProduto>((*T)->codProd))
                         Insere_Elemento_Arvore(&(*T)->Dir, codProduto);
                      else printf("Elemento ja existe na árvore %d \n", codProduto);
}

void in_ordem(Arvore T, Lista_Est *L){ 
    if (T!=NULL){
        in_ordem(T->Esq);
        Exibir_Elemento(T->codProd, *L);
        in_ordem(T->Dir);
    }
 }
  
int main(){
    Lista_Est lista;
    Arvore T;
    T_Item X;
    
    Criar_Lista_Vazia(&lista);
    Criar_Arvore_Vazia(&T);
    
    X.codProduto = 10;
    strcpy(X.nomeProduto, "Arroz Cristal");
    strcpy(X.tipoProduto, "Alimento");
    X.valorProduto = 20.30;
    strcpy(X.uniProduto, "Kg");
    X.qtdEstoque = 30;
    strcpy(X.dataVencimento, "11/12/2020");
    X.codFornecedor = 112;
    
    Insere_Elemento_Lista(&lista, X, &T);
    
    X.codProduto = 15;
    strcpy(X.nomeProduto, "Macarrão Mariana");
    strcpy(X.tipoProduto, "Alimento");
    X.valorProduto = 3.50;
    strcpy(X.uniProduto, "Kg");
    X.qtdEstoque = 10;
    strcpy(X.dataVencimento, "09/01/2018");
    X.codFornecedor = 112;
    
    Insere_Elemento_Lista(&lista, X, &T);
    
    in_ordem(T, &lista);
    
    return 0;
}
