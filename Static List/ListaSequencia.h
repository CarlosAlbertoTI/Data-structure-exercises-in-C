#define MAX 100
struct aluno {
    int matricula;
    char nome[30];
    float n1,n2,n3;
};
typedef struct aluno Aluno;
typedef struct lista Lista;

Lista* criarLista();

void liberaLista(Lista* li);
int tamanhoLista(Lista* li);
int listaCheia(Lista* li);
int insereListaFinal(Lista* li, struct aluno al);
int insereListaInicio(Lista* li, struct aluno al);
int insereListaOrdenada(Lista* li,struct aluno al);
int removerListaFinal(Lista* li);
int removerListaInicio(Lista* li);
int removerLista(Lista* li, int mat);
int consultaListaPos(Lista* li, int pos, struct aluno al); 
int consultaListaMat(Lista* li, int mat, struct aluno al); 