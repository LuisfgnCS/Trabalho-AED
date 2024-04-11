#include "q1.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  arvores lista[10];
  int count = 0;
  int n = 1;

  char linha[100]; // Tamanho máximo da linha
  FILE *arquivo;

  arquivo = fopen("testes.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }
  int numero[2];
  char letra, virgula[3];
  do {
    if (fgets(linha, 11, arquivo) != NULL) {
      sscanf(linha, "%d %c %c %c %d, %c", &numero[0], &virgula[0], &letra,
             &virgula[1], &numero[1], &virgula[2]);
      if (virgula[1] != ',') { // CRIAR ARVORE
        sscanf(linha, "%d %c %d", &numero[0], &virgula[0], &numero[1]);
        printf("\nvalores: %d, %d\n", numero[0], numero[1]);
        lista[count].id = numero[0];
        lista[count].ordem = numero[1];
        lista[count].tree = criar();
        count++;
      } else {
        int i = 0;
        virgula[1] = '\0';
        for (int i = 0; i <= count; i++) {
          if (lista[i].id == numero[0]) {
            arvore *aux = lista[i].tree;
            inserir(aux, numero[1], letra);
            break;
          }
        }
        if (i > count) {
          printf("Erro na linha: %d", n);
        }
      }
    } else {
      break;
    }
    n++;
  } while (2 > 1);
  // printf("%d", (*a)->informacao.chave);
  for (int i = 0; i < count; i++) {
    int z = lista[i].ordem;
    arvore *a = lista[i].tree;
    printf("\n\nArvore %d:\n", lista[i].id);
    switch (z){
    case 1:
      printf("Pre-ordem: ");
      pre_ordem(*a);
      printf("\n");
      break;
    case 2:
      printf("Em-ordem: ");
      em_ordem(*a);
      printf("\n");
      break;
    case 3:
      printf("Pos-ordem: ");
      pos_ordem(*a);
      printf("\n");
      break;
    default:
      printf("Erro");
    }
  }
  fclose(arquivo);
  return 0;
}