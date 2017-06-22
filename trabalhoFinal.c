//Karine e Filipe Barros 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 180
#define MAXS 10 //Define a quantidade de sessões que cabe no teatro
#define MAXR 36 //10% do total de cadeiras em cada sessao.
#define LIN 2
#define COL 1

typedef struct{
    char nome[100];
    char telefone[11];
    int statusCadeira;
}Cliente;

typedef struct {
    int codigo;
    char data[10];
    char nome[100];
    char horasInicio[8];
    char horasFinal[5];
    Cliente cadeirasd[LIN][COL];
    Cliente cadeirase[LIN][COL];
}Sessao;

typedef struct {
    Cliente cliente;
    int diponibilidade;
    Sessao sessao;
}Status;

typedef struct {
    Sessao Elem[MAXS];
    int Prim, Ult;
}ListaSessao;

typedef struct {
    Cliente elem[MAXR];
    int Inicio, Fim, Total;
}FilaEspera;

void Criar_Lista_Vazia(ListaSessao *L);
void Criar_Fila_Vazia(FilaEspera *F);
int Verifica_Lista_Vazia(ListaSessao L);
int Verifica_Fila_Vazia(FilaEspera F);
int Verifica_Lista_Cheia (ListaSessao L);
int Verifica_Fila_Cheia(FilaEspera F);
void Ler_Elemento (Cliente *X);
void Ler_Sessao(Sessao *X);
void Insere_Elemento_Lista(ListaSessao *L, Sessao sessao);
int Remove_Elemento_Lista (ListaSessao *L, int codigoSessao);
int Consulta_Elemento(ListaSessao *L, int cod);
void Exibir_Elemento_Sessao(Sessao X);
void Exibir_Lista(ListaSessao L);
int Efetua_Venda(Cliente *cliente, int numFila, int numCadeira, ListaSessao *L, int pos, int lado);
int Cancela_Compra(Cliente *cliente, ListaSessao *L);
void Enfileirar(FilaEspera *F, Cliente X);
int Contador_Cadeiras(int p, ListaSessao L);
void Exibir_Fila_Espera(FilaEspera *F);
void Menu2();
void Menu();
char *dataaa(void);
char *format(int number);

