struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct aluno Aluno;
typedef struct fila Fila;

Fila* criar_fila();

void liberar_fila(Fila *);

int tamanho_fila(Fila *);
int fila_cheia(Fila *);
int fila_vazia(Fila *);

int insere_fila(Fila *,Aluno );
int remove_fila(Fila *);
int consulta_fila(Fila *, Aluno *);

int imprime_lista(Fila *);