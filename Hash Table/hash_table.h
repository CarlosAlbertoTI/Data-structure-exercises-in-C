struct aluno{
    int matricula;
    char * nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;
typedef struct aluno Aluno;
Hash* criarHash(int TABLE_SIZE);
void liberaHash(Hash * hash);
int valorString(char * nome);

int insere_hash_sem_colisao(Hash * hash, struct aluno al);
int busca_hash_sem_colisao(Hash * hash, int matricula, struct aluno *al);

int insere_hash_ender_aberto(Hash * hash, struct aluno al);
int busca_hash_ender_aberto(Hash * hash, int matricula, struct aluno *al);