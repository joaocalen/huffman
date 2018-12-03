/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   leitorArquivo.h
 * Author: joaogcalen
 *
 * Created on 6 de Novembro de 2018, 01:29
 */

#ifndef LEITORARQUIVO_H
#define LEITORARQUIVO_H

#include "arvore.h"
#include "lista.h"

#ifdef __cplusplus
extern "C" {
#endif
    // inicializa vetor de ocorrencias de cara caracter
    void inicializaVetor(int* c);

    // função principal para a leitura do arquivo original para a compactação. Para cada ocorrência de um dado caracter, adiciona uma ocorrencia na posição do vetor
    // cujo inteiro representa o dado caracter.
    ListaArvores* contagemArquivo(char* arquivo);

    // Dado o vetor de inteiros, retorna uma lista de árvores apenas com os nós folhas.
    ListaArvores* adicionarArvoresArquivo(int* c);

    // Lê o cabeçalho do arquivo e retorna a árvore de huffman
    Arvore* lerCompactado(char* arquivo);

    // Retorna o numbits usados para representar o cabeçalho do arquivo compactado
    int lerNumBits(FILE* compactado);

    // retorna o número de caracteres do arquivo original
    int lerNumCaracteres(FILE* compactado);
    
    // retorna uma string com todo o conteúdo do cabeçalho (representado apenas por 0s e 1s).
    unsigned char* lerCabecalho(FILE* compactado, int numBits);
    
    // função que, dado uma sequencia de binários, faz chamadas recursivas para montar a árvore de huffman para a descompactação do arquivo
    Arvore* sequencia_to_arvore(unsigned char* sequencia, int* aux);

#ifdef __cplusplus
}
#endif

#endif /* LEITORARQUIVO_H */

