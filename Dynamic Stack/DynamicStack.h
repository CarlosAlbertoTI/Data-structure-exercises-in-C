struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;    
};

typedef struct aluno Aluno;
typedef struct elemento* Pilha;

Pilha* criar_pilha();
void liberar_pilha(Pilha* );

int tamanho_pilha(Pilha* );
int pilha_cheia(Pilha* );
int pilha_vazia(Pilha* );

int inserir_pilha(Pilha*, struct aluno);
int remove_pilha(Pilha* );

int consulta_pilha(Pilha* , struct aluno *);

int imprime_pilha(Pilha* );
