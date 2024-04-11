#include <stdio.h>
#include <stdlib.h>
#include "q1.h"

int main(void) {
    arvores lista[10];
    int count = 0;
    int n = 1;

    char linha[100]; // Tamanho máximo da linha
    FILE *arquivo;

    // Abre o arquivo para leitura
    arquivo = fopen("testes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    int a = 1;
    int numero[2];
    char letra, virgula[3];
    // Lê a linha do arquivo
    do{
        if (fgets(linha, 11, arquivo) != NULL){
            sscanf(linha, "%d %c %c %c %d, %c", &numero[0], &virgula[0], &letra, &virgula[1], &numero[1], &virgula[2]);
            if(virgula[1] != ','){ // CRIAR ARVORE
                sscanf(linha, "%d %c %d", &numero[0], &virgula[0], &numero[1]);
                lista[0].id = numero[0];
                lista[0].ordem = numero[1];
                lista[0].tree = criar();
                count++;
            }
            else{
                int i = 0;
                for(int i = 0; i <= count; i++){
                    if(lista[i].id == numero[0]){
                        arvore *aux = lista[i].tree;
                        info informacao = {numero[1], letra};
                        inserir(aux, informacao);
                        break;
                    } 
                }
                if(i > count){
                    printf("Erro na linha: %d", n);
                }
            }
        } 
        else {
            break;
        }
        n++;
    } while(2 > 1);

    // Fecha o arquivo
    fclose(arquivo);
    return 0;
}
