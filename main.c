#include <stdio.h>
#include <stdlib.h>

#include "BPlusTree.h" 

#define MAX_LINHA 100

void carregarRegistro(const char *nomeArquivo, BPlusTree_t *arvore) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    char linha[MAX_LINHA];
  
    while (fgets(linha, sizeof(linha), arquivo)) {
        registro_t r;

        linha[strcspn(linha, "\n")] = 0;
        sscanf(linha, "%d,%19[^,],%d,%19[^\n]", &r.chave, r.modelo, &r.ano, r.cor);

        inserir(arvore, r);
    }

    fclose(arquivo);
}

int main() {
    BPlusTree_t *arvore = criarArvoreBPlus();
  
    const char *nomeArquivo = "registros_carros.txt";
    carregarRegistro("registros_carros.txt", arvore);

    // fazer buscas, impressões e testes

    return 0;
}