int main(){
    int opcao, op2, codS, numFila, numCadeira, lado;
    Sessao sessao;
    Cliente cliente;
    ListaSessao listaDeSessoes;
    FilaEspera filaDeEspera;
    
    int codigoSessaoAux, aux, auxRemoveuSessao;
    char data_sistema[100];
    int p;
    
    Menu();
    scanf("%i", &opcao);
    
    Criar_Lista_Vazia(&listaDeSessoes);
    Criar_Fila_Vazia(&filaDeEspera);
    
    while(opcao!=0){
        switch(opcao) {
            case 1:
                Ler_Sessao(&sessao);
                Insere_Elemento_Lista(&listaDeSessoes, sessao);
                Exibir_Lista(listaDeSessoes);
                printf("\nSESSAO INCLUIDA COM SUCESSO\n");
                break;
            case 2:
                printf("Entre com o Código que deseja Remover: ");
                scanf("%d", &codigoSessaoAux);
                auxRemoveuSessao = Remove_Elemento_Lista(&listaDeSessoes, codigoSessaoAux);
                if(auxRemoveuSessao != -1)
                    printf("\nA sessao foi removida com sucesso da lista\n");
                else
                    printf("\nOcorreu um erro ao remover sessao da lista\n");
                break;
            case 3:
                printf("\nDigite o codigo da sessao que deseja consultar: ");
                scanf("%d", &codigoSessaoAux);
                codigoSessaoAux = Consulta_Elemento(&listaDeSessoes, codigoSessaoAux);
                if(codigoSessaoAux != -1)
                    Exibir_Elemento_Sessao(listaDeSessoes.Elem[codigoSessaoAux]);
                else
                    printf("\nSorry, a sessao ainda nao esta na lista\n");
                break;
            case 4:
                Exibir_Lista(listaDeSessoes);
                break;
            case 5:
                Menu2();
                scanf("%i", &op2);
                while(op2 != 0){
                    printf("\n\nInforme o NOME DO CLIENTE: ");
                    scanf("%s", cliente.nome);
                    printf("\nInforme o TELEFONE DO CLIENTE: ");
                    scanf("%s", cliente.telefone);
                    if(op2 == 1){
                        printf("\nInforme o CODIGO DA SESSAO DESEJADA: ");
                        scanf("%i", &codS);
                        aux = Consulta_Elemento(&listaDeSessoes, codS); //Recebe posição da lista onde a sessão está guardada
                        if(aux!=-1){
                            Exibir_Elemento_Sessao(listaDeSessoes.Elem[aux]);
                            int contadorCadeiras = Contador_Cadeiras(aux, listaDeSessoes);
                            int res;
                            
                            if(contadorCadeiras == LIN*COL*2){
                                printf("\nSessão LOTADA!");
                                printf("\nDeseja fazer reserva de uma cadeira?\n1- SIM\n2- NAO\nDigite sua escolha: ");
                                scanf("%i", &res);
                                if(res == 1){
                                    if(Verifica_Fila_Cheia(filaDeEspera)){
                                        printf("\nSorry, a fila de espera estah cheia!\n");
                                        break;
                                    }
                                    Enfileirar(&filaDeEspera, cliente);
                                    printf("\nCliente %s foi incluido da fila de espera com sucesso!\n", cliente.nome);
                                    break;
                                }
                            }
                            else{
                                do{
                                    printf("\nEscolha de 1 a %i para a fila e de 1 a %i para a posição da cadeira", LIN, COL);
                                    printf("\nInforme o numero da fila de 1 a %i: ", LIN);
                                    scanf("%i", &numFila);
                                    printf("\nInforme o numero da cadeira de 1 a %i: ", COL);
                                    scanf("%i", &numCadeira);
                                    printf("\nInforme o lado 1 - Direito ou 2 - Esquerdo: ");
                                    scanf("%i", &lado);
                                } while(!(numFila>0 && numFila<=LIN) && !(numCadeira>0 && numCadeira<=COL) && !(lado>=1 && lado<=2));
                                
                                int vendeu = Efetua_Venda(&cliente, (numFila-1), (numCadeira-1), &listaDeSessoes, aux, lado);
                                if(vendeu != -1){
                                    printf("\nCompra efetuada com sucesso\n");
                                }
                                else {
                                    printf("\nOps!, ocorreu um erro e a venda nao foi feita\n");
                                }
                            }
                        }
                        else {
                            printf("\nOps, a sessao escolhida não existe na lista de sessoes\n\n");
                            break;
                        }
                        break;
                    }
                    else if(op2 == 2){
                        int auxCancela = Cancela_Compra(&cliente, &listaDeSessoes);
                        if(auxCancela != -1)
                            printf("\nCancelado com sucesso\n");
                        else
                            printf("\nOcorreu erro ao cancelar\n");
                        break;
                    }
                    Menu2();
                    scanf("%i", &op2);
                }
                break;
            case 6:
                break;
            case 7:
                Exibir_Fila_Espera(&filaDeEspera);
                break;
            case 8: //Função que pega a hora atual do sistema verifica quais sessões passaram da data e retira da lista
                printf("\n*******ATENCAO*******\n");
                printf("ESSA FUNCAO REMOVE DA LISTA TODAS AS SESSOES JA PASSADAS APARTIR DA HORA DO SISTEMA\n");
                printf("DESEJA CONTINUAR? 1 - Sim, 2 - Nao\nInforme a opcao: ");
                scanf("%i", &op2);
                if(op2 == 1){
                    sprintf(data_sistema, "%s", dataaa());
                    printf("%s\n",data_sistema);
                    
                    if (Verifica_Lista_Vazia(listaDeSessoes))
                        printf("\nA lista esta vazia\n");
                    else {
                        p = listaDeSessoes.Prim;
                        while (p < listaDeSessoes.Ult){
                            if(strcmp(listaDeSessoes.Elem[p].data, data_sistema) < 0){
                                aux = Remove_Elemento_Lista(&listaDeSessoes, listaDeSessoes.Elem[p].codigo);
                                break;
                            }
                            p++;
                        }
                        if(aux!=-1)
                            printf("\nSessoes passsadas removidas com sucesso\n");
                        else
                            printf("\nOcorreu um erro ao remover as sessao da lista\n");
                    }
                }
                break;
            default:
                printf("\nSaindo...\n");
                break;
        }
        Menu();
        scanf("%i", &opcao);
    }
    
}

void Criar_Lista_Vazia(ListaSessao *L){
    L -> Prim = 0;
    L -> Ult = L -> Prim;
}

int Verifica_Lista_Vazia(ListaSessao L){
    return(L.Prim == L.Ult); // Quando Prim for igual a Ult a lista está vazia
}

int Verifica_Lista_Cheia (ListaSessao L){
    return(L.Ult == MAX); // Quando Ult apontar para a posição Max a lista está cheia
}

void Criar_Fila_Vazia(FilaEspera *F){
    F-> Inicio = 0;
    F-> Fim = 0;
    F-> Total = 0;
}

int Verifica_Fila_Vazia(FilaEspera F){
    return(F.Inicio == F.Fim);
}

int Verifica_Fila_Cheia(FilaEspera F){
    return((F.Fim+1)%MAXS == F.Fim);
}

