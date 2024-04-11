// STRUCTS --------------------------------------------------------------------------
typedef struct{
    int chave;
    char caractere;
} info;

typedef struct Elemento{
    int alt;
    info informacao;
    struct Elemento *esq;
    struct Elemento *dir;
} elemento;

typedef elemento* arvore; // ponteiro de ponteiro

typedef struct ARVORE{
    int id;
    int ordem;
    arvore *tree;
}arvores;

// FUNCOES --------------------------------------------------------------------------
arvore *criar();
int alt_no(elemento *no);
int fatB(elemento *no);
int maior(int a, int b);
int inserir(arvore *raiz, info informacoes);