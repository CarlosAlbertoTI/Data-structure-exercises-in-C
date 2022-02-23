typedef struct SkipList SkipList;

SkipList* criar_skipList(int MAXLVL, float p);
void liberarSkipList(SkipList* skipList);

int buscar_skipList(SkipList* skipList, int chave);
int inserir_skipList(SkipList* skipList, int chave);
int remove_skipList(SkipList* skipList, int chave);