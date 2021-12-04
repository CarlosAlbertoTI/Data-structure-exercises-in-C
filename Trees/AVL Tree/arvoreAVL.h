struct NO{
    int info;
    int altura;
    struct NO *esquerda;
    struct NO *direita;
};

typedef struct NO NO;
typedef struct NO* ArvrAVL;

ArvrAVL* cria_arvoreAVL();
void libera_ArvAVL(ArvrAVL* raiz);

int estaVazia_ArvoreAVL(ArvrAVL *raiz);
int altura_arvoreAVL(ArvrAVL *raiz);
int total_NO_arvoreAVL(ArvrAVL *raiz);

void preOrdem_ArvoreAVL(ArvrAVL *raiz);
void emOrdem_ArvoreAVL(ArvrAVL *raiz);
void posOrdem_ArvoreAVL(ArvrAVL *raiz);

int altura_NO(struct NO* no);
int fatorBalanceamento_NO(struct NO* no);

void rotacaoLL(ArvrAVL *raiz);

void rotacaoRR(ArvrAVL *raiz);

void rotacaoLR(ArvrAVL *raiz);

void rotacaoRL(ArvrAVL *raiz);

int inserir_arvAVL(ArvrAVL *raiz, int valor);

int remover_arvAVL(ArvrAVL *raiz, int valor);
