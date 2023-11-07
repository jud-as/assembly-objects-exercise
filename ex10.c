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


int main() {

    solicitarInfos();
    return 0;
}


/**** empilhar(No *topo) {
    No *novo = malloc(sizeof(No));

    if(novo) {
        novo->o = solicitarInfos();
    } else {
        printf("\nErro ao alocar memoria.");
    }
    
}*/