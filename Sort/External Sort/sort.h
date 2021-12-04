struct arquivo{
    FILE *f;
    int pos, MAX, *buffer;
};

void criaArquivoTeste(char * nome);
void mergeSortExterno(char * nome);

int criaArquivosOrdenados(char * nome);
void salvarArquivo(char * nome, int * V, int tam, int mudaLinhaFinal);

void merge(char * nome, int numArqs, int K );
int procuraMenor(struct arquivo* arq, int numArgs, int K, int * menor);
void preencheBuffer(struct arquivo* arg, int K);