void Ler_Elemento (Cliente *X){
    printf("\n Entre com o Nome : ");
    scanf("%s",X->nome);
    printf("\n Entre com o Telefone : ");
    scanf("%s",X->telefone);
    X->statusCadeira = 0;
}

void Ler_Sessao(Sessao *X) {
    int i, j;
    printf("\nEntre com o codigo da sessao: ");
    scanf("%i", &X->codigo);
    printf("\nEntre com a Nome da sessao: ");
    scanf ("%*C");
    fgets( X->nome, 100, stdin );
    printf("\nEntre com a Data da sessao: ");
    scanf("%s", X->data);
    printf("\nEntre com o horario do início da sessao: ");
    scanf("%s", X->horasInicio);
    printf("\nEntre com o Término da sessao: ");
    scanf("%s", X->horasFinal);
    
    for(i=0;i<LIN;i++){
        for(j=0;j<COL;j++){
            X->cadeirasd[i][j].statusCadeira = 0;
            X->cadeirase[i][j].statusCadeira = 0;
        }
    }
    
}

void Insere_Elemento_Lista(ListaSessao *L, Sessao sessao){
    int A, P = L -> Prim;
    
    if (Verifica_Lista_Cheia(*L))
        printf("\n A LISTA DE SESSÕES ESTÁ CHEIA ***** AUMENTE A CAPACIDADE DELA \n ");
    else {
        while ((P < L->Ult) && (sessao.codigo > L->Elem[P].codigo))
            P++;
        if(P == L->Ult){
            L->Elem[P] = sessao;
            L->Ult++;
        }
        else {
            for(A=L->Ult; A>P; A--)
                L -> Elem[A] = L->Elem[A-1];
            
            L->Elem[P] = sessao;
            L->Ult++;
        }
    }
}

int Remove_Elemento_Lista (ListaSessao *L, int codigoSessao){
    int p, i;
    
    if(Verifica_Lista_Vazia(*L)){
        printf("A Lista está vazia - Remocao negada \n");
        return -1;
    }
    else {
        p = L->Prim;
        
        while ((p < L->Ult) && (codigoSessao > L->Elem[p].codigo))
            p++;
        if ((p==L->Ult) || (codigoSessao != L->Elem[p].codigo)){
            printf("Elemento nao foi encontrado na Lista - Remove \n");
            return -1;
        }
        else {
            for (i=p; i<L->Ult; i++)
                L->Elem[i]=L->Elem[i+1];
            L->Ult--;
            return 0;
        }
    }
}

int Consulta_Elemento(ListaSessao *L, int cod){ //Consultar elemento na lista de sessões
    int p;
    
    if (Verifica_Lista_Vazia(*L))
        return -1;
    else {
        p = L->Prim;
        
        while ((p < L->Ult) && (cod > L->Elem[p].codigo))
            p++;
        if ((p==L->Ult) || (cod != L->Elem[p].codigo)){
            printf("Elemento nao Encontrado na lista\n");
            return -1;
        }
        else
            return p;
    }
}

void Exibir_Elemento_Sessao(Sessao X){
    int i, j;
    
    printf("\n---------Exibindo Sessão---------");
    printf("\nCODIGO: %i", X.codigo);
    printf("\nNOME DA PECA: %s", X.nome);
    printf("\nDATA DA SESSAO: %s", X.data);
    printf("\nHORA DE INICIO: %s", X.horasInicio);
    printf("\nHORA DE TERMINO: %s", X.horasFinal);
    printf("\n--------Exibindo cadeiras lado esquerdo--------\n");
    for(i=0;i<LIN;i++){
        printf("%i\t", i+1);
        for(j=0;j<COL;j++){
            printf("%i ", X.cadeirase[i][j].statusCadeira);
        }
        printf("\n");
    }
    printf("\n--------Exibindo cadeiras lado direito--------\n");
    for(i=0;i<LIN;i++){
        printf("%i\t", i+1);
        for(j=0;j<COL;j++){
            printf("%i ", X.cadeirasd[i][j].statusCadeira);
        }
        printf("\n");
    }
}

void Exibir_Lista(ListaSessao L){ // Exibir Sessões da lista
    int p;
    
    if (Verifica_Lista_Vazia(L))
        printf("\n LISTA VAZIA - SEM EXIBIR \n");
    else {
        p = L.Prim;
        
        while (p < L.Ult){
            Exibir_Elemento_Sessao(L.Elem[p]);
            p++;
        }
        printf("\n FIM DA LISTA ******* FIM DA LISTA \n");
    }
}

