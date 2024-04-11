// STRUCTS --------------------------------------------------------------------------
typedef struct Elemento {
  int chave;
  char caractere;
  struct Elemento *esq;
  struct Elemento *dir;
  int alt;
} elemento;

typedef elemento* arvore; // ponteiro de ponteiro

typedef struct ARVORE{
    int id;
    int ordem;
    arvore *tree;
}arvores;

// FUNCOES --------------------------------------------------------------------------
arvore *criar();
int inserir(arvore *raiz, int valor, char caractere);
void pre_ordem(elemento *no);
void em_ordem(elemento *no);
void pos_ordem(elemento *no);