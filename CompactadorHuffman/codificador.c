// Classe que, dada a árvore de huffman, devolve um vetor de 256 caracteres onde cada posição guardará a sequência binária correspondente (ainda em string)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codificador.h"
#include "arvore.h"

unsigned char* criaSequencias(Arvore* huffman) {
    unsigned char* sequencias[256];
    percorreArvore(huffman, 1, sequencias);
    return *sequencias;
}

void percorreArvore(Arvore* huffman, int sequencia, unsigned char* sequencias[]) {
    if (!arvore_vazia(huffman) && !arvore_isFolha(huffman)) {
        sequencia *= 10;
        percorreArvore(arvore_getNoE(huffman), sequencia, sequencias);
        sequencia += 1;
        percorreArvore(arvore_getNoD(huffman), sequencia, sequencias);
        sequencia = (int) ((sequencia - 1) / 10);
    } else if (arvore_isFolha(huffman)) {

        sequencias[(int) arvore_getConteudo(huffman)] = (unsigned char*) malloc(9 * sizeof (unsigned char));
        snprintf(sequencias[(int) arvore_getConteudo(huffman)], 9, "%d", sequencia);
        int i = 0;
        while (sequencias[(int) arvore_getConteudo(huffman)][i] == '1' || sequencias[(int) arvore_getConteudo(huffman)][i] == '0') {
            sequencias[(int) arvore_getConteudo(huffman)][i] = sequencias[(int) arvore_getConteudo(huffman)][i + 1];
            i++;
        }
        printf("\n%c: %s", arvore_getConteudo(huffman), sequencias[(int) arvore_getConteudo(huffman)]);
    }
}