int Efetua_Venda(Cliente *cliente, int numFila, int numCadeira, ListaSessao *L, int pos, int lado){
    if(lado == 1){
        L->Elem[pos].cadeirasd[numFila][numCadeira] = *cliente;
        L->Elem[pos].cadeirasd[numFila][numCadeira].statusCadeira = 1;
        return 0;
    }
    if(lado == 2){
        L->Elem[pos].cadeirase[numFila][numCadeira] = *cliente;
        L->Elem[pos].cadeirase[numFila][numCadeira].statusCadeira = 1;
        return 0;
    }
    return -1;
}

int Cancela_Compra(Cliente *cliente, ListaSessao *L){
    int p, i, j;
    
    if (Verifica_Lista_Vazia(*L))
        printf("\n LISTA VAZIA - SEM EXIBIR \n");
    else{
        p = L->Prim;
        
        while (p < L->Ult){
            for(i=0;i<LIN;i++){
                for(j=0;j<COL;j++){
                    if((strcmp(cliente->nome, L->Elem[p].cadeirase[i][j].nome) == 0) || (strcmp(cliente->nome, L->Elem[p].cadeirasd[i][j].nome) == 0)){
                        if(strcmp(cliente->nome, L->Elem[p].cadeirase[i][j].nome) == 0){
                            L->Elem[p].cadeirase[i][j].statusCadeira = 0;
                            return 0;
                        }
                        else{
                            L->Elem[p].cadeirasd[i][j].statusCadeira = 0;
                            printf("\nCompra/Reserva cancelada com sucesso\n");
                            return 0;
                        }
                    }
                }
            }
            p++;
        }
        return -1;
    }
}

void Enfileirar(FilaEspera *F, Cliente X){
    if(Verifica_Fila_Cheia(*F))
        printf("A Fila de reserva estah cheia - Enfileirar\n");
    else{
        F->elem[F->Fim] = X;
        F->Fim = (F->Fim + 1)%MAXR;
        F->Total++;
    }
}

int Contador_Cadeiras(int p, ListaSessao L){
    int ncad = 0, i, j;
    
    for(i = 0; i < LIN; i++){
        for(j = 0; j < COL; j++){
            if(L.Elem[p].cadeirase[i][j].statusCadeira == 1)
                ncad++;
            if(L.Elem[p].cadeirasd[i][j].statusCadeira == 1)
                ncad++;
        }
    }
    return ncad;
}

void Exibir_Fila_Espera(FilaEspera *F){
    int p = F->Inicio;
    
    while(p < F->Fim) {
        printf("\nPOSICAO DA FILA: %i\n", p+1);
        printf("NOME DO CLIENTE: %s\n", F->elem[p].nome);
        printf("TELEFONE DO CLIENTE: %s\n", F->elem[p].telefone);
        p++;
    }
}

void Menu2(){
    printf("\n---------------MENU---------------\n");
    printf("1 - Comprar ou Reservar Cadeira\n");
    printf("2 - Cancelar compra\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
}

void Menu() {
    printf("\n************ MENU ************\n");
    printf("1 - Insere Sessão na lista\n");
    printf("2 - Remover Sessão da lista\n");
    printf("3 - Consultar Status de uma Sessão da lista\n");
    printf("4 - Exibir Sessões da lista\n");
    printf("5 - Comprar, Reservar ou cancelar compra de cadeira de uma sessão\n");
    printf("6 - Armazenar arquivo em disco\n");
    printf("7 - Exibir fila de espera\n");
    printf("8 - Remover da lista sessoes ja passadas\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
}

// for fim retorna um ponteiro para uma variavel do tipo char com o valor da conversao
char *format(int number){
    char 	*retorno,
    ret[100];
    int 	i;
    
    if (number < 10){
        sprintf(ret,"0%d",number);
        retorno = ret;
        return retorno;
    }
    else{
        sprintf(ret,"%d",number);
        retorno = ret;
        return retorno;
    }
}

// funcao que retorna datam
char *dataaa(void){
    
    int dia,mes,ano;
    char var1[100], var2[100], var3[100], var4[100], *dataPtr;
    struct tm *local;
    time_t t;
    
    t = time(NULL);
    local = localtime(&t);
    
    dia = local -> tm_mday;
    mes = local -> tm_mon + 1;
    ano = local -> tm_year + 1900;
    
    // por algum motivo precisa converter os valores retornados pelos ponteiros
    // da funcao em variaveis do tipo char
    sprintf(var1,"%s",format(dia));
    sprintf(var2,"%s",format(mes));
    sprintf(var3,"%s",format(ano));
    
    // cria a variavel de retorno dos dados e cria um ponteiro para essa variavel
    sprintf(var4,"%s/%s/%s",var1,var2,var3);
    
    // retorna data no formato dd:MM:yyyy com um ponteiro
    dataPtr = var4;
    return dataPtr;
}
