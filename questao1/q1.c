#include "q1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

arvore *criar(){
  arvore *raiz = (arvore *)malloc(sizeof(arvore));
  if (raiz != NULL)
    *raiz = NULL;
  return raiz;
}

static int altura(elemento *no) {
  if (no == NULL)
    return -1;
  else
    return no->alt;
}

static int fatorBalanceamento_NO(elemento *no) {
  return labs(altura(no->esq) - altura(no->dir));
}

static int maior(int a, int b) {
  if (a > b) return a;
  else return b;
}

void pre_ordem(elemento *raiz) {
  if (raiz != NULL) {
    printf("%c", raiz->caractere);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

void em_ordem(elemento *raiz) {
  if (raiz != NULL) {
    em_ordem(raiz->esq);
    printf("%c", raiz->caractere);
    em_ordem(raiz->dir);
  }
}

void pos_ordem(elemento *raiz) {
  if (raiz != NULL) {
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%c", raiz->caractere);
  }
}

static void RotacaoLL(arvore *A) {
  elemento *B;
  B = (*A)->esq;
  (*A)->esq = B->dir;
  B->dir = *A;
  (*A)->alt = maior(altura((*A)->esq), altura((*A)->dir)) + 1;
  B->alt = maior(altura(B->esq), (*A)->alt) + 1;
  *A = B;
}

static void RotacaoRR(arvore *A) { 
  elemento *B;
  B = (*A)->dir;
  (*A)->dir = B->esq;
  B->esq = (*A);
  (*A)->alt = maior(altura((*A)->esq), altura((*A)->dir)) + 1;
  B->alt = maior(altura(B->dir), (*A)->alt) + 1;
  (*A) = B;
}

static void RotacaoLR(arvore *A) {
  RotacaoRR(&(*A)->esq);
  RotacaoLL(A);
}

static void RotacaoRL(arvore *A) {
  RotacaoLL(&(*A)->dir);
  RotacaoRR(A);
}

int inserir(arvore *raiz, int valor, char caractere) {
  int res;
  if (*raiz == NULL) {
    elemento *novo;
    novo = (elemento *)malloc(sizeof(elemento));
    if (novo == NULL)
      return 0;

    novo->chave = valor;
    novo->alt = 0;
    novo->caractere = caractere;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return 1;
  }

  elemento *atual = *raiz;
  if (valor < atual->chave) {
    if ((res = inserir(&(atual->esq), valor, caractere)) == 1) {
      if (fatorBalanceamento_NO(atual) >= 2) {
        if (valor < (*raiz)->esq->chave) {
          RotacaoLL(raiz);
        } else {
          RotacaoLR(raiz);
        }
      }
    }
  } else {
    if (valor > atual->chave) {
      if ((res = inserir(&(atual->dir), valor, caractere)) == 1) {
        if (fatorBalanceamento_NO(atual) >= 2) {
          if ((*raiz)->dir->chave < valor) {
            RotacaoRR(raiz);
          } else {
            RotacaoRL(raiz);
          }
        }
      }
    } else {
      printf("O valor já está na árvore.\n");
      return 0;
    }
  }

  atual->alt = maior(altura(atual->esq), altura(atual->dir)) + 1;

  return res;
}