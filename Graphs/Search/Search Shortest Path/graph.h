typedef struct grafo Grafo;

Grafo *criar_grafo(int num_vertices, int grau_max, int eh_ponderado);
void libera_grafo(Grafo* grafo);
int insereAresta(Grafo* grafo, int origem, int destino, int eh_digrafo, float peso);
int removerAresta(Grafo* grafo, int origem, int destino, int eh_digrafo);

void menorCaminho_Grafo(Grafo *grafo, int inicio, int * anterior, float * distancia);

void imprime_Grafo(Grafo *gr);