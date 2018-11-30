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
#include "leitorArquivo.h"
#include "arvore.h"
#include "lista.h"
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