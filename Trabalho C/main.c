#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

struct lista
{
    int qnt;
    struct aluno dados[MAX];
};

Lista* criar_lista(){
    Lista *li;
    li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        li->qnt = 0;
    return li;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    int i = 0, k;
    while (i < li->qnt && strcmp(li->dados[i].nome, al.nome) < 0)
        i++;
    for(k = li->qnt-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];
    li->dados[i] = al;
    li->qnt++;
    return 1;
}

int exibe_lista(Lista* li){
    int i;
    printf("Lista: \"");
    for(i = 0; i < li->qnt; i++)
        printf("%s - %2.1lf | ", li->dados[i].nome, li->dados[i].nota);
    printf("\"\n");
    return 1;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    return (li->qnt == 0) ? 1 : 0;
    // RETORNA 1 QUANDO VAZIO
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    return(li->qnt == MAX) ? 1 : 0;
    // RETORNA 1 QUANDO CHEIO

}

int consulta_lista(Lista* li, char nome[], struct aluno *al){
    if(li == NULL)
        return 0;
    int i = 0;
    while(i < li->qnt && strcmp(li->dados[i].nome, nome) != 0)
        i++;
    if(i == li->qnt)
        return 0;
    *al = li->dados[i];
    return 1;

}

int remove_lista(Lista* li, char nome[]){
    if(li == NULL)
        return 0;
    if(li->qnt == 0)
        return 0;
    int i, k = 0;
    while(i < li->qnt && strcmp(li->dados[i].nome, nome) != 0)
        i++;
    if(i == li->qnt)
        return 0;
    for(k = i; k < li->qnt-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qnt--;
    return 1;
}

void libera_lista(Lista* li){
    free(li);
}

int main(){
    int x, sel = 0;
    Lista* li = NULL;
    struct aluno dados_aluno;
    do{
        printf("Digite 1 para criar lista\n");
        printf("Digite 2 para inserir um aluno\n");
        printf("Digite 3 para exibir a lista\n");
        printf("Digite 4 para verificar se a lista esta vazia\n");
        printf("Digite 5 para buscar um aluno\n");
        printf("Digite 6 para excluir um aluno\n");
        printf("Digite 7 para liberar a lista\n");
        printf("Digite 8 para sair\n");
        scanf("%d", &sel);
        switch (sel){
            case 1:
                li = criar_lista();
                if (li != NULL){
                    printf("Lista criada com sucesso\n");
                    break;
                }
                printf("Erro ao criar lista");
                break;
            case 2:
                if(li == NULL){
                    printf("A lista nao foi criada ainda.\n");
                    break;
                }
                printf("Digite o nome do aluno\n");
                scanf("%99s", dados_aluno.nome);
                printf("Digite a nota do aluno\n");
                scanf("%f", &dados_aluno.nota);
                insere_lista_ordenada(li, dados_aluno);
                break;
            case 3:
                if(li == NULL){
                    printf("A lista nao foi criada ainda.\n");
                    break;
                }
                exibe_lista(li);
                break;
            case 4:
                x = lista_vazia(li);
                if (x == 1)
                    printf("A lista esta vazia\n");
                else
                    printf("A lista nao esta vazia\n");
                break;
            case 5:
                printf("Digite o nome do aluno\n");
                scanf("%99s", dados_aluno.nome);
                x = consulta_lista(li, dados_aluno.nome, &dados_aluno);
                if(x == 1)
                    printf("%s esta com a nota %2.lf\n", dados_aluno.nome, dados_aluno.nota);
                else
                    printf("O nome nao esta na lista\n");
                break;
            case 6:
                printf("Digite o nome do aluno\n");
                scanf("%99s", dados_aluno.nome);
                x = remove_lista(li, dados_aluno.nome);
                if (x == 1)
                    printf("O aluno foi removido com sucesso\n");
                else
                    printf("Erro ao remover aluno\n");
                break;
            case 7:
                libera_lista(li);
                li = NULL;
                printf("Lista liberada com sucesso\n");
                break;
            default:
                break;
        }
    }while (sel != 8);

    
    return 0;
}