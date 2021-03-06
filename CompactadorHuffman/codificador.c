// Classe que, dada a árvore de huffman, devolve um vetor de 256 caracteres onde cada posição guardará a sequência binária correspondente (ainda em string)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codificador.h"
#include "arvore.h"

unsigned char** criaSequencias(Arvore* huffman) {
    unsigned char** sequencias = (unsigned char**) malloc(256 * sizeof (unsigned char*));
    tabela_aloca(sequencias);
    percorreArvore(huffman, 1, sequencias);
    return sequencias;
}

void percorreArvore(Arvore* huffman, int sequencia, unsigned char** sequencias) {
    if (!arvore_vazia(huffman) && !arvore_isFolha(huffman)) {
        sequencia *= 10;
        percorreArvore(arvore_getNoE(huffman), sequencia, sequencias);
        sequencia += 1;
        percorreArvore(arvore_getNoD(huffman), sequencia, sequencias);
        sequencia = (int) ((sequencia - 1) / 10);
    } else if (arvore_isFolha(huffman)) {
        snprintf(sequencias[(unsigned int) arvore_getConteudo(huffman)], 9, "%d", sequencia);
        int i = 0;
        while (sequencias[(unsigned int) arvore_getConteudo(huffman)][i] == '1' || sequencias[(unsigned int) arvore_getConteudo(huffman)][i] == '0') {
            sequencias[(unsigned int) arvore_getConteudo(huffman)][i] = sequencias[(unsigned int) arvore_getConteudo(huffman)][i + 1];
            i++;
        }
    }
}

void tabela_libera(unsigned char** tabela) {
    for (int i = 0; i < 256; i++) {
        free(tabela[i]);
    }
    free(tabela);
}

void tabela_aloca(unsigned char** tabela) {
    for (int i = 0; i < 256; i++) {
        tabela[i] = (unsigned char*) malloc(9 * sizeof (unsigned char));
        memset(tabela[i], 0, 9);
    }
}