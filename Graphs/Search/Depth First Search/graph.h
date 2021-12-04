typedef struct grafo Grafo;

Grafo *criar_grafo(int num_vertices, int grau_max, int eh_ponderado);
void libera_grafo(Grafo* grafo);

int insereAresta(Grafo* grafo, int origem, int destino, int eh_digrafo, float peso);
int removerAresta(Grafo* grafo, int origem, int destino, int eh_digrafo);


void buscaProfundidade(Grafo* grafo, int inicio, int * vetor_visitado, int count);
void buscaProfundidade_Grafo(Grafo *grafo, int inicio, int *vetor_visitados);