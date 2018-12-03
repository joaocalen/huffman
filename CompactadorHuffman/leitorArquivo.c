/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* Contar quantos bytes tem cada caracter, caracteres[i]++ para cada caracter com i sendo seu valor na tabela ASCII
   Contar quantos bytes diferentes ocorrem no arquivo: while(i<256) if(caracteres[i] !=0 nBytes++;
    
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitorArquivo.h"
#include "arvore.h"
#include "lista.h"
#include "bin.h"
#define n 255

ListaArvores* contagemArquivo(char* arquivo) {

    // inicializando ponteiro pro arquivo

    FILE *entrada;
    entrada = fopen(arquivo, "r");

    // inicializando o vetor com a contagem das ocorrências de cada caracter. n = 255 pois há 256 caracteres na tabela ASCII.

    int caracteres[n];

    // chama função para inicializar todos as posições do vetor com 0.
    inicializaVetor(caracteres);

    // Leitura do arquivo

    int c = fgetc(entrada);

    // -1 é o inteiro referente a EOF
    while (c > 0) {
        caracteres[c]++;
        c = fgetc(entrada);
    }

    // adicionando árvores, (apenas nós folhas) dos caracteres com mais de 1 occorência no arquivo, na lista de árvores

    ListaArvores* listaArvores = adicionarArvoresArquivo(caracteres);

    //lista_imprime(listaArvores);

    fclose(entrada);

    return listaArvores;

}

void inicializaVetor(int* c) {
    int i = 0;
    while (i < n) {
        c[i] = 0;
        i++;
    }

}

ListaArvores* adicionarArvoresArquivo(int* c) {
    //printf("Caracter %c: %i vezes \n", (char) i, caracteres[i]);
    ListaArvores* lista = lista_inicializa();
    int i = 0;
    while (i < n) {
        if (c[i] > 0) {
            lista_insere(arvore_cria((char) i, c[i], arvore_criavazia(), arvore_criavazia()), lista);
            lista = lista_setTamanho(lista, lista_getTamanho(lista) + 1);
        }
        i++;
    }
    return lista;
}

Arvore* lerCompactado(char* arquivo) {
    FILE *compactado;
    compactado = fopen(arquivo, "r");
    int numBits = lerNumBits(compactado);
    fgetc(compactado); //andando uma posição no arquivo (pular o ponto)
    int numCaracteres = lerNumBits(compactado);
    fgetc(compactado); //andando uma posição no arquivo, para chegar na árvore compactada impressa
    char* sequencia = lerCabecalho(compactado, numBits);
    int aux = 0; // variavel para posicao no vetor de bits
    Arvore* huffman = sequencia_to_arvore(sequencia, &aux);
    //arvore_imprime(huffman);
    free(sequencia);
    fclose(compactado);
    return huffman;
}

int lerNumBits(FILE* compactado) {
    int c = 0;
    fscanf(compactado, "%d", &c);
    return c;
}

char* lerCabecalho(FILE* compactado, int numBits) {
    int i = 0, j = 0, k = 0, numBytes = 0;
    numBytes = (int) numBits / 8;
    char* sequencia = (char*) malloc(numBits + 1 * sizeof (char));
    memset(sequencia, 0, numBits + 1);
    while (i < numBytes) {
        char* letra = dec_to_bin(fgetc(compactado));
        k = 0;
        while (k != 8) {
            sequencia[j] = letra[k];
            k++;
            j++;
        }
        i++;
        free(letra);
    }

    // pegar os bits refentes à sobra. Ou seja, não pegará todos os bits do último byte, se numBits % 8 != 0
    k = 0;
    char* letra = dec_to_bin(fgetc(compactado));
    while (j < numBits) {
        sequencia[j] = letra[k];
        k++;
        j++;
    }
    free(letra);
    return sequencia;
}

Arvore* sequencia_to_arvore(char* sequencia, int* aux) {
    if (sequencia[*aux] == '1') {
        *aux = *aux + 1;
        char caracter[8] = {'0'};
        for (int i = 0; i < 8; i++) {
            caracter[i] = sequencia[*aux];
            *aux = *aux + 1;
        }
        return arvore_cria(bin_to_dec(caracter), 1, arvore_criavazia(), arvore_criavazia());
    } else {
        *aux = *aux + 1;
        Arvore* arv1 = arvore_cria(0, 0, arvore_criavazia(), arvore_criavazia());
        arv1 = arvore_setNoE(arv1, sequencia_to_arvore(sequencia, aux));
        arv1 = arvore_setNoD(arv1, sequencia_to_arvore(sequencia, aux));
        return arv1;
    }
}