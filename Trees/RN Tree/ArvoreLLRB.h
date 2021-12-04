struct No
{
    int info;
    struct No *left;
    struct No *right;
    int color;
};
    

typedef struct No* ArvoreLLRB;

ArvoreLLRB* createTree();
void freeTree(ArvoreLLRB* root);
int insertTree(ArvoreLLRB *root, int value);
int removeTree(ArvoreLLRB *root, int value);
int searchTree(ArvoreLLRB* root, int value);
void preOrderTree(ArvoreLLRB* root);
