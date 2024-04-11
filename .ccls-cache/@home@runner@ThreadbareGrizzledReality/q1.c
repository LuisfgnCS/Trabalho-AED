#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

arvore *criar(){
    arvore *nova = (arvore *)malloc(sizeof(arvore));
    if(nova == NULL) *nova = NULL;
    return nova;
}

int alt_no(elemento *no){
    if(no == NULL) return -1;
    else return no->alt;
}

int fatB(elemento *no){
    return (alt_no(no->esq) - alt_no(no->dir));
}

int maior(int a, int b){
    if(a >= b) return a;
    else return b;
}

static void rotacionarLL(arvore *raiz){
    elemento *no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt) + 1;
    *raiz = no;
}

static void rotacionarRR(arvore *raiz){
    elemento *no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->dir), (*raiz)->alt) + 1;
    *raiz = no;
}

static void rotacionarRL(arvore *raiz){
    rotacionarLL(&(*raiz)->dir);
    rotacionarRR(raiz);
}

static void rotacionarLR(arvore *raiz){
    rotacionarRR(&(*raiz)->esq);
    rotacionarLR(raiz);
}

int inserir(arvore *raiz, info informacoes){
    int res;
    if(*raiz == NULL){
        elemento *novo = (elemento *)malloc(sizeof(elemento));
        if(novo == NULL) return 0;
        novo->informacao.caractere = informacoes.caractere;
        novo->informacao.chave = informacoes.chave;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    else{
        elemento *atual = *raiz;
        if(informacoes.chave < atual->informacao.chave){
            if((res = inserir(&(atual->esq), informacoes)) == 1){
                if(fatB(atual) >= 2){
                    if(informacoes.chave < (*raiz)->esq->informacao.chave) rotacionarLL(raiz);
                    else rotacionarLR(raiz);
                }
            }
        }
        else{
            if(informacoes.chave > atual->informacao.chave){
                if((res = inserir(&(atual->dir), informacoes)) == 1){
                    if(fatB(atual) >= 2){
                        if((*raiz)->dir->informacao.chave < informacoes.chave) rotacionarRR(raiz);
                        else rotacionarRL(raiz);
                    }
                }
            }
            else{
                printf("O valor já está na árvore.");
                return 0;
            }
        }
        atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) + 1;
        return res;
    }
}
