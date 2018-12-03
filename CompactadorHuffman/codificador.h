/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   codificador.h
 * Author: joaogcalen
 *
 * Created on 30 de Novembro de 2018, 23:13
 */

#ifndef CODIFICADOR_H
#define CODIFICADOR_H

#include "arvore.h"

#ifdef __cplusplus
extern "C" {
#endif

    // Função recursiva que através da árvore de huffman, insere os valores binários de huffman referente à cada caracter. Esses valores são inseridos em um vetor de 256 posições
    void percorreArvore(Arvore* huffman, int sequencia, unsigned char** sequencias);
    
    // função principal do arquivo, chama as outras funçoes auxiliares e retorna a tabela de sequencias binárias definidas em percorreArvore
    unsigned char** criaSequencias(Arvore* huffman);

    // libera (free) em todas as posições da tabela
    void tabela_libera(unsigned char** tabela);

    // faz alocação dinâmica das posições da tabela
    void tabela_aloca(unsigned char** tabela);

#ifdef __cplusplus
}
#endif

#endif /* CODIFICADOR_H */

