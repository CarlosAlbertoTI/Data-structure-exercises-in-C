typedef struct descritor Bag;
 
Bag* criarBag();
void liberaBag(Bag* bag);

int insereBag(Bag* bag, int valor);
int removerBag(Bag* bag, int valor);
int buscaBag(Bag* bag, int valor);

void beginBag(Bag* Bag);
int endBag(Bag* Bag);
void nextBag(Bag* Bag);
void getItemBag(Bag* Bag, int * num);