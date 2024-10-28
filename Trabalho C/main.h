#define MAX 100

struct aluno{
    char nome[MAX];
    float nota;
};

typedef struct lista Lista;

Lista* criar_lista();

int insere_lista_ordenada(Lista* li, struct aluno al);

int exibe_lista(Lista* li);

int lista_vazia(Lista* li);

int lista_cheia(Lista* li);

int consulta_lista(Lista* li, char nome[], struct aluno *al);

int remove_lista(Lista* li, char nome[]);

void libera_lista(Lista* li);