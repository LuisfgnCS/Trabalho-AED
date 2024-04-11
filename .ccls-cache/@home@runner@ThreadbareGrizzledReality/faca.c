#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int chave;
    char caractere;
} info;

typedef struct Elemento {
    info dados;
    struct Elemento *esq;
    struct Elemento *dir;
    int alt;
} elemento;

int altura(elemento *no) {
    int h = 0;
    if (no != NULL) {
        int alt_esq = altura(no->esq);
        int alt_dir = altura(no->dir);
        int max_alt = alt_esq > alt_dir ? alt_esq : alt_dir;
        h = 1 + max_alt;
    }
    return h;
}

elemento **criar(){
    elemento **novaArvore = (elemento **)malloc(sizeof(elemento *));
    if(novaArvore == NULL) *novaArvore = NULL;
    return novaArvore;
}

int fatorBalanceamento(elemento *no) {
    return labs(altura(no->esq) - altura(no->dir));
}

int maior(int a, int b) {
  if(a >= b) return a;
  else return b;
}

void rotacao_simples_direita(elemento **raiz) {
    elemento *q = *raiz;
    elemento *p = q->esq;

    q->esq = p->dir;
    p->dir = q;

    q->alt = 1 + maior(altura(q->esq), altura(q->dir));
    p->alt = 1 + maior(altura(p->esq), q->alt);

    *raiz = p;
}

void rotacao_simples_esquerda(elemento **raiz) {
    elemento *p = *raiz;
    elemento *q = p->dir;

    p->dir = q->esq;
    q->esq = p;

    p->alt = 1 + maior(altura(p->esq), altura(p->dir));
    q->alt = 1 + maior(altura(q->dir), p->alt);

    *raiz = q;
}


void insercao_arvore(elemento **raiz, info dados) {
    elemento *novo = (elemento *)malloc(sizeof(elemento));
    novo->dados = dados;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->alt = 0;

    if (*raiz == NULL) {
        *raiz = novo;
        return;
    }

    elemento *atual = *raiz;
    elemento *antecessor = NULL;

    while (atual != NULL) {
        antecessor = atual;

        if (dados.chave < atual->dados.chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    if (dados.chave < antecessor->dados.chave)
        antecessor->esq = novo;
    else
        antecessor->dir = novo;
}

int main(void){
    int b;
    elemento **tree = criar();
    info dados[10];
    dados[0].chave = 21;
    dados[0].caractere = 'L';
    insercao_arvore(tree, dados[0]);
    printf("%d", (**tree).dados.chave);
    scanf("%d", &b);
    return 0;
}