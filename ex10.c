#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nomePeca[30];
}Peca;

typedef struct 
{
    Peca pecas[10];
    char nomeObj[30];
    int qntdPecas;
}Objeto;


typedef struct no
{
    Objeto o;
    struct no *proximo;
}No;


Objeto solicitarInfos() {
    Objeto o;
    printf("Objeto: "); 
    fgets(o.nomeObj, 30, stdin);
    printf("Quantidade de pecas: ");
    scanf("%d", &o.qntdPecas);
    for (int i = 0; i < o.qntdPecas; i++)
    {
        printf("Peca[%d/%d]: ", i+1, o.qntdPecas);
        scanf("%s", &o.pecas[i].nomePeca);
    }

    for (int i = 0; i < o.qntdPecas; i++) {
        printf("%s ", o.pecas[i].nomePeca);
    }
    return o;
}


void imprimirObjeto(Objeto o) {
    printf("\nNome: %sQuantidade de pecas: %d\n", o.nomeObj, o.qntdPecas);
    for (int i = 0; i < o.qntdPecas; i++)
    {
        printf("%s\n", o.pecas[i].nomePeca);
    }    
}

No* empilhar(No *topo) {
    No *novo = malloc(sizeof(No));
    
    if (novo)
    {
        novo->o = solicitarInfos();
        novo->proximo = topo;
        return novo;
    } else {
        printf("Erro de alocacao de memoria.");
    }
    return NULL;

}

No* desempilhar(No **topo) {
    if (*topo != NULL)
    {
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    } else {
        printf("\nPilha vazia!");
    }
    return NULL;
    
}

void imprimir_pilha(No *topo) {
    printf("\n---------------- PILHA -----------------\n");
    while (topo)
    {
        imprimirObjeto(topo->o);
        topo = topo->proximo;   
    }
    printf("\n-------------- FIM PILHA ---------------\n");
}

int main() {

    No *remover, *topo = NULL;
    int opcao;

    do
    {
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao)
        {
        case 1:
            topo = empilhar(topo);         
            break;
        case 2:
            remover = desempilhar(&topo);
            if (remover)
            {
                printf("\nElemento removido com sucesso.\n");
                imprimirObjeto(remover->o);
            }
            else
            {
                printf("\nSem no para remover.");
            }
            break;
        case 3:
                imprimir_pilha(topo);
            break;
        
        default:
            if (opcao != 0)
            {
                printf("\nOpcao invalida!\n");
            }
        }
    } while (opcao != 0);

    return 0;
}
