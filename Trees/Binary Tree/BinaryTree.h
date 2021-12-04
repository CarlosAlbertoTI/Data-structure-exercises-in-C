struct NO{
    int info;
    struct NO* esquerda;
    struct NO* direita;
};

typedef struct NO* ArvBinaria;

ArvBinaria* cria_arvoreB();
void libera_ArvBin(ArvBinaria* raiz);

int estaVazia_ArvoreB(ArvBinaria *raiz);
int altura_arvoreB(ArvBinaria *raiz);
int total_NO_arvoreB(ArvBinaria *raiz);

void preOrdem_ArvoreB(ArvBinaria *raiz);
void emOrdem_ArvoreB(ArvBinaria *raiz);
void posOrdem_ArvoreB(ArvBinaria *raiz);

int inserir_ArvoreB(ArvBinaria *raiz, int valor);
int remove_ArvoreB(ArvBinaria *raiz, int valor);
int consulta_ArvoreB(ArvBinaria *raiz, int valor);