// Classe que, dada a árvore de huffman, devolve um vetor de 256 caracteres onde cada posição guardará a sequência binária correspondente (ainda em string)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codificador.h"
#include "arvore.h"

char* sequencias[256];

char* criaSequencias(Arvore* huffman){
    char* sequencia = (char*) malloc(8*sizeof(char)); // considerando 8 como a maior sequência possível
    sequencia = "";
    percorreArvore(huffman,sequencia,0);
}

char* percorreArvore(Arvore* huffman, char* sequencia, int tam) {
    if (!arvore_vazia(huffman) && !arvore_isFolha(huffman)){
        sequencia[tam] = '0';
        percorreArvore(arvore_getNoE(huffman),sequencia,tam+1);
        tam--;
        sequencia[tam] = '1';
        percorreArvore(arvore_getNoD(huffman),sequencia,tam+1);
        tam--;
        sequencia[tam] = ' ';
    } else if (arvore_isFolha(huffman)){
        
    }
